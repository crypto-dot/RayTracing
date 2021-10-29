//
// Created by Carlos on 8/29/2021.
//

#ifndef COLOR_H
#define COLOR_H
#include "Vec3.h"

void writeColor(ostream &ostream,const color &pixel_color){
    ostream << static_cast<uint16_t>(pixel_color.x() * 255) << " " << static_cast<uint16_t>(pixel_color.y() * 255) << " " << static_cast<uint16_t>(pixel_color.z() * 255) << "\n";
}

#endif// COLOR_H
