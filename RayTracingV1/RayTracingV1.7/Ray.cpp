//
// Created by Carlos on 8/30/2021.
//

//Important NOTE: our ray direction vector is not a unit vector this is to make for simpler code and faster code!!

#include "Ray.h"
Ray::Ray(const point3 &origin, const Vec3 &direction) : origin{origin}, direction{direction} {}
point3 Ray::getorig() const{
    return origin;
}

Vec3 Ray::getDir() const{
    return direction;
}

Vec3 Ray::at(double t) const{
    return origin + direction *t;
}
