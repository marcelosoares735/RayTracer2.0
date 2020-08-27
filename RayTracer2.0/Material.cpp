#include "Material.h"

Material::Material():color(Colors::White), ambient(.1f), diffuse(.9f),specular(.9f),shininess(200) {
	
}

Material::Material(Color c, float ambient, float diffuse, float specular, float shininess): color(c),
	ambient(ambient),
	diffuse(diffuse),
	specular(specular),
	shininess(shininess)
{}

Material::Material(Color c):Material() {
	color = c;
}

void Material::SetColor(Color c) {
	color = c;
}

void Material::SetAmbient(float ambient) {
	this->ambient = ambient;
}

void Material::SetDiffuse(float diffuse) {
	this->diffuse = diffuse;
}

void Material::SetSpecular(float specular) {
	this->specular = specular;
}

void Material::SetShininess(float shininess) {
	this->shininess = shininess;
}

Color Material::GetColor() const {
	return color;
}

float Material::GetAmbient() const {
	return ambient;
}

float Material::GetDiffuse() const {
	return diffuse;
}

float Material::GetSpecular() const {
	return specular;
}

float Material::GetShininess() const {
	return shininess;
}
