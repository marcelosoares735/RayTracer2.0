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
	const Sphere* GetSphere1Pointer()const;
	const Sphere* GetSphere2Pointer()const;
	PointLight GetLight()const;
	void SetLight(PointLight light);
};
