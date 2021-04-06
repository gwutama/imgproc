#pragma once

#include <memory>
#include "common.h"
#include "bitmap/bitmapfile.h"

class Algorithm;

class Image : public std::enable_shared_from_this<Image>
{
public:
    static std::shared_ptr<Image> fromFile(const std::string &path);

    explicit Image(std::shared_ptr<BitmapFile> bitmapFile);

    uint8_t bitDepth();
    Size resolution();
    void setResolution(Size size);
    std::shared_ptr<ByteArray> pixelData();
    void setPixelData(std::shared_ptr<ByteArray> data);
    std::shared_ptr<ByteArray> pixelDataCopy();
    bool write(const std::string& path);
    bool write();

    // 8bit images only
    uint8_t *pixel8bit(const Coordinate& coord);
    bool setPixel(const Coordinate& coord, uint8_t value);

    void applyAlgorithm(std::shared_ptr<Algorithm> algorithm);

private:
    std::shared_ptr<BitmapFile> mBitmapFile;
};
