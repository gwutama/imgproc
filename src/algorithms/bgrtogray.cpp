#include "bgrtogray.h"
#include <iostream>

void BgrToGray::apply24bit(std::shared_ptr<Image> &image)
{
    auto pixelData = image->pixelData();
    auto numPixelsRgb = pixelData->size();
    auto newPixelData = std::shared_ptr<ByteArray>(new ByteArray);

    for (uint64_t i = 0; i < numPixelsRgb; i = i + 3) {
        auto b = pixelData->at(i);
        auto g = pixelData->at(i + 1);
        auto r = pixelData->at(i + 2);

        auto gray =  static_cast<uint8_t>(round(0.299 * r + 0.587 * g + 0.114 * b));
        newPixelData->push_back(gray);
    }

    image->setPixelData(newPixelData);
    image->setBitDepth(8);
    image->write("/tmp/foobar.bmp");
}
