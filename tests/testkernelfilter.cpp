#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/kernelfilter.h>

TEST(TestKernelFilter, all_gray_bmp_boxblur)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::BoxBlur);

    auto image = Image::fromFile("../../tests/images/all_gray.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/all_gray.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-all_gray_bmp-boxblur.png");
}

TEST(TestKernelFilter, man_bmp_boxblur)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::BoxBlur);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-man_bmp-boxblur.png");
}

TEST(TestKernelFilter, lena_bmp_sharpen)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::Sharpen);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lena_bmp-sharpen.png");
}

TEST(TestKernelFilter, girlface_bmp_edgedetection)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::EdgeDetect);

    auto image = Image::fromFile("../../tests/images/girlface.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/girlface.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-girlface_bmp-edgedetection.png");
}

TEST(TestKernelFilter, man_bmp_gaussianblur3x3)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::GaussianBlur3x3);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-man_bmp-gaussianblur3x3.png");
}

TEST(TestKernelFilter, man_bmp_gaussianblur5x5)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::GaussianBlur5x5);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-man_bmp-gaussianblur5x5.png");
}

TEST(TestKernelFilter, houses_bmp_linedetecthorizontal)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::LineDetectHorizontal);

    auto image = Image::fromFile("../../tests/images/houses.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/houses.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-houses_bmp-linedetecthorizontal.png");
}

TEST(TestKernelFilter, houses_bmp_linedetectvertical)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Type::LineDetectVertical);

    auto image = Image::fromFile("../../tests/images/houses.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/houses.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-houses_bmp-linedetectvertical.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}