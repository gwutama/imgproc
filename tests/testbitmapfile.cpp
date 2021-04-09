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

TEST(TestBitmapFile, read_fruits)
{
    auto bitmap = BitmapFile::fromFile("../../tests/images/fruits.bmp");
    bitmap->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-read_fruits.bmp");
}

TEST(TestBitmapFile, black_8bit_8x2)
{
    auto bitmap = BitmapFile({8, 2}, 8);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_8x2.bmp");
}

TEST(TestBitmapFile, black_8bit_4x4)
{
    auto bitmap = BitmapFile({4, 4}, 8);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_4x4.bmp");
}

TEST(TestBitmapFile, black_8bit_5x5)
{
    auto bitmap = BitmapFile({5, 5}, 8);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_5x5.bmp");
}

TEST(TestBitmapFile, black_8bit_10x10)
{
    auto bitmap = BitmapFile({4, 4}, 8);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_10x10.bmp");
}

TEST(TestBitmapFile, black_8bit_600x400)
{
    auto bitmap = BitmapFile({600, 400}, 8);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_600x400.bmp");
}

TEST(TestBitmapFile, black_8bit_601x401)
{
    auto bitmap = BitmapFile({601, 401}, 8);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_601x401.bmp");
}

TEST(TestBitmapFile, black_8bit_1024x1024)
{
    auto bitmap = BitmapFile({1024, 1024}, 8);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-black_8bit_1024x1024.bmp");
}

TEST(TestBitmapFile, white_8bit_5x5)
{
    auto bitmap = BitmapFile({5, 5}, 8, 255);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-white_8bit_5x5.bmp");
}

TEST(TestBitmapFile, gray_8bit_100x100)
{
    auto bitmap = BitmapFile({100, 100}, 8, 128);
    bitmap.write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testbitmapfile-gray_8bit_100x100.bmp");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}