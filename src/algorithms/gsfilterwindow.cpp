#include "gsfilterwindow.h"
#include <iostream>

void GsFilterWindow::applyFilterKernel(const Kernel &kernel)
{
    auto weights = kernel.getKernel();
    auto numWeights = weights->size();
    auto numPixelRefs = mPixelRefs.size();

    if (numWeights != numPixelRefs) {
        std::cerr << "Number of weights in window isn't equal to that of pixel refs" << std::endl;
        return;
    }

    // Calculate sum of each pixel in the window
    double sum = 0;

    for (int i = 0; i < numWeights; i++) {
        auto ref = mPixelRefs.at(i);

        if (ref != nullptr) {
            auto w = weights->at(i);
            auto calc = *ref * w;
            sum = sum + calc;
        }
    }

    sum = std::clamp<double>(round(sum), 0.0, 255.0);

    // Set each pixel in the window to sum
    for (int i = 0; i < numPixelRefs; i++) {
        auto ref = mPixelRefs.at(i);

        if (ref != nullptr) {
            *ref = sum;
        }
    }
}
