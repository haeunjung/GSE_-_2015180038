#include "stdafx.h"
#include "sceneMgr.h"

#include "building.h"
#include "character.h"
#include "bullet.h"
#include "arrow.h"

sceneMgr::sceneMgr()
{
	IsInitialized();
}


sceneMgr::~sceneMgr()
{
	delete g_Renderer;
}

void sceneMgr::IsInitialized()
{
	startTime = (float)timeGetTime() * 0.001f;   //√ ¥‹¿ß∑Œ πŸ≤„¡‹
	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
	building* objbuilding = new building(0.f, 0.f, 0.f, 50.f, 1.f, 1.f, 0.f, 1.f);
	Obj_building[0] = objbuilding;
	objbuilding->psceneMgr = this;
}

void sceneMgr::RenderObjects()
{
	nowTime = (float)timeGetTime() * 0.001f;   //√ ¥‹¿ß∑Œ πŸ≤„¡‹
	for (int i = 0; i < 1; ++i)
	{
		Obj_building[i]->Update(nowTime - startTime);
		g_Renderer->DrawSolidRect(Obj_building[i]->x, Obj_building[i]->y, Obj_building[i]->z,
								Obj_building[i]->size,
								Obj_building[i]->r,	Obj_building[i]->g,	Obj_building[i]->b,	Obj_building[i]->a);
	}

	for (int i = 0; i < charNumber; ++i)
	{
		Obj_character[i]->Update(nowTime - startTime);
		g_Renderer->DrawSolidRect(Obj_character[i]->x, Obj_character[i]->y, Obj_character[i]->z,
			Obj_character[i]->size,
			Obj_character[i]->r, Obj_character[i]->g, Obj_character[i]->b, Obj_character[i]->a);
	}

	for (int i = 0; i < bulletNumber; ++i)
	{
		Obj_bullet[i]->Update(nowTime - startTime);
		g_Renderer->DrawSolidRect(Obj_bullet[i]->x, Obj_bullet[i]->y, Obj_bullet[i]->z,
			Obj_bullet[i]->size,
			Obj_bullet[i]->r, Obj_bullet[i]->g, Obj_bullet[i]->b, Obj_bullet[i]->a);
	}

	for (int i = 0; i < arrowNumeber; ++i)
	{
		Obj_arrow[i]->Update(nowTime - startTime);
		g_Renderer->DrawSolidRect(Obj_arrow[i]->x, Obj_arrow[i]->y, Obj_arrow[i]->z,
			Obj_arrow[i]->size,
			Obj_arrow[i]->r, Obj_arrow[i]->g, Obj_arrow[i]->b, Obj_arrow[i]->a);
	}

	//printf("%f\n", nowTime - startTime);
	startTime = nowTime;
}

void sceneMgr::ClickMouse(int x, int y)
{
	if (charNumber >= 10) return;

	character* objchar = new character(x, y, 0.f, 20.f, 1.f, 1.f, 1.f, 1.f);
	Obj_character[charNumber] = objchar;
	objchar->psceneMgr = this;
	++charNumber;
}

void sceneMgr::AddBullet()
{
	if (bulletNumber >= 30) return;

	bullet* objbull = new bullet(0, 0, 0.f, 7.f, 1.f, 0.f, 0.f, 1.f);
	Obj_bullet[bulletNumber] = objbull;
	++bulletNumber;
}

void sceneMgr::AddArrow(int x, int y)
{
	if (arrowNumeber >= 100) return;

	arrow* objarrow = new arrow(x, y, 0.f, 6.f, 1.f, 0.f, 1.f, 1.f);
	Obj_arrow[arrowNumeber] = objarrow;
	++arrowNumeber;
}
