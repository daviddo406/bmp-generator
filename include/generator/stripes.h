#ifndef STRIPES_H
#define STRIPES_H

#include "pixel-generator.h"
#include "pixel.h"

class Stripes : public PixelGenerator {
public:
    Stripes(int numStripes);
    Pixel Generate(int x, int y) override;
private:
    int _numStripes; 
};

#endif