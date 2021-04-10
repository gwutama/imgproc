#include "downsampling.h"
#include <iostream>

void Downsampling::apply8bit(std::shared_ptr<Image> &image)
{
    if (mNewSize.width == 0 || mNewSize.height == 0) {
        return;
    }

    auto imgRes = image->getResolution();

    if (imgRes.width <= mNewSize.width || imgRes.height <= mNewSize.height) {
        return;
    }

    auto newRes = calculateClosestResolution(imgRes, mNewSize);
    auto imgWidthRatio = float(imgRes.width) / float(newRes.width);
    auto imgHeightRatio = float(imgRes.height) / float(newRes.height);
    auto maskWidth = static_cast<uint8_t>(ceil(imgWidthRatio));
    auto maskHeight = static_cast<uint8_t>(ceil(imgHeightRatio));
    auto maskRes = maskWidth * maskHeight;
    auto newPixelData = std::shared_ptr<ByteArray>(new ByteArray);

    for (int32_t y = 0; y < newRes.height; y++) {
        for (int32_t x = 0; x < newRes.width; x++) {
            auto xOrigImage = static_cast<int32_t>(round(imgWidthRatio * x));
            auto yOrigImage = static_cast<int32_t>(round(imgHeightRatio * y));
            auto sum = 0;

            for (int i = 0; i < maskHeight; i++) {
                for (int j = 0; j < maskWidth; j++) {
                    auto xClamp = std::clamp(xOrigImage + j, 0, imgRes.width - 1);
                    auto yClamp = std::clamp(yOrigImage + i, 0, imgRes.height - 1);
                    sum = sum + *(image->pixel8bit({xClamp, yClamp}));
                }
            }

            auto avg = static_cast<uint8_t>(round(float(sum) / float(maskRes)));
            newPixelData->push_back(avg);
        }
    }

    image->setResolution(newRes);
    image->setPixelData(newPixelData);
}

Size Downsampling::calculateClosestResolution(Size imageSize, Size desiredSize)
{
    auto widthRatio = float(desiredSize.width) / float(imageSize.width);
    auto heightRatio = float(desiredSize.height) / float(imageSize.height);
    int32_t newHeight = desiredSize.height;
    int32_t newWidth = desiredSize.width;

    if (widthRatio > heightRatio) {
        newHeight = widthRatio * imageSize.height;
    }
    else {
        newWidth = heightRatio * imageSize.width;
    }

    return Size{newWidth, newHeight};
}