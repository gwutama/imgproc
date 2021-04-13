#include <gtest/gtest.h>
#include <image.h>
#include <image.h>
#include <algorithms/drawline.h>

TEST(TestDrawLine, horizontal_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(0);
    drawLine->setPointFrom({0, 250});
    drawLine->setPointTo({500, 250});

    auto image = std::shared_ptr<Image>(new Image({500, 500}, 8, 255));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-horizontal.bmp");
}

TEST(TestDrawLine, horizontal_rgb_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(Rgb{0, 0, 255});
    drawLine->setPointFrom({0, 250});
    drawLine->setPointTo({500, 250});

    auto image = std::shared_ptr<Image>(new Image({500, 500},{255, 0, 0}));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-horizontal_rgb.bmp");
}

TEST(TestDrawLine, vertical_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(0);
    drawLine->setPointFrom({250, 0});
    drawLine->setPointTo({250, 500});

    auto image = std::shared_ptr<Image>(new Image({500, 500}, 8, 255));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-vertical.bmp");
}

TEST(TestDrawLine, vertical_rgb_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(Rgb{0, 0, 255});
    drawLine->setPointFrom({250, 0});
    drawLine->setPointTo({250, 500});

    auto image = std::shared_ptr<Image>(new Image({500, 500},{255, 0, 0}));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-vertical_rgb.bmp");
}

TEST(TestDrawLine, diagonal1_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(0);
    drawLine->setPointFrom({0, 0});
    drawLine->setPointTo({500, 500});

    auto image = std::shared_ptr<Image>(new Image({500, 500}, 8, 255));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-diagonal1.bmp");
}

TEST(TestDrawLine, diagonal1_rgb_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(Rgb{0, 0, 255});
    drawLine->setPointFrom({0, 0});
    drawLine->setPointTo({500, 500});

    auto image = std::shared_ptr<Image>(new Image({500, 500},{255, 0, 0}));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-diagonal1_rgb.bmp");
}

TEST(TestDrawLine, diagonal2_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(0);
    drawLine->setPointFrom({500, 0});
    drawLine->setPointTo({0, 500});

    auto image = std::shared_ptr<Image>(new Image({500, 500}, 8, 255));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-diagonal2.bmp");
}

TEST(TestDrawLine, diagonal2_rgb_bmp)
{
    auto drawLine = std::shared_ptr<DrawLine>(new DrawLine);
    drawLine->setColor(Rgb{0, 0, 255});
    drawLine->setPointFrom({500, 0});
    drawLine->setPointTo({0, 500});

    auto image = std::shared_ptr<Image>(new Image({500, 500},{255, 0, 0}));
    image->applyAlgorithm(drawLine);
    image->write("/tmp/out.bmp");

    system("mkdir -p ../results/");
    system("cp /tmp/out.bmp ../results/testdrawline-diagonal2_rgb.bmp");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}