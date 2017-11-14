#include "stdafx.h"
#include "character.h"
#include "sceneMgr.h"

character::character()
{
}

character::character(float posx, float posy, float posz, float objsize, float colorr, float colorg, float colorb, float colora)
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


character::~character()
{
}

int character::Update(float fTime)
{
	if (hp <= 0) dieSwitch = true;
	if (dieSwitch)
	{
		hp = 20;
		return 0;
	}

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


	x += dirx * fTime * 100.f;
	y += diry * fTime * 100.f;

	
	arrowTime += fTime;
	if (arrowTime > 0.5f)
	{
		arrowTime = 0.f;
		psceneMgr->AddArrow(x, y, Number);
	}

	return 0;
}
