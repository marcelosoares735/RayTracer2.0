#pragma once
#include "cmath"

constexpr float EPSILON = 0.00001F;

inline bool compareFloat(float a, float b) {
	if (std::abs(a - b) < EPSILON) return true;
	
	return false;
}