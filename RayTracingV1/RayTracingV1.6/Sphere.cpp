//
// Created by Carlos Arbizu on 10/25/21.
//

#include "Sphere.h"

bool Sphere::hit(const Ray &r, double t_min,double t_max,hit_record &rec) const{
    auto oc  {r.getorig() - center};
    auto a  {r.getDir().lengthSquared()};
    auto half_b  { dot(r.getDir(),oc) };
    auto c { dot(oc, oc) - radius * radius};
    auto discriminate  {half_b * half_b - (a * c)};
    if(discriminate < 0) {
        return false;
    }
    auto sqrtd{sqrt(discriminate)};

    //Find the nearest root that lies in the acceptable range.
    auto root {(-half_b - sqrtd)/a};
    if(root < t_min || root > t_max){
        root = (-half_b + sqrtd)/a;
        //If none found return false
        if(root < t_min || root > t_max){
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    Vec3 outwardNormal =(rec.p - center) / radius;
    rec.set_face_normal(r,outwardNormal);

    return true;
}
Sphere::Sphere(const point3 &center,double radius) : center{center},radius{radius} {

}
double Sphere::getRadius() {
    return radius;
}

point3 Sphere::getCenter() {
    return center;
}