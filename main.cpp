#include <iostream>
#include <fstream>

#include <sstream>

int main() {

    std::ifstream image;
    std::ofstream newimage;

    image.open("bird2.ppm");
    newimage.open("Monument.ppm");

    // copy over header info
    std::string type = "", width = "", height = "", RGB = "";
    image >> type;
    image >> width;
    image >> height;
    image >> RGB;

    newimage << type << std::endl;
    newimage << width << " " << height << std::endl;
    newimage << RGB << std::endl;
    
    std::string red = "", green = "", blue = "";
    int r = 0, g = 0, b = 0;
    while(!image.eof()){
        image >> red;
        image >> green;
        image >> blue;

        std::stringstream redstream(red);
        std::stringstream greenstream(green);
        std::stringstream bluestream(blue);
        redstream >> r;
        greenstream >> g;
        bluestream >> b;

        b = std::min(b + 100, 255);

        newimage << r << " " << g << " " << b << std::endl;
    }


    image.close();
    newimage.close();

    return 0;
}