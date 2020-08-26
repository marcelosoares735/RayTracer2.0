#pragma once
#include "Matrix.h"
#include "Material.h"

class Sphere {
private:
	static int count;
	int id;
	Matrix transformMat;
	Material material;
	
public:
	Sphere();
	void SetMaterial(Material material);
	Material GetMaterial()const;
	void SetTransformMat(const Matrix& mat);
	void Translate(const Matrix& mat);
	void Rotate(const Matrix& mat);
	void Scale(const Matrix& mat);
	Matrix GetTransformMat()const;
	Vec4 NormalAt(const Vec4& world_point)const;
};
