#include "Intersection.h"
#include <algorithm>
#include <cassert>

Computations PrepareComputations(const Intersection& intersection, const Ray& ray) {
	Computations comps;
	comps.t = intersection.t;
	comps.object = intersection.object;

	comps.point = ray.PositionAt(comps.t);
	comps.eye_vec = -ray.GetDir();
	comps.normal_vec = comps.object->NormalAt(comps.point);

	if(comps.normal_vec * comps.eye_vec < 0) {
		comps.inside = true;
		comps.normal_vec = -comps.normal_vec;
	}else {
		comps.inside = false;
	}
	
	return comps;
}

std::pair<Intersection, Intersection> Intersect( const Sphere* object, const Ray& ray) {
	const Ray transformed_ray = ray * object->GetTransformMat().Inverse();
	const Vec4 sphere_to_ray = transformed_ray.GetOrigin() - Vec4::MakePoint(0, 0, 0);
	const float a = transformed_ray.GetDir() * transformed_ray.GetDir();
	const float b = (transformed_ray.GetDir() * sphere_to_ray) * 2;
	const float c = sphere_to_ray * sphere_to_ray - 1;

	const float discriminant = b * b - 4 * a * c;

	if (discriminant < 0) return std::make_pair(Intersection(), Intersection());

	Intersection inter1, inter2;
	inter2.object = inter1.object = object;
	inter1.t = (-b - std::sqrt(discriminant)) / (2 * a);
	inter2.t = (-b + std::sqrt(discriminant)) / (2 * a);

	return std::make_pair(inter1, inter2);
}

Intersection Hit(std::vector<Intersection>& intersections) {
	assert(std::is_sorted(intersections.begin(), intersections.end()));

	const auto result = std::find_if(intersections.begin(),
		intersections.end(),
		[](const Intersection& inter) {return inter.t > 0; });
	if (result == intersections.end()) return Intersection();

	return *result;
}

std::vector<Intersection> IntersectWorld(const World& world, const Ray& ray) {
	auto [first1, second1] = Intersect(world.GetSphere1Pointer(), ray);
	std::vector<Intersection> intersections;
	intersections.push_back(first1);
	intersections.push_back(second1);

	auto [first2, second2] = Intersect(world.GetSphere2Pointer(), ray);
	intersections.push_back(first2);
	intersections.push_back(second2);
	std::sort(intersections.begin(), intersections.end());
	return intersections;
}

bool Intersection::operator<(const Intersection& rhs)const {
	return t < rhs.t;
}

Intersection::Intersection(float t, const Sphere* obj): t(t), object(obj) {
}
