#pragma once
#include <iostream>
#include <vector>

class Object
{
public:
	
	float X, Y, Z;
	float Size;
	float R, G, B, A;
	float dir_X, dir_Y;
	float Life, Life_Time;
	
	float SetObject(float x, float y, float z, float size, float r, float g, float b, float a);
	float Update(float vector_x, float vector_y);

private:
};

