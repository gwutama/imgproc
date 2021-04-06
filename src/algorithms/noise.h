#pragma once

#include "algorithm.h"

/**
 * Generates salt and pepper noise.
 */
class Noise final: public Algorithm
{
public:
    void apply8bit(std::shared_ptr<Image> &image) override;

    void setProbability(uint8_t probability)
    {
        mProbability = probability;
    }

private:
    uint8_t mProbability = 0;
};
