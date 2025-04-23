#ifndef PIXEL_GENERATOR_H
#define PIXEL_GENERATOR_H

#include "pixel.h"

class PixelGenerator {
public:
    virtual Pixel Generate(int x, int y) = 0;
};

#endif