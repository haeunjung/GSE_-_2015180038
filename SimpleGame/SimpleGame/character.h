#pragma once

class sceneMgr;
class character
{
public:
	character();
	character(float posx, float posy, float posz, float objsize, float colorr, float colorg, float colorb, float colora);
	~character();
public:
	float x, y, z;
	float size;
	float r, g, b, a;

	float dirx, diry;
	float arrowTime{ 0.f };

	bool dieSwitch{ true };
	int	hp{ 20 };

	int	Number{ -1 };

	sceneMgr* psceneMgr{ nullptr };

	int	Update(float fTime);

};

