#include "morphologicalfilter.h"
#include <iostream>

void MorphologicalFilter::apply8bit(std::shared_ptr<Image> &image)
{
    if (mFilter == Filter::Maximum) {
        maximum8bit(image);
    }
    else if (mFilter == Filter::Minimum) {
        minimum8bit(image);
    }
    else if (mFilter == Filter::Average) {
        average8bit(image);
    }
}

void MorphologicalFilter::maximum8bit(std::shared_ptr<Image> &image)
{
    const auto imgWidth = image->resolution().width;
    const auto imgHeight = image->resolution().height;
    auto newPixelData = std::shared_ptr<ByteArray>(new ByteArray);

    for (int32_t y = 0; y < imgHeight; y++) {
        for (int32_t x = 0; x < imgWidth; x++) {
            uint8_t newVal = 0;
            uint8_t* pixel = nullptr;

            for (int i = -mRadius; i <= mRadius; i++) {
                for (int j = -mRadius; j <= mRadius; j++) {
                    pixel = image->pixel8bit({x + j, y + i});
                    if (pixel != nullptr && *(pixel) > newVal) {
                        newVal = *(pixel);
                    }
                }
            }

            newPixelData->push_back(newVal);
        }
    }

    image->setPixelData(newPixelData);
}

void MorphologicalFilter::minimum8bit(std::shared_ptr<Image> &image)
{
    const auto imgWidth = image->resolution().width;
    const auto imgHeight = image->resolution().height;
    auto newPixelData = std::shared_ptr<ByteArray>(new ByteArray);

    for (int32_t y = 0; y < imgHeight; y++) {
        for (int32_t x = 0; x < imgWidth; x++) {
            uint8_t newVal = 255;
            uint8_t* pixel = nullptr;

            for (int i = -mRadius; i <= mRadius; i++) {
                for (int j = -mRadius; j <= mRadius; j++) {
                    pixel = image->pixel8bit({x + j, y + i});
                    if (pixel != nullptr && *(pixel) < newVal) {
                        newVal = *(pixel);
                    }
                }
            }

            newPixelData->push_back(newVal);
        }
    }

    image->setPixelData(newPixelData);
}

void MorphologicalFilter::average8bit(std::shared_ptr<Image> &image)
{
    const auto imgWidth = image->resolution().width;
    const auto imgHeight = image->resolution().height;
    auto newPixelData = std::shared_ptr<ByteArray>(new ByteArray);

    for (int32_t y = 0; y < imgHeight; y++) {
        for (int32_t x = 0; x < imgWidth; x++) {
            uint16_t newVal = 0;
            uint8_t* pixel = nullptr;
            uint8_t div = 0;

            for (int i = -mRadius; i <= mRadius; i++) {
                for (int j = -mRadius; j <= mRadius; j++) {
                    pixel = image->pixel8bit({x + j, y + i});
                    if (pixel != nullptr) {
                        newVal = newVal + *(pixel);
                        div++;
                    }
                }
            }

            newVal = round(float(newVal) / float(div));
            newPixelData->push_back(newVal);
        }
    }

    image->setPixelData(newPixelData);
}