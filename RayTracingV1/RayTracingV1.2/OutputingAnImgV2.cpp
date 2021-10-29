//
// Created by Carlos Arbizu on 9/15/21.
//
#include "Vec3.h"
#include "Ray.h"
#include "Color.h"
color Ray_Color(Ray &r){
    Vec3 unit_vec = unit(r.getDir());
    double t = 0.5 * (unit_vec.y() + 1);
    return  t * color(1,1,1) + (1- t) * color(.5,.3,1);
}

int main(){
    //Image
    constexpr double aspect_ratio {16.0/9};
    const uint16_t imageWidth = 400;
    const auto imageHeight = static_cast<uint16_t>(imageWidth/aspect_ratio);
    //Camera
    point3 origin{0,0,0};
    double viewportHeight {2.0};
    double viewportWidth {viewportHeight * aspect_ratio};
    double focal_length{1};

    Vec3 verticalVec {Vec3(0,viewportHeight,0)};
    Vec3 horizontalVec{Vec3(viewportWidth,0,0)};
    Vec3 focalLengthVec {Vec3(0,0,focal_length)};
    point3 lower_left_hand_corner {origin - (horizontalVec/2) - (verticalVec/2) - focalLengthVec};

    cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
    for(int16_t j {imageHeight - 1}; j >=0; j--){
        std::cerr << "\rScan Lines remaining: " << j << " " << std::flush;
        for(uint16_t i {0}; i < imageWidth; i++){
            double u = double(j)/(imageHeight-1);
            double v = double(i)/(imageWidth-1);
            Ray r(origin,lower_left_hand_corner + (u*verticalVec) + (v * horizontalVec) -origin);
            color pixel {Ray_Color(r) };
            writeColor(std::cout, pixel);
        }

    }
    std::cerr << "\nFinished.\n";
    return 0;
}