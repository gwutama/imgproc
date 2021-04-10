#include "bitmapfile.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include "bitmapreader.h"
#include "bitmapwriter.h"

std::shared_ptr<BitmapFile> BitmapFile::fromFile(const std::string &filePath)
{
    BitmapReader reader(filePath);
    auto bitmapFile = reader.read();
    return bitmapFile;
}

BitmapFile::BitmapFile(const std::string &filePath)
    :
    mSourceFileName(filePath)
{
}

BitmapFile::BitmapFile(Size size, uint8_t bitDepth, uint8_t fill)
{
    setVersion(BitmapVersion::Old);
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

void BitmapFile::setVersion(BitmapVersion version)
{
    mVersion = version;
}

BitmapVersion BitmapFile::getVersion() const
{
    return mVersion;
}

const std::string &BitmapFile::getSourceFileName() const
{
    return mSourceFileName;
}

void BitmapFile::setResolution(Size size)
{
    if (mVersion == BitmapVersion::Old) {
        mInfoHeader->biWidth = size.width;
        mInfoHeader->biHeight = size.height;
        mInfoHeader->biSizeImage = size.width * size.height;
    }
    else if (mVersion == BitmapVersion::V5) {
        mV5Header->bV5Width = size.width;
        mV5Header->bV5Height = size.height;
        mV5Header->bV5SizeImage = size.width * size.height;
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return;
    }
}

Size BitmapFile::getResolution()
{
    if (mVersion == BitmapVersion::Old) {
        return {
            static_cast<int32_t>(mInfoHeader->biWidth),
            static_cast<int32_t>(mInfoHeader->biHeight)
        };
    }
    else if (mVersion == BitmapVersion::V5) {
        return {
            static_cast<int32_t>(mV5Header->bV5Width),
            static_cast<int32_t>(mV5Header->bV5Height)
        };
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return {};
    }
}

uint8_t BitmapFile::getBitDepth()
{
    if (mVersion == BitmapVersion::Old) {
        return mInfoHeader->biBitCount;
    }
    else if (mVersion == BitmapVersion::V5) {
        return mV5Header->bV5BitCount;
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return 0;
    }
}

void BitmapFile::setBitDepth(uint8_t bitDepth)
{
    if (mVersion == BitmapVersion::Old) {
        mInfoHeader->biBitCount = bitDepth;
    }
    else if (mVersion == BitmapVersion::V5) {
        mV5Header->bV5BitCount = bitDepth;
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return;
    }

    if (bitDepth <= 8) {
        mColorTable->clear();

        auto colorTableSize = pow(2, getBitDepth());

        if (mVersion == BitmapVersion::Old) {
            mInfoHeader->biClrUsed = colorTableSize;
        }
        else if (mVersion == BitmapVersion::V5) {
            mV5Header->bV5ClrUsed = colorTableSize;
        }

        for (uint32_t i = 0; i < colorTableSize; i++) {
            uint8_t val = static_cast<uint8_t>(i);
            BitmapRgbQuad rgbQuad{val, val, val};
            mColorTable->push_back(rgbQuad);
        }
    }
}

uint32_t BitmapFile::getColorTableSize()
{
    if (mVersion == BitmapVersion::Old) {
        return mInfoHeader->biClrUsed;
    }
    else if (mVersion == BitmapVersion::V5) {
        return mV5Header->bV5ClrUsed;
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return 0;
    }
}

uint32_t BitmapFile::getImageSize()
{
    if (mVersion == BitmapVersion::Old) {
        return mInfoHeader->biSizeImage;
    }
    else if (mVersion == BitmapVersion::V5) {
        return mV5Header->bV5SizeImage;
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return 0;
    }
}

const std::shared_ptr<RgbQuadArray> &BitmapFile::getColorTable() const
{
    return mColorTable;
}

void BitmapFile::setColorTable(const std::shared_ptr<RgbQuadArray> &colorTable)
{
    if (mVersion == BitmapVersion::Old) {
        mInfoHeader->biClrUsed = colorTable->size();
    }
    else if (mVersion == BitmapVersion::V5) {
        mV5Header->bV5ClrUsed = colorTable->size();
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return;
    }

    mColorTable = colorTable;
}

const std::shared_ptr<ByteArray> &BitmapFile::getPixelData() const
{
    return mPixelData;
}

void BitmapFile::setPixelData(const std::shared_ptr<ByteArray> &pixelData)
{
    if (mVersion == BitmapVersion::Old) {
        mInfoHeader->biSizeImage = pixelData->size();
    }
    else if (mVersion == BitmapVersion::V5) {
        mV5Header->bV5SizeImage = pixelData->size();
    }
    else {
        std::cerr << "Unknown bitmap version" << std::endl;
        return;
    }

    mPixelData = pixelData;
}

const std::shared_ptr<BitmapFileHeader> &BitmapFile::getFileHeader() const
{
    return mFileHeader;
}

const std::shared_ptr<BitmapInfoHeader> &BitmapFile::getInfoHeader() const
{
    return mInfoHeader;
}

const std::shared_ptr<BitmapV5Header> &BitmapFile::getV5Header() const
{
    return mV5Header;
}

bool BitmapFile::write()
{
    if (mSourceFileName.empty()) {
        std::cerr << "File name is empty" << std::endl;
        return false;
    }

    return write(mSourceFileName);
}

bool BitmapFile::write(const std::string &path)
{
    auto mine = shared_from_this();
    BitmapWriter writer(mine);
    bool isOk = writer.write(path);
    return isOk;
}

uint32_t BitmapFile::calculateStride(uint32_t width, uint8_t bitCount)
{
    auto stride = (((width * bitCount) + 31) & ~31) >> 3;
    return stride;
}

uint32_t BitmapFile::calculateStride()
{
    auto stride = (((getInfoHeader()->biWidth * getBitDepth()) + 31) & ~31) >> 3;
    return stride;
}

bool BitmapFile::isBitDepthSupported(uint8_t bitDepth)
{
    return (bitDepth == 1 || bitDepth == 8 || bitDepth == 24 || bitDepth == 32);
}