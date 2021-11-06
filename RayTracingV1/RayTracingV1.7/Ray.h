//
// Created by Carlos on 8/30/2021.
//

#ifndef CPP_RAY_H
#define CPP_RAY_H
#include "Vec3.h"

class Ray {
private:
    point3 origin;
    Vec3 direction;
public:
    Ray() = default;
    Ray(const point3 &origin,const Vec3 &direction);
    point3 getorig() const;
    Vec3 getDir() const;
    //function p(t) = a +tb
    Vec3 at(double t) const;
};


#endif //CPP_RAY_H
