#pragma once
#include "FloatCompare.h"

class Color {
public:
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
public:
	Color(float r, float g, float b): r(r),g(g),b(b){}

	Color& operator +=(const Color& rhs) {
		r += rhs.r;
		g += rhs.g;
		b += rhs.b;
		return *this;
	}

	Color operator +(const Color& rhs)const {
		return Color(*this) += rhs;
	}

	Color& operator -=(const Color& rhs) {
		r -= rhs.r;
		g -= rhs.g;
		b -= rhs.b;
		return *this;
	}

	Color operator -(const Color& rhs)const {
		return Color(*this) -= rhs;
	}

	Color& operator*=(float rhs) {
		r *= rhs;
		g *= rhs;
		b *= rhs;
		return *this;
	}

	Color operator *(float rhs)const {
		return Color(*this) *= rhs;
	}

	Color& operator *=(const Color& rhs) {
		r *= rhs.r;
		g *= rhs.g;
		b *= rhs.b;
		return *this;
	}

	Color operator *(const Color& rhs)const {
		return Color(*this) *= rhs;
	}

	bool operator ==(const Color& rhs)const {
		return compareFloat(r, rhs.r) &&
			compareFloat(g, rhs.g) &&
			compareFloat(b, rhs.b);
	}
};