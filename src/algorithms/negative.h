#pragma once

#include "algorithm.h"

class Negative final: public Algorithm
{
public:
    void apply8bit(std::shared_ptr<Image> &image) override;
};
