#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/rotate.h>

TEST(TestRotate, lena_bmp_180)
{
    auto rotate = std::shared_ptr<Rotate>(new Rotate);
    rotate->setDirection(Rotate::Direction::ROTATE_180);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(rotate);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testrotate-lena_bmp-180.png");
}

TEST(TestRotate, cameraman_bmp_180)
{
    auto rotate = std::shared_ptr<Rotate>(new Rotate);
    rotate->setDirection(Rotate::Direction::ROTATE_180);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(rotate);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testrotate-cameraman_bmp-180.png");
}

TEST(TestRotate, lena_bmp_90cw)
{
    auto rotate = std::shared_ptr<Rotate>(new Rotate);
    rotate->setDirection(Rotate::Direction::ROTATE_90_CW);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(rotate);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testrotate-lena_bmp-90cw.png");
}

TEST(TestRotate, man_bmp_90ccw)
{
    auto rotate = std::shared_ptr<Rotate>(new Rotate);
    rotate->setDirection(Rotate::Direction::ROTATE_90_CCW);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(rotate);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testrotate-man_bmp-90ccw.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}