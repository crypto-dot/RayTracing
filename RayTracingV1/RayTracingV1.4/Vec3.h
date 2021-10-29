//
// Created by Carlos Arbizu on 9/15/21.
//

#ifndef CPP_VEC3_H
#define CPP_VEC3_H

#include <iostream>
#include <cmath>
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
    friend double dot(const Vec3 &vec,const Vec3 &vec2);
    Vec3 cross(const Vec3 &vec,const Vec3 &vec2);
    Vec3 friend unit(const Vec3 &vec);

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


#endif //CPP_VEC3_H
