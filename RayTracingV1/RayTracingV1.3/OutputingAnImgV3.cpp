//
// Created by Carlos Arbizu on 10/23/21.
//
#include "Ray.h"
#include "Vec3.h"
#include "Color.h"

double hit_sphere(const Ray &r,const point3 &center,const double &radius){
    Vec3 oc {r.getorig() - center};
    auto a {dot(r.getDir(),r.getDir())};
    auto half_b {dot(r.getDir(),oc)};
    auto c {dot(oc,oc) - radius * radius};
    auto discriminate {(half_b * half_b) - (a * c)};
    if(discriminate < 0){
        return -1;
    }
    else {
        //Since the sphere is hard coded in front of the camera we are choosing the smallest t aka closest hit point
        return (-half_b - sqrt(discriminate) )/(a);
    }
}
color write_Ray(const Ray &r){
    //Here we are creating colored normal vectors on the sphere
    //We are not concerned with negative values of T since we have 1 sphere directly in front off the camera
    auto t  {hit_sphere(r,point3(0,0,-1),0.5)};
    if(t > 0.0){
        //Remember a surface normal vector on a sphere is a point on the sphere minus the center
        Vec3 N {unit(r.at(t) - Vec3(0,0,-1))};
        //Here we make sure our normalized vector ranges from 0 to 1 instead of -1 to 1 to color code the vectors with rgb values
        return 0.5 * color{N.x() + 1,N.y() + 1, N.z() + 1};
    }
    Vec3 unitVec {unit(r.getDir())};
    t = 0.5 * (unitVec.y() + 1);
    return (t) * color(1,1,1) + (1 - t) * color(.5,0.7,1.0);
}
int main(){
    double aspectRatio = 16.0/9;
    const uint16_t imageWidth = 600;
    const auto imageHeight = static_cast<int16_t>(imageWidth/aspectRatio);

    const double viewportHeight = 2.0;
    const double viewportWidth = viewportHeight * aspectRatio;
    const double focalLength = 1;

    point3 origin{0, 0, 0};
    auto horizontalVector {Vec3(viewportWidth,0,0)};
    auto verticalVector {Vec3(0,viewportHeight,0)};
    auto focalLengthVec {Vec3(0,0,focalLength)};
    point3 lowerleftHandCorner {origin - (horizontalVector/2) - (verticalVector/2) - focalLengthVec};

    cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    for(int16_t j{static_cast<int16_t>(imageHeight - 1)}; j >= 0;j--){
        std::cerr << "\rLines remaining: " << j << " " << std::flush;
        for(uint16_t i {0}; i < imageWidth; i++){
            auto u = static_cast<double>(i)/(imageWidth-1);
            auto v = static_cast<double>(j)/(imageHeight-1);
            Ray r{origin,(lowerleftHandCorner + (u * horizontalVector) + (v * verticalVector)) - origin};
            color pixel { write_Ray(r) };
            writeColor(std::cout, pixel);
        }
    }
    std::cerr << "\nFinished.\n";
    return 0;
}