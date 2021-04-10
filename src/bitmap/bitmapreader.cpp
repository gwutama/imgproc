#include "bitmapreader.h"
#include <iostream>

BitmapReader::BitmapReader(const std::string &filePath)
    :
    mFilePath(filePath)
{
}

std::shared_ptr<BitmapFile> BitmapReader::read()
{
    mIfs = std::ifstream(mFilePath, std::ifstream::in | std::ifstream::binary);

    if (!mIfs) {
        std::cerr << "Unable to read file: " << mFilePath << std::endl;
        return nullptr;
    }

    auto headerSize = readHeaderSize();

    // Read the info header mVersion. We only support BITMAPINFOHEADER and BITMAPV5HEADER
    // 40 bytes header: BITMAPINFOHEADER, 124 bytes: BITMAPV5HEADER
    // Header size information in offset 14 (4 bytes)
    if (headerSize != BITMAP_INFOHEADER_SIZE && headerSize != BITMAP_V5HEADER_SIZE) {
        std::cerr << "Unsupported bitmap header structure: " << headerSize << " bytes" << std::endl;
        return nullptr;
    }

    std::shared_ptr<BitmapFile> bmpFile = nullptr;

    if (headerSize == BITMAP_INFOHEADER_SIZE) {
        bmpFile = readOldFormat();
    }
    else if (headerSize == BITMAP_V5HEADER_SIZE) {
        bmpFile = readV5Format();
    }

    mIfs.close();

    return bmpFile;
}

uint32_t BitmapReader::readHeaderSize()
{
    // header size is located in 14th bytes with 4 bytes length of a bitmap file
    char buffer[4] = {0};
    readBytes(buffer, 14, sizeof (buffer));

    uint32_t headerSize = 0;
    memcpy(&headerSize, buffer, 4);

    return headerSize;
}

std::shared_ptr<BitmapFile> BitmapReader::readOldFormat()
{
    auto bmpFile = std::shared_ptr<BitmapFile>(new BitmapFile(mFilePath));
    bmpFile->setVersion(BitmapVersion::Old);

    readFileHeader(bmpFile);
    readOldInfoHeader(bmpFile);
    readOldColorTable(bmpFile);
    readOldPixelData(bmpFile);

    return bmpFile;
}

void BitmapReader::readFileHeader(std::shared_ptr<BitmapFile> &bmpFile)
{
    // File header is always 14 bytes (offset 0)
    uint32_t ifsOffset = 0;
    char bitmapFileHeader[BITMAP_FILEHEADER_SIZE];
    readBytes(bitmapFileHeader, ifsOffset, BITMAP_FILEHEADER_SIZE);
    auto fileHeaderRef = bmpFile->getFileHeader();
    memcpy(&fileHeaderRef.get()->bfType, bitmapFileHeader, BITMAP_FILEHEADER_SIZE);
}

void BitmapReader::readOldInfoHeader(std::shared_ptr<BitmapFile> &bmpFile)
{
    // read bitmap info header
    uint32_t ifsOffset = BITMAP_FILEHEADER_SIZE;
    char bitmapInfoHeader[BITMAP_INFOHEADER_SIZE];
    readBytes(bitmapInfoHeader, ifsOffset, BITMAP_INFOHEADER_SIZE);
    auto infoHeaderRef = bmpFile->getInfoHeader();
    memcpy(infoHeaderRef.get(), bitmapInfoHeader, BITMAP_INFOHEADER_SIZE);
}

void BitmapReader::readOldColorTable(std::shared_ptr<BitmapFile> &bmpFile)
{
    // Color table is irrelevant for images with bit depths > 8
    // and is usually set to 0 for images with bit depths > 8
    uint32_t ifsOffset = BITMAP_FILEHEADER_SIZE + BITMAP_INFOHEADER_SIZE;

    auto infoHeaderRef = bmpFile->getInfoHeader();
    auto colorTableSize = infoHeaderRef->biClrUsed;
    auto colorTable = bmpFile->getColorTable();
    auto colorTableNumBytes = calculateColorTableNumBytes(bmpFile->getBitDepth(), colorTableSize);
    colorTable->reserve(colorTableNumBytes);

    for (int i = 0; i < colorTableNumBytes; i = i + 4) {
        char buffer[BITMAP_RGBQUAD_SIZE];
        readBytes(buffer, ifsOffset + i, BITMAP_RGBQUAD_SIZE);

        BitmapRgbQuad rgbQuad{};
        memcpy(&rgbQuad, buffer, BITMAP_RGBQUAD_SIZE);

        colorTable->push_back(rgbQuad);
    }
}

void BitmapReader::readOldPixelData(std::shared_ptr<BitmapFile> &bmpFile)
{
    auto infoHeaderRef = bmpFile->getInfoHeader();
    auto pixelSize = infoHeaderRef->biSizeImage;

    if (pixelSize == 0) {
        pixelSize = infoHeaderRef->biWidth * infoHeaderRef->biHeight;
    }

    auto pixelDataNumBytes = pixelSize * (bmpFile->getBitDepth() / 8);
    auto pixelDataRef = bmpFile->getPixelData();
    pixelDataRef->reserve(pixelDataNumBytes);

    auto colorTableSize = infoHeaderRef->biClrUsed;
    auto colorTableNumBytes = calculateColorTableNumBytes(bmpFile->getBitDepth(), colorTableSize);
    uint32_t ifsOffset = BITMAP_FILEHEADER_SIZE + BITMAP_INFOHEADER_SIZE + colorTableNumBytes;

    mIfs.seekg(ifsOffset, mIfs.beg);

    for (int i = 0; i < pixelDataNumBytes; i++) {
        int c = mIfs.get();
        auto b = static_cast<uint8_t>(c);
        pixelDataRef->push_back(b);
    }
}

std::shared_ptr<BitmapFile> BitmapReader::readV5Format()
{
    return {};
}

uint32_t BitmapReader::calculateColorTableNumBytes(uint8_t bitDepth,
                                                   uint32_t colorTableSize)
{
    uint32_t colorTableNumBytes = 0;

    // Calculate default color table size if it is set to 0
    // Color table is irrelevant for images with bit depths > 8
    // IF color table is 0, then the default color table size is assumed (2 ^ bit depth)
    if (colorTableSize == 0 && bitDepth <= 8) {
        colorTableSize = pow(2, bitDepth);
    }

    colorTableNumBytes = colorTableSize * BITMAP_RGBQUAD_SIZE;
    return colorTableNumBytes;
}

void BitmapReader::readBytes(char *dest, uint32_t offset, uint32_t size)
{
    mIfs.seekg(offset, mIfs.beg);
    mIfs.read(dest, size);
}