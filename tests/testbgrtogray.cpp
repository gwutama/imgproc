#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/bgrtogray.h>

TEST(TestBgrToGray, fruits_bmp)
{
    auto bgrToGray = std::shared_ptr<BgrToGray>(new BgrToGray);

    auto image = Image::fromFile("../../tests/images/fruits.bmp");
    image->applyAlgorithm(bgrToGray);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/fruits.bmp /tmp/out.bmp +append "
           "../results/testbgrtogray-fruits_bmp.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}