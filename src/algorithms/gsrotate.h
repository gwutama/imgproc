#pragma once

#include "algorithmbase.h"

class GsRotate final: public AlgorithmBase
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

    void apply(std::shared_ptr<GsImageAdapterBase> &image) override;

private:
    double directionToRadian(Direction direction);

private:
    Direction mDirection = Direction::ROTATE_NONE;
};
