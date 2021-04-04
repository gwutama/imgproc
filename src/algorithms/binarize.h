#pragma once

#include "algorithm.h"

class Binarize final: public Algorithm
{
public:
    void setThreshold(int threshold)
    {
        mThreshold = threshold;
    }

    void apply8bit(std::shared_ptr<Image> &image) override;

private:
    int mThreshold = 0;
};
