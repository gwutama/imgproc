#pragma once

#include "algorithm.h"

class DrawLine final: public Algorithm
{
public:
    void apply8bit(std::shared_ptr<Image> &image) override;

    void setColor8bit(uint8_t color8Bit)
    {
        mColor8bit = color8Bit;
    }

    void setPointFrom(const Coordinate &pointFrom)
    {
        mPointFrom = pointFrom;
    }

    void setPointTo(const Coordinate &pointTo)
    {
        mPointTo = pointTo;
    }

private:
    // https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C.2B.2B
    void plot8bit(Coordinate p1, Coordinate p2, uint8_t color, std::shared_ptr<Image> &image);

private:
    uint8_t mColor8bit = 0;
    Coordinate mPointFrom;
    Coordinate mPointTo;
};
