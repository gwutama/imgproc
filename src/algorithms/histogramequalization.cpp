#include "histogramequalization.h"
#include <fstream>
#include <iostream>
#include <cmath>

void HistogramEqualization::apply8bit(std::shared_ptr<Image> &image)
{
    // https://en.wikipedia.org/wiki/Histogram_equalization
    // 1. calculate px(i)
    const int L = 256; // total number of gray levels in image
    std::vector<float> px;
    px.resize(L);

    auto n = image->pixelData()->size(); // num of pixels in image

    // 1a. calculate ni (number of occurrences of gray level i)
    for (int x = 0; x < n; x++) {
        auto ni = static_cast<uint32_t>(image->pixelData()->at(x));
        px.at(ni) = px.at(ni) + 1;
    }

    // 2. calculate cumulative distribution function (cdfx) corresponding to px
    // this is image's accumulated normalized histogram
    std::vector<float> cdfx;
    cdfx.resize(L);

    for (int i = 0; i < L; i++) {
        auto iMin1 = i - 1;

        if (iMin1 < 0) {
            iMin1 = 0;
        }

        cdfx.at(i) = cdfx.at(iMin1) + px.at(i);
    }

    // 3. calculate equalized histogram h(v) (= normalized cdf)
    // The cdf must be normalized to [0 , 255]

    // 3a. find cdfMin
    auto cdfMax = cdfx.at(255); // last value must have the largest cdfx value
    auto cdfMin = cdfMax;

    for (int i = 0; i < L; i++) {
        auto cdfi = cdfx.at(i);

        if (cdfi < cdfMin && cdfi > 0) {
            cdfMin = cdfi;
        }
    }

    // 3b. calculate hv
    std::vector<float> hv;
    hv.resize(L);

    for (int i = 0; i < L; i++) {
        auto cdfv = cdfx.at(i);
        auto hvi = round(((cdfv - cdfMin) / (n - cdfMin)) * (L - 1));
        hv.at(i) = hvi;
    }

    // 4. the values of the equalized image are directly taken
    // from the normalized cdf to yield the equalized values
    for (int x = 0; x < n; x++) {
        auto val = static_cast<float>(image->pixelData()->at(x));
        auto replaceVal = hv.at(val);
        image->pixelData()->at(x) = replaceVal;
    }
}
