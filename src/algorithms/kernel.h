#pragma once

#include "common.h"
#include <memory>

class Kernel
{
public:
    enum class KernelType
    {
        Unknown = 0,
        BoxBlur,
        Sharpen,
        EdgeDetection,
        GaussianBlur5x5
    };

    explicit Kernel(KernelType kernel);
    Kernel(std::shared_ptr<std::vector<double>> kernel,
           const Size &size);

    const std::shared_ptr<std::vector<double>> &getKernel() const
    {
        return mKernel;
    }

    const Size &getSize() const
    {
        return mSize;
    }

private:
    std::shared_ptr<std::vector<double>> mKernel;
    Size mSize;
};
