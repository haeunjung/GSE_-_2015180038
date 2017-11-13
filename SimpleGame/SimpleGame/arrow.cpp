#include "stdafx.h"
#include "arrow.h"


arrow::arrow()
{
}

arrow::arrow(float posx, float posy, float posz, float objsize, float colorr, float colorg, float colorb, float colora)
{
	x = posx;
	y = posy;
	z = posz;
	size = objsize;
	r = colorr;
	g = colorg;
	b = colorb;
	a = colora;

	dirx = rand() % 10 - 5;
	diry = rand() % 10 - 5;

	float dis = sqrtf(pow(dirx, 2) + pow(diry, 2));
	dirx /= dis;
	diry /= dis;
}


arrow::~arrow()
{
}

int arrow::Update(float fTime)
{
	if (x > 250)
	{
		dirx *= -1;
	}
	if (x < -250)
	{
		dirx *= -1;
	}
	if (y > 250)
	{
		diry *= -1;
	}
	if (y < -250)
	{
		diry *= -1;
	}
	x += dirx * 0.05f;
	y += diry * 0.05f;

	return 0;
}
