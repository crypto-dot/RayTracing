//
// Created by Carlos Arbizu on 10/28/21.
//

#ifndef CPP_RAYTRACINGV1_H
#define CPP_RAYTRACINGV1_H
#include <cmath>
#include <limits>
#include <memory>
#include "Vec3.h"
#include <random>

//Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
//Below is an alternative way of generating random values
//It is much faster, but suffers from a lack of randomness
/*inline double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}
inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}*/
static inline double randomDouble(double min = 0.0,double max =1.0){
    std::uniform_real_distribution<double> distribution(min,max);
    std::mt19937_64 mtgenerator{};
    return distribution(mtgenerator);
}
static inline double clamp(double x,double min,double max){
    if(x < min){
        return min;
    }
    if(x > max){
        return max;
    }
    return x;
}
static inline double degrees_to_radians(double degrees){
    return degrees * pi/180;
}
#endif //CPP_RAYTRACINGV1_H
