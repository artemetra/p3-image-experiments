#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <cstdlib>

int norm_cos(int input){
    //\operatorname{round}\left(\frac{255}{2}\left(\cos\left(20\left(x-180\right)\right)+1\right)\right)
    return int((255/2)*(cos(20*(input - 180))+1));
}

int main() {

    auto MAX_SIZE = std::make_pair(2000, 2000);

    std::ofstream image;

    image.open("image.ppm");

    srand(time(0));

    if(image.is_open()) {
        image << "P3" << std::endl;
        image << MAX_SIZE.first << " " << MAX_SIZE.second << std::endl;
        //image << 250 << " " << 250 << std::endl;
        image << "255" << std::endl;

        for(int y = 0; y < MAX_SIZE.second; y++){
            for(int x = 0; x < MAX_SIZE.first; x++){
                int br = rand() % 255;
                //std::cout << "Printing line " << x << "...." << std::endl;
                image << br << " " << br << " " << br << std::endl;
            }
        }
    }

    image.close();

    return 0;
}