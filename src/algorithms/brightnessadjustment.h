#pragma once

#include "algorithm.h"

class BrightnessAdjustment final: public Algorithm
{
public:
    void setValue(int16_t value)
    {
        mValue = value;
    }

    void apply8bit(std::shared_ptr<Image> &image) override;

private:
    int16_t mValue = 0;
};

