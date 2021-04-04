#include "kernelfilter.h"

void KernelFilter::apply8bit(std::shared_ptr<Image> &image)
{
    if (mKernelType == Kernel::KernelType::Unknown) {
        return;
    }

    Kernel kernel(mKernelType);
    auto windows = image->calculateFilterWindows(kernel.getSize());

    for (auto window: windows) {
        window.applyFilterKernel(kernel);
    }
}
