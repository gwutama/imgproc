#include "image.h"
#include "algorithms/algorithm.h"

std::shared_ptr<Image> Image::fromFile(const std::string &path)
{
    auto imageFile = BitmapFile::fromFile(path);

    if (imageFile == nullptr) {
        return nullptr;
    }

    auto image = std::shared_ptr<Image>(new Image(imageFile));
    return image;
}

Image::Image(std::shared_ptr<BitmapFile> bitmapFile)
    :
    mBitmapFile(bitmapFile)
{
}

uint8_t Image::bitDepth()
{
    if (mBitmapFile == nullptr) {
        return 0;
    }

    return mBitmapFile->getInfoHeader()->biBitCount;
}

Size Image::resolution()
{
    if (mBitmapFile == nullptr) {
        return {};
    }

    auto header = mBitmapFile->getInfoHeader();
    return {
        static_cast<uint32_t>(header->biWidth),
        static_cast<uint32_t>(header->biHeight)
    };
}

std::shared_ptr<ByteArray> Image::pixelData()
{
    if (mBitmapFile == nullptr) {
        return nullptr;
    }

    return mBitmapFile->getPixelData();
}

bool Image::write(const std::string &path)
{
    if (mBitmapFile == nullptr) {
        return false;
    }

    return mBitmapFile->write(path);
}

bool Image::write()
{
    if (mBitmapFile == nullptr) {
        return false;
    }

    return mBitmapFile->write();
}

std::shared_ptr<ByteArray> Image::pixelDataCopy()
{
    if (mBitmapFile == nullptr) {
        return nullptr;
    }

    auto copy = std::shared_ptr<ByteArray>(new ByteArray);
    auto pxData = pixelData();
    auto iter = pxData->begin();

    while (iter != pxData->end()) {
        auto data = *iter;
        copy->push_back(data);
        iter++;
    }

    return copy;
}

uint8_t *Image::at(Coordinate coord)
{
    if (mBitmapFile == nullptr) {
        return 0;
    }

    auto res = resolution();

    if (coord.x >= res.width || coord.y >= res.height) {
        return nullptr;
    }

    auto pos = coordinateToVectorIndex(coord, res);
    auto pixel = &(pixelData()->at(pos));
    return pixel;
}

std::vector<GsFilterWindow> Image::calculateFilterWindows(const Size &windowSize)
{
    if (mBitmapFile == nullptr) {
        return {};
    }

    auto imgWidth = resolution().width;
    auto imgHeight = resolution().height;
    auto windows = std::vector<GsFilterWindow>();

    for (uint32_t y = 0; y < imgHeight; y += windowSize.height) {
        for (uint32_t x = 0; x < imgWidth; x += windowSize.width) {
            auto window = calculateFilterWindow({x, y}, windowSize);
            windows.push_back(window);
        }
    }

    return windows;
}

GsFilterWindow Image::calculateFilterWindow(const Coordinate &topLeftPixel,
                                            const Size &windowSize)
{
    if (mBitmapFile == nullptr) {
        return {};
    }

    GsFilterWindow window;

    for (uint32_t y = topLeftPixel.y; y < (topLeftPixel.y + windowSize.height); y++) {
        for (uint32_t x = topLeftPixel.x; x < (topLeftPixel.x + windowSize.width); x++) {
            auto pixelRef = at({x, y});
            window.addPixelRef(pixelRef);
        }
    }

    return window;
}

void Image::applyAlgorithm(std::shared_ptr<Algorithm> algorithm)
{
    if (mBitmapFile == nullptr) {
        return;
    }

    auto bd = bitDepth();
    auto mine = shared_from_this();

    if (bd == 8) {
        algorithm->apply8bit(mine);
    }
    else if (bd == 24) {
        algorithm->apply24bit(mine);
    }
}