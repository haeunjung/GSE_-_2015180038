#pragma once
class arrow
{
public:
	arrow();
	arrow(float posx, float posy, float posz, float objsize, float colorr, float colorg, float colorb, float colora);
	~arrow();
public:
	float x, y, z;
	float size;
	float r, g, b, a;

	float dirx, diry;

	int	Update(float fTime);
};

