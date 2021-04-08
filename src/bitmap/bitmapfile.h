#pragma once

#include <string>
#include <memory>
#include "bitmaptypes.h"

/**
 * http://www.dragonwins.com/domains/getteched/bmp/bmpfileformat.htm
 */
class BitmapFile
{
public:
    static std::shared_ptr<BitmapFile> fromFile(const std::string &filePath);

    BitmapFile(Size size, uint8_t bitDepth, uint8_t fill = 0);

    bool write();
    bool write(const std::string &path);

    const std::string &getFileName() const
    {
        return mFileName;
    }

    const std::shared_ptr<RgbQuadArray> &getColorTable() const
    {
        return mColorTable;
    }

    void setColorTable(const std::shared_ptr<RgbQuadArray> &colorTable)
    {
        mInfoHeader->biClrUsed = colorTable->size();
        mColorTable = colorTable;
    }

    const std::shared_ptr<ByteArray> &getPixelData() const
    {
        return mPixelData;
    }

    void setPixelData(const std::shared_ptr<ByteArray> &pixelData)
    {
        mInfoHeader->biSizeImage = pixelData->size();
        mPixelData = pixelData;
    }

    void setResolution(Size size)
    {
        mInfoHeader->biWidth = size.width;
        mInfoHeader->biHeight = size.height;
    }

    uint8_t getBitDepth()
    {
        return mInfoHeader->biBitCount;
    }

    void setBitDepth(uint8_t bitDepth);

    Size getResolution()
    {
        return {
            static_cast<int32_t>(mInfoHeader->biWidth),
            static_cast<int32_t>(mInfoHeader->biHeight)
        };
    }

    static bool isBitDepthSupported(uint8_t bitDepth)
    {
        return (bitDepth == 8 || bitDepth == 24 || bitDepth == 32);
    }

private:
    explicit BitmapFile() = default;

    uint32_t calculateBitmapFileSize();
    uint32_t calculateBitmapDataOffset();
    uint32_t calculateStride(uint32_t width, uint8_t bitCount);
    uint32_t calculateStride();

private:
    std::string mFileName;
    std::shared_ptr<BitmapFileHeader> mFileHeader = std::shared_ptr<BitmapFileHeader>(new BitmapFileHeader);
    std::shared_ptr<BitmapInfoHeader> mInfoHeader = std::shared_ptr<BitmapInfoHeader>(new BitmapInfoHeader);

    // the color table is normally not used when the pixels are in
    // the 16-bit per pixel (16bpp) format (and higher);
    std::shared_ptr<RgbQuadArray> mColorTable = std::shared_ptr<RgbQuadArray>(new RgbQuadArray);

    std::shared_ptr<ByteArray> mPixelData = std::shared_ptr<ByteArray>(new ByteArray);
};
