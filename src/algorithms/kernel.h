#pragma once

#include "common.h"
#include <memory>

class Kernel
{
public:
    enum class Mask
    {
        Unknown = 0,
        BoxBlur,
        Sharpen,
        EdgeDetect,
        GaussianBlur3x3,
        GaussianBlur5x5,
        LineDetectHorizontal,
        LineDetectVertical,
        PrewittVertical,
        PrewittHorizontal,
        SobelVertical,
        SobelHorizontal,
        RobinsonNorth,
        RobinsonWest,
        RobinsonSouth,
        RobinsonEast,
        KirschNorth,
        KirschWest,
        KirschSouth,
        KirschEast,
        LaplacianNegative,
        LaplacianPositive,
    };

    explicit Kernel(Mask mask);

    const std::shared_ptr<std::vector<double>> &getKernel() const
    {
        return mKernel;
    }

    const Size &getSize() const
    {
        return mSize;
    }

    const double &at(Coordinate coord) const;

private:
    std::shared_ptr<std::vector<double>> mKernel;
    Size mSize;
};
