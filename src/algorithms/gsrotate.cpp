#include "gsrotate.h"
#include <algorithm>

void GsRotate::apply(std::shared_ptr<GsImageAdapterBase> &image)
{
    auto res = image->resolution();
    auto h = res.height;
    auto w = res.width;

    auto x0 = round(w / 2) - 1;
    auto y0 = round(h / 2) - 1;
    auto radian = directionToRadian(mDirection);
    auto cosTheta = round(cos(radian));
    auto sinTheta = round(sin(radian));

    auto imageCp = image->pixelDataCopy();

    for (uint32_t y = 0; y < h; y++) {
        for (uint32_t x = 0; x < w; x++) {
            uint32_t x2 = cosTheta * (x - x0) + sinTheta * (y - y0) + x0;
            uint32_t y2 = -1 * sinTheta * (x - x0) + cosTheta * (y - y0) + y0;
            auto pos = coordinateToVectorIndex({x, y}, res);
            auto val = imageCp->at(pos);
            auto pixelRef = image->at({x2, y2});

            if (pixelRef != nullptr) {
                *pixelRef = val;
            }
        }
    }
}

double GsRotate::directionToRadian(Direction direction)
{
    auto degree = 0.0;

    switch (direction) {
        case Direction::ROTATE_180:
            degree = 180;
            break;
        case Direction::ROTATE_90_CW:
            degree = 90;
            break;
        case Direction::ROTATE_90_CCW:
            degree = -90;
            break;
        case Direction::ROTATE_NONE:
        default:
            break;
    }

    auto radian = degreeToRadian(degree);
    return radian;
}