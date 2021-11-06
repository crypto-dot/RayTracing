//
// Created by Carlos Arbizu on 11/2/21.
//

#ifndef CPP_METAL_H
#define CPP_METAL_H
#include "RayTracingV1.h"
#include "Material.h"
#include "Hittable.h"
class Metal : public Material {
public:
    Metal(const color &a,double f);
    bool scatter(const Ray &ray_in,const hit_record &rec,color &attentuation, Ray &scattered)const override;
private:
    color albedo;
    double fuzz;
};


#endif //CPP_METAL_H
