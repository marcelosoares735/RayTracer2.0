#pragma once

#include "Shape.h"
#include "Ray.h"
#include "World.h"

struct Intersection {
	float t = -1;
	const Sphere* object = nullptr;
	bool operator <(const Intersection& rhs)const;
	Intersection(float t, const Sphere* obj);
	Intersection() = default;
};

struct Computations {
	float t;
	const Sphere* object;
	Vec4 point;
	Vec4 eye_vec;
	Vec4 normal_vec;
	bool inside;
};


Computations PrepareComputations(const Intersection& intersection, const Ray& ray);
std::pair<Intersection, Intersection> Intersect(const Sphere* object, const Ray& ray);
Intersection Hit(std::vector<Intersection>& intersections);
std::vector<Intersection> IntersectWorld(const World& world, const Ray& ray);

