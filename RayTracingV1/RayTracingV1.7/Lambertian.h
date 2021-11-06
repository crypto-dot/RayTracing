//
// Created by Carlos Arbizu on 11/2/21.
//

#ifndef CPP_LAMBERTIAN_H
#define CPP_LAMBERTIAN_H
#include "RayTracingV1.h"
#include "Material.h"
#include "Hittable.h"

class Lambertian : public Material {
public:
    Lambertian(const color &a);
    bool scatter(const Ray &r_in,const hit_record &rec,color &attentuation,Ray &scattered) const override;
private:
    color albedo;
};


#endif //CPP_LAMBERTIAN_H
