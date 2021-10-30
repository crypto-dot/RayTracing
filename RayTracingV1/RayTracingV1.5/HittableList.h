//
// Created by Carlos Arbizu on 10/28/21.
//

#ifndef CPP_HITTABLELIST_H
#define CPP_HITTABLELIST_H
#include <memory>
#include <vector>
#include "Hittable.h"
#include "Ray.h"

class HittableList : public Hittable{
public:
    HittableList()=default;
    HittableList(const std::shared_ptr<Hittable> &object) {objects.push_back(object);}
    void add(const std::shared_ptr<Hittable> &object) {objects.push_back(object);}
    bool hit(const Ray &r, double t_min, double t_max, hit_record& rec) const override;
    std::vector<std::shared_ptr<Hittable>> objects;
};
#endif //CPP_HITTABLELIST_H
