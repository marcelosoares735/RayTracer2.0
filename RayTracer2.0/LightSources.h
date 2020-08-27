#pragma once

#include "Vec4.h"
#include "Color.h"

class PointLight {
private:
	Vec4 pos;
	Color intensity;

public:
	PointLight(Vec4 pos, Color intensity);
	void SetPos(Vec4 new_pos);
	void SetColor(Color new_color);
	Vec4 GetPos()const;
	Color GetIntensity()const;
};
