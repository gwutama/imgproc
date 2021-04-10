#pragma once

#include <string>
#include <memory>
#include "bitmaptypes.h"

/**
 * http://www.dragonwins.com/domains/getteched/bmp/bmpfileformat.htm
 */
class BitmapFile: public std::enable_shared_from_this<BitmapFile>
{
    friend class BitmapReader;
    friend class BitmapWriter;

public:
    static std::shared_ptr<BitmapFile> fromFile(const std::string &filePath);

    BitmapFile(Size size, uint8_t bitDepth, uint8_t fill = 0);

    const std::string &getSourceFileName() const;
    void setResolution(Size size);
    Size getResolution();
    uint8_t getBitDepth();
    void setBitDepth(uint8_t bitDepth);
    uint32_t getColorTableSize();
    uint32_t getImageSize();

    const std::shared_ptr<RgbQuadArray> &getColorTable() const;
    void setColorTable(const std::shared_ptr<RgbQuadArray> &colorTable);
    const std::shared_ptr<ByteArray> &getPixelData() const;
    void setPixelData(const std::shared_ptr<ByteArray> &pixelData);

    bool write();
    bool write(const std::string &path);

private:
    explicit BitmapFile(const std::string& filePath);

    void setVersion(BitmapVersion version);
    BitmapVersion getVersion() const;

    const std::shared_ptr<BitmapFileHeader> &getFileHeader() const;
    const std::shared_ptr<BitmapInfoHeader> &getInfoHeader() const;
    const std::shared_ptr<BitmapV5Header> &getV5Header() const;

    uint32_t calculateStride(uint32_t width, uint8_t bitCount);
    uint32_t calculateStride();
    bool isBitDepthSupported(uint8_t bitDepth);

private:
    BitmapVersion mVersion = BitmapVersion::Unknown;
    std::string mSourceFileName;
    std::shared_ptr<BitmapFileHeader> mFileHeader = std::shared_ptr<BitmapFileHeader>(new BitmapFileHeader);
    std::shared_ptr<BitmapInfoHeader> mInfoHeader = std::shared_ptr<BitmapInfoHeader>(new BitmapInfoHeader);
    std::shared_ptr<BitmapV5Header> mV5Header = std::shared_ptr<BitmapV5Header>(new BitmapV5Header);
    std::shared_ptr<RgbQuadArray> mColorTable = std::shared_ptr<RgbQuadArray>(new RgbQuadArray);
    std::shared_ptr<ByteArray> mPixelData = std::shared_ptr<ByteArray>(new ByteArray);
};
