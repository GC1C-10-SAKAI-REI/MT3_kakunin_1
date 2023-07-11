#pragma once
#include <cmath>
#include <assert.h>
#include "Struct.h"

class MyMatrix
{
public:
	// コンストラクタ
	MyMatrix();
	// デストラクタ
	~MyMatrix();
	// X軸回転
	Matrix4x4 MakeRotateXMatrix(float rad);
	// Y軸回転
	Matrix4x4 MakeRotateYMatrix(float rad);
	// Z軸回転
	Matrix4x4 MakeRotateZMatrix(float rad);
	// 積
	Matrix4x4 Multiply(Matrix4x4& m1, const Matrix4x4& m2);
	// 1.アフィン変換行列
	Matrix4x4 MakeAffineMatrix(const Vec3& scale, const Vec3& rotate, const Vec3& translate);
	// 2.逆行列
	Matrix4x4 Inverse(Matrix4x4& m1);
	// 3.透視投影行列
	Matrix4x4
	    MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
	// 4.ビューポート変換行列
	Matrix4x4 MakeViewportMatrix(
	    float left, float top, float width, float height, float minDepth, float maxDepth);
	// 5.座標変換行列
	Vec3 Transform(const Vec3& vector, const Matrix4x4& matrix);
	// グリッド描画
	void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewPortMatrix);

	//行列表示関数
	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label, int columnWidth, int rowHeight);
	//ベクトル表示
	void VectorScreenPrintf(int x, int y, const Vec3& vector, const char* label, int columnWidth);
};