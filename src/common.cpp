#include "common.h"

double degreeToRadian(double degree)
{
    auto const pi = 3.14159265;
    auto radian = degree * pi / 180.0;
    return radian;
}
