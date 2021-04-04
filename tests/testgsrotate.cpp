#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>
#include <bitmap/bitmapimageadapter.h>
#include <imageprocessor.h>
#include <algorithms/gsrotate.h>


TEST(TestGsRotate, lena_bmp_180)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/lena.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto rotate = std::shared_ptr<GsRotate>(new GsRotate);
    rotate->setDirection(GsRotate::Direction::ROTATE_180);
    processor.applyAlgorithm(rotate);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "testgsrotate-lena_bmp-180.png");
}

TEST(TestGsRotate, cameraman_bmp_180)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/cameraman.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto rotate = std::shared_ptr<GsRotate>(new GsRotate);
    rotate->setDirection(GsRotate::Direction::ROTATE_180);
    processor.applyAlgorithm(rotate);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "testgsrotate-cameraman_bmp-180.png");
}

TEST(TestGsRotate, lena_bmp_90cw)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/lena.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto rotate = std::shared_ptr<GsRotate>(new GsRotate);
    rotate->setDirection(GsRotate::Direction::ROTATE_90_CW);
    processor.applyAlgorithm(rotate);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "testgsrotate-lena_bmp-90cw.png");
}

TEST(TestGsRotate, man_bmp_90ccw)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto rotate = std::shared_ptr<GsRotate>(new GsRotate);
    rotate->setDirection(GsRotate::Direction::ROTATE_90_CCW);
    processor.applyAlgorithm(rotate);

    imageFile->write("/tmp/out.bmp");

    system("convert "
           "-resize 500x500 "
           "../../tests/images/man.bmp /tmp/out.bmp +append "
           "testgsrotate-man_bmp-90ccw.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}