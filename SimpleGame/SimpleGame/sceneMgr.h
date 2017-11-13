#pragma once
#include <iostream>
#include "Renderer.h"


class bullet;
class arrow;
class character;
class building;
class sceneMgr
{
public:
	sceneMgr();
	~sceneMgr();

	character*	Obj_character[10];
	building*	Obj_building[1];
	bullet*		Obj_bullet[30];
	arrow*		Obj_arrow[100];

	int	charNumber{ 0 };
	int	buildingNumber{ 0 };
	int bulletNumber{ 0 };
	int arrowNumeber{ 0 };

	Renderer *g_Renderer;

	void IsInitialized();
	void RenderObjects();
	void ClickMouse(int x, int y);

	void AddBullet();
	void AddArrow(int x, int y);

	float startTime{ 0.f };
	float nowTime{ 0.f };
};
