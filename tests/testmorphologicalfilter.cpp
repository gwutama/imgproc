#include <gtest/gtest.h>
#include <image.h>
#include <algorithms/morphologicalfilter.h>
#include <algorithms/bgrtogray.h>

TEST(TestMorphologicalFilter, lena_bmp_max)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Maximum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-lena_bmp-max.png");
}

TEST(TestMorphologicalFilter, cameraman_bmp_max)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Maximum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-cameraman_bmp-max.png");
}

TEST(TestMorphologicalFilter, 003_SCANNED_GRAY_GT_bmp_max)
{
    auto bgr2gray = std::shared_ptr<BgrToGray>(new BgrToGray);
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Maximum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/003_SCANNED_GRAY_GT.bmp");
    image->applyAlgorithm(bgr2gray);
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 1000x1000 "
           "../../tests/images/003_SCANNED_GRAY_GT.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-003_SCANNED_GRAY_GT_bmp-max.png");
}

TEST(TestMorphologicalFilter, DISABLED_multfont_bmp_max)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Maximum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/multfont.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/multfont.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-multfont_bmp-max.png");
}

TEST(TestMorphologicalFilter, lena_bmp_min)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Minimum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-lena_bmp-min.png");
}

TEST(TestMorphologicalFilter, cameraman_bmp_min)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Minimum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-cameraman_bmp-min.png");
}

TEST(TestMorphologicalFilter, DISABLED_multfont_bmp_min)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Minimum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/multfont.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/multfont.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-multfont_bmp-min.png");
}

TEST(TestMorphologicalFilter, 003_SCANNED_GRAY_GT_bmp_min)
{
    auto bgr2gray = std::shared_ptr<BgrToGray>(new BgrToGray);
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Minimum);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/003_SCANNED_GRAY_GT.bmp");
    image->applyAlgorithm(bgr2gray);
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 1000x1000 "
           "../../tests/images/003_SCANNED_GRAY_GT.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-003_SCANNED_GRAY_GT_bmp-min.png");
}

TEST(TestMorphologicalFilter, lena_bmp_avg)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Average);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/lena.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/lena.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-lena_bmp-avg.png");
}

TEST(TestMorphologicalFilter, cameraman_bmp_avg)
{
    auto morph = std::shared_ptr<MorphologicalFilter>(new MorphologicalFilter);
    morph->setFilter(MorphologicalFilter::Filter::Average);
    morph->setRadius(1);

    auto image = Image::fromFile("../../tests/images/cameraman.bmp");
    image->applyAlgorithm(morph);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("convert "
           "-resize 500x500 "
           "../../tests/images/cameraman.bmp /tmp/out.bmp +append "
           "../results/testmorphologicalfilter-cameraman_bmp-avg.png");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
