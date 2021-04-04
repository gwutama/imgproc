#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>
#include <bitmap/bitmapimageadapter.h>
#include <imageprocessor.h>
#include <algorithms/gshistogram.h>

TEST(TestGsHistogram, man_bmp)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto histogramCalc = std::shared_ptr<GsHistogram>(new GsHistogram);
    processor.applyAlgorithm(histogramCalc);
    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out.dat");

    system("gnuplot -e "
           "\"set terminal png; "
           "set output '/tmp/out.png'; "
           "plot '/tmp/out.dat' with impulse;\"");

    system("convert "
           "-resize 500x500 "
           "/tmp/out.png ../../tests/images/man.bmp +append "
           "testgshistogram-man_bmp.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}