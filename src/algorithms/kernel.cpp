#include "kernel.h"

Kernel::Kernel(Type kernel)
{
    if (kernel == Type::BoxBlur) {
        auto kernelPtr = std::vector<double>{1.0 / 9, 1.0 / 9, 1.0 / 9,
                                             1.0 / 9, 1.0 / 9, 1.0 / 9,
                                             1.0 / 9, 1.0 / 9, 1.0 / 9};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
        mCalculateModifiedPixels = true;
    }
    else if (kernel == Type::Sharpen) {
        auto kernelPtr = std::vector<double>{ 0, -1, 0,
                                             -1,  5, -1,
                                              0, -1, 0};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
        mCalculateModifiedPixels = false;
    }
    else if (kernel == Type::EdgeDetect) {
        auto kernelPtr = std::vector<double>{-1, -1, -1,
                                             -1,  8, -1,
                                             -1, -1, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
        mCalculateModifiedPixels = false;
    }
    else if (kernel == Type::GaussianBlur3x3) {
        auto kernelPtr = std::vector<double>{1.0 / 16, 2.0 / 16, 1.0 / 16,
                                             2.0 / 16, 4.0 / 16, 2.0 / 16,
                                             1.0 / 16, 2.0 / 16, 1.0 / 16};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
        mCalculateModifiedPixels = true;
    }
    else if (kernel == Type::GaussianBlur5x5) {
        auto kernelPtr = std::vector<double>{1.0 / 256,  4.0 / 256,  6.0 / 256,  4.0 / 256, 1.0 / 256,
                                             4.0 / 256, 16.0 / 256, 24.0 / 256, 16.0 / 256, 4.0 / 256,
                                             6.0 / 256, 24.0 / 256, 36.0 / 256, 24.0 / 256, 6.0 / 256,
                                             4.0 / 256, 16.0 / 256, 24.0 / 256, 16.0 / 256, 4.0 / 256,
                                             1.0 / 256,  4.0 / 256,  6.0 / 256,  4.0 / 256, 1.0 / 256};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{5, 5};
        mCalculateModifiedPixels = true;
    }
    else if (kernel == Type::LineDetectHorizontal) {
        auto kernelPtr = std::vector<double>{-1, -1, -1,
                                              2,  2,  2,
                                             -1, -1, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
        mCalculateModifiedPixels = false;
    }
    else if (kernel == Type::LineDetectVertical) {
        auto kernelPtr = std::vector<double>{-1, 2, -1,
                                             -1, 2, -1,
                                             -1, 2, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
        mCalculateModifiedPixels = false;
    }
}