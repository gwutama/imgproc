#include "bitmapfile.h"
#include <fstream>
#include <cmath>
#include <iostream>

std::shared_ptr<BitmapFile> BitmapFile::fromFile(const std::string &filePath)
{
    std::ifstream ifs(filePath, std::ifstream::in | std::ifstream::binary);

    if (!ifs) {
        std::cerr << "Unable to read file: " << filePath << std::endl;
        return {};
    }

    auto bmpFile = std::shared_ptr<BitmapFile>(new BitmapFile);
    bmpFile->mFileName = filePath;

    // read bitmap file header
    char bitmapFileHeader[BITMAP_FILEHEADER_SIZE];
    ifs.read(bitmapFileHeader, BITMAP_FILEHEADER_SIZE);
    auto fileHeaderRef = bmpFile->mFileHeader;
    memcpy(&fileHeaderRef.get()->bfType, bitmapFileHeader, BITMAP_FILEHEADER_SIZE);

    // read bitmap info header
    uint32_t ifsOffset = BITMAP_FILEHEADER_SIZE;
    char bitmapInfoHeader[BITMAP_INFOHEADER_SIZE];
    ifs.seekg(ifsOffset, ifs.beg);
    ifs.read(bitmapInfoHeader, BITMAP_INFOHEADER_SIZE);
    auto infoHeaderRef = bmpFile->mInfoHeader;
    memcpy(infoHeaderRef.get(), bitmapInfoHeader, BITMAP_INFOHEADER_SIZE);

    if (infoHeaderRef->biSize != BITMAP_INFOHEADER_SIZE) {
        std::cerr << "Unsupported bitmap. Structure is not BITMAPINFOHEADER." << std::endl;
        return nullptr;
    }

    if (bmpFile->getBitDepth() != 8 && bmpFile->getBitDepth() != 24) {
        std::cerr << "Unsupported bit count: " << bmpFile->getBitDepth() << std::endl;
        return nullptr;
    }

    // read color table
    // Color table is irrelevant for images with bit depths > 8
    // and is usually set to 0 for images with bit depths > 8
    ifsOffset = ifsOffset + BITMAP_INFOHEADER_SIZE;
    auto colorTableSize = infoHeaderRef->biClrUsed;

    // Calculate default color table size if it is set to 0
    // Color table is irrelevant for images with bit depths > 8
    // IF color table is 0, then the default color table size is assumed (2 ^ bit depth)
    if (colorTableSize == 0 && bmpFile->getBitDepth() <= 8) {
        colorTableSize = pow(2, bmpFile->getBitDepth());
    }

    auto colorTableNumBytes = colorTableSize * BITMAP_RGBQUAD_SIZE;
    bmpFile->mColorTable->reserve(colorTableNumBytes);

    for (int i = 0; i < colorTableNumBytes; i = i + 4) {
        BitmapRgbQuad rgbQuad{};
        char buffer[BITMAP_RGBQUAD_SIZE];
        ifs.seekg(ifsOffset + i, ifs.beg);
        ifs.read(buffer, BITMAP_RGBQUAD_SIZE);
        memcpy(&rgbQuad, buffer, BITMAP_RGBQUAD_SIZE);
        bmpFile->mColorTable->push_back(rgbQuad);
    }

    // read pixel data
    auto pixelSize = infoHeaderRef->biSizeImage;

    if (pixelSize == 0) {
        pixelSize = infoHeaderRef->biWidth * infoHeaderRef->biHeight;
    }

    auto pixelDataNumBytes = pixelSize * (bmpFile->getBitDepth() / 8);
    auto pixelDataRef = bmpFile->getPixelData();
    pixelDataRef->reserve(pixelDataNumBytes);

    ifsOffset = ifsOffset + colorTableNumBytes;
    ifs.seekg(ifsOffset, ifs.beg);

    for (int i = 0; i < pixelDataNumBytes; i++) {
        int c = ifs.get();
        auto b = static_cast<uint8_t>(c);
        pixelDataRef->push_back(b);
    }

    ifs.close();

    return bmpFile;
}

BitmapFile::BitmapFile(Size size, uint8_t bitDepth, uint8_t fill)
{
    setBitDepth(bitDepth);
    setResolution(size);

    if (!isBitDepthSupported(bitDepth)) {
        std::cerr << "Invalid bit depth: " << bitDepth << ". Setting to 8." << std::endl;
        bitDepth = 8;
    }

    // reserve pixel data
    auto stride = size.width;

    // if width is odd, we need to add padding (stride)
    if (size.width % 2) {
        stride = calculateStride();
    }

    auto pixelDataSize = stride * size.height * (bitDepth / 8);
    auto pixelData = std::shared_ptr<ByteArray>(new ByteArray);

    for (int i = 0; i < pixelDataSize; i++) {
        pixelData->push_back(fill);
    }

    setPixelData(pixelData);
}

bool BitmapFile::write()
{
    if (mFileName.empty()) {
        std::cerr << "File name is empty" << std::endl;
        return false;
    }

    return write(mFileName);
}

bool BitmapFile::write(const std::string &path)
{
    std::ofstream ofs(path, std::ofstream::out | std::ofstream::binary);

    if (!ofs) {
        std::cerr << "Unable to write file: " << path << std::endl;
        return false;
    }

    // Write file header
    mFileHeader->bfSize = calculateBitmapFileSize();
    mFileHeader->bfOffBits = calculateBitmapDataOffset();
    char fileHeader[BITMAP_FILEHEADER_SIZE];
    memcpy(fileHeader, mFileHeader.get(), BITMAP_FILEHEADER_SIZE);
    ofs.write(fileHeader, BITMAP_FILEHEADER_SIZE);

    // Write info header
    char infoHeader[BITMAP_INFOHEADER_SIZE];
    memcpy(infoHeader, mInfoHeader.get(), BITMAP_INFOHEADER_SIZE);
    ofs.write(infoHeader, BITMAP_INFOHEADER_SIZE);

    // Write color table
    auto iter = mColorTable->begin();

    while (iter != mColorTable->end()) {
        char buffer[4]
            {
                static_cast<char>(iter->rgbBlue),
                static_cast<char>(iter->rgbGreen),
                static_cast<char>(iter->rgbRed),
                static_cast<char>(iter->rgbReserved)
            };
        ofs.write(buffer, BITMAP_RGBQUAD_SIZE);
        iter++;
    }

    // Write pixel data
    auto iter2 = mPixelData->begin();

    while (iter2 != mPixelData->end()) {
        char c = static_cast<char>(*iter2);
        ofs.write(&c, 1);
        iter2++;
    }

    ofs.close();

    return true;
}

void BitmapFile::setBitDepth(uint8_t bitDepth)
{
    mInfoHeader->biBitCount = bitDepth;

    if (bitDepth <= 8) {
        mColorTable->clear();

        auto colorTableSize = pow(2, getBitDepth());
        mInfoHeader->biClrUsed = colorTableSize;

        for (uint32_t i = 0; i < colorTableSize; i++) {
            uint8_t val = static_cast<uint8_t>(i);
            BitmapRgbQuad rgbQuad{ val, val, val };
            mColorTable->push_back(rgbQuad);
        }
    }
}

uint32_t BitmapFile::calculateBitmapFileSize()
{
    uint32_t pixelDataSize = mPixelData->size() / (getBitDepth() / 8);
    uint32_t colorTableSize = mColorTable->size() * BITMAP_RGBQUAD_SIZE;
    uint32_t size = calculateBitmapDataOffset() + colorTableSize + pixelDataSize;
    return size;
}

uint32_t BitmapFile::calculateBitmapDataOffset()
{
    uint32_t size = BITMAP_FILEHEADER_SIZE + BITMAP_INFOHEADER_SIZE;
    return size;
}

uint32_t BitmapFile::calculateStride(uint32_t width, uint8_t bitCount)
{
    auto stride = (((width * bitCount) + 31) & ~31) >> 3;
    return stride;
}

uint32_t BitmapFile::calculateStride()
{
    auto stride = (((mInfoHeader->biWidth * getBitDepth()) + 31) & ~31) >> 3;
    return stride;
}