//
// Created by Carlos Arbizu on 9/15/21.
//

#ifndef CPP_VEC3_H
#define CPP_VEC3_H

#include <iostream>
#include <cmath>
#include "RayTracingV1.h"
using std::sqrt;
using std::ostream;
using std::cout;

class Vec3 {
public:
    Vec3()=default;
    Vec3(double e,double e2,double e3) : arr{e,e2,e3} {}


    //funcs
    double x() const;
    double y() const;
    double z() const;
    double lengthSquared() const;
    double length() const;


    // Why are we finding a random point in a unit cube?
    // To help us generate random points in a unit sphere we will use a rejection method that involves getting random values
    // for x,y,z (if the points do not fall within the unit sphere they are rejected)
    // Why are we finding points in a unit sphere?
    // We need to find points in a unit sphere to properly diffuse surfaces (aka make light bounce off in random directions
    // for more realistic materials) in order to do that we need to find a tangent unit sphere to a point p (where the ray hits)
    // such that there is a point s that will be intersected by a random ray. The center of this sphere will be p + n (or p - n for
    // a unit sphere WITHIN the surface) also note that the magnitude of normalized vectors is always 1 insuring that the radius of the sphere is 1,
    // (the point p on the surface moved up (or down) by the surface normal)







    friend Vec3 operator*(const Vec3 &lhs,const Vec3 &rhs);
    friend Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs);
    friend Vec3 operator*(const Vec3 &vec,double scalar);
    friend Vec3 operator*(double scalar, const Vec3 &vec3);
    friend Vec3 operator+(const Vec3 &vec,double scalar);
    friend Vec3 operator+(double scalar,const Vec3 &vec);
    friend Vec3 operator-(const Vec3 &lhs,const Vec3 &rhs);
    friend ostream &operator<<(ostream &ostream1, const Vec3 &vec3);

    Vec3 operator-() const;
    Vec3 operator/(double scalar) const;

    Vec3 &operator+=(const Vec3 &rhs);
    Vec3 &operator/=(double scalar);
    Vec3 &operator*=(double scalar);
private:
    double arr[3];
};

//Some aliases for the class
using point3 = Vec3;
using color = Vec3;

static inline Vec3 random(double min = 0,double max =0){
    return {randomDouble(min,max), randomDouble(min,max), randomDouble(min,max)};
}
static inline Vec3 random_in_unit_sphere(){
    auto p { random(-1.0,1.0) };
    while(p.lengthSquared() >= 1) {
        p = random(-1.0,1.0);
    }
    return p;
}
static inline Vec3 cross(const Vec3 &vec, const Vec3 &vec2) {
    double i {( vec.y() * vec2.z() )- ( vec.z() * vec2.y() )};
    double j {( vec.x() * vec2.z() ) - (vec2.x() * vec.z()) };
    double k {( vec.x() * vec2.y()) - (vec2.x() * vec.y())};
    return {i,-j,k};
}
static inline double dot(const Vec3 &vec, const Vec3 &vec2) {
    return ( vec.x() * vec2.x() ) + ( vec.y() * vec2.y() ) + ( vec.z() * vec2.z() );
}

static inline Vec3 unit(const Vec3 &vec) {
    return (vec/vec.length());
}

#endif //CPP_VEC3_H
