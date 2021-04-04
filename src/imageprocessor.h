#pragma once

#include "gsimageadapterbase.h"
#include "algorithms/algorithmbase.h"

class ImageProcessor
{
public:
    explicit ImageProcessor(std::shared_ptr<GsImageAdapterBase> image);
    void applyAlgorithm(std::shared_ptr<AlgorithmBase> algorithm);

private:
    std::shared_ptr<GsImageAdapterBase> mImage;
};
