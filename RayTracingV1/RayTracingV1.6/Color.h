//
// Created by Carlos on 8/29/2021.
//

#ifndef COLOR_H
#define COLOR_H
#include "Vec3.h"
#include "RayTracingV1.h"
void writeColor(ostream &ostream,const color &pixel_color,const int &samples_per_pixel){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    double scale = 1.0/samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    ostream << static_cast<uint16_t>(256 * clamp(r,0.0,0.999)) << ' '
    << static_cast<uint16_t>(256 * clamp(g,0.0,0.999)) << ' '
    << static_cast<uint16_t>(256 * clamp(b,0.0,0.999)) << '\n';
}

#endif// COLOR_H
