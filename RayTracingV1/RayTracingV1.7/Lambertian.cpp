//
// Created by Carlos Arbizu on 11/2/21.
//

#include "Lambertian.h"

Lambertian::Lambertian(const color &a) : albedo{a} {

}

bool Lambertian::scatter(const Ray &r_in, const hit_record &rec, color &attentuation,Ray &scattered) const{
    auto scatter_direction = rec.normal + random_unitVec();
    //If the random unit vector is exactly opposite the normal vector this can lead to infinities and NaNs
    //The below code prevents this
    if(scatter_direction.near_zero()){
        scatter_direction = rec.normal;
    }
    scattered = Ray(rec.p,scatter_direction);
    attentuation = albedo;
    return true;

}