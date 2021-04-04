#include "gskernelfilter.h"

void GsKernelFilter::apply(std::shared_ptr<GsImageAdapterBase> &image)
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
