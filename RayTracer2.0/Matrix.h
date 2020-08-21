#pragma once
#include <algorithm>
#include <cassert>
#include "Vec4.h"


class Matrix {
public:
	int rows;
	int cols;
	float data[4 * 4];
public:
	static Matrix GetIdentity(int order = 4) {
		Matrix id(order);
		id.data[0] = 1;
		id.data[5] = 1;
		id.data[10] = 1;
		id.data[15] = 1;
		return id;
	}

	static Matrix GetTransposed(const Matrix& mat) {
		Matrix transposed(mat.rows);
		for(int row = 0; row < mat.rows; ++row) {
			for(int col = 0; col < mat.cols; ++col) {
				transposed(row, col) = mat(col, row);
			}
		}
		return transposed;
	}

	static float Determinant(const Matrix& mat) {
		float det = 0;
		if(mat.rows == 2)
			return mat(0, 0) * mat(1, 1) - mat(0, 1) * mat(1, 0);
	
		for(int col = 0; col < mat.cols; ++col) {
			det += mat(0, col) * GetCoFactor(mat, 0, col);
		}
		
		return det;
	}

	static Matrix GetSubMatrix(const Matrix& mat, int row, int col) {
		Matrix sub(mat.rows - 1);
		int isub = 0;
		int jsub = 0;
		for (int i = 0; i < mat.rows; ++i) {
			if (i == row) continue;

			for(int j = 0; j < mat.cols; ++j) {
				if (j == col) continue;

				sub(isub, jsub) = mat(i, j);
				++jsub;
			}

			++isub;
			jsub = 0;
		}

		return sub;
	}

	static float GetMinor(const Matrix& mat, int row, int col) {
		Matrix subMat = GetSubMatrix(mat, row, col);
		return Determinant(subMat);
	}

	static float GetCoFactor(const Matrix& mat, int row, int col) {
		float cofact = GetMinor(mat, row, col);

		return (row + col) % 2 == 0 ? cofact : -cofact;
	}

	static Matrix GetInverse(const Matrix& mat) {
		float det = Determinant(mat);
		if (det == 0) return GetIdentity(mat.rows);

		Matrix inv(mat.rows);

		for(int row = 0; row < mat.rows; ++row) {
			for(int col = 0; col < mat.cols; ++col) {
				const float cofactor = GetCoFactor(mat, row, col);
				inv(col, row) = cofactor / det;
			}
		}

		return inv;
	}

	static Matrix GetTranslationMat(float x_offset, float y_offset, float z_offset) {
		Matrix translationMat = GetIdentity();
		translationMat(0, 3) = x_offset;
		translationMat(1, 3) = y_offset;
		translationMat(2, 3) = z_offset;

		return translationMat;
	}

	static Matrix GetUniformScalingMat(float scale) {
		return GetScalingMat(scale, scale, scale);
	}

	static Matrix GetScalingMat(float x_scale, float y_scale, float z_scale) {
		Matrix scalingMat = GetIdentity();
		scalingMat(0, 0) = x_scale;
		scalingMat(1, 1) = y_scale;
		scalingMat(2, 2) = z_scale;

		return scalingMat;
	}
	
	Matrix(int order = 4): rows(order), cols(order) {
		std::memset(data, 0, sizeof(float) * 16);
	}

	Matrix(const float* data, int order = 4) : rows(order), cols(order) {
		for(int i = 0; i < 16; ++i) {
			this->data[i] = *(data + i);
		}
	}

	/*Matrix(const Matrix& mat) {
		rows = mat.rows;
		cols = mat.cols;
		std::copy(std::begin(mat.data), std::end(mat.data), std::begin(data));
	}*/

	float& operator()(int i, int j) {
		assert(i < rows && j < cols);
		
		return data[i * cols + j];
	}

	const float& operator()(int i, int j)const {
		assert(i < rows&& j < cols);
		
		return data[i * cols + j];
	}

	bool operator==(const Matrix& rhs)const {
		return rows == rhs.rows && std::equal(std::begin(data),
											  std::end(data),
											  std::begin(rhs.data));
	}

	Matrix& operator*=(const Matrix& rhs) {
		assert(rows == rhs.rows);
		float new_data[16];
		for(int row = 0; row < rows; ++row) {
			for(int col = 0; col < cols; ++col) {
				new_data[row * cols + col] = (*this)(row, 0) * rhs(0, col) +
											(*this)(row, 1) * rhs(1, col) +
											(*this)(row, 2) * rhs(2, col) +
											(*this)(row, 3) * rhs(3, col);
			}
		}
		std::copy(std::begin(new_data), std::end(new_data), data);
		return *this;
	}

	Matrix operator *(const Matrix& rhs)const {
		return Matrix(*this) *= rhs;
	}

	Vec4 operator *(const Vec4& rhs)const {
		assert(rows == 4);
		float results[4];
		for(int row = 0; row < rows; ++row) {
			results[row] = (*this)(row, 0) * rhs.x +
				(*this)(row, 1) * rhs.y +
				(*this)(row, 2) * rhs.z +
				(*this)(row, 3) * rhs.w;
		}
		return { results[0],results[1],results[2],results[3] };
	}

	Matrix& Transpose() {
		Matrix transposed(rows);
		for(int row = 0; row < rows; ++row) {
			for(int col = 0; col < cols; ++col) {
				transposed(row, col) = (*this)(col, row);
			}
		}
		std::copy(std::begin(transposed.data), std::end(transposed.data), std::begin(data));
		return *this;
	}

	float GetDeterminant() const {
		float det = 0;
		if(rows == 2) 
			return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
	
		for(int col = 0; col < cols; ++col) {
			det += (*this)(0, col) * GetCoFactor(*this, 0, col);
		}
		
		return det;
	}
};
