#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>
#include <bitmap/bitmapimageadapter.h>
#include <imageprocessor.h>
#include <algorithms/unibrightnessadjustment.h>

TEST(TestBrightnessAdjustment, man_bmp_up)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto brightnessFilter = std::shared_ptr<UniBrightnessAdjustment>(new UniBrightnessAdjustment);
    brightnessFilter->setValue(100);
    processor.applyAlgorithm(brightnessFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testunibrightnessadjustment-man_bmp_up-100.png");
}

TEST(TestBrightnessAdjustment, man_bmp_down)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto brightnessFilter = std::shared_ptr<UniBrightnessAdjustment>(new UniBrightnessAdjustment);
    brightnessFilter->setValue(-100);
    processor.applyAlgorithm(brightnessFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testunibrightnessadjustment-man_bmp_down-100.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}