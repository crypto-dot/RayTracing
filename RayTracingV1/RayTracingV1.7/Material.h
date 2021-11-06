//
// Created by Carlos Arbizu on 11/2/21.
//

#ifndef CPP_MATERIAL_H
#define CPP_MATERIAL_H
#include "RayTracingV1.h"
#include "Ray.h"

struct hit_record;
class Material{
public:
    virtual bool scatter(const Ray& r_in, const hit_record &rec, color &attentuation, Ray &scattered) const =0;
    virtual ~Material() =default;
};
#endif //CPP_MATERIAL_H
