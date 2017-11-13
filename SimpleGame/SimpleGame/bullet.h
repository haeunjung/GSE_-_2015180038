#pragma once
class bullet
{
public:
	bullet();
	bullet(float posx, float posy, float posz, float objsize, float colorr, float colorg, float colorb, float colora);
	~bullet();
public:
	float x, y, z;
	float size;
	float r, g, b, a;

	float dirx, diry;

	int	Update(float fTime);
};

