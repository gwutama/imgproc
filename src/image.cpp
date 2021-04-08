#include "image.h"
#include "algorithms/algorithm.h"
#include <iostream>

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

Image::Image(Size size, uint8_t bitDepth, uint8_t fill)
{
    mBitmapFile = std::shared_ptr<BitmapFile>(new BitmapFile(size, bitDepth, fill));
}

uint8_t Image::bitDepth()
{
    if (mBitmapFile == nullptr) {
        return 0;
    }

    return mBitmapFile->getBitDepth();
}

void Image::setBitDepth(uint8_t bitDepth)
{
    if (mBitmapFile == nullptr) {
        return;
    }

    if (!BitmapFile::isBitDepthSupported(bitDepth)) {
        std::cerr << "Unsupported bit depth: " << bitDepth << std::endl;
        return;
    }

    mBitmapFile->setBitDepth(bitDepth);
}

Size Image::resolution()
{
    if (mBitmapFile == nullptr) {
        return {};
    }

    return mBitmapFile->getResolution();
}

void Image::setResolution(Size size)
{
    if (mBitmapFile == nullptr) {
        return;
    }

    mBitmapFile->setResolution(size);
}

std::shared_ptr<ByteArray> Image::pixelData()
{
    if (mBitmapFile == nullptr) {
        return nullptr;
    }

    return mBitmapFile->getPixelData();
}

void Image::setPixelData(std::shared_ptr<ByteArray> data)
{
    if (mBitmapFile == nullptr) {
        return;
    }

    mBitmapFile->setPixelData(data);
}

bool Image::write(const std::string &path)
{
    if (mBitmapFile == nullptr) {
        return false;
    }

    if (path.empty()) {
        return false;
    }

    return mBitmapFile->write(path);
}

bool Image::write()
{
    if (mBitmapFile == nullptr) {
        return false;
    }

    if (mBitmapFile->getFileName().empty()) {
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

uint8_t *Image::pixel8bit(const Coordinate &coord)
{
    if (mBitmapFile == nullptr) {
        return 0;
    }

    auto res = resolution();

    // Out of bounds
    if (coord.x >= res.width || coord.x < 0 || coord.y >= res.height || coord.y < 0) {
        return nullptr;
    }

    auto pos = coordToIndex8bit(coord, res);
    auto pixel = &(pixelData()->at(pos));
    return pixel;
}

bool Image::setPixel(const Coordinate &coord, uint8_t value)
{
    if (mBitmapFile == nullptr) {
        return false;
    }

    auto res = resolution();

    // Out of bounds
    if (coord.x >= res.width || coord.x < 0 || coord.y >= res.height || coord.y < 0) {
        return false;
    }

    auto pos = coordToIndex8bit(coord, res);
    pixelData()->at(pos) = value;
    return true;
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