#include "kernel.h"

Kernel::Kernel(Mask mask)
{
    if (mask == Mask::BoxBlur) {
        auto kernelPtr = std::vector<double>{1.0 / 9, 1.0 / 9, 1.0 / 9,
                                             1.0 / 9, 1.0 / 9, 1.0 / 9,
                                             1.0 / 9, 1.0 / 9, 1.0 / 9};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::Sharpen) {
        auto kernelPtr = std::vector<double>{ 0, -1, 0,
                                             -1,  5, -1,
                                              0, -1, 0};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::EdgeDetect) {
        auto kernelPtr = std::vector<double>{-1, -1, -1,
                                             -1,  8, -1,
                                             -1, -1, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::GaussianBlur3x3) {
        auto kernelPtr = std::vector<double>{1.0 / 16, 2.0 / 16, 1.0 / 16,
                                             2.0 / 16, 4.0 / 16, 2.0 / 16,
                                             1.0 / 16, 2.0 / 16, 1.0 / 16};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::GaussianBlur5x5) {
        auto kernelPtr = std::vector<double>{1.0 / 256,  4.0 / 256,  6.0 / 256,  4.0 / 256, 1.0 / 256,
                                             4.0 / 256, 16.0 / 256, 24.0 / 256, 16.0 / 256, 4.0 / 256,
                                             6.0 / 256, 24.0 / 256, 36.0 / 256, 24.0 / 256, 6.0 / 256,
                                             4.0 / 256, 16.0 / 256, 24.0 / 256, 16.0 / 256, 4.0 / 256,
                                             1.0 / 256,  4.0 / 256,  6.0 / 256,  4.0 / 256, 1.0 / 256};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{5, 5};
    }
    else if (mask == Mask::LineDetectHorizontal) {
        auto kernelPtr = std::vector<double>{-1, -1, -1,
                                              2,  2,  2,
                                             -1, -1, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::LineDetectVertical) {
        auto kernelPtr = std::vector<double>{-1, 2, -1,
                                             -1, 2, -1,
                                             -1, 2, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::PrewittVertical) {
        auto kernelPtr = std::vector<double>{1, 0, -1,
                                             1, 0, -1,
                                             1, 0, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::PrewittHorizontal) {
        auto kernelPtr = std::vector<double>{ 1,  1,  1,
                                              0,  0,  0,
                                             -1, -1, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::SobelVertical) {
        auto kernelPtr = std::vector<double>{1, 0, -1,
                                             2, 0, -2,
                                             1, 0, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::SobelHorizontal) {
        auto kernelPtr = std::vector<double>{  1,  2,  1,
                                               0,  0,  0,
                                              -1, -2, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::RobinsonNorth) {
        auto kernelPtr = std::vector<double>{-1, 0, 1,
                                             -2, 0, 2,
                                             -1, 0, 1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::RobinsonWest) {
        auto kernelPtr = std::vector<double>{ 1,  2,  1,
                                              0,  0,  0,
                                             -1, -2, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::RobinsonSouth) {
        auto kernelPtr = std::vector<double>{1, 0, -1,
                                             2, 0, -2,
                                             1, 0, -1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::RobinsonEast) {
        auto kernelPtr = std::vector<double>{-1, -2, -1,
                                              0,  0,  0,
                                              1,  2,  1};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::KirschNorth) {
        auto kernelPtr = std::vector<double>{-3, -3, 5,
                                             -3,  0, 5,
                                             -3, -3, 5};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::KirschWest) {
        auto kernelPtr = std::vector<double>{ 5,  5,  5,
                                             -3,  0, -3,
                                             -3, -3, -3};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::KirschSouth) {
        auto kernelPtr = std::vector<double>{5, -3, -3,
                                             5,  0, -3,
                                             5, -3, -3};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::KirschEast) {
        auto kernelPtr = std::vector<double>{-3, -3, -3,
                                             -3,  0, -3,
                                              5,  5,  5};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::LaplacianNegative) {
        auto kernelPtr = std::vector<double>{ 0, -1,  0,
                                             -1,  4, -1,
                                              0, -1,  0};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
    else if (mask == Mask::LaplacianPositive) {
        auto kernelPtr = std::vector<double>{0,  1, 0,
                                             1, -4, 1,
                                             0,  1, 0};
        mKernel = std::make_shared<std::vector<double>>(kernelPtr);
        mSize = Size{3, 3};
    }
}