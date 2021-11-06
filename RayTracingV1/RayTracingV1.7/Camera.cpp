//
// Created by Carlos Arbizu on 10/29/21.
//

#include "Camera.h"

Camera::Camera() {
    double aspectRatio= 16.0/9.0;
    double viewportHeight = 2.0;
    double viewportWidth = viewportHeight * aspectRatio;
    double focalLength = 1.0;

    origin = {0,0,0};
    horizontalVec = {viewportWidth,0,0};
    verticalVec = {0,viewportHeight,0};
    lowerLefthandCorner = {origin - (horizontalVec/2) - (verticalVec/2) - Vec3(0,0,focalLength)};

}

Ray Camera::get_Ray(double u, double v) const {
    return {origin,lowerLefthandCorner + (u * horizontalVec) + (v * verticalVec) - origin};

}