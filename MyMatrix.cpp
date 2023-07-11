#include "MyMatrix.h"
#include "Novice.h"

MyMatrix::MyMatrix()
{

}

MyMatrix::~MyMatrix()
{

}

Matrix4x4 MyMatrix::MakeRotateXMatrix(float rad)
{
	Matrix4x4 result;

	result.m[0][0] = 1;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = cos(rad);
	result.m[1][2] = sin(rad);
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = -sin(rad);
	result.m[2][2] = cos(rad);
	result.m[2][3] = 0;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}

Matrix4x4 MyMatrix::MakeRotateYMatrix(float rad)
{
	Matrix4x4 result;

	result.m[0][0] = cos(rad);
	result.m[0][1] = 0;
	result.m[0][2] = -sin(rad);
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = 1;
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = sin(rad);
	result.m[2][1] = 0;
	result.m[2][2] = cos(rad);
	result.m[2][3] = 0;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}

Matrix4x4 MyMatrix::MakeRotateZMatrix(float rad)
{
	Matrix4x4 result;

	result.m[0][0] = cos(rad);
	result.m[0][1] = sin(rad);
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = -sin(rad);
	result.m[1][1] = cos(rad);
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1;
	result.m[2][3] = 0;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}

Matrix4x4 MyMatrix::Multiply(Matrix4x4& m1, const Matrix4x4& m2)
{
	Matrix4x4 result;
	// 0行目
	result.m[0][0] = (m1.m[0][0] * m2.m[0][0]) + (m1.m[0][1] * m2.m[1][0]) +
	                 (m1.m[0][2] * m2.m[2][0]) + (m1.m[0][3] * m2.m[3][0]);
	result.m[0][1] = (m1.m[0][0] * m2.m[0][1]) + (m1.m[0][1] * m2.m[1][1]) +
	                 (m1.m[0][2] * m2.m[2][1]) + (m1.m[0][3] * m2.m[3][1]);
	result.m[0][2] = (m1.m[0][0] * m2.m[0][2]) + (m1.m[0][1] * m2.m[1][2]) +
	                 (m1.m[0][2] * m2.m[2][2]) + (m1.m[0][3] * m2.m[3][2]);
	result.m[0][3] = (m1.m[0][0] * m2.m[0][3]) + (m1.m[0][1] * m2.m[1][3]) +
	                 (m1.m[0][2] * m2.m[2][3]) + (m1.m[0][3] * m2.m[3][3]);
	// 1行目
	result.m[1][0] = (m1.m[1][0] * m2.m[0][0]) + (m1.m[1][1] * m2.m[1][0]) +
	                 (m1.m[1][2] * m2.m[2][0]) + (m1.m[1][3] * m2.m[3][0]);
	result.m[1][1] = (m1.m[1][0] * m2.m[0][1]) + (m1.m[1][1] * m2.m[1][1]) +
	                 (m1.m[1][2] * m2.m[2][1]) + (m1.m[1][3] * m2.m[3][1]);
	result.m[1][2] = (m1.m[1][0] * m2.m[0][2]) + (m1.m[1][1] * m2.m[1][2]) +
	                 (m1.m[1][2] * m2.m[2][2]) + (m1.m[1][3] * m2.m[3][2]);
	result.m[1][3] = (m1.m[1][0] * m2.m[0][3]) + (m1.m[1][1] * m2.m[1][3]) +
	                 (m1.m[1][2] * m2.m[2][3]) + (m1.m[1][3] * m2.m[3][3]);
	// 2行目
	result.m[2][0] = (m1.m[2][0] * m2.m[0][0]) + (m1.m[2][1] * m2.m[1][0]) +
	                 (m1.m[2][2] * m2.m[2][0]) + (m1.m[2][3] * m2.m[3][0]);
	result.m[2][1] = (m1.m[2][0] * m2.m[0][1]) + (m1.m[2][1] * m2.m[1][1]) +
	                 (m1.m[2][2] * m2.m[2][1]) + (m1.m[2][3] * m2.m[3][1]);
	result.m[2][2] = (m1.m[2][0] * m2.m[0][2]) + (m1.m[2][1] * m2.m[1][2]) +
	                 (m1.m[2][2] * m2.m[2][2]) + (m1.m[2][3] * m2.m[3][2]);
	result.m[2][3] = (m1.m[2][0] * m2.m[0][3]) + (m1.m[2][1] * m2.m[1][3]) +
	                 (m1.m[2][2] * m2.m[2][3]) + (m1.m[2][3] * m2.m[3][3]);
	// 3行目
	result.m[3][0] = (m1.m[3][0] * m2.m[0][0]) + (m1.m[3][1] * m2.m[1][0]) +
	                 (m1.m[3][2] * m2.m[2][0]) + (m1.m[3][3] * m2.m[3][0]);
	result.m[3][1] = (m1.m[3][0] * m2.m[0][1]) + (m1.m[3][1] * m2.m[1][1]) +
	                 (m1.m[3][2] * m2.m[2][1]) + (m1.m[3][3] * m2.m[3][1]);
	result.m[3][2] = (m1.m[3][0] * m2.m[0][2]) + (m1.m[3][1] * m2.m[1][2]) +
	                 (m1.m[3][2] * m2.m[2][2]) + (m1.m[3][3] * m2.m[3][2]);
	result.m[3][3] = (m1.m[3][0] * m2.m[0][3]) + (m1.m[3][1] * m2.m[1][3]) +
	                 (m1.m[3][2] * m2.m[2][3]) + (m1.m[3][3] * m2.m[3][3]);

	return result;
}

Matrix4x4 MyMatrix::MakeAffineMatrix(const Vec3& scale, const Vec3& rotate, const Vec3& translate)
{
	Matrix4x4 result;

	// X,Y,Zそれぞれの回転成分を計算
	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.X);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.Y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.Z);
	// それらを掛け合わせる
	Matrix4x4 roateResultMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));

	result.m[0][0] = scale.X * roateResultMatrix.m[0][0];
	result.m[0][1] = scale.X * roateResultMatrix.m[0][1];
	result.m[0][2] = scale.X * roateResultMatrix.m[0][2];
	result.m[0][3] = 0;
	result.m[1][0] = scale.Y * roateResultMatrix.m[1][0];
	result.m[1][1] = scale.Y * roateResultMatrix.m[1][1];
	result.m[1][2] = scale.Y * roateResultMatrix.m[1][2];
	result.m[1][3] = 0;
	result.m[2][0] = scale.Z * roateResultMatrix.m[2][0];
	result.m[2][1] = scale.Z * roateResultMatrix.m[2][1];
	result.m[2][2] = scale.Z * roateResultMatrix.m[2][2];
	result.m[2][3] = 0;
	result.m[3][0] = translate.X;
	result.m[3][1] = translate.Y;
	result.m[3][2] = translate.Z;
	result.m[3][3] = 1;

	return result;
}

Matrix4x4 MyMatrix::Inverse(Matrix4x4& m1)
{
	Matrix4x4 result;
	// 行列の絶対値を求める
	float determinant = (m1.m[0][0] * m1.m[1][1] * m1.m[2][2] * m1.m[3][3]) + (m1.m[0][0] * m1.m[1][2] * m1.m[2][3] * m1.m[3][1]) + (m1.m[0][0] * m1.m[1][3] * m1.m[2][1] * m1.m[3][2])
					  - (m1.m[0][0] * m1.m[1][3] * m1.m[2][2] * m1.m[3][1]) - (m1.m[0][0] * m1.m[1][2] * m1.m[2][1] * m1.m[3][3]) - (m1.m[0][0] * m1.m[1][1] * m1.m[2][3] * m1.m[3][2])
					  - (m1.m[0][1] * m1.m[1][0] * m1.m[2][2] * m1.m[3][3]) - (m1.m[0][2] * m1.m[1][0] * m1.m[2][3] * m1.m[3][1]) - (m1.m[0][3] * m1.m[1][0] * m1.m[2][1] * m1.m[3][2])
					  + (m1.m[0][3] * m1.m[1][0] * m1.m[2][2] * m1.m[3][1]) + (m1.m[0][2] * m1.m[1][0] * m1.m[2][1] * m1.m[3][3]) + (m1.m[0][1] * m1.m[1][0] * m1.m[2][3] * m1.m[3][2])
					  + (m1.m[0][1] * m1.m[1][2] * m1.m[2][0] * m1.m[3][3]) + (m1.m[0][2] * m1.m[1][3] * m1.m[2][0] * m1.m[3][1]) + (m1.m[0][3] * m1.m[1][1] * m1.m[2][0] * m1.m[3][2])
					  - (m1.m[0][3] * m1.m[1][2] * m1.m[2][0] * m1.m[3][1]) - (m1.m[0][2] * m1.m[1][1] * m1.m[2][0] * m1.m[3][3]) - (m1.m[0][1] * m1.m[1][3] * m1.m[2][0] * m1.m[3][2])
					  - (m1.m[0][1] * m1.m[1][2] * m1.m[2][3] * m1.m[3][0]) - (m1.m[0][2] * m1.m[1][3] * m1.m[2][1] * m1.m[3][0]) - (m1.m[0][3] * m1.m[1][1] * m1.m[2][2] * m1.m[3][0])
					  + (m1.m[0][3] * m1.m[1][2] * m1.m[2][1] * m1.m[3][0]) + (m1.m[0][2] * m1.m[1][1] * m1.m[2][3] * m1.m[3][0]) + (m1.m[0][1] * m1.m[1][3] * m1.m[2][2] * m1.m[3][0]);

	// 逆行列の各値を求める
	// 0行目
	result.m[0][0] = ((m1.m[1][1] * m1.m[2][2] * m1.m[3][3]) + (m1.m[1][2] * m1.m[2][3] * m1.m[3][1]) + (m1.m[1][3] * m1.m[2][1] * m1.m[3][2])
					- (m1.m[1][3] * m1.m[2][2] * m1.m[3][1]) - (m1.m[1][2] * m1.m[2][1] * m1.m[3][3]) - (m1.m[1][1] * m1.m[2][3] * m1.m[3][2])) / determinant;
	result.m[0][1] = (-(m1.m[0][1] * m1.m[2][2] * m1.m[3][3]) - (m1.m[0][2] * m1.m[2][3] * m1.m[3][1]) - (m1.m[0][3] * m1.m[2][1] * m1.m[3][2])
					 + (m1.m[0][3] * m1.m[2][2] * m1.m[3][1]) + (m1.m[0][2] * m1.m[2][1] * m1.m[3][3]) + (m1.m[0][1] * m1.m[2][3] * m1.m[3][2])) / determinant;
	result.m[0][2] =
	    ((m1.m[0][1] * m1.m[1][2] * m1.m[3][3]) + (m1.m[0][2] * m1.m[1][3] * m1.m[3][1]) +
	     (m1.m[0][3] * m1.m[1][1] * m1.m[3][2]) - (m1.m[0][3] * m1.m[1][2] * m1.m[3][1]) -
	     (m1.m[0][2] * m1.m[1][1] * m1.m[3][3]) - (m1.m[0][1] * m1.m[1][3] * m1.m[3][2])) /
	    determinant;
	result.m[0][3] =
	    (-(m1.m[0][1] * m1.m[1][2] * m1.m[2][3]) - (m1.m[0][2] * m1.m[1][3] * m1.m[2][1]) -
	     (m1.m[0][3] * m1.m[1][1] * m1.m[2][2]) + (m1.m[0][3] * m1.m[1][2] * m1.m[2][1]) +
	     (m1.m[0][2] * m1.m[1][1] * m1.m[2][3]) + (m1.m[0][1] * m1.m[1][3] * m1.m[2][2])) /
	    determinant;
	// 1行目
	result.m[1][0] =
	    (-(m1.m[1][0] * m1.m[2][2] * m1.m[3][3]) - (m1.m[1][2] * m1.m[2][3] * m1.m[3][0]) -
	     (m1.m[1][3] * m1.m[2][0] * m1.m[3][2]) + (m1.m[1][3] * m1.m[2][2] * m1.m[3][0]) +
	     (m1.m[1][2] * m1.m[2][0] * m1.m[3][3]) + (m1.m[1][0] * m1.m[2][3] * m1.m[3][2])) /
	    determinant;
	result.m[1][1] =
	    ((m1.m[0][0] * m1.m[2][2] * m1.m[3][3]) + (m1.m[0][2] * m1.m[2][3] * m1.m[3][0]) +
	     (m1.m[0][3] * m1.m[2][0] * m1.m[3][2]) - (m1.m[0][3] * m1.m[2][2] * m1.m[3][0]) -
	     (m1.m[0][2] * m1.m[2][0] * m1.m[3][3]) - (m1.m[0][0] * m1.m[2][3] * m1.m[3][2])) /
	    determinant;
	result.m[1][2] =
	    (-(m1.m[0][0] * m1.m[1][2] * m1.m[3][3]) - (m1.m[0][2] * m1.m[1][3] * m1.m[3][0]) -
	     (m1.m[0][3] * m1.m[1][0] * m1.m[3][2]) + (m1.m[0][3] * m1.m[1][2] * m1.m[3][0]) +
	     (m1.m[0][2] * m1.m[1][0] * m1.m[3][3]) + (m1.m[0][0] * m1.m[1][3] * m1.m[3][2])) /
	    determinant;
	result.m[1][3] =
	    ((m1.m[0][0] * m1.m[1][2] * m1.m[2][3]) + (m1.m[0][2] * m1.m[1][3] * m1.m[2][0]) +
	     (m1.m[0][3] * m1.m[1][0] * m1.m[2][2]) - (m1.m[0][3] * m1.m[1][2] * m1.m[2][0]) -
	     (m1.m[0][2] * m1.m[1][0] * m1.m[2][3]) - (m1.m[0][0] * m1.m[1][3] * m1.m[2][2])) /
	    determinant;
	// 2行目
	result.m[2][0] =
	    ((m1.m[1][0] * m1.m[2][1] * m1.m[3][3]) + (m1.m[1][1] * m1.m[2][3] * m1.m[3][0]) +
	     (m1.m[1][3] * m1.m[2][0] * m1.m[3][1]) - (m1.m[1][3] * m1.m[2][1] * m1.m[3][0]) -
	     (m1.m[1][1] * m1.m[2][0] * m1.m[3][3]) - (m1.m[1][0] * m1.m[2][3] * m1.m[3][1])) /
	    determinant;
	result.m[2][1] =
	    (-(m1.m[0][0] * m1.m[2][1] * m1.m[3][3]) - (m1.m[0][1] * m1.m[2][3] * m1.m[3][0]) -
	     (m1.m[0][3] * m1.m[2][0] * m1.m[3][1]) + (m1.m[0][3] * m1.m[2][1] * m1.m[3][0]) +
	     (m1.m[0][1] * m1.m[2][0] * m1.m[3][3]) + (m1.m[0][0] * m1.m[2][3] * m1.m[3][1])) /
	    determinant;
	result.m[2][2] =
	    ((m1.m[0][0] * m1.m[1][1] * m1.m[3][3]) + (m1.m[0][1] * m1.m[1][3] * m1.m[3][0]) +
	     (m1.m[0][3] * m1.m[1][0] * m1.m[3][1]) - (m1.m[0][3] * m1.m[1][1] * m1.m[3][0]) -
	     (m1.m[0][1] * m1.m[1][0] * m1.m[3][3]) - (m1.m[0][0] * m1.m[1][3] * m1.m[3][1])) /
	    determinant;
	result.m[2][3] =
	    (-(m1.m[0][0] * m1.m[1][1] * m1.m[2][3]) - (m1.m[0][1] * m1.m[1][3] * m1.m[2][0]) -
	     (m1.m[0][3] * m1.m[1][0] * m1.m[2][1]) + (m1.m[0][3] * m1.m[1][1] * m1.m[2][0]) +
	     (m1.m[0][1] * m1.m[1][0] * m1.m[2][3]) + (m1.m[0][0] * m1.m[1][3] * m1.m[2][1])) /
	    determinant;
	// 3行目
	result.m[3][0] =
	    (-(m1.m[1][0] * m1.m[2][1] * m1.m[3][2]) - (m1.m[1][1] * m1.m[2][2] * m1.m[3][0]) -
	     (m1.m[1][2] * m1.m[2][0] * m1.m[3][1]) + (m1.m[1][2] * m1.m[2][1] * m1.m[3][0]) +
	     (m1.m[1][1] * m1.m[2][0] * m1.m[3][2]) + (m1.m[1][0] * m1.m[2][2] * m1.m[3][1])) /
	    determinant;
	result.m[3][1] =
	    ((m1.m[0][0] * m1.m[2][1] * m1.m[3][2]) + (m1.m[0][1] * m1.m[2][2] * m1.m[3][0]) +
	     (m1.m[0][2] * m1.m[2][0] * m1.m[3][1]) - (m1.m[0][2] * m1.m[2][1] * m1.m[3][0]) -
	     (m1.m[0][1] * m1.m[2][0] * m1.m[3][2]) - (m1.m[0][0] * m1.m[2][2] * m1.m[3][1])) /
	    determinant;
	result.m[3][2] =
	    (-(m1.m[0][0] * m1.m[1][1] * m1.m[3][2]) - (m1.m[0][1] * m1.m[1][2] * m1.m[3][0]) -
	     (m1.m[0][2] * m1.m[1][0] * m1.m[3][1]) + (m1.m[0][2] * m1.m[1][1] * m1.m[3][0]) +
	     (m1.m[0][1] * m1.m[1][0] * m1.m[3][2]) + (m1.m[0][0] * m1.m[1][2] * m1.m[3][1])) /
	    determinant;
	result.m[3][3] =
	    ((m1.m[0][0] * m1.m[1][1] * m1.m[2][2]) + (m1.m[0][1] * m1.m[1][2] * m1.m[2][0]) +
	     (m1.m[0][2] * m1.m[1][0] * m1.m[2][1]) - (m1.m[0][2] * m1.m[1][1] * m1.m[2][0]) -
	     (m1.m[0][1] * m1.m[1][0] * m1.m[2][2]) - (m1.m[0][0] * m1.m[1][2] * m1.m[2][1])) /
	    determinant;

	return result;
}

Matrix4x4 MyMatrix::MakePerspectiveFovMatrix(
    float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 result;

	result.m[0][0] = (1 / tan(fovY / 2)) / aspectRatio;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = (1 / tan(fovY / 2));
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = farClip / (farClip - nearClip);
	result.m[2][3] = 1;
	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = -nearClip * farClip / (farClip - nearClip);
	;
	result.m[3][3] = 0;

	return result;
}

Matrix4x4 MyMatrix::MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 result;

	result.m[0][0] = width / 2;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = -(height / 2);
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = maxDepth - minDepth;
	result.m[2][3] = 0;
	result.m[3][0] = left + (width / 2);
	result.m[3][1] = top + (height / 2);
	result.m[3][2] = minDepth;
	result.m[3][3] = 1;

	return result;
}

Vec3 MyMatrix::Transform(const Vec3& vector, const Matrix4x4& matrix) {
	Vec3 result;

	result.X = (vector.X * matrix.m[0][0]) + (vector.Y * matrix.m[1][0]) +
	           (vector.Z * matrix.m[2][0]) + matrix.m[3][0];
	result.Y = (vector.X * matrix.m[0][1]) + (vector.Y * matrix.m[1][1]) +
	           (vector.Z * matrix.m[2][1]) + matrix.m[3][1];
	result.Z = (vector.X * matrix.m[0][2]) + (vector.Y * matrix.m[1][2]) +
	           (vector.Z * matrix.m[2][2]) + matrix.m[3][2];

	float w = (vector.X * matrix.m[0][3]) + (vector.Y * matrix.m[1][3]) +
	          (vector.Z * matrix.m[2][3]) + matrix.m[3][3];
	assert(w != 0.0f);

	result.X /= w;
	result.Y /= w;
	result.Z /= w;

	return result;
}

void MyMatrix::DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewPortMatrix) {
	// Gridの半分の幅
	const float kGridHalfWidth = 2.0f;
	// 分割数
	const uint32_t subdivision = 10;
	// 一つ分の長さ
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(subdivision);

	// 奥から手前への線を引いていく
	for (uint32_t xIndex = 0; xIndex <= subdivision; ++xIndex) {
		float x = -kGridHalfWidth + (xIndex * kGridEvery);
		// 上の情報を使ってワールド座標系上の始点と終点を求める
		Vec3 start = {x, 0.0f, -kGridHalfWidth};
		Vec3 end = {x, 0.0f, kGridHalfWidth};
		// スクリーン座標系まで変換をかける
		Vec3 scrStart = Transform(Transform(start, viewProjectionMatrix), viewPortMatrix);
		Vec3 scrEnd = Transform(Transform(end, viewProjectionMatrix), viewPortMatrix);

		if (x == 0) {
			Novice::DrawLine(int(scrStart.X), int(scrStart.Y), int(scrEnd.X), int(scrEnd.Y), BLACK);
		} else {
			Novice::DrawLine(int(scrStart.X), int(scrStart.Y), int(scrEnd.X), int(scrEnd.Y), 0xAAAAAAFF);
		}
	}
	// 左から右も同じように順々に引いていく
	for (uint32_t zIndex = 0; zIndex <= subdivision; ++zIndex) {
		float z = -kGridHalfWidth + (zIndex * kGridEvery);
		Vec3 start = {-kGridHalfWidth, 0.0f, z};
		Vec3 end = {kGridHalfWidth, 0.0f, z};
		Vec3 scrStart = Transform(Transform(start, viewProjectionMatrix), viewPortMatrix);
		Vec3 scrEnd = Transform(Transform(end, viewProjectionMatrix), viewPortMatrix);

		if (z == 0) {
			Novice::DrawLine(int(scrStart.X), int(scrStart.Y), int(scrEnd.X), int(scrEnd.Y), BLACK);
		}
		else {
			Novice::DrawLine(int(scrStart.X), int(scrStart.Y), int(scrEnd.X), int(scrEnd.Y), 0xAAAAAAFF);
		}
	}
}

void MyMatrix::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label, int columnWidth, int rowHeight)
{
	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			Novice::ScreenPrintf(x + column * columnWidth, (y + 20) + row * rowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}

void MyMatrix::VectorScreenPrintf(int x, int y, const Vec3& vector, const char* label, int columnWidth)
{
	Novice::ScreenPrintf(x, y, "%0.2f", vector.X);
	Novice::ScreenPrintf(x + columnWidth, y, "%0.2f", vector.Y);
	Novice::ScreenPrintf(x + columnWidth * 2, y, "%0.2f", vector.Z);
	Novice::ScreenPrintf(x + columnWidth * 3, y, "%s", label);
}