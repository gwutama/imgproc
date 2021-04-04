#pragma once

#include "algorithmbase.h"
#include <vector>

class GsHistogram final: public AlgorithmBase
{
public:
    void apply(std::shared_ptr<GsImageAdapterBase> &image) override;

    const std::vector<float> &getHistogramBin() const
    {
        return mHistogramBin;
    }

    bool write(const std::string &filePath);

private:
    std::vector<float> mHistogramBin;
};
