#include "Shape.h"

int Sphere::count = 0;
Sphere::Sphere() {
	id = count++;
	transformMat = Matrix::GetIdentity();
}

void Sphere::SetTrasnformMat(const Matrix& mat) {
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
