#pragma once

#include "algorithm.h"
#include "kernel.h"

class KernelFilter final: public Algorithm
{
public:
    void setKernelType(Kernel::KernelType kernelType)
    {
        mKernelType = kernelType;
    }

    void apply8bit(std::shared_ptr<Image> &image) override;

private:
    Kernel::KernelType mKernelType;
    std::shared_ptr<Kernel> mKernel;
};
