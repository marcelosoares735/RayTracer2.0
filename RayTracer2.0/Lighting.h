#pragma once

#include "Vec4.h"
#include "Material.h"
#include "LightSources.h"
#include "Color.h"

Color Lighting(const Material& material, const PointLight& light, const Vec4& point, const Vec4& eye_vec, const Vec4& normal_vec);


