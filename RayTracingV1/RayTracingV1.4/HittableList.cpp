//
// Created by Carlos Arbizu on 10/28/21.
//
#include "HittableList.h"
bool HittableList::hit(const Ray &r, double t_min, double t_max, hit_record& rec) const{
    hit_record tempRec;
    bool hit_anything {false};
    auto closestRoot{t_max};
    for(const auto &object : objects){
        if(object->hit(r,t_min,closestRoot,tempRec)){
            closestRoot = tempRec.t;
            hit_anything = true;
            //update record
            rec = tempRec;
        }
    }
    return hit_anything;
}