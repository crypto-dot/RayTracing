//
// Created by Carlos Arbizu on 10/28/21.
//

#ifndef CPP_RAYTRACINGV1_H
#define CPP_RAYTRACINGV1_H
#include <cmath>
#include <limits>
#include <memory>
#include "Vec3.h"
#include "Ray.h"
#include <random>

//Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
double randomDouble(){
    std::random_device rd;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    std::mt19937 mtgenerator(rd);
    return distribution(mtgenerator);
}
double degrees_to_radians(double degrees){
    return degrees * pi/180;
}
#endif //CPP_RAYTRACINGV1_H
