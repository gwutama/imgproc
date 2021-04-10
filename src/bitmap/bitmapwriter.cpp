#include "bitmapwriter.h"
#include <iostream>

BitmapWriter::BitmapWriter(std::shared_ptr<BitmapFile> &bmpFile)
    :
    mBmpFile(bmpFile)
{
}

bool BitmapWriter::write(const std::string &filePath)
{
    if (mBmpFile == nullptr) {
        std::cerr << "Bitmap file object is null" << std::endl;
        return false;
    }

    if (mBmpFile->getVersion() == BitmapVersion::Unknown) {
        std::cerr << "Bitmap version is unknown" << std::endl;
        return false;
    }

    mOfs = std::ofstream(filePath, std::ofstream::out | std::ofstream::binary);

    if (!mOfs) {
        std::cerr << "Unable to write file: " << filePath << std::endl;
        return false;
    }

    writeFileHeader();

    if (mBmpFile->getVersion() == BitmapVersion::Old) {
        writeOldInfoHeader();
    }
    else if (mBmpFile->getVersion() == BitmapVersion::V5) {
        writeV5InfoHeader();
    }

    writeColorTable();
    writePixelData();

    mOfs.close();

    return true;
}

void BitmapWriter::writeFileHeader()
{
    auto header = mBmpFile->getFileHeader();
    header->bfSize = calculateBitmapFileSize();
    header->bfOffBits = calculateBitmapDataOffset();
    char fileHeader[BITMAP_FILEHEADER_SIZE];
    memcpy(fileHeader, header.get(), BITMAP_FILEHEADER_SIZE);
    mOfs.write(fileHeader, BITMAP_FILEHEADER_SIZE);
}

void BitmapWriter::writeOldInfoHeader()
{
    char infoHeader[BITMAP_INFOHEADER_SIZE];
    memcpy(infoHeader, mBmpFile->getInfoHeader().get(), BITMAP_INFOHEADER_SIZE);
    mOfs.write(infoHeader, BITMAP_INFOHEADER_SIZE);
}

void BitmapWriter::writeV5InfoHeader()
{
    char buffer[BITMAP_V5HEADER_SIZE];
    memcpy(buffer, mBmpFile->getV5Header().get(), BITMAP_V5HEADER_SIZE);
    mOfs.write(buffer, BITMAP_V5HEADER_SIZE);
}

void BitmapWriter::writeColorTable()
{
    auto table = mBmpFile->getColorTable();
    auto iter = table->begin();

    while (iter != table->end()) {
        char buffer[4]
            {
                static_cast<char>(iter->rgbBlue),
                static_cast<char>(iter->rgbGreen),
                static_cast<char>(iter->rgbRed),
                static_cast<char>(iter->rgbReserved)
            };
        mOfs.write(buffer, BITMAP_RGBQUAD_SIZE);
        iter++;
    }
}

void BitmapWriter::writePixelData()
{
    auto pixels = mBmpFile->getPixelData();
    auto iter = pixels->begin();

    while (iter != pixels->end()) {
        char c = static_cast<char>(*iter);
        mOfs.write(&c, 1);
        iter++;
    }
}

uint32_t BitmapWriter::calculateBitmapFileSize()
{
    auto pxs = mBmpFile->getPixelData()->size();
    auto div = ceil(mBmpFile->getBitDepth() / 8.0);
    uint32_t pixelDataSize = pxs / div;
    uint32_t size = calculateBitmapDataOffset() + pixelDataSize;
    return size;
}

uint32_t BitmapWriter::calculateBitmapDataOffset()
{
    uint32_t colorTableSize = mBmpFile->getColorTable()->size() * BITMAP_RGBQUAD_SIZE;

    uint32_t size = 0;

    if (mBmpFile->getVersion() == BitmapVersion::Old) {
        size = BITMAP_FILEHEADER_SIZE + BITMAP_INFOHEADER_SIZE + colorTableSize;
    }
    else if (mBmpFile->getVersion() == BitmapVersion::V5) {
        size = BITMAP_FILEHEADER_SIZE + BITMAP_V5HEADER_SIZE + colorTableSize;
    }

    return size;
}
