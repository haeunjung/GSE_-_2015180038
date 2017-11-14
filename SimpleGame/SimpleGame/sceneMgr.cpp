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
	building* objbuilding = new building(0.f, 0.f, 0.f, 100.f, 1.f, 1.f, 0.f, 1.f);
	Obj_building[0] = objbuilding;
	objbuilding->psceneMgr = this;
	objbuilding->dieSwitch = false;
	buildingNumber = 1;

	for (int i = 0; i < 10; ++i)
	{
		character* objchar = new character(0, 0, 0.f, 30.f, 1.f, 1.f, 1.f, 1.f);
		Obj_character[i] = objchar;
		objchar->psceneMgr = this;
		objchar->Number = i;
	}
	for (int i = 0; i < 30; ++i)
	{
		bullet* objbull = new bullet(0, 0, 0.f, 15.f, 1.f, 0.f, 0.f, 1.f);
		Obj_bullet[i] = objbull;
	}
	for (int i = 0; i < 100; ++i)
	{
		arrow* objarrow = new arrow(0, 0, 0.f, 15.f, 1.f, 0.f, 1.f, 1.f);
		Obj_arrow[i] = objarrow;
	}

	imageNum[0] = g_Renderer->CreatePngTexture("./Textures/building.png");
	imageNum[1] = g_Renderer->CreatePngTexture("./Textures/character.png");
	imageNum[2] = g_Renderer->CreatePngTexture("./Textures/bullet.png");
	imageNum[3] = g_Renderer->CreatePngTexture("./Textures/arrow.png");
}

void sceneMgr::checkcollision()
{
	for (int i = 0; i < 10; ++i)
	{
		if (true == Obj_character[i]->dieSwitch) continue;

		for (int j = 0; j < 1; ++j)
		{
			if (true == Obj_building[j]->dieSwitch) continue;
			if (Obj_building[j]->x - Obj_building[j]->size * 0.5f	< Obj_character[i]->x + Obj_character[i]->size * 0.5f &&
				Obj_building[j]->y - Obj_building[j]->size * 0.5f	< Obj_character[i]->y + Obj_character[i]->size * 0.5f &&
				Obj_building[j]->x + Obj_building[j]->size * 0.5f	> Obj_character[i]->x - Obj_character[i]->size * 0.5f &&
				Obj_building[j]->y + Obj_building[j]->size * 0.5f	> Obj_character[i]->y - Obj_character[i]->size * 0.5f)
			{
				Obj_character[i]->dieSwitch = true;
				Obj_building[i]->hp = Obj_building[i]->hp - Obj_character[j]->hp;
			}
		}

		for (int j = 0; j < 100; ++j)
		{
			if (true == Obj_arrow[j]->dieSwitch) continue;
			if( Obj_arrow[j]->x - Obj_arrow[j]->size * 0.5f	< Obj_character[i]->x + Obj_character[i]->size * 0.5f &&
				Obj_arrow[j]->y - Obj_arrow[j]->size * 0.5f	< Obj_character[i]->y + Obj_character[i]->size * 0.5f &&
				Obj_arrow[j]->x + Obj_arrow[j]->size * 0.5f	> Obj_character[i]->x - Obj_character[i]->size * 0.5f &&
				Obj_arrow[j]->y + Obj_arrow[j]->size * 0.5f	> Obj_character[i]->y - Obj_character[i]->size * 0.5f)
			{
				if (Obj_arrow[j]->Number == Obj_character[i]->Number) continue;

				Obj_arrow[j]->dieSwitch = true;
				Obj_character[i]->hp = Obj_character[i]->hp - Obj_arrow[j]->hp;
			}
		}

		for (int j = 0; j < 30; ++j)
		{
			if (true == Obj_bullet[j]->dieSwitch) continue;
			if (Obj_bullet[j]->x - Obj_bullet[j]->size * 0.5f	< Obj_character[i]->x + Obj_character[i]->size * 0.5f &&
				Obj_bullet[j]->y - Obj_bullet[j]->size * 0.5f	< Obj_character[i]->y + Obj_character[i]->size * 0.5f &&
				Obj_bullet[j]->x + Obj_bullet[j]->size * 0.5f	> Obj_character[i]->x - Obj_character[i]->size * 0.5f &&
				Obj_bullet[j]->y + Obj_bullet[j]->size * 0.5f	> Obj_character[i]->y - Obj_character[i]->size * 0.5f)
			{
				Obj_bullet[j]->dieSwitch = true;
				Obj_character[i]->hp = Obj_character[i]->hp - Obj_bullet[j]->hp;
			}
		}
	}
}

void sceneMgr::RenderObjects()
{
	nowTime = (float)timeGetTime() * 0.001f;   //√ ¥‹¿ß∑Œ πŸ≤„¡‹

	checkcollision();
	for (int i = 0; i < 1; ++i)
	{
		Obj_building[i]->Update(nowTime - startTime);

		if (true == Obj_building[i]->dieSwitch) continue;
		g_Renderer->DrawTexturedRect(Obj_building[i]->x, Obj_building[i]->y, Obj_building[i]->z,
								Obj_building[i]->size,
								Obj_building[i]->r,	Obj_building[i]->g,	Obj_building[i]->b,	Obj_building[i]->a,
								imageNum[0]);
	}
	for (int i = 0; i < 10; ++i)
	{
		Obj_character[i]->Update(nowTime - startTime);
		
		if (true == Obj_character[i]->dieSwitch) continue;
		g_Renderer->DrawTexturedRect(Obj_character[i]->x, Obj_character[i]->y, Obj_character[i]->z,
			Obj_character[i]->size,
			Obj_character[i]->r, Obj_character[i]->g, Obj_character[i]->b, Obj_character[i]->a,
			imageNum[1]);
	}

	for (int i = 0; i < 30; ++i)
	{
		Obj_bullet[i]->Update(nowTime - startTime);

		if (true == Obj_bullet[i]->dieSwitch) continue;
		g_Renderer->DrawTexturedRect(Obj_bullet[i]->x, Obj_bullet[i]->y, Obj_bullet[i]->z,
			Obj_bullet[i]->size,
			Obj_bullet[i]->r, Obj_bullet[i]->g, Obj_bullet[i]->b, Obj_bullet[i]->a,
			imageNum[2]);
	}

	for (int i = 0; i < 100; ++i)
	{
		Obj_arrow[i]->Update(nowTime - startTime);

		if (true == Obj_arrow[i]->dieSwitch) continue;
		g_Renderer->DrawTexturedRect(Obj_arrow[i]->x, Obj_arrow[i]->y, Obj_arrow[i]->z,
			Obj_arrow[i]->size,
			Obj_arrow[i]->r, Obj_arrow[i]->g, Obj_arrow[i]->b, Obj_arrow[i]->a,
			imageNum[3]);
	}

	//printf("%f\n", nowTime - startTime);
	startTime = nowTime;
}

void sceneMgr::ClickMouse(int x, int y)
{
	for (int i = 0; i < 10; ++i)
	{
		if (Obj_character[i]->dieSwitch == true)
		{
			Obj_character[i]->x = x;
			Obj_character[i]->y = y;
			Obj_character[i]->dieSwitch = false;
			return;
		}
	}
}

void sceneMgr::AddBullet()
{
	for (int i = 0; i < 30; ++i)
	{
		if (Obj_bullet[i]->dieSwitch == true)
		{
			Obj_bullet[i]->dieSwitch = false;
			return;
		}
	}
}

void sceneMgr::AddArrow(int x, int y, int num)
{
	for (int i = 0; i < 100; ++i)
	{
		if (Obj_arrow[i]->dieSwitch == true)
		{
			Obj_arrow[i]->x = x;
			Obj_arrow[i]->y = y;
			Obj_arrow[i]->Number = num;
			Obj_arrow[i]->dieSwitch = false;
			return;
		}
	}
}
