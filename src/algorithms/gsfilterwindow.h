#pragma once

#include "common.h"
#include "kernel.h"

class GsFilterWindow
{
public:
    void addPixelRef(uint8_t *pixelRef)
    {
        mPixelRefs.push_back(pixelRef);
    }

    void applyFilterKernel(const Kernel &kernel);

private:
    std::vector<uint8_t *> mPixelRefs;
};
