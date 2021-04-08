#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/noise.h>

TEST(TestNoise, lena_bmp_1)
{
    auto noise = std::shared_ptr<Noise>(new Noise);
    noise->setProbability(1);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(noise);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testnoise-lena_bmp-1.png");
}

TEST(TestNoise, lena_bmp_5)
{
    auto noise = std::shared_ptr<Noise>(new Noise);
    noise->setProbability(5);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(noise);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testnoise-lena_bmp-5.png");
}

TEST(TestNoise, lena_bmp_20)
{
    auto noise = std::shared_ptr<Noise>(new Noise);
    noise->setProbability(20);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(noise);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testnoise-lena_bmp-20.png");
}

TEST(TestNoise, gray_bmp_20)
{
    auto noise = std::shared_ptr<Noise>(new Noise);
    noise->setProbability(20);

    auto image1 = std::shared_ptr<Image>(new Image({400, 400}, 8, 128));
    image1->write("/tmp/out.bmp");

    auto image2 = std::shared_ptr<Image>(new Image({400, 400}, 8, 128));
    image2->applyAlgorithm(noise);
    image2->write("/tmp/out2.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "/tmp/out.bmp /tmp/out2.bmp +append "
           "../results/testnoise-gray-20.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
