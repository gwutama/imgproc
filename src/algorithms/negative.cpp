#include "negative.h"

void Negative::apply8bit(std::shared_ptr<Image> &image)
{
    auto size = image->pixelData()->size();

    for (int32_t i = 0; i < size; i++) {
        auto val = 255 - image->pixelData()->at(i);
        image->pixelData()->at(i) = val;
    }
}