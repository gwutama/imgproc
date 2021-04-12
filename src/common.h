#pragma once

#include <vector>

struct Rgb
{
    // 3 bytes, 12 bits
    uint8_t blue = 0;
    uint8_t green = 0;
    uint8_t red = 0;
};

struct Rgba
{
    // 4 bytes, 16 bits
    uint8_t blue = 0;
    uint8_t green = 0;
    uint8_t red = 0;
    uint8_t alpha = 0;
};

struct Size
{
    int32_t width = 0;
    int32_t height = 0;
};

struct Coordinate
{
    int32_t x = 0;
    int32_t y = 0;
};

typedef std::vector<uint8_t> ByteArray;

uint32_t coordToIndex8bit(Coordinate coord, Size resolution);
uint32_t coordToIndex24bit(Coordinate coord, Size resolution);
double degreeToRadian(double degree);