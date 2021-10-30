//
// Created by Carlos Arbizu on 9/15/21.
//

#include "Vec3.h"


Vec3 operator*(const Vec3 &lhs, const Vec3 &rhs) {
    return {lhs.x() * rhs.x(),lhs.y() * rhs.y(),lhs.z() * rhs.z()};
}

Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs) {
    return {lhs.x() + rhs.x(),lhs.y() + rhs.y(), lhs.z() + rhs.z()};
}

Vec3 operator*(const Vec3 &vec, double scalar) {
    return {vec.x() * scalar,vec.y() * scalar,vec.z() * scalar};
}

Vec3 operator+(const Vec3 &vec, double scalar) {
    return {vec.x() + scalar,vec.y() + scalar,vec.z() + scalar};
}

Vec3 operator+(double scalar,const Vec3 &vec){
    return vec + scalar;
}


Vec3 &Vec3::operator+=(const Vec3 &rhs) {
    arr[0] += rhs.x();
    arr[1] += rhs.y();
    arr[2] += rhs.z();
    return *this;
}

Vec3 &Vec3::operator/=(double scalar) {
    *this *= (1/scalar);
    return *this;
}

Vec3 &Vec3::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

double Vec3::z() const{
    return arr[2];
}

double Vec3::y() const{
    return arr[1];
}

double Vec3::x() const{
    return arr[0];
}

Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs) {
    return {lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z()};
}

Vec3 Vec3::operator/(double scalar) const{
    return *this * (1/scalar);
}

ostream &operator<<(ostream &ostream1, const Vec3 &vec3) {
    ostream1 << "[ ";
    for(size_t i {0}; i < 3; i++){
        ostream1 << vec3.arr[i] << " ";
    }
    ostream1 << "] ";
    return ostream1;
}


double Vec3::lengthSquared() const {
    return (arr[0] * arr[0]) + (arr[1] * arr[1]) + (arr[2] * arr[2]);
}

double Vec3::length() const {
    return sqrt(lengthSquared());
}

Vec3 operator*(double scalar, const Vec3 &vec3){
    return vec3 * scalar;
}



Vec3 Vec3::operator-() const{
    return (*this * -1);
}



