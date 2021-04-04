#pragma once

#include <string>
#include <memory>
#include "bitmaptypes.h"

class BitmapFile
{
public:
    static std::shared_ptr<BitmapFile> fromFile(const std::string &filePath);

    bool write();
    bool write(const std::string &path);

    const std::string &getFileName() const
    {
        return mFileName;
    }

    const std::shared_ptr<BitmapFileHeader> &getFileHeader() const
    {
        return mFileHeader;
    }

    void setFileHeader(std::shared_ptr<BitmapFileHeader> fileHeader)
    {
        mFileHeader = fileHeader;
    }

    const std::shared_ptr<BitmapInfoHeader> &getInfoHeader() const
    {
        return mInfoHeader;
    }

    void setInfoHeader(std::shared_ptr<BitmapInfoHeader> infoHeader)
    {
        mInfoHeader = infoHeader;
    }

    const std::shared_ptr<RgbQuadArray> &getColorTable() const
    {
        return mColorTable;
    }

    void setColorTable(const std::shared_ptr<RgbQuadArray> &colorTable)
    {
        mColorTable = colorTable;
    }

    const std::shared_ptr<ByteArray> &getPixelData() const
    {
        return mPixelData;
    }

    void setPixelData(const std::shared_ptr<ByteArray> &pixelData)
    {
        mPixelData = pixelData;
    }

private:
    BitmapFile() = default;

private:
    std::string mFileName;
    std::shared_ptr<BitmapFileHeader> mFileHeader = std::shared_ptr<BitmapFileHeader>(new BitmapFileHeader);
    std::shared_ptr<BitmapInfoHeader> mInfoHeader = std::shared_ptr<BitmapInfoHeader>(new BitmapInfoHeader);

    // the color table is normally not used when the pixels are in
    // the 16-bit per pixel (16bpp) format (and higher);
    std::shared_ptr<RgbQuadArray> mColorTable = std::shared_ptr<RgbQuadArray>(new RgbQuadArray);

    std::shared_ptr<ByteArray> mPixelData = std::shared_ptr<ByteArray>(new ByteArray);
};
