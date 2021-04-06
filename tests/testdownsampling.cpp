#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/downsampling.h>

TEST(TestDownsampling, man_bmp_512)
{
    auto downsampling = std::shared_ptr<Downsampling>(new Downsampling);
    downsampling->setNewSize({512, 512});

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(downsampling);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testdownsampling-man_bmp-512.png");
}

TEST(TestDownsampling, man_bmp_500)
{
    auto downsampling = std::shared_ptr<Downsampling>(new Downsampling);
    downsampling->setNewSize({500, 500});

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(downsampling);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testdownsampling-man_bmp-500.png");
}

TEST(TestDownsampling, man_bmp_200)
{
    auto downsampling = std::shared_ptr<Downsampling>(new Downsampling);
    downsampling->setNewSize({200, 100});

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(downsampling);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testdownsampling-man_bmp-200.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}