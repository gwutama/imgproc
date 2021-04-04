#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/brightnessadjustment.h>

TEST(TestBrightnessAdjustment, man_bmp_up)
{
    auto brightness = std::shared_ptr<BrightnessAdjustment>(new BrightnessAdjustment);
    brightness->setValue(100);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(brightness);
    image->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testbrightnessadjustment-man_bmp_up-100.png");
}

TEST(TestBrightnessAdjustment, man_bmp_down)
{
    auto brightness = std::shared_ptr<BrightnessAdjustment>(new BrightnessAdjustment);
    brightness->setValue(-100);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(brightness);
    image->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testbrightnessadjustment-man_bmp_down-100.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}