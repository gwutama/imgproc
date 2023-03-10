#include <gtest/gtest.h>
#include <bitmap/bitmapfile.h>

TEST(TestBitmapFile, read_all_gray)
{
    auto bitmap = BitmapFile::fromFile("../../tests/images/all_gray.bmp");
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-read_all_gray.bmp");
}

TEST(TestBitmapFile, read_gray_24bit_10x10)
{
    auto bitmap = BitmapFile::fromFile("../../tests/images/gray_24bit_10x10.bmp");
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-read_gray_24bit_10x10.bmp");
}

TEST(TestBitmapFile, read_bikes)
{
    auto bitmap = BitmapFile::fromFile("../../tests/images/bikes.bmp");
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-read_bikes.bmp");
}

TEST(TestBitmapFile, read_fruits)
{
    auto bitmap = BitmapFile::fromFile("../../tests/images/fruits.bmp");
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-read_fruits.bmp");
}

TEST(TestBitmapFile, read_multfont)
{
    auto bitmap = BitmapFile::fromFile("../../tests/images/multfont.bmp");
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-read_multfont.bmp");
}

TEST(TestBitmapFile, read_003_SCANNED_GRAY_GT)
{
    auto bitmap = BitmapFile::fromFile("../../tests/images/003_SCANNED_GRAY_GT.bmp");
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-read_003_SCANNED_GRAY_GT.bmp");
}

TEST(TestBitmapFile, black_8bit_8x2)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({8, 2}, 8, 0));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_8x2.bmp");
}

TEST(TestBitmapFile, black_8bit_4x4)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({4, 4}, 8, 0));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_4x4.bmp");
}

TEST(TestBitmapFile, black_8bit_5x5)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({5, 5}, 8, 0));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_5x5.bmp");
}

TEST(TestBitmapFile, black_8bit_10x10)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({4, 4}, 8, 0));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_10x10.bmp");
}

TEST(TestBitmapFile, black_8bit_600x400)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({600, 400}, 8, 0));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_600x400.bmp");
}

TEST(TestBitmapFile, black_8bit_601x401)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({601, 401}, 8, 0));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_601x401.bmp");
}

TEST(TestBitmapFile, black_8bit_1024x1024)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({1024, 1024}, 8, 0));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_1024x1024.bmp");
}

TEST(TestBitmapFile, white_8bit_5x5)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({5, 5}, 8, 255));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-white_8bit_5x5.bmp");
}

TEST(TestBitmapFile, gray_8bit_100x100)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({100, 100}, 8, 128));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-gray_8bit_100x100.bmp");
}

TEST(TestBitmapFile, green_100x100)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({100, 100}, Rgb{0, 255, 0}));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-green_100x100.bmp");
}

TEST(TestBitmapFile, blue_3x5)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({3, 5}, Rgb{255, 0, 0}));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-blue_3x5.bmp");
}

TEST(TestBitmapFile, blue_601x401)
{
    auto bitmap = std::shared_ptr<BitmapFile>(new BitmapFile({601, 401}, Rgb{255, 0, 0}));
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-blue_601x401.bmp");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}