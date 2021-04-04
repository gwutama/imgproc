#pragma once

#include "gsimageadapterbase.h"

class AlgorithmBase
{
public:
    virtual void apply(std::shared_ptr<GsImageAdapterBase> &image) = 0;
};
