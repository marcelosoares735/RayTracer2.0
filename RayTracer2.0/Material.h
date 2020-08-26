#pragma once
#include "Color.h"

class Material {
private:
	Color color;
	float ambient;
	float diffuse;
	float specular;
	float shininess;
public:
	Material();
	Material(Color c, float ambient, float diffuse, float specular, float shininess);
	void SetColor(Color c);
	void SetAmbient(float ambient);
	void SetDiffuse(float diffuse);
	void SetSpecular(float specular);
	void SetShininess(float shininess);
	Color GetColor()const;
	float GetAmbient()const;
	float GetDiffuse()const;
	float GetSpecular()const;
	float GetShininess()const;
};

