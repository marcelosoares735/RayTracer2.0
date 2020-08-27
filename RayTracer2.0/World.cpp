#include "World.h"

World::World():light(PointLight(Vec4::MakePoint(-10, 10, -10), Colors::White)) {
	s1 = Sphere(Material(Color(0.8f, 1, 0.6f), 1, 0.7f, 0.2f,200));
	s2.SetTransformMat(Matrix::GetUniformScalingMat(0.5f));
	Material mat;
	mat.SetAmbient(1);
	s2.SetMaterial(mat);
}

Sphere World::GetSphere1() const {
	return s1;
}

Sphere World::GetSphere2() const {
	return s2;
}

const Sphere* World::GetSphere1Pointer() const {
	return &s1;
}
const Sphere* World::GetSphere2Pointer() const {
	return &s2;
}

PointLight World::GetLight() const {
	return light;
}

void World::SetLight(PointLight light) {
	this->light = light;
}
