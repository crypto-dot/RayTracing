//
// Created by Carlos on 8/25/2021.
//

#include <iostream>
#include "Color.h"
using std::cout;
using std::cerr;

//255 based formula vs 256 base formula:
// https://stackoverflow.com/questions/1914115/converting-color-value-from-float-0-1-to-byte-0-255
int main(){
    const uint16_t imageHeight {256};
    const uint16_t imageWidth {256};
    //PPM file header
    cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    for(int16_t j{imageHeight-1}; j >= 0; j--){
        cerr << "\rScan lines remaining: " << j << " " << std::flush;
        for(uint16_t i{0}; i < imageWidth; i++){
               color pixel(static_cast<double>(i) / (imageWidth - 1), static_cast<double> (j) / (imageHeight -1), .25);
               writeColor(cout,pixel);
        }
    }

    std::cerr << "\n Finished. \n";
    return 0;
}
