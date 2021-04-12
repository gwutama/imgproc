#include "drawline.h"

void DrawLine::apply8bit(std::shared_ptr<Image> &image)
{
    // adjust coordinate system
    // x : same
    // y : to standard coordinate
    Coordinate p1{mPointFrom.x, image->getResolution().height - mPointFrom.y};
    Coordinate p2{mPointTo.x, image->getResolution().height - mPointTo.y};
    plot8bit(p1, p2, mColor8bit, image);
}

void DrawLine::plot8bit(Coordinate p1,
                        Coordinate p2,
                        uint8_t color,
                        std::shared_ptr<Image> &image)
{
    const bool steep = (fabs(p2.y - p1.y) > fabs(p2.x - p1.x));
    if (steep) {
        std::swap(p1.x, p1.y);
        std::swap(p2.x, p2.y);
    }

    if (p1.x > p2.x) {
        std::swap(p1.x, p2.x);
        std::swap(p1.y, p2.y);
    }

    const float dx = p2.x - p1.x;
    const float dy = fabs(p2.y - p1.y);

    float error = dx / 2.0f;
    const int ystep = (p1.y < p2.y) ? 1 : -1;
    int y = (int) p1.y;

    const int maxX = (int) p2.x;

    for (int x = (int) p1.x; x <= maxX; x++) {
        if (steep) {
            image->setPixel({y, x}, color);
        }
        else {
            image->setPixel({x, y}, color);
        }

        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}
