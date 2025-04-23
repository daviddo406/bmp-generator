#include "EasyBMP.h"
#include "opencv2/opencv.hpp"

#include "pixel.h"
#include "pixel-generator.h"
#include "stripes.h"

#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <vector>

static int IMAGE_COUNT = 0;

int create(int width, int height, PixelGenerator* generator)
{
    BMP myImage;
    myImage.SetSize(width, height);

    Pixel pixel;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            pixel = generator->Generate(x, y);
            myImage(x, y)->Red = pixel.Red;
            myImage(x, y)->Green = pixel.Green;
            myImage(x, y)->Blue = pixel.Blue;
        }
    }
    
    std::string filename = std::format("out/image-{}.bmp", IMAGE_COUNT++);
    myImage.WriteToFile(filename.c_str());

    return 0;
}

int main(int argc, char* argv[])
{   
    if (argc != 3)
    {
        std::cout << "Error: 3 arguments required, " << argc << " given" << std::endl;
        return 1;
    }

    int IN_WIDTH  = atoi(argv[1]);
    int IN_LENGTH   = atoi(argv[2]);

    // TODO: Create interface to construct many types of PixelGenerators with their unique parameters.
    PixelGenerator* generator = new Stripes(6);
    create(IN_WIDTH, IN_LENGTH, generator);
    return 0;
}