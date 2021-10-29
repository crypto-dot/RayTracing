//
// Created by Carlos Arbizu on 10/25/21.
//

#ifndef CPP_SPHERE_H
#define CPP_SPHERE_H
#include "Vec3.h"
#include "Hittable.h"
#include "Ray.h"

class Sphere : public Hittable {
public:
    Sphere() =default;
    Sphere(const point3 &center,double radius);
    point3 getCenter();
    double getRadius();
    bool hit(const Ray &r,double t_min,double t_max,hit_record &rec) const override;
private:
    point3 center;
    double radius;


};


#endif //CPP_SPHERE_H
