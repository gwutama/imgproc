#pragma once

#include "algorithm.h"

class Rotate final: public Algorithm
{
public:
    enum class Direction
    {
        ROTATE_NONE = 0,
        ROTATE_90_CW,
        ROTATE_180,
        ROTATE_90_CCW
    };

    void setDirection(Direction direction)
    {
        mDirection = direction;
    }

    void apply8bit(std::shared_ptr<Image> &image) override;

private:
    double directionToRadian(Direction direction);

private:
    Direction mDirection = Direction::ROTATE_NONE;
};
