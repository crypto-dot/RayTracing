//
// Created by Carlos Arbizu on 10/29/21.
//

//Using anti-aliasing and custom camera class
#include "Camera.h"
#include "Sphere.h"
#include "RayTracingV1.h"
#include "Color.h"
#include "HittableList.h"

color ray_color(const Ray &r,const Hittable &world){
    hit_record rec;

    if(world.hit(r,0,infinity,rec)){
        return 0.5 * (rec.normal + color(1,1,1));
    }

    Vec3 unit_dir = unit(r.getDir());
    double t = 0.5 * (unit_dir.y() + 1.0);
    return (t) * color(1,1,1) + (1 - t) * color(.5,.7,1);
}
int main(){

    //Image
    double aspectRatio{16.0 / 9.0};
    const uint16_t imageWidth {400};
    auto imageHeight{static_cast<int16_t>(imageWidth / aspectRatio)};
    const int samples_per_pixel{100};
    //Camera
    Camera cam{};

    //World
    HittableList world;
    world.add(std::make_shared<Sphere>(point3(0,0,-1),0.5));
   world.add(std::make_shared<Sphere>(point3(0,-100.5,-1),100));
    //Render
    std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
    for(int16_t j {static_cast<int16_t>(imageHeight-1)}; j >=0; j-- ){
        std::cerr << "\rScan Lines Remaining: " << j << ' ' << std::flush;
        for(uint16_t i {0}; i < imageWidth; i++){
            color pixel (0,0,0);
            for(size_t s {0}; s < samples_per_pixel; s++){
                double u { (i + randomDouble()) / (imageWidth-1) };
                double v { (j + randomDouble()) / (imageHeight-1) };
                Ray r = cam.get_Ray(u,v);
                pixel += ray_color(r,world);
            }
            writeColor(std::cout,pixel, samples_per_pixel);
        }
    }
    std::cerr << "\nFinished.\n";




    return 0;
}