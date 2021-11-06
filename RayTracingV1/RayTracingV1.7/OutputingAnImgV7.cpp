//
// Created by Carlos Arbizu on 11/2/21.
//
#include "Camera.h"
#include "Ray.h"
#include "HittableList.h"
#include "Color.h"
#include "RayTracingV1.h"
#include "Vec3.h"
#include "Sphere.h"
#include "Lambertian.h"
#include "Metal.h"
color ray_color(const Ray &ray,const Hittable &world,int max_hits){
    hit_record rec;
    if(max_hits <= 0){
        return {0,0,0};
    }
    if(world.hit(ray,0.001,infinity,rec)){
        Ray scattered;
        color attentuation;
        if(rec.mat_ptr->scatter(ray,rec,attentuation,scattered)){
            //If the rays scattered when they hit the material return a recursive call to the ray_color function using the scattered ray as an arg
            return attentuation * ray_color(scattered,world,max_hits-1);
        }
        return {0,0,0};
    }
    Vec3 unit_direction = unit(ray.getDir());
    double t = 0.5 * (unit_direction.y() + 1);
    return (1 - t) * color(1,1,1) + t * color(0.5,0.7,1);

}
int main(){
    const double aspectRatio {16.0/9.0};
    const uint16_t imageWidth {400};
    const int16_t imageHeight {static_cast<int16_t> (imageWidth/aspectRatio)};
    const int max_hits {100};
    const int samples_perPixels{400};

    //Camera
    Camera camera{};

    //World
    HittableList world {};
    auto material_ground = std::make_shared<Lambertian>(color(0.8,0.8,0.0));
    auto material_center_sphere = std::make_shared<Lambertian>(color(0.7,0.3,0.3));
    auto material_left_sphere = std::make_shared<Metal>(color(0.8,0.8,0.7),0);
    auto material_right_sphere = std::make_shared<Metal>(color(0.8,0.6,0.4),0.5);
    world.add(std::make_shared<Sphere>(point3(0,0,-1),0.5,material_center_sphere));
    world.add(std::make_shared<Sphere>(point3(-1,0,-1),0.5,material_left_sphere));
    world.add(std::make_shared<Sphere>(point3(0,-100.5,-1),-100,material_ground));
    world.add(std::make_shared<Sphere>(point3(1,0,-1),0.5,material_right_sphere));

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
    for(int16_t j {static_cast<int16_t>(imageHeight-1)};j >=0; j--){
        std::cerr << "\rRemaining Lines: " << j << ' ' << std::flush;
        for(uint16_t i {0}; i < imageWidth; i++) {
            color pixel(0, 0, 0);
            for (size_t s{0}; s < samples_perPixels; s++) {
                double u { (i + randomDouble())/ (imageWidth - 1) };
                double v { ( j + randomDouble() ) / (imageHeight - 1)};
                Ray r = camera.get_Ray(u,v);
                pixel += ray_color(r,world,max_hits);
            }
            writeColor(std::cout,pixel,samples_perPixels);
        }
    }

    return 0;
}