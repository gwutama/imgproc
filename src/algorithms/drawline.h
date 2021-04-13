#pragma once

#include "algorithm.h"

class DrawLine final: public Algorithm
{
public:
    void apply8bit(std::shared_ptr<Image> &image) override;
    void apply24bit(std::shared_ptr<Image> &image) override;

    void setColor(uint8_t color8Bit)
    {
        mColor8bit = color8Bit;
    }

    void setColor(Rgb color24Bit)
    {
        mColor24bit = color24Bit;
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
    // TODO: templatize the function?
    void plot(Coordinate p1, Coordinate p2, uint8_t color, std::shared_ptr<Image> &image);
    void plot(Coordinate p1, Coordinate p2, Rgb color, std::shared_ptr<Image> &image);

private:
    uint8_t mColor8bit = 0;
    Rgb mColor24bit = {0, 0, 0};
    Coordinate mPointFrom;
    Coordinate mPointTo;
};
