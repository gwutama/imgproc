#include "brightnessadjustment.h"

void BrightnessAdjustment::apply8bit(std::shared_ptr<Image> &image)
{
    auto size = image->pixelData()->size();

    for (int32_t i = 0; i < size; i++) {
        uint8_t val = std::clamp(image->pixelData()->at(i) + mValue, 0, 255);
        image->pixelData()->at(i) = val;
    }
}