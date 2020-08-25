#pragma once
#include "Matrix.h"

class Sphere {
private:
	static int count;
	int id;
	Matrix transformMat;
public:
	Sphere();
	void SetTrasnformMat(const Matrix& mat);
	void Translate(const Matrix& mat);
	void Rotate(const Matrix& mat);
	void Scale(const Matrix& mat);
	Matrix GetTransformMat()const;
};
