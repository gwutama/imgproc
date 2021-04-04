#pragma once

#include <memory>
#include "common.h"
#include "bitmap/bitmapfile.h"
#include "algorithms/gsfilterwindow.h"

class GsImageAdapterBase
{
public:
    virtual uint8_t bitDepth() = 0;
    virtual Size resolution() = 0;
    virtual std::shared_ptr<ByteArray> pixelData() = 0;
    virtual std::shared_ptr<ByteArray> pixelDataCopy() = 0;
    virtual uint8_t *at(Coordinate coord);
    std::vector<GsFilterWindow> calculateFilterWindows(const Size &windowSize);

private:
    GsFilterWindow calculateFilterWindow(const Coordinate &topLeftPixel,
                                         const Size &windowSize);
};
