#include "stripes.h"

// directions - left right up diag-left diag-right

Stripes::Stripes(int numStripes){
    _numStripes = numStripes;
}

Pixel Stripes::Generate(int x, int y){
    Pixel pixel;
    pixel.Red = (x) * (_numStripes);
    pixel.Green = 0;
    pixel.Blue = 0;
    return pixel;
}
