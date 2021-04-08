#pragma once

#include <vector>

struct Rgb
{
    // 3 bytes, 12 bits
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

struct Rgba
{
    // 4 bytes, 16 bits
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t alpha;
};

struct Size
{
    int32_t width;
    int32_t height;
};

struct Coordinate
{
    int32_t x;
    int32_t y;
};

typedef std::vector<uint8_t> ByteArray;

uint32_t coordToIndex8bit(Coordinate coord, Size resolution);
uint32_t coordToIndex24bit(Coordinate coord, Size resolution);
double degreeToRadian(double degree);