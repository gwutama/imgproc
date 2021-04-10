#include "noise.h"
#include <random>

void Noise::apply8bit(std::shared_ptr<Image> &image)
{
    mProbability = std::clamp<uint8_t>(mProbability, 0, 99);
    std::default_random_engine generator;
    std::uniform_int_distribution<uint8_t> chance(0, 99);
    std::uniform_int_distribution<uint8_t> shade(0, 255);

    for (int32_t y = 0; y < image->getResolution().height; y++) {
        for (int32_t x = 0; x < image->getResolution().width; x++) {
            auto randChance = chance(generator);

            if (randChance < mProbability) {
                auto randShade = shade(generator);
                image->setPixel({x, y}, randShade);
            }
        }
    }
}
