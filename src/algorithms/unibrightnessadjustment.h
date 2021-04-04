#pragma once

#include "algorithmbase.h"

class UniBrightnessAdjustment final: public AlgorithmBase
{
public:
    void setValue(int16_t value)
    {
        mValue = value;
    }

    void apply(std::shared_ptr<GsImageAdapterBase> &image) override;

private:
    int16_t mValue = 0;
};

