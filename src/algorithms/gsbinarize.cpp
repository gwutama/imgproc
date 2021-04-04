#include "gsbinarize.h"

void GsBinarize::apply(std::shared_ptr<GsImageAdapterBase> &image)
{
    auto size = image->pixelData()->size();

    for (int i = 0; i < size; i++) {
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