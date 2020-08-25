
#include "Ray.h"

Ray::Ray(Vec4 origin, Vec4 dir): origin(origin), dir(dir) {
}

void Ray::SetDir(Vec4 dir) {
	this->dir = dir;
}

Vec4 Ray::GetDir() const {
	return dir;
}

Vec4 Ray::GetOrigin() const {
	return origin;
}

void Ray::SetOrigin(Vec4 origin) {
	this->origin = origin;
}

Vec4 Ray::PositionAt(float t) const {
	return origin + dir * t;
}

void Ray::Transform(const Matrix& mat) {
	origin = mat * origin;
	dir = mat * dir;
}

Ray Ray::GetTransformedRay(const Matrix& mat) const {
	return Ray(mat * origin, mat * dir);
}

Ray& Ray::operator*=(const Matrix& mat) {
	origin = mat * origin;
	dir = mat * dir;
	return *this;
}

Ray Ray::operator*(const Matrix& mat)const {
	return Ray(*this) *= mat;
}
