#pragma once

#include "Shape.h"
#include "Ray.h"

struct Intersection {
	float t = -1;
	const Sphere* object = nullptr;
	bool operator <(const Intersection& rhs)const;
	Intersection(float t, const Sphere* obj);
	Intersection() = default;
};



std::pair<Intersection, Intersection> Intersect(const Sphere& object, const Ray& ray);
Intersection Hit(std::vector<Intersection>& intersections);
