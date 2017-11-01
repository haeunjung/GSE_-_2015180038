/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "object.h"

Renderer *g_Renderer = NULL;

Object* C_Object[50];
int count = 0;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);


	// Renderer Test
	for (int i = 0; i < count; i++)
	{
		int random_X, random_Y, sel;

		random_X = rand() % 3 - 1;
		random_Y = rand() % 3 - 1;

		if (random_X == 0 || random_Y == 0)
		{
			random_X += 1;
			random_Y -= 1;
		}

		C_Object[i]->Update(random_X, random_Y);
		g_Renderer->DrawSolidRect(C_Object[i]->X, C_Object[i]->Y, C_Object[i]->Z, C_Object[i]->Size, C_Object[i]->R, C_Object[i]->G, C_Object[i]->B, C_Object[i]->A);
	}

	glutSwapBuffers();
}

void Idle(void)
{

	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	if((button == GLUT_LEFT_BUTTON && state == GLUT_UP) )
	{
	 		if (count < 50)
				{
			 		C_Object[count] = new Object();
			 		C_Object[count]->SetObject(x - 250, 250 - y, 0, 5, 1, 1, 1, 1);
			

			 			count++;
			 	}
	
	}

	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}



	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

