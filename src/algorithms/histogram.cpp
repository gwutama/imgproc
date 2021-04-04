#include "histogram.h"
#include <fstream>
#include <iostream>

void Histogram::apply8bit(std::shared_ptr<Image> &image)
{
    std::vector<float> px;
    px.resize(256);

    auto size = image->pixelData()->size();

    for (int n = 0; n < size; n++) {
        auto val = static_cast<uint32_t>(image->pixelData()->at(n));
        px.at(val) = px.at(val) + 1;
    }

    // 1a. Normalized (divide each occurrence in each bin by number of pixels in the image)
    for (int i = 0; i < 256; i++) {
        auto normalizedFrequency = float(px.at(i)) / float(size);
        px.at(i) = normalizedFrequency;
    }

    mHistogramBin.clear();
    mHistogramBin = px;
}

bool Histogram::write(const std::string &filePath)
{
    std::ofstream ofs(filePath, std::ofstream::out);

    if (!ofs) {
        std::cout << "Unable to write file: " << filePath << std::endl;
        return false;
    }

    auto size = mHistogramBin.size();

    for (int i = 0; i < size; i++) {
        ofs << std::to_string(mHistogramBin.at(i)) << std::endl;
    }

    ofs.close();

    return true;
}
