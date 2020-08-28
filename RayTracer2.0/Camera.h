#pragma once

#include "Matrix.h"
#include "Ray.h"

class Camera {
private:
	int hsize;
	int vsize;
	float field_of_view;
	float half_width;
	float half_height;
	float pixel_size;
	Matrix transform;
public:
	Camera(int hsize, int vsize, float field_of_view);
	Ray RayForPixel(int x, int y)const;
	void SetTransformMat(Matrix transform);
};