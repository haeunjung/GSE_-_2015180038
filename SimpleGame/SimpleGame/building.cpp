#include "stdafx.h"
#include "building.h"
#include "sceneMgr.h"

building::building()
{
}

building::building(float posx, float posy, float posz, float objsize, float colorr, float colorg, float colorb, float colora)
{
	x = posx;
	y = posy;
	z = posz;
	size = objsize;
	r = colorr;
	g = colorg;
	b = colorb;
	a = colora;
}


building::~building()
{
}

int building::Update(float fTime)
{
	if (hp <= 0) dieSwitch = true;
	if (dieSwitch)
	{
		hp = 100;
		return 0;
	}


	bulletTime += fTime;
	if (bulletTime > 0.5f)
	{
		bulletTime = 0.f;
		psceneMgr->AddBullet();
	}
	return 0;
}
