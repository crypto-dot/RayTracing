//
// Created by Carlos Arbizu on 11/2/21.
//

#include "Metal.h"

Metal::Metal(const color &a,double f) : albedo{a},fuzz{ f < 1 ? f : 1} {}

bool Metal::scatter(const Ray &ray_in,const hit_record &rec, color &attentuation,Ray &scattered) const {
    auto scatter_direction = reflect(ray_in.getDir(),rec.normal);
    scattered = Ray(rec.p,scatter_direction + ( fuzz * random_in_unit_sphere() ));
    attentuation = albedo;
    return (dot(scattered.getDir(),rec.normal) > 0);
}