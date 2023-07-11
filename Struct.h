#pragma once

typedef struct Vec3
{
	float X, Y, Z;
} Vec3;

typedef struct Matrix4x4
{
	float m[4][4];
} Matrix4x4;

//
typedef struct Sphere
{
	Vec3 Center;
	float Rad;
};