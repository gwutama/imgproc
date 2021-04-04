#include "unibrightnessadjustment.h"

void UniBrightnessAdjustment::apply(std::shared_ptr<GsImageAdapterBase> &image)
{
    auto size = image->pixelData()->size();

    for (int i = 0; i < size; i++) {
        uint8_t val = std::clamp(image->pixelData()->at(i) + mValue, 0, 255);
        image->pixelData()->at(i) = val;
    }
}