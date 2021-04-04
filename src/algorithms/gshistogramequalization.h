#pragma once

#include "algorithmbase.h"
#include <vector>

class GsHistogramEqualization final: public AlgorithmBase
{
public:
    void apply(std::shared_ptr<GsImageAdapterBase> &image) override;
};
