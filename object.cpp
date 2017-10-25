#include "stdafx.h"
#include "object.h"
#include "stdlib.h"


float Object::SetObject(float x, float y, float z, float size, float r, float g, float b, float a)
{
	X = x;
	Y = y;
	Z = z;
	Size = size;
	R = r;
	G = g;
	B = b;
	A = a;

	return 0;
}

float Object::Update(float vector_X, float vector_Y)
{
	dir_X = vector_X * 0.2;
	dir_Y = vector_Y * 0.2;

	 X += dir_X;
	 Y += dir_Y;

	return 0;
}