#include "common.h"

uint32_t coordToIndex8bit(Coordinate coord, Size resolution)
{
    auto const maxIndex = resolution.width * resolution.height - 1;
    auto pos = std::clamp<uint32_t>(coord.y * resolution.width + coord.x, 0, maxIndex);
    return pos;
}

uint32_t coordToIndex24bit(Coordinate coord, Size resolution)
{
    auto const maxIndex = resolution.width * resolution.height - 1;
    auto pos = std::clamp<uint32_t>((coord.y * resolution.width + coord.x) * 3, 0, maxIndex);
    return pos;
}

double degreeToRadian(double degree)
{
    auto const pi = 3.14159265;
    auto radian = degree * pi / 180.0;
    return radian;
}
