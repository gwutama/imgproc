#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>
#include <bitmap/bitmapimageadapter.h>
#include <imageprocessor.h>
#include <algorithms/gshistogram.h>
#include <algorithms/gshistogramequalization.h>

TEST(TestGsHistogramEqualization, man_bmp)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/man.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto histogramCalc = std::shared_ptr<GsHistogram>(new GsHistogram);
    processor.applyAlgorithm(histogramCalc);
    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_orig.dat");

    auto histogramEq = std::shared_ptr<GsHistogramEqualization>(new GsHistogramEqualization);
    processor.applyAlgorithm(histogramEq);

    processor.applyAlgorithm(histogramCalc);
    histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_mod.dat");

    imageFile->write("/tmp/out.bmp");

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
           "testgshistogramequalization-man_bmp.png");
}

TEST(TestGsHistogramEqualization, girlface_bmp)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/girlface.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto histogramCalc = std::shared_ptr<GsHistogram>(new GsHistogram);
    processor.applyAlgorithm(histogramCalc);
    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_orig.dat");

    auto histogramEq = std::shared_ptr<GsHistogramEqualization>(new GsHistogramEqualization);
    processor.applyAlgorithm(histogramEq);

    processor.applyAlgorithm(histogramCalc);
    histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_mod.dat");

    imageFile->write("/tmp/out.bmp");

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
           "testgshistogramequalization-girlface.png");
}

TEST(TestGsHistogramEqualization, lena_bmp)
{
    auto imageFile = BitmapFile::fromFile("../../tests/images/lena.bmp");
    ASSERT_NE(imageFile, nullptr);

    auto image = std::shared_ptr<BitmapImageAdapter>(new BitmapImageAdapter(imageFile));
    ImageProcessor processor(image);

    auto histogramCalc = std::shared_ptr<GsHistogram>(new GsHistogram);
    processor.applyAlgorithm(histogramCalc);
    auto histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_orig.dat");

    auto histogramEq = std::shared_ptr<GsHistogramEqualization>(new GsHistogramEqualization);
    processor.applyAlgorithm(histogramEq);

    processor.applyAlgorithm(histogramCalc);
    histogram = histogramCalc->getHistogramBin();
    histogramCalc->write("/tmp/out_mod.dat");

    imageFile->write("/tmp/out.bmp");

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
           "testgshistogramequalization-lena.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}