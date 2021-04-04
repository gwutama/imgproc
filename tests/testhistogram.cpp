#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/histogram.h>

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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}