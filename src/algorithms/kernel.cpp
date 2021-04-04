#include "kernel.h"

Kernel::Kernel(KernelType kernel)
{
    if (kernel == KernelType::BoxBlur) {
        auto kernelPtr = std::vector<double>{1.0 / 9, 1.0 / 9, 1.0 / 9,
                                             1.0 / 9, 1.0 / 9, 1.0 / 9,
                                             1.0 / 9, 1.0 / 9, 1.0 / 9};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (kernel == KernelType::Sharpen) {
        auto kernelPtr = std::vector<double>{ 0, -1, 0,
                                             -1,  5, -1,
                                              0, -1, 0};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (kernel == KernelType::EdgeDetection) {
        auto kernelPtr = std::vector<double>{-1, -1, -1,
                                             -1,  8, -1,
                                             -1, -1, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (kernel == KernelType::GaussianBlur5x5) {
        auto kernelPtr = std::vector<double>{1.0 / 256,  4.0 / 256,  6.0 / 256,  4.0 / 256, 1.0 / 256,
                                             4.0 / 256, 16.0 / 256, 24.0 / 256, 16.0 / 256, 4.0 / 256,
                                             6.0 / 256, 24.0 / 256, 36.0 / 256, 24.0 / 256, 6.0 / 256,
                                             4.0 / 256, 16.0 / 256, 24.0 / 256, 16.0 / 256, 4.0 / 256,
                                             1.0 / 256,  4.0 / 256,  6.0 / 256,  4.0 / 256, 1.0 / 256};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{5, 5};
    }
    else if (kernel == KernelType::LineDetectHorizontal) {
        auto kernelPtr = std::vector<double>{-1, -1, -1,
                                              2,  2,  2,
                                             -1, -1, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (kernel == KernelType::LineDetectVertical) {
        auto kernelPtr = std::vector<double>{-1, 2, -1,
                                             -1, 2, -1,
                                             -1, 2, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
}

Kernel::Kernel(std::shared_ptr<std::vector<double>> kernel,
               const Size &size)
    :
    mKernel(kernel),
    mSize(size)
{
}