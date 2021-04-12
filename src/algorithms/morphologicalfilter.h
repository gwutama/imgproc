#pragma once

#include "algorithm.h"

class MorphologicalFilter final: public Algorithm
{
public:
    enum class Filter {
        Invalid = 0,
        Maximum, // dilation
        Minimum, // erosion
        Mean
    };

    void apply8bit(std::shared_ptr<Image> &image) override;

    void setFilter(Filter filter)
    {
        mFilter = filter;
    }

    void setRadius(uint8_t radius)
    {
        mRadius = radius;
    }

private:
    void maximum8bit(std::shared_ptr<Image>& image);
    void minimum8bit(std::shared_ptr<Image>& image);
    void mean8bit(std::shared_ptr<Image>& image);

private:
    Filter mFilter = Filter::Invalid;
    uint8_t mRadius = 1;
};
