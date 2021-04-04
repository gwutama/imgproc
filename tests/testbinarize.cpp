#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/binarize.h>

TEST(TestBinarize, man_bmp)
{
    auto binarize = std::shared_ptr<Binarize>(new Binarize);
    binarize->setThreshold(100);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(binarize);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "../results/testbinarize-man_bmp-100.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}