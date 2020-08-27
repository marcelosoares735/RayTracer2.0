#pragma once
#include "LightSources.h"
#include "Shape.h"

class World {
private:
	PointLight light;
	Sphere s1;
	Sphere s2;
public:
	World();
	Sphere GetSphere1()const;
	Sphere GetSphere2()const;
	PointLight GetLight()const;
};
