#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>
#include <bitmap/bitmapimageadapter.h>
#include <imageprocessor.h>
#include <algorithms/gskernelfilter.h>

TEST(TestGsKernelFilter, man_bmp_boxblur)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto kernelFilter = std::shared_ptr<GsKernelFilter>(new GsKernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::BoxBlur);
    processor.applyAlgorithm(kernelFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testgskernelfilter-man_bmp-boxblur.png");
}

TEST(TestGsKernelFilter, lena_bmp_sharpen)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/lena.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto kernelFilter = std::shared_ptr<GsKernelFilter>(new GsKernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::Sharpen);
    processor.applyAlgorithm(kernelFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "testgskernelfilter-lena_bmp-sharpen.png");
}

TEST(TestGsKernelFilter, girlface_bmp_edgedetection)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/girlface.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto kernelFilter = std::shared_ptr<GsKernelFilter>(new GsKernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::EdgeDetection);
    processor.applyAlgorithm(kernelFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/girlface.bmp /tmp/out.bmp +append "
           "testgskernelfilter-girlface_bmp-edgedetection.png");
}

TEST(TestGsKernelFilter, man_bmp_gaussianblur5x5)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto kernelFilter = std::shared_ptr<GsKernelFilter>(new GsKernelFilter);
    kernelFilter->setKernelType(Kernel::KernelType::GaussianBlur5x5);
    processor.applyAlgorithm(kernelFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testgskernelfilter-man_bmp-gaussianblur5x5.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}