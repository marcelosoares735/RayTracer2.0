#include "LightSources.h"

PointLight::PointLight(Vec4 pos, Color intensity): pos(pos), intensity(intensity) {
}

void PointLight::SetPos(Vec4 new_pos) {
	pos = new_pos;
}
void PointLight::SetColor(Color new_color) {
	intensity = new_color;
}
Vec4 PointLight::GetPos() const {
	return pos;
}
Color PointLight::GetIntensity() const {
	return intensity;
}
