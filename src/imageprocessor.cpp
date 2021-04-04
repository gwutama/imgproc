#include "imageprocessor.h"

ImageProcessor::ImageProcessor(std::shared_ptr<GsImageAdapterBase> image)
    :
    mImage(image)
{
}

void ImageProcessor::applyAlgorithm(std::shared_ptr<AlgorithmBase> algorithm)
{
    algorithm->apply(mImage);
}