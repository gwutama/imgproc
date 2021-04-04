#pragma once

#include "algorithm.h"
#include <vector>

class Histogram final: public Algorithm
{
public:
    void apply8bit(std::shared_ptr<Image> &image) override;

    const std::vector<float> &getHistogramBin() const
    {
        return mHistogramBin;
    }

    bool write(const std::string &filePath);

private:
    std::vector<float> mHistogramBin;
};
