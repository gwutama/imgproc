#pragma once

#include <memory>
#include "common.h"
#include "bitmap/bitmapfile.h"
#include "algorithms/gsfilterwindow.h"

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
    uint8_t *at(Coordinate coord);
    std::vector<GsFilterWindow> calculateFilterWindows(const Size &windowSize);
    void applyAlgorithm(std::shared_ptr<Algorithm> algorithm);

private:
    GsFilterWindow calculateFilterWindow(const Coordinate &topLeftPixel,
                                         const Size &windowSize);

private:
    std::shared_ptr<BitmapFile> mBitmapFile;
};
