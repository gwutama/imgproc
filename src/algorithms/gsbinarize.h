#pragma once

#include "algorithmbase.h"

class GsBinarize final: public AlgorithmBase
{
public:
    void setThreshold(int threshold)
    {
        mThreshold = threshold;
    }

    void apply(std::shared_ptr<GsImageAdapterBase> &image) override;

private:
    int mThreshold = 0;
};
