#include "pch.h"
#include "../RayTracer2.0/Vec4.h"
#include "../RayTracer2.0/Color.h"
#include "../RayTracer2.0/Matrix.h"
#include "../RayTracer2.0/Ray.h"
#include "../RayTracer2.0/Shape.h"
#include "../RayTracer2.0/Intersection.h"

TEST(testTestCase, TestTest) {
	Vec4 a(1, 2, 3, 4);
	
	ASSERT_EQ(Vec4(2,4,6,8), a *= 2);
}

TEST(VectorTest, LenghtTest) {
	ASSERT_EQ(true,compareFloat(float(std::sqrt(14)), Vec4(-1, -2, -3, 0).GetLength()));
}

TEST(VectorTest, NormalizedVecTest) {
	ASSERT_EQ(true, compareFloat(1, Vec4(-1, -2, -3, 0).Normalize().GetLengthSqr()));
}

TEST(VectorTest, DotProductTest) {
	Vec4 a(1, 2, 3, 0);
	Vec4 b(2, 3, 4, 0);
	
	ASSERT_EQ(true, compareFloat(20,DotProduct(a,b)));
}

TEST(VectorTest, CrossProductTest) {
	Vec4 a(1, 2, 3, 0);
	Vec4 b(2, 3, 4, 0);

	ASSERT_EQ(Vec4(1, -2, 1, 0), CrossProduct(b, a));
}

TEST(ColorTest, ColorMultiplicationTest) {
	Color a(1, 0.2f, 0.4f);
	Color b(0.9f, 1, 0.1f);

	ASSERT_EQ(Color(0.9f, 0.2f, 0.04f), a * b);
}

TEST(MatrixTest, ComparisonTest) {
	Matrix m(4);
	Matrix n(4);
	m(0, 3) = 5.5654f;
	n(0, 3) = 5.5654f;
	
	ASSERT_EQ(true, m == n);
}

TEST(MatrixTest, MatrixMultiplicationTest) {
	Matrix a;
	Matrix b;
	float auxa[] = { 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2 };
	float auxb[] = { -2,1,2,3,3,2,1,-1,4,3,6,5,1,2,7,8 };
	std::copy(std::begin(auxa),std::end(auxa),a.data);
	std::copy(std::begin(auxb),std::end(auxb),b.data);
	float auxResult[] = { 20,22,50,48,44,54,114,108,40,58,110,102,16,26,46,42 };
	Matrix result;
	std::copy(std::begin(auxResult), std::end(auxResult), result.data);
	a *= b;
	ASSERT_EQ(true, result == a);
}

TEST(MatrixTest, MatrixVectorMultiplication) {
	Matrix a;
	float auxa[] = { 1,2,3,4,2,4,4,2,8,6,4,1,0,0,0,1 };
	std::copy(std::begin(auxa),std::end(auxa),a.data);
	Vec4 b(1, 2, 3, 1);
	Vec4 result(18, 24, 33, 1);
	ASSERT_EQ(result, a * b);
}

TEST(MatrixTest, IdentityMatrixMultTest) {
	Matrix a;
	float auxa[] = { 0,1,2,4,1,2,4,8,2,4,8,16,4,8,16,32 };
	std::copy(std::begin(auxa),std::end(auxa),a.data);
	Matrix b = Matrix::GetIdentity();
	ASSERT_EQ(a, a * b);
}

TEST(MatrixTest, IdentityMatrixVecMultTest) {
	Matrix a = Matrix::GetIdentity();
	Vec4 b (1,2,3,4);
	ASSERT_EQ(b, a * b);
}

TEST(MatrixTest, MatrixTransposeTest) {
	Matrix a;
	float auxa[] = { 0,1,2,4,1,2,4,8,2,4,8,16,4,8,16,32 };
	std::copy(std::begin(auxa),std::end(auxa),a.data);
	Matrix result;
	float auxres[] = { 0,1,2,4,1,2,4,8,2,4,8,16,4,8,16,32 };
	std::copy(std::begin(auxres),std::end(auxres),result.data);
	ASSERT_EQ(result,a.Transpose());
}

TEST(MatrixTest, Determinant2x2Test) {
	float aux[] = { 1,5,-3,2,0,0,0,0,0,0,0,0,0,0,0,0 };
	Matrix a(aux, 2);
	ASSERT_EQ(17, a.GetDeterminant());
}

TEST(MatrixTest, SubMatrixTest) {
	float aux[] = { -6,1,1,6,-8,5,8,6,-1,0,8,2,-7,1,-1,1};
	Matrix a(aux, 4);
	float auxb[] = { -6,1,6,-8,8,6,-7,-1,1,0,0,0,0,0,0,0};
	Matrix b(auxb, 3);
	ASSERT_EQ(b, Matrix::GetSubMatrix(a, 2, 1));
}

TEST(MatrixTest, minorTest) {
	float aux[] = { 3,5,0,2,-1,-7,6,-1,5,0,0,0,0,0,0,0 };
	Matrix a(aux, 3);
	float minor = 25;
	ASSERT_EQ(minor, Matrix::GetMinor(a, 1, 0));
}

TEST(MatrixTest, CoFactorTest) {
	float aux[] = { 3,5,0,2,-1,-7,6,-1,5,0,0,0,0,0,0,0 };
	Matrix a(aux, 3);
	float cofac = -25;
	ASSERT_EQ(cofac, Matrix::GetCoFactor(a, 1, 0));
}

TEST(MatrixTest, Det3x3Test) {
	float aux[] = { 1,2,6,-5,8,-4,2,6,4,0,0,0,0,0,0,0 };
	Matrix a(aux, 3);
	float det = -196;
	ASSERT_EQ(det, Matrix::Determinant(a));
}

TEST(MatrixTest, Det4x4Test) {
	float aux[] = { -2,-8,3,5,-3,1,7,3,1,2,-9,6,-6,7,7,-9 };
	Matrix a(aux, 4);
	float det = -4071;
	ASSERT_EQ(det, a.GetDeterminant());
}

TEST(MatrixTest, inverseMatTest) {
	float aux[] = { 9,3,0,9,-5,-2,-6,-3,-4,9,6,4,-7,6,6,2 };
	Matrix a(aux, 4);
	float auxinv[] = { -0.04074f, -0.07778f, 0.14444f,-0.22222f,
						-0.07778f, 0.03333f, 0.36667f, -0.33333f,
						-0.02901f,-0.14630f, -0.10926f,0.12963f,
						0.17778f, 0.06667f, -0.26667f, 0.33333f };
	Matrix inv(auxinv, 4);
	ASSERT_EQ(inv, Matrix::GetInverse(a));
}

TEST(MatrixTest, RotationMatX) {
	Vec4 p(0, 1, 0, 1);
	Matrix half_quarter_Rot_x = Matrix::GetRotationZMat(deg_to_rad(45));
	Matrix full_quarter_Rot_x = Matrix::GetRotationZMat(deg_to_rad(90));

	ASSERT_EQ(Vec4(-float(std::sqrt(2)) / 2.0f,  float(std::sqrt(2)) / 2.0f, 0, 1), half_quarter_Rot_x * p);
	ASSERT_EQ(Vec4(-1, 0, 0, 1), full_quarter_Rot_x * p);	
}

//TEST(RayTest, PositionAtTest) {
//	Ray r(Vec4::MakePoint(2, 3, 4), Vec4::MakeVector(1, 0, 0));
//
//	ASSERT_EQ(Vec4::MakePoint(1, 3, 4), r.PositionAt(-1));
//}
//
//TEST(IntersectionTest, RaySphereIntersecTest) {
//	Ray r(Vec4::MakePoint(0, 0, 5), Vec4::MakeVector(0, 0, 1));
//	Sphere s;
//	auto intersects = Intersect(s, r);
//
//	ASSERT_EQ(true, compareFloat(intersects.first.t, -6.f));
//	ASSERT_EQ(true, compareFloat(intersects.second.t, -4.0f));
//}
//
//TEST(IntersectionTest, IntersectionsListTest) {
//	Sphere s;
//	std::vector<Intersection> intersections;
//	intersections.emplace_back(5, &s);
//	intersections.emplace_back(7, &s);
//	intersections.emplace_back(-3, &s);
//	intersections.emplace_back(2, &s);
//	std::sort(intersections.begin(), intersections.end());
//	auto intersec = Hit(intersections);
//
//	ASSERT_EQ(true, compareFloat(intersec.t, 2));
//}
//
//TEST(IntersectioTest, ScaledSphereIntersectionTest) {
//	Ray r(Vec4::MakePoint(0, 0, -5), Vec4::MakeVector(0, 0, 1));
//	Sphere s;
//	s.SetTrasnformMat(Matrix::GetUniformScalingMat(2));
//	auto intersec = Intersect(s, r);
//	ASSERT_EQ(true, compareFloat(3, intersec.first.t));
//	ASSERT_EQ(true, compareFloat(7, intersec.second.t));
//}
//
//TEST(IntersectioTest, TranslatedSphereIntersectionTest) {
//	Ray r(Vec4::MakePoint(0, 0, -5), Vec4::MakeVector(0, 0, 1));
//	Sphere s;
//	s.SetTrasnformMat(Matrix::GetTranslationMat(5,0,0));
//	auto intersec = Intersect(s, r);
//	ASSERT_EQ(nullptr, intersec.first.object);
//	
//}

TEST(NormalTest, TransformedNormal) {
	Sphere s;
	s.SetTransformMat(Matrix::GetScalingMat(1, 0.5f, 1) * Matrix::GetRotationZMat(PI / 5));
	Vec4 n = s.NormalAt(Vec4::MakePoint(0, sqrt(2.f) / 2, -sqrt(2.f) / 2));

	ASSERT_EQ(Vec4::MakeVector(0, 0.97014f, -0.24254f), n);
}

TEST(VectorTest, ReflectVectoTest) {
	Vec4 v = Vec4::MakeVector(0, -1, 0);
	Vec4 n = Vec4::MakeVector(sqrt(2.f) / 2, sqrt(2.f) / 2, 0);

	ASSERT_EQ(Vec4::MakeVector(1, 0, 0), v.GetReflected(n));
}