#pragma once
#include "MyMath.h"

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

namespace Colors {
	static Color White = { 1, 1, 1 };
	static Color Black = { 0, 0, 0 };
	static Color Gray = { 128/255.f, 128/255.f, 128/255.f };
	static Color LightGray = { 211/255.f, 211 / 255.f, 211 / 255.f };
	static Color Red = { 1, 0, 0 };
	static Color Green = { 0, 1, 0 };
	static Color Blue = { 0, 0, 1 };
	static Color Yellow = { 1, 1, 0 };
	static Color Cyan = { 0, 1, 1 };
	static Color Magenta = { 1, 0, 1 };
}
