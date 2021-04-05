#pragma once

#include "algorithm.h"
#include "kernel.h"

class KernelFilter final: public Algorithm
{
public:
    void setKernelType(Kernel::Mask kernelType)
    {
        mKernelType = kernelType;
    }

    void apply8bit(std::shared_ptr<Image> &image) override;

private:
    void convolute(std::shared_ptr<Image> &image,
                   std::shared_ptr<std::vector<uint8_t>> &imageCopy,
                   const Coordinate &pos,
                   const Kernel &kernel);

private:
    Kernel::Mask mKernelType = Kernel::Mask::Unknown;
    std::shared_ptr<Kernel> mKernel;
};
