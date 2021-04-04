#pragma once

#include "algorithmbase.h"
#include "kernel.h"

class GsKernelFilter final: public AlgorithmBase
{
public:
    void setKernelType(Kernel::KernelType kernelType)
    {
        mKernelType = kernelType;
    }

    void apply(std::shared_ptr<GsImageAdapterBase> &image) override;

private:
    Kernel::KernelType mKernelType;
    std::shared_ptr<Kernel> mKernel;
};
