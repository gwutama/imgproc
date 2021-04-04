#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>
#include <bitmap/bitmapimageadapter.h>
#include <imageprocessor.h>
#include <algorithms/uninegative.h>

TEST(TestUniNegative, man_bmp)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto negativeFilter = std::shared_ptr<UniNegative>(new UniNegative);
    processor.applyAlgorithm(negativeFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testuninegative-man_bmp.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}