#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/kernelfilter.h>

TEST(TestKernelFilter, man_bmp_boxblur)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::BoxBlur);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testkernelfilter-man_bmp-boxblur.png");
}

TEST(TestKernelFilter, lena_bmp_sharpen)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::Sharpen);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "testkernelfilter-lena_bmp-sharpen.png");
}

TEST(TestKernelFilter, girlface_bmp_edgedetection)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::EdgeDetection);

    auto image = Image::fromFile("../../tests/images/girlface.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/girlface.bmp /tmp/out.bmp +append "
           "testkernelfilter-girlface_bmp-edgedetection.png");
}

TEST(TestKernelFilter, man_bmp_gaussianblur5x5)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::GaussianBlur5x5);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testkernelfilter-man_bmp-gaussianblur5x5.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}