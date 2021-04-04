#include "uninegative.h"

void UniNegative::apply(std::shared_ptr<GsImageAdapterBase> &image)
{
    auto size = image->pixelData()->size();

    for (int i = 0; i < size; i++) {
        auto val = 255 - image->pixelData()->at(i);
        image->pixelData()->at(i) = val;
    }
}