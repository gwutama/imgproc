#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/negative.h>

TEST(TestNegative, man_bmp)
{
    auto negativeFilter = std::shared_ptr<Negative>(new Negative);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(negativeFilter);
    image->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testnegative-man_bmp.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}