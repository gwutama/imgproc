#include "binarize.h"

void Binarize::apply8bit(std::shared_ptr<Image> &image)
{
    auto size = image->pixelData()->size();

    for (int32_t i = 0; i < size; i++) {
        auto val = image->pixelData()->at(i);

        if (val > mThreshold) {
            val = 255;
        }
        else if (val < mThreshold) {
            val = 0;
        }

        image->pixelData()->at(i) = val;
    }
}