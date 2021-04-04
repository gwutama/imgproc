#pragma once

#include <memory>
#include "../image.h"

class Algorithm
{
public:
    virtual void apply8bit(std::shared_ptr<Image> &image) {}
    virtual void apply24bit(std::shared_ptr<Image> &image) {}
};
