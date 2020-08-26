#pragma once
#include <cmath>
#include <random>


constexpr float EPSILON = 0.00001f;
constexpr float PI = 3.14159265f;

inline bool compareFloat(float a, float b) {
	if (std::abs(a - b) < EPSILON) return true;

	return false;
}

inline float deg_to_rad(const float deg_angle) {
	return deg_angle / 180.0f * float(std::_Pi);
}
