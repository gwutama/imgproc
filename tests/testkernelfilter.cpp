#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/kernelfilter.h>

TEST(TestKernelFilter, all_gray_bmp_boxblur)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::BoxBlur);

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
    kernelFilter->setKernelType(Kernel::Mask::BoxBlur);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-man_bmp-boxblur.png");
}

TEST(TestKernelFilter, cameraman_bmp_boxblur)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::BoxBlur);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-cameraman_bmp-boxblur.png");
}

TEST(TestKernelFilter, lena_bmp_sharpen)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::Sharpen);

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
    kernelFilter->setKernelType(Kernel::Mask::EdgeDetect);

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
    kernelFilter->setKernelType(Kernel::Mask::GaussianBlur3x3);

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
    kernelFilter->setKernelType(Kernel::Mask::GaussianBlur5x5);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-man_bmp-gaussianblur5x5.png");
}

TEST(TestKernelFilter, cameraman_bmp_gaussianblur3x3)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::GaussianBlur3x3);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-cameraman_bmp-gaussianblur3x3.png");
}

TEST(TestKernelFilter, cameraman_bmp_gaussianblur5x5)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::GaussianBlur5x5);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-cameraman_bmp-gaussianblur5x5.png");
}

TEST(TestKernelFilter, houses_bmp_linedetecthorizontal)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::LineDetectHorizontal);

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
    kernelFilter->setKernelType(Kernel::Mask::LineDetectVertical);

    auto image = Image::fromFile("../../tests/images/houses.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/houses.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-houses_bmp-linedetectvertical.png");
}

TEST(TestKernelFilter, girlface_bmp_prewittvertical)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::PrewittVertical);

    auto image = Image::fromFile("../../tests/images/girlface.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/girlface.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-girlface_bmp-prewittvertical.png");
}

TEST(TestKernelFilter, girlface_bmp_prewitthorizontal)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::PrewittHorizontal);

    auto image = Image::fromFile("../../tests/images/girlface.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/girlface.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-girlface_bmp-prewitthorizontal.png");
}

TEST(TestKernelFilter, lena_bmp_sobelvertical)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::SobelVertical);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lena_bmp-sobelvertical.png");
}

TEST(TestKernelFilter, lena_bmp_sobelhorizontal)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::SobelHorizontal);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lena_bmp-sobelhorizontal.png");
}

TEST(TestKernelFilter, cameraman_bmp_robinsonnorth)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::RobinsonNorth);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-cameraman_bmp-robinsonnorth.png");
}

TEST(TestKernelFilter, cameraman_bmp_robinsoneast)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::RobinsonEast);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-cameraman_bmp-robinsoneast.png");
}

TEST(TestKernelFilter, cameraman_bmp_robinsonsouth)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::RobinsonSouth);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-cameraman_bmp-robinsonsouth.png");
}

TEST(TestKernelFilter, cameraman_bmp_robinsonwest)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::RobinsonWest);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-cameraman_bmp-robinsonwest.png");
}

TEST(TestKernelFilter, lena_bmp_kirschnorth)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::KirschNorth);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lena_bmp-kirschnorth.png");
}

TEST(TestKernelFilter, lena_bmp_kirscheast)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::KirschEast);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lena_bmp-kirscheast.png");
}

TEST(TestKernelFilter, lena_bmp_kirschsouth)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::KirschSouth);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lena_bmp-kirschsouth.png");
}

TEST(TestKernelFilter, lena_bmp_kirschwest)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::KirschWest);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lena_bmp-kirschwest.png");
}

TEST(TestKernelFilter, lighthouse_bmp_laplaciannegative)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::LaplacianNegative);

    auto image = Image::fromFile("../../tests/images/lighthouse.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lighthouse.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lighthouse_bmp-laplaciannegative.png");
}

TEST(TestKernelFilter, lighthouse_bmp_laplacianpositive)
{
    auto kernelFilter = std::shared_ptr<KernelFilter>(new KernelFilter);
    kernelFilter->setKernelType(Kernel::Mask::LaplacianPositive);

    auto image = Image::fromFile("../../tests/images/lighthouse.bmp");
    image->applyAlgorithm(kernelFilter);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lighthouse.bmp /tmp/out.bmp +append "
           "../results/testkernelfilter-lighthouse_bmp-laplacianpositive.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}