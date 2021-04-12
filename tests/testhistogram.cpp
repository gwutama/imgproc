#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/histogram.h>
#include <algorithms/bgrtogray.h>

TEST(TestHistogram, man_bmp)
{
    auto histogramCalc = std::shared_ptr<Histogram>(new Histogram);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(histogramCalc);

    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out.dat");

    system("gnuplot -e "
           "\"set terminal png; "
           "set output '/tmp/out.png'; "
           "plot '/tmp/out.dat' with impulse;\"");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "/tmp/out.png ../../tests/images/man.bmp +append "
           "../results/testhistogram-man_bmp.png");
}

TEST(TestHistogram, 003_SCANNED_GRAY_GT_bmp)
{
    auto bgr2gray = std::shared_ptr<BgrToGray>(new BgrToGray);
    auto histogramCalc = std::shared_ptr<Histogram>(new Histogram);

    auto image = Image::fromFile("../../tests/images/003_SCANNED_GRAY_GT.bmp");
    image->applyAlgorithm(bgr2gray);
    image->applyAlgorithm(histogramCalc);

    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out.dat");

    system("gnuplot -e "
           "\"set terminal png; "
           "set output '/tmp/out.png'; "
           "plot '/tmp/out.dat' with impulse;\"");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 1000x1000 "
           "/tmp/out.png ../../tests/images/003_SCANNED_GRAY_GT.bmp +append "
           "../results/testhistogram-003_SCANNED_GRAY_GT_bmp.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}