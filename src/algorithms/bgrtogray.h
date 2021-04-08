#pragma once

#include "algorithm.h"

/**
 * Uses algorithm from OpenCV
 * https://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#void%20cvtColor%28InputArray%20src,%20OutputArray%20dst,%20int%20code,%20int%20dstCn%29
 */
class BgrToGray final: public Algorithm
{
public:
    void apply24bit(std::shared_ptr<Image> &image) override;
};
