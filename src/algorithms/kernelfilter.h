#pragma once

#include "algorithm.h"
#include "kernel.h"

class KernelFilter final: public Algorithm
{
public:
    void setKernelType(Kernel::Type kernelType)
    {
        mKernelType = kernelType;
    }

    void apply8bit(std::shared_ptr<Image> &image) override;

private:
    void calculateFilterWindow(std::shared_ptr<Image> &image,
                               std::shared_ptr<std::vector<uint8_t>> &imageCopy,
                               const Coordinate &pos,
                               const Kernel &kernel);

private:
    Kernel::Type mKernelType = Kernel::Type::Unknown;
    std::shared_ptr<Kernel> mKernel;
};
