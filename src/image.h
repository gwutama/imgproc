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
    std::shared_ptr<ByteArray> pixelData();
    std::shared_ptr<ByteArray> pixelDataCopy();
    bool write(const std::string& path);
    bool write();

    // 8bit images only
    uint8_t *at(const Coordinate& coord);
    bool setValue(const Coordinate& coord, uint8_t value);

    void applyAlgorithm(std::shared_ptr<Algorithm> algorithm);

private:
    std::shared_ptr<BitmapFile> mBitmapFile;
};
