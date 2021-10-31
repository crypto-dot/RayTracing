//
// Created by Carlos Arbizu on 10/30/21.
//
#include "Ray.h"
#include "Vec3.h"
#include "Sphere.h"
#include "HittableList.h"
#include "Color.h"
#include "RayTracingV1.h"
#include "Camera.h"

color ray_color(const Ray &ray,const Hittable &world,int maxHits){
    hit_record rec;
    if(maxHits <= 0){
        return {0,0,0};
    }
    //t min is 0.001 to get rid of shadow acne since rays are not reflecting off at exactly t = 0 but t = 0.0000001 or t = -0.0000001 or
    //the closest floating point approximation the sphere intersector gives us. Doing this ignores hits very near 0

    if(world.hit(ray,0.001,infinity,rec)){
        point3 target {rec.p + random_in_hemisphere(rec.normal)};
        return 0.5 * ray_color(Ray(rec.p,target-rec.p),world,maxHits -1);
    }

    Vec3 unit_direction = unit(ray.getDir());
    double t = 0.5 * (unit_direction.y() + 1 );
    return t * color(1,1,1) + (1-t) * color(0.5,0.7,1);
}

int main(){
    //Image
    const double aspectRatio {16.0/9.0};
    const uint16_t image_width{600};
    const int16_t image_height {static_cast<int16_t>(image_width/aspectRatio)};
    const int samples_per_pixels{400};
    int maxHits {100};
    //Camera
    Camera cam{};

    //World
    HittableList world{};
    world.add(std::make_shared<Sphere>(point3{0,0,-1},0.5));
    world.add(std::make_shared<Sphere>(point3(0,-100.5,-1),-100));
    //Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for(int16_t j {static_cast<int16_t>(image_height - 1)}; j >= 0; j--){
        std::cerr<< "\rScan Lines Remaining: " << j << ' ' << std::flush;
        for(uint16_t i{0}; i < image_width; i++){
            color pixel(0,0,0);
            for(size_t s {0}; s < samples_per_pixels; s++) {
                double u = {(i + randomDouble()) / (image_width - 1)};
                double v = {(j + randomDouble()) / (image_height - 1)};
                Ray r{cam.get_Ray(u, v)};
                pixel += ray_color(r, world,maxHits);
            }
            //write the color avging the values from the samples taken for each pixel
            writeColor(std::cout,pixel,samples_per_pixels);
        }
    }



    return 0;
}