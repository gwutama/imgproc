#pragma once

#include "algorithmbase.h"

class UniNegative final: public AlgorithmBase
{
public:
    void apply(std::shared_ptr<GsImageAdapterBase> &image) override;
};
