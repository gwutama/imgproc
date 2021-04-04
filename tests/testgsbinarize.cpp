#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>
#include <bitmap/bitmapimageadapter.h>
#include <imageprocessor.h>
#include <algorithms/gsbinarize.h>

TEST(TestGsBinarize, man_bmp)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto binarizeFilter = std::shared_ptr<GsBinarize>(new GsBinarize);
    binarizeFilter->setThreshold(100);
    processor.applyAlgorithm(binarizeFilter);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testgsbinarize-man_bmp-100.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}