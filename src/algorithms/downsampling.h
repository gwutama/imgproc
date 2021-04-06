#pragma once

#include "algorithm.h"

/**
 * Simple image downsampling with box (grid) filter.
 * This is similar to 3d downsampling with VoxelGrid filter.
 */
class Downsampling final: public Algorithm
{
public:
    void apply8bit(std::shared_ptr<Image> &image) override;

    void setNewSize(const Size &newSize)
    {
        mNewSize = newSize;
    }

private:
    Size calculateClosestResolution(Size imageSize,
                                    Size desiredSize);

private:
    Size mNewSize;
};
