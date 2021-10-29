//
// Created by Carlos Arbizu on 10/25/21.
//

#ifndef CPP_HITTABLE_H
#define CPP_HITTABLE_H
#include "Ray.h"
struct hit_record{
    Vec3 normal;
    double t;
    point3 p;
    bool frontFace;
    //Here we want to see where our rays are hitting the figure
    //If our rays are hitting the figure from within then the dot product of are ray and normal would be positive
    // else negative (Our normals are currently set up to point outward from surfaces on objects)
    inline void set_face_normal(const Ray& r,const Vec3& outwardNormal){
        frontFace = dot(r.getDir(),outwardNormal) < 0;
         normal = frontFace ? outwardNormal : -outwardNormal;
    }
};
class Hittable{
public:
    virtual bool hit(const Ray &r,double t_min,double t_max, hit_record& rec) const = 0;
    virtual ~Hittable() = default;
};
#endif //CPP_HITTABLE_H
