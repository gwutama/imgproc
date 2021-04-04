#include "gsimageadapterbase.h"

uint8_t *GsImageAdapterBase::at(Coordinate coord)
{
    auto res = resolution();

    if (coord.x >= res.width || coord.y >= res.height) {
        return nullptr;
    }

    auto pos = coordinateToVectorIndex(coord, res);
    auto pixel = &(pixelData()->at(pos));
    return pixel;
}

std::vector<GsFilterWindow> GsImageAdapterBase::calculateFilterWindows(const Size &windowSize)
{
    auto imgWidth = resolution().width;
    auto imgHeight = resolution().height;
    auto windows = std::vector<GsFilterWindow>();

    for (uint32_t y = 0; y < imgHeight; y += windowSize.height) {
        for (uint32_t x = 0; x < imgWidth; x += windowSize.width) {
            auto window = calculateFilterWindow({x, y}, windowSize);
            windows.push_back(window);
        }
    }

    return windows;
}

GsFilterWindow GsImageAdapterBase::calculateFilterWindow(const Coordinate &topLeftPixel,
                                                       const Size &windowSize)
{
    GsFilterWindow window;

    for (uint32_t y = topLeftPixel.y; y < (topLeftPixel.y + windowSize.height); y++) {
        for (uint32_t x = topLeftPixel.x; x < (topLeftPixel.x + windowSize.width); x++) {
            auto pixelRef = at({x, y});
            window.addPixelRef(pixelRef);
        }
    }

    return window;
}