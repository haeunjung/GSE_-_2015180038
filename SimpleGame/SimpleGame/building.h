#pragma once

class sceneMgr;
class building
{
public:
	building();
	building(float posx, float posy, float posz, float objsize, float colorr, float colorg, float colorb, float colora);
	~building();

public:
	float x, y, z;
	float size;
	float r, g, b, a;

	float bulletTime{ 0.f };
	sceneMgr* psceneMgr{ nullptr };

	bool dieSwitch{ true };
	int	hp{ 100 };

	int	Update(float fTime);

};

