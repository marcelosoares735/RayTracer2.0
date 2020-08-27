#include "World.h"

World::World():light(PointLight(Vec4::MakePoint(-10, 10, -10), Colors::White)) {
	s1 = Sphere(Material(Color(0.8f, 1, 0.6f), 0.1f, 0.7f, 0.2f,200));
	s2.SetTransformMat(Matrix::GetUniformScalingMat(0.5f));
	
}

Sphere World::GetSphere1() const {
	return s1;
}

Sphere World::GetSphere2() const {
	return s2;
}

PointLight World::GetLight() const {}
