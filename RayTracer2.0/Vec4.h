#pragma once
#include <cmath>
#include "FloatCompare.h"

class Vec4 {
public:
	float x;
	float y;
	float z;
	float w;
public:
	Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}
	Vec4() = default;
	
	Vec4& operator/=(float rhs) {
		x /= rhs;
		y /= rhs;
		z /= rhs;
		w /= rhs;
		return *this;
	}

	Vec4 operator/(float rhs) const{
		return Vec4(*this) /= rhs;
	}
	
	Vec4& operator*=(float rhs) {
		x *= rhs;
		y *= rhs;
		z *= rhs;
		w *= rhs;
		return *this;
	}

	Vec4 operator*(float rhs) const{
		return Vec4(*this) *= rhs;
	}

	Vec4& operator+=(const Vec4& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	Vec4 operator+(const Vec4& rhs)const {
		return Vec4(*this) += rhs;
	}

	Vec4& operator-=(const Vec4& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}

	Vec4 operator-(const Vec4& rhs)const {
		return Vec4(*this) -= rhs;
	}

	Vec4 operator-()const {
		return {-x, -y, -z, -w};
	}

	bool operator==(const Vec4& rhs)const {
		return compareFloat(x, rhs.x) &&
			compareFloat(y, rhs.y) &&
			compareFloat(z, rhs.z) && 
			compareFloat(w, rhs.w);
	}
	
	float GetLengthSqr()const {
		return x * x + y * y + z * z + w * w;
	}
	
	float GetLength()const {
		return std::sqrt(GetLengthSqr());
	}
	
	Vec4& Normalize() {
		*this /= GetLength();
		return *this;
	}

	Vec4 GetNormalizedVec()const {
		Vec4 norm = *this;
		norm.Normalize();
		return norm;
	}

	float DotProduct(const Vec4& rhs)const {
		return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	}
};

inline float DotProduct(const Vec4& a, const Vec4& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline Vec4 CrossProduct(const Vec4& a, const Vec4& b) {
	return {	a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x,
				0
	};
}