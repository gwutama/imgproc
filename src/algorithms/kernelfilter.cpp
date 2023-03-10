#include "kernelfilter.h"
#include <iostream>

void KernelFilter::apply8bit(std::shared_ptr<Image> &image)
{
    if (mKernelType == Kernel::Mask::Unknown) {
        return;
    }

    Kernel kernel(mKernelType);

    auto imgWidth = image->getResolution().width;
    auto imgHeight = image->getResolution().height;
    auto imgCopy = image->pixelDataCopy();

    for (int32_t y = 0; y < imgHeight; y++) {
        for (int32_t x = 0; x < imgWidth; x++) {
            Coordinate pos{x, y};
            convolute(image, imgCopy, pos, kernel);
        }
    }
}

void KernelFilter::convolute(std::shared_ptr<Image> &image,
                             std::shared_ptr<std::vector<uint8_t>> &imageCopy,
                             const Coordinate &pos,
                             const Kernel &kernel)
{
    const auto kWidth = kernel.getSize().width;
    const auto kHeight = kernel.getSize().height;
    const auto imgWidthMaxPos = image->getResolution().width - 1;
    const auto imgHeightMaxPos = image->getResolution().height - 1;

    // calculate absolute coordinate of kernel to the pos of the image,
    // and find the absolute top left.
    const Coordinate kCentroid = {(kWidth - 1) / 2, (kHeight - 1) / 2};
    const Coordinate absPosTopLeft{pos.x - kCentroid.x, pos.y - kCentroid.y};

    // Calculate sum of each pixel in the window
    double sum = 0;

    for (int32_t y = absPosTopLeft.y; y < absPosTopLeft.y + kHeight; y++) {
        for (int32_t x = absPosTopLeft.x; x < absPosTopLeft.x + kWidth; x++) {
            int xClamped = std::clamp(x, 0, imgWidthMaxPos);
            int yClamped = std::clamp(y, 0, imgHeightMaxPos);
            auto p2 = coordToIndex8bit({xClamped, yClamped}, image->getResolution());
            auto pixel = imageCopy->at(p2);
            auto w = kernel.at({x - absPosTopLeft.x, y - absPosTopLeft.y});
            sum = sum + (pixel * w);
        }
    }

    sum = std::clamp<double>(round(sum), 0.0, 255.0);
    image->setPixel(pos, sum);
}
