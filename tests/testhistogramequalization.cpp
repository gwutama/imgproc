#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/histogram.h>
#include <algorithms/histogramequalization.h>

TEST(TestHistogramEqualization, man_bmp)
{
    auto histogramCalc = std::shared_ptr<Histogram>(new Histogram);
    auto histogramEq = std::shared_ptr<HistogramEqualization>(new HistogramEqualization);

    auto image = Image::fromFile("../../tests/images/man.bmp");
    image->applyAlgorithm(histogramCalc);
    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_orig.dat");

    image->applyAlgorithm(histogramEq);
    image->applyAlgorithm(histogramCalc);
    histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_mod.dat");

    image->write("/tmp/out.bmp");

    system("gnuplot -e "
           "\"set terminal png; "
           "set output '/tmp/out.png'; "
           "set multiplot layout 2,1; "
           "plot '/tmp/out_orig.dat' with impulse; "
           "plot '/tmp/out_mod.dat' with impulse; "
           "unset multiplot\"");

    system("convert "
           "-resize 500x500 "
           "/tmp/out.png ../../tests/images/man.bmp /tmp/out.bmp +append "
           "testhistogramequalization-man_bmp.png");
}

TEST(TestHistogramEqualization, girlface_bmp)
{
    auto histogramCalc = std::shared_ptr<Histogram>(new Histogram);
    auto histogramEq = std::shared_ptr<HistogramEqualization>(new HistogramEqualization);

    auto image = Image::fromFile("../../tests/images/girlface.bmp");
    image->applyAlgorithm(histogramCalc);
    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_orig.dat");

    image->applyAlgorithm(histogramEq);
    image->applyAlgorithm(histogramCalc);
    histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_mod.dat");

    image->write("/tmp/out.bmp");

    system("gnuplot -e "
           "\"set terminal png; "
           "set output '/tmp/out.png'; "
           "set multiplot layout 2,1; "
           "plot '/tmp/out_orig.dat' with impulse; "
           "plot '/tmp/out_mod.dat' with impulse; "
           "unset multiplot\"");

    system("convert "
           "-resize 500x500 "
           "/tmp/out.png ../../tests/images/girlface.bmp /tmp/out.bmp +append "
           "testhistogramequalization-girlface.png");
}

TEST(TestHistogramEqualization, lena_bmp)
{
    auto histogramCalc = std::shared_ptr<Histogram>(new Histogram);
    auto histogramEq = std::shared_ptr<HistogramEqualization>(new HistogramEqualization);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(histogramCalc);
    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_orig.dat");

    image->applyAlgorithm(histogramEq);
    image->applyAlgorithm(histogramCalc);
    histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_mod.dat");

    image->write("/tmp/out.bmp");

    system("gnuplot -e "
           "\"set terminal png; "
           "set output '/tmp/out.png'; "
           "set multiplot layout 2,1; "
           "plot '/tmp/out_orig.dat' with impulse; "
           "plot '/tmp/out_mod.dat' with impulse; "
           "unset multiplot\"");

    system("convert "
           "-resize 500x500 "
           "/tmp/out.png ../../tests/images/lena.bmp /tmp/out.bmp +append "
           "testhistogramequalization-lena.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}