#pragma once

#include "Vec4.h"
#include "Matrix.h"

class Ray {
private:
	Vec4 origin;
	Vec4 dir;

public:
	Ray(Vec4 origin, Vec4 dir);
	Ray() = default;
	void SetDir(Vec4 dir);
	void SetOrigin(Vec4 origin);
	Vec4 GetDir()const;
	Vec4 GetOrigin()const;
	Vec4 PositionAt(float point)const;
	void Transform(const Matrix& mat);
	Ray GetTransformedRay(const Matrix& mat)const;
	Ray& operator*=(const Matrix& mat);
	Ray operator*(const Matrix& mat)const;
};
