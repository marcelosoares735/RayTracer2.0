#include "Intersection.h"
#include <algorithm>
#include <cassert>

std::pair<Intersection, Intersection> Intersect( const Sphere& object, const Ray& ray) {
	const Ray transformed_ray = ray * object.GetTransformMat().Inverse();
	const Vec4 sphere_to_ray = transformed_ray.GetOrigin() - Vec4::MakePoint(0, 0, 0);
	const float a = transformed_ray.GetDir() * transformed_ray.GetDir();
	const float b = (transformed_ray.GetDir() * sphere_to_ray) * 2;
	const float c = sphere_to_ray * sphere_to_ray - 1;

	const float discriminant = b * b - 4 * a * c;

	if (discriminant < 0) return std::make_pair(Intersection(), Intersection());

	Intersection inter1, inter2;
	inter2.object = inter1.object = &object;
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

bool Intersection::operator<(const Intersection& rhs)const {
	return t < rhs.t;
}

Intersection::Intersection(float t, const Sphere* obj): t(t), object(obj) {
}
