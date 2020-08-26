#pragma once

#include "Vec4.h"
#include "Color.h"

class PointLight {
private:
	Vec4 pos;
	Color intensity;

public:
	PointLight(Vec4 pos, Color intensity);
};
