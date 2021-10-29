//
// Created by Carlos Arbizu on 10/25/21.
//
#include "Vec3.h"
#include "Ray.h"
#include "Color.h"
#include "HittableList.h"
#include "Sphere.h"
#include "RayTracingV1.h"

#include <iostream>
color ray_color(const Ray &r, const Hittable &world){
    hit_record rec;
    if(world.hit(r,0,infinity,rec)){
        return 0.5 * (rec.normal + color(1,1,1));
    }
    Vec3 unit_direction = unit(r.getDir());
    double t = 0.5 * (unit_direction.y() + 1);
    return (1-t) * color(1,1,1) + t * color(0.5,0.7,1);

}
int main(){
    //Image
    const double aspectRatio {16.0/9.0};
    const uint16_t imageWidth {400};
    const int16_t imageHeight {static_cast<int16_t>(imageWidth/aspectRatio)};

    //world
    HittableList world;
    //Small sphere
    world.add(std::make_shared<Sphere>(point3(0,0,-1),0.5));
    //Large sphere in the background
    world.add(std::make_shared<Sphere>(point3(0,-100.5,-1),100));


    //Camera
    double viewportHeight {2.0};
    double viewportWidth{viewportHeight * aspectRatio};
    double focalLength = 1.0;

    point3 origin {0,0,0};
    Vec3 horizontal {viewportWidth,0,0};
    Vec3 vertical {0,viewportHeight,0};
    Vec3 focalLengthVec3 {0,0,focalLength};
    point3 lowerLeftHandCorner {origin - horizontal/2 - vertical/2 - focalLengthVec3};

    cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
    for(int16_t j {static_cast<int16_t>(imageHeight - 1)}; j >= 0; j--){
        std::cerr << "\rScan Lines Remaining " << j << " " << std::flush;
        for(uint16_t i {0}; i < imageWidth; i++){
            double u {static_cast<double>(j)/(imageHeight-1)};
            double v {static_cast<double>(i)/(imageWidth-1)};
            Ray r {origin,lowerLeftHandCorner + (u * vertical) + (v * horizontal) - origin};
            color pixel = ray_color(r,world);
            writeColor(std::cout,pixel);
        }
    }


    return 0;
}