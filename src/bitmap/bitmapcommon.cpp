#include "bitmapcommon.h"

uint32_t coordToIndex8bit(Coordinate coord, Size resolution)
{
    auto const maxIndex = resolution.width * resolution.height - 1;
    auto pos = std::clamp<uint32_t>(coord.y * resolution.width + coord.x, 0, maxIndex);
    return pos;
}

uint32_t coordToIndex24bit(Coordinate coord, Size resolution, uint8_t bitDepth)
{
    auto stride = calculateStride(resolution.width, bitDepth);
    auto padding = stride - (resolution.width * bitDepth / 8);
    auto paddings = padding * coord.y;
    auto const maxIndex = resolution.width * resolution.height * 3 - 1;
    auto pos = std::clamp<uint32_t>((coord.y * resolution.width + coord.x) * 3 + paddings, 0, maxIndex);
    return pos;
}

uint32_t calculateStride(uint32_t width, uint8_t bitCount)
{
    auto stride = (((width * bitCount) + 31) & ~31) >> 3;
    return stride;
}
