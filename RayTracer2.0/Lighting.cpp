#include "Lighting.h"

Color Lighting(const Material& material, const PointLight& light, const Vec4& point, const Vec4& eye_vec, const Vec4& normal_vec) {
    const Color effective_color = material.GetColor() * light.GetIntensity();

	const Vec4 light_vec = (light.GetPos() - point).Normalize();

	const Color ambient = effective_color * material.GetAmbient();

	const float light_dot_normal = light_vec * normal_vec;

	Color diffuse, specular;
	
	if(light_dot_normal > 0) {
		diffuse = effective_color * material.GetDiffuse() * light_dot_normal;
		
		const float reflect_dot_eye = (-light_vec).Reflect(normal_vec) * eye_vec;

		if(reflect_dot_eye > 0) {
			const float factor = pow(reflect_dot_eye, material.GetShininess());
			specular = light.GetIntensity() * material.GetSpecular() * factor;
		}
	}

	return ambient + diffuse + specular;
}
