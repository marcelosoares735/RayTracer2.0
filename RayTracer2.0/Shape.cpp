#include "Shape.h"

int Sphere::count = 0;
Sphere::Sphere() {
	id = count++;
	transformMat = Matrix::GetIdentity();
}

void Sphere::SetTransformMat(const Matrix& mat) {
	transformMat = mat;
}

void Sphere::Translate(const Matrix& mat) {
	transformMat *= mat;
}

void Sphere::Rotate(const Matrix& mat) {
	transformMat *= mat;
}

void Sphere::Scale(const Matrix& mat) {
	transformMat *= mat;
}

Matrix Sphere::GetTransformMat() const {
	return transformMat;
}

Vec4 Sphere::NormalAt(const Vec4& world_point) const {
	Vec4 object_point = transformMat.Inverse() * world_point;
	Vec4 object_normal = object_point - Vec4::MakePoint(0, 0, 0);
	Vec4 world_normal = transformMat.Inverse().Transpose() * object_normal;
	world_normal.w = 0;
	return world_normal.Normalize();
}
