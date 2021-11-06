//
// Created by Carlos Arbizu on 10/29/21.
//

#ifndef CPP_CAMERA_H
#define CPP_CAMERA_H
#include "Ray.h"

class Camera {
public:
    Camera();
    Ray get_Ray(double u,double v) const;
private:
    point3 lowerLefthandCorner;
    point3 origin;
    Vec3 horizontalVec;
    Vec3 verticalVec;

};


#endif //CPP_CAMERA_H
