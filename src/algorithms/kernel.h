#pragma once

#include "common.h"
#include <memory>

class Kernel
{
public:
    enum class Type
    {
        Unknown = 0,
        BoxBlur,
        Sharpen,
        EdgeDetect,
        GaussianBlur3x3,
        GaussianBlur5x5,
        LineDetectHorizontal,
        LineDetectVertical,
    };

    explicit Kernel(Type kernel);

    const std::shared_ptr<std::vector<double>> &getKernel() const
    {
        return mKernel;
    }

    const Size &getSize() const
    {
        return mSize;
    }

    const double &at(Coordinate coord) const
    {
        auto pos = coordinateToVectorIndex(coord, mSize);
        return mKernel->at(pos);
    }

    bool calculateModifiedPixels() const
    {
        return mCalculateModifiedPixels;
    }

private:
    std::shared_ptr<std::vector<double>> mKernel;
    Size mSize;
    bool mCalculateModifiedPixels = false;
};
