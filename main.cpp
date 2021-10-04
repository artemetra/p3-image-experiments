#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <cstdlib>


void writeHeader(std::ofstream& image, uint32_t& width, uint32_t& height, const uint32_t& rgb_max = 255){
    image << "P3" << std::endl;
    image << width << " " << height << std::endl;
    image << rgb_max << std::endl;
}

// template<typename R, typename G, typename B>
// void writePixel(std::ofstream& image, R& red, G& green, B& blue){
//     image << red << " " << green << " " << blue << std::endl;
// }

void writePixel(std::ofstream& image, int& red, int& green, int& blue){
    image << red << " " << green << " " << blue << std::endl;
}

int main() {
    using std::min;
    using std::max;
    std::ofstream image;
    image.open("bruh.ppm");
    unsigned int width = 2000;
    unsigned int height = 2000;
    int rgb_max = 255;
    writeHeader(image, width, height);

    for(int y = 0; y <= height; y++){
        for(int x = 0; x <= width; x++){
            //int b = 128*(int(sin(y)+1));
            //int r = std::min(int((int(abs(sqrt(y)-x)) % (rgb_max)) * int(sin(x/20)+1)), 255);
            int r = min(int(255*min(max(atan(x/20), double(-1)) + 1, double(255))), 255);;
            int g = min(int(255*min(max(tan(x/20), double(-1)) + 1, double(255))), 255);
            int b = min(int(255*min(max(tan(-x/19), double(-6)) + 6, double(255))), 255);;
            //int g = r;
            //int b = r;
            writePixel(image, r, g, b);
        }
    }

    return 0;
}