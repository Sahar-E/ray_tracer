//
// Created by Sahar on 10/06/2022.
//

#include <HitResult.h>
#include "Sphere.h"

Sphere::Sphere(const Point3 &center, double radius) : _center(center), _radius(radius) {}

bool Sphere::hit(const Ray &ray, double tStart, double tEnd, HitResult &hitRes) const {
    Vec3 oc = ray.origin() - _center;
    auto a = ray.direction().length_squared();
    auto half_b = dot(oc, ray.direction());
    auto c = oc.length_squared() - _radius*_radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) {
        return false;
    }
    auto sqrtD = std::sqrt(discriminant);
    auto root = (-half_b - sqrtD) / a;      // Closer root
    if (root < tStart || root > tEnd) {
        root = (-half_b + sqrtD) / a;       // Farther root
        if (root < tStart || root > tEnd) {
            return false;
        }
    }
    
    // Get color by normal of the hit point:
    Point3 hitPoint = ray.at(root);
    Vec3 normalOfHitPoint = unitVector(hitPoint - _center);

    // Get reflected ray:
    Vec3 dirOfReflection = reflect(ray.direction(), normalOfHitPoint);
    Ray reflectedRay(hitPoint, dirOfReflection);

    hitRes.reflectionRay = reflectedRay;
    hitRes.color = normalOfHitPoint / 2 + Vec3(0.5, 0.5, 0.5);
    hitRes.tOfHittingRay = root;
    hitRes.hitPoint = hitPoint;
    hitRes.normal = normalOfHitPoint;
    return true;
}
