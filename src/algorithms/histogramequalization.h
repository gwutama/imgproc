#pragma once

#include "algorithm.h"
#include <vector>

class HistogramEqualization final: public Algorithm
{
public:
    void apply8bit(std::shared_ptr<Image> &image) override;
};
