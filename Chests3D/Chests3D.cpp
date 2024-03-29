﻿#include <iostream>
#include<string>
#include<random>
#include<time.h>

#ifndef LIST_H
#define LIST_H
#include "Libraries/List.h"
#endif
//#include "Libraries/List.cpp"
#ifndef GAME_SPACE_H
#define GAME_SPACE_H
#include"Libraries/GameSpace.h"
#endif

#ifndef COLLISIONS_H
#define COLLISIONS_H
//#include "Libraries/Collisions.h"
#endif

#ifndef MATRIX_H
#define MATRIX_H
#include "Libraries/Matrix.h"
#endif

//#include "Libraries/GameSpace.cpp"
#include <GL/glut.h>//nupengl.core

List* list = new List(1);
GameSpace * gamespase1 = new GameSpace(*list);

const int BLACK_KING = -1, BLACK_SUPER_QUIN = -2, BLACK_QUIN_DIAGONAL = -3, BLACK_QUIN = -4, BLACK_BISHOP_DIAGONAL = -5, BLACK_BISHOP = -6, BLACK_KNIGHT_DIAGONAL = -7, BLACK_KNIGHT = -8, BLACK_ROOK = -9, BLACK_PAWN = -10, _VOID = 0, WHITE_KING = 1, WHITE_SUPER_QUIN = 2, WHITE_QUIN_DIAGONAL = 3, WHITE_QUIN = 4, WHITE_BISHOP_DIAGONAL = 5, WHITE_BISHOP = 6, WHITE_KNIGHT_DIAGONAL = 7, WHITE_KNIGHT = 8, WHITE_ROOK = 9, WHITE_PAWN = 10;

float distance_between_figures = 3.0f;

const float DELTA_DISTANCE_BETWEEN_FIGURES = 0.5f, MAX_DISTANCE_BETWEEN_FIGURES = 10.0f, MIN_DISTANCE_BETWEEN_FIGURES = 2.0f, DEFAULT_ANGLE_OF_SHOW = 60.0, Z_NEAR = 0.1, Z_FAR = 1000.0;

const float PI = 3.141592653589793;

const bool WHITE = true, BLACK = false;

int window_wight = 1000, window_hight = 800;

int window_x_left_up_position = 400, window_y_left_up_position = 400;

int cell_x_position = 4, cell_y_position = 4, cell_z_position = 4;

int x_target_position = 0, y_target_position = 0, z_target_position = 0;

int x_figure_position = 0, y_figure_position = 0, z_figure_position = 0;

int special_key_number = 0, normal_key_number = 0;

short move_x = 0, move_y = 0, move_z = 0;//возможность перемещения по оси -1 - REVERS; 0 - STOP; 1 - FORVARD

short draw_grid = 2;

float red = 1.0f, blue = 1.0f, green = 1.0f, alpha = 0.1f;

double angle_xz = 1.48, angle_xy = -0.54, d_angle_xz = 0, d_angle_xy = 0;// угол поворота камеры

float mouse_x_position_last = NULL, mouse_y_position_last = NULL;// значение предыдущей позиции мыши

float lx = sin(angle_xz) * cos(angle_xy), ly = sin(angle_xy), lz = -cos(angle_xz) * cos(angle_xy);// координаты вектора направления движения камеры

float dx = 0.0f, dy = 0.0f, dz = 0.0f;// смещения по осям

float x = -4.1f, y = 17.0f, z = 9.2f;// начальная позиция камеры

float camera_speed = 0.1f, mouse_modification = 0.001f, angle_of_show = DEFAULT_ANGLE_OF_SHOW;// скорость

float wight_d_hight;

float delta_red = 0.4f, delta_green = 0.4f, delta_blue = 0.4f;//Разница цветов между фигурами

bool forvard_backvard = true;

bool show_lines = false, draw_all_variants = true;

bool bottoms[100];
bool mouse_motion = false;

bool target_figure = false, draw_target_figure_all_variants = false, target_any_variants = false;

double __angle__ = 0.3393;


bool CellInSpace(int x, int y, int z)
{
	return (x < list->GetElement(0) && x > -1 && y < list->GetElement(1) && y > -1 && z < list->GetElement(2) && z > -1);
}

//RENDER's FUNCTIONS...

void DrawCube(double x_position, double y_position, double z_position, double rang)
{
	glBegin(GL_TRIANGLES);

	glColor4f(0.9f, 0.6f, 0.3f, 0.5f);

	glVertex3f(x_position + rang, y_position + rang, z_position + rang);
	glVertex3f(x_position - rang, y_position + rang, z_position + rang);
	glVertex3f(x_position + rang, y_position - rang, z_position + rang);

	glVertex3f(x_position - rang, y_position + rang, z_position + rang);
	glVertex3f(x_position + rang, y_position - rang, z_position + rang);
	glVertex3f(x_position - rang, y_position - rang, z_position + rang);

	glColor4f(0.9f, 0.3f, 0.6f, 0.5f);

	glVertex3f(x_position + rang, y_position + rang, z_position - rang);
	glVertex3f(x_position - rang, y_position + rang, z_position - rang);
	glVertex3f(x_position + rang, y_position - rang, z_position - rang);

	glVertex3f(x_position - rang, y_position + rang, z_position - rang);
	glVertex3f(x_position + rang, y_position - rang, z_position - rang);
	glVertex3f(x_position - rang, y_position - rang, z_position - rang);

	glColor4f(0.6f, 0.9f, 0.3f, 0.5f);

	glVertex3f(x_position + rang, y_position + rang, z_position + rang);
	glVertex3f(x_position - rang, y_position + rang, z_position + rang);
	glVertex3f(x_position + rang, y_position + rang, z_position - rang);

	glVertex3f(x_position - rang, y_position + rang, z_position + rang);
	glVertex3f(x_position + rang, y_position + rang, z_position - rang);
	glVertex3f(x_position - rang, y_position + rang, z_position - rang);

	glColor4f(0.6f, 0.3f, 0.9f, 0.5f);

	glVertex3f(x_position + rang, y_position - rang, z_position + rang);
	glVertex3f(x_position - rang, y_position - rang, z_position + rang);
	glVertex3f(x_position + rang, y_position - rang, z_position - rang);

	glVertex3f(x_position - rang, y_position - rang, z_position + rang);
	glVertex3f(x_position + rang, y_position - rang, z_position - rang);
	glVertex3f(x_position - rang, y_position - rang, z_position - rang);

	glColor4f(0.3f, 0.9f, 0.6f, 0.5f);

	glVertex3f(x_position + rang, y_position + rang, z_position + rang);
	glVertex3f(x_position + rang, y_position - rang, z_position + rang);
	glVertex3f(x_position + rang, y_position + rang, z_position - rang);

	glVertex3f(x_position + rang, y_position - rang, z_position + rang);
	glVertex3f(x_position + rang, y_position + rang, z_position - rang);
	glVertex3f(x_position + rang, y_position - rang, z_position - rang);

	glColor4f(0.3f, 0.6f, 0.9f, 0.5f);

	glVertex3f(x_position - rang, y_position + rang, z_position + rang);
	glVertex3f(x_position - rang, y_position - rang, z_position + rang);
	glVertex3f(x_position - rang, y_position + rang, z_position - rang);

	glVertex3f(x_position - rang, y_position - rang, z_position + rang);
	glVertex3f(x_position - rang, y_position + rang, z_position - rang);
	glVertex3f(x_position - rang, y_position - rang, z_position - rang);
	glEnd();
}

void DrawCube()
{
	glutSolidCube(1.0f);
}

void DrawCell()
{
	const float rang = 0.3f;

	if (target_figure && gamespase1->IsMoveWhite())
	{
		glColor3f(0.8f, 0.6f, 0.8f);
	}
	else if (target_figure && gamespase1->IsMoveBlack())
	{
		glColor3f(0.2f, 0.4f, 0.2f);
	}
	else
	{
		glColor3f(0.45f, 0.55f, 0.45f);
	}

	glPushMatrix();
	glTranslatef(cell_x_position * distance_between_figures, cell_y_position * distance_between_figures, cell_z_position * distance_between_figures);
	glutSolidCube(rang);
	glColor3f(1.0f, 0.0f, 0.0f);
	if (show_lines)
	{
		glBegin(GL_LINES);
		glVertex3f(-rang * 0.51f, -rang * 0.51f, -rang * 0.51f);
		glVertex3f(-rang * 0.51f, -rang * 0.51f, rang * 0.51f);

		glVertex3f(rang * 0.51f, -rang * 0.51f, -rang * 0.51f);
		glVertex3f(rang * 0.51f, -rang * 0.51f, rang * 0.51f);

		glVertex3f(-rang * 0.51f, rang * 0.51f, -rang * 0.51f);
		glVertex3f(-rang * 0.51f, rang * 0.51f, rang * 0.51f);

		glVertex3f(rang * 0.51f, rang * 0.51f, -rang * 0.51f);
		glVertex3f(rang * 0.51f, rang * 0.51f, rang * 0.51f);


		glVertex3f(-rang * 0.51f, -rang * 0.51f, -rang * 0.51f);
		glVertex3f(-rang * 0.51f, rang * 0.51f, -rang * 0.51f);

		glVertex3f(rang * 0.51f, -rang * 0.51f, -rang * 0.51f);
		glVertex3f(rang * 0.51f, rang * 0.51f, -rang * 0.51f);

		glVertex3f(-rang * 0.51f, -rang * 0.51f, rang * 0.51f);
		glVertex3f(-rang * 0.51f, rang * 0.51f, rang * 0.51f);

		glVertex3f(rang * 0.51f, -rang * 0.51f, rang * 0.51f);
		glVertex3f(rang * 0.51f, rang * 0.51f, rang * 0.51f);


		glVertex3f(-rang * 0.51f, -rang * 0.51f, -rang * 0.51f);
		glVertex3f(rang * 0.51f, -rang * 0.51f, -rang * 0.51f);

		glVertex3f(-rang * 0.51f, rang * 0.51f, -rang * 0.51f);
		glVertex3f(rang * 0.51f, rang * 0.51f, -rang * 0.51f);

		glVertex3f(-rang * 0.51f, -rang * 0.51f, rang * 0.51f);
		glVertex3f(rang * 0.51f, -rang * 0.51f, rang * 0.51f);

		glVertex3f(-rang * 0.51f, rang * 0.51f, rang * 0.51f);
		glVertex3f(rang * 0.51f, rang * 0.51f, rang * 0.51f);
		glEnd();
	}
	glPopMatrix();
}

void DrawBishopDiagonal(bool white, float figure_size)
{
	const double i = 0.5, scale = 0.3393, lines_scale = 1.002;
	if (white)
	{
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
	}
	else
	{
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
	}
	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glRotatef(35.26438968275462, 0, 0, 1);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glRotatef(35.26438968275462, 0, 0, 1);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glRotatef(135, 0, 1, 0);
	glRotatef(35.26438968275462, 0, 0, 1);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glRotatef(-135, 0, 1, 0);
	glRotatef(35.26438968275462, 0, 0, 1);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(i), 0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glRotatef(-35.26438968275462, 0, 0, 1);
	glRotatef(180, 1, 0, 0);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glRotatef(-35.26438968275462, 0, 0, 1);
	glRotatef(180, 1, 0, 0);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glRotatef(135, 0, 1, 0);
	glRotatef(-35.26438968275462, 0, 0, 1);
	glRotatef(180, 1, 0, 0);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glRotatef(-135, 0, 1, 0);
	glRotatef(-35.26438968275462, 0, 0, 1);
	glRotatef(180, 1, 0, 0);
	glTranslatef(scale, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(i), 0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i), 0.0, 0.0);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	if (show_lines)
	{
		if (white)
		{
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		else
		{
			glColor3f(0.8f, 0.8f, 0.8f);
		}
		glPushMatrix();
		glRotatef(45, 0, 1, 0);
		glRotatef(35.26438968275462, 0, 0, 1);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(i), 0);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(i), 0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(0.0, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(-45, 0, 1, 0);
		glRotatef(35.26438968275462, 0, 0, 1);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(i), 0);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(i), 0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(0.0, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(135, 0, 1, 0);
		glRotatef(35.26438968275462, 0, 0, 1);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(i), 0);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(i), 0);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(0.0, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(-135, 0, 1, 0);
		glRotatef(35.26438968275462, 0, 0, 1);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(i), 0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(45, 0, 1, 0);
		glRotatef(-35.26438968275462, 0, 0, 1);
		glRotatef(180, 1, 0, 0);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(i), 0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(-45, 0, 1, 0);
		glRotatef(-35.26438968275462, 0, 0, 1);
		glRotatef(180, 1, 0, 0);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(i), 0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(135, 0, 1, 0);
		glRotatef(-35.26438968275462, 0, 0, 1);
		glRotatef(180, 1, 0, 0);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(i), 0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(-135, 0, 1, 0);
		glRotatef(-35.26438968275462, 0, 0, 1);
		glRotatef(180, 1, 0, 0);
		glTranslatef(scale + lines_scale - 1, 0, 0);
		glScalef(lines_scale, lines_scale, lines_scale);

		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(figure_size* cos(i), 0.0, 0.0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(i), 0);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(0.0, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(0.0, figure_size* sin(i), 0);

		glEnd();
		glPopMatrix();
	}
}

void DrawBishop(bool white, float figure_size)
{
	const double i = 0.5, scale = 0.3;
	if (white)
	{
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
	}
	else
	{
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
	}

	glPushMatrix();
	glRotatef(45.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(135.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-135.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(135.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-135.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(45.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(135.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(-135.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, sin(i), 0);
	glVertex3f(scale, 0, sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, sin(i));
	glVertex3f(scale, -sin(i), 0);

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, -sin(i), 0);
	glVertex3f(scale, 0, -sin(i));

	glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
	glVertex3f(scale, 0, -sin(i));
	glVertex3f(scale, sin(i), 0);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	if (show_lines)
	{
		if (white)
		{
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		else
		{
			glColor3f(0.8f, 0.8f, 0.8f);
		}

		glPushMatrix();
		glRotatef(45.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(135.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(-135.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size * cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();


		glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(135.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(-135.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(-45.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();


		glPushMatrix();
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(45.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(135.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(-135.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glPushMatrix();
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(figure_size* cos(-i) + scale, 0.0, 0.0);
		glVertex3f(scale, 0, -sin(i));


		glVertex3f(scale, sin(i), 0);
		glVertex3f(scale, 0, sin(i));

		glVertex3f(scale, 0, sin(i));
		glVertex3f(scale, -sin(i), 0);

		glVertex3f(scale, -sin(i), 0);
		glVertex3f(scale, 0, -sin(i));

		glVertex3f(scale, 0, -sin(i));
		glVertex3f(scale, sin(i), 0);

		glEnd();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
}

void DrawKnightDiagonal(bool white, float figure_size)
{
	const double i = 0.5;// угол отклонения от высоты
	const double xi = 0.5;// угол отклонения от оси x
	short forvard = 0;
	if (white)
	{
		forvard = 1;
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
	}
	else
	{
		forvard = -1;
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
	}

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);

	glutSolidSphere(0.25f * figure_size, figure_size * 10, figure_size * 10);

	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);


	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(120, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);


	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(210, xi, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);


	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(210, -xi, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);


	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	if (show_lines)
	{
		if (white)
		{
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		else
		{
			glColor3f(0.8f, 0.8f, 0.8f);
		}

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);


		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(120, 0.0, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(210, xi, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);


		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(210, -xi, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);


		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, 0.0, 0.0);
		glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glEnd();
		glPopMatrix();
	}
}

void DrawKnight(bool white, float figure_size)
{
	const double i = 0.5;// угол отклонения от высоты
	const double xi = 0.5;// угол отклонения от оси x
	short forvard = 0;
	if (white)
	{
		forvard = 1;
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
	}
	else
	{
		forvard = -1;
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
	}

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);

	glutSolidSphere(0.25f * figure_size, figure_size * 10, figure_size * 10);

	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(120, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);


	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(210, xi, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);


	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(210, -xi, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);


	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
	glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
	glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	if (show_lines)
	{
		if (white)
		{
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		else
		{
			glColor3f(0.8f, 0.8f, 0.8f);
		}

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);


		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(120, 0.0, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);


		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(210, xi, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);


		glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

		glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(210, -xi, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);


		glVertex3f(figure_size* cos(i)* forvard, figure_size* sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

		glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(figure_size* cos(-i)* forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(-i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);

		glVertex3f(2.0f * figure_size * cos(-i) * forvard, figure_size* sin(-i) * 0.5, figure_size* sin(i)* sqrt(3) / 2);
		glVertex3f(2.0f * figure_size * cos(i) * forvard, figure_size* sin(i), 0);

		glEnd();
		glPopMatrix();
	}
}

void DrawRook(bool white, float figure_size)
{
	const double scale = 4;
	if (white)
	{
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
	}
	else
	{
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
	}

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, scale * figure_size, 0);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);


	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);

	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);


	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, scale * figure_size, 0);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);


	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);

	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);


	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, scale * figure_size, 0);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);


	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);

	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(-figure_size, scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size, -scale * figure_size, 0);


	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
	glVertex3f(-figure_size, -scale * figure_size, 0);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glVertex3f(figure_size, -scale * figure_size, 0);
	glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
	glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	if (show_lines)
	{
		if (white)
		{
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		else
		{
			glColor3f(0.8f, 0.8f, 0.8f);
		}
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size, scale * figure_size, 0);
		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size, scale * figure_size, 0);

		glVertex3f(-figure_size, scale * figure_size, 0);
		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size, scale * figure_size, 0);


		glVertex3f(figure_size, scale * figure_size, 0);
		glVertex3f(figure_size, -scale * figure_size, 0);

		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size, scale * figure_size, 0);
		glVertex3f(-figure_size, -scale * figure_size, 0);

		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);


		glVertex3f(figure_size, -scale * figure_size, 0);
		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size, -scale * figure_size, 0);

		glVertex3f(-figure_size, -scale * figure_size, 0);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size, -scale * figure_size, 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size, scale * figure_size, 0);
		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size, scale * figure_size, 0);

		glVertex3f(-figure_size, scale * figure_size, 0);
		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size, scale * figure_size, 0);


		glVertex3f(figure_size, scale * figure_size, 0);
		glVertex3f(figure_size, -scale * figure_size, 0);

		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size, scale * figure_size, 0);
		glVertex3f(-figure_size, -scale * figure_size, 0);

		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);


		glVertex3f(figure_size, -scale * figure_size, 0);
		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size, -scale * figure_size, 0);

		glVertex3f(-figure_size, -scale * figure_size, 0);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size, -scale * figure_size, 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(figure_size, scale * figure_size, 0);
		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size, scale * figure_size, 0);

		glVertex3f(-figure_size, scale * figure_size, 0);
		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size, scale * figure_size, 0);


		glVertex3f(figure_size, scale * figure_size, 0);
		glVertex3f(figure_size, -scale * figure_size, 0);

		glVertex3f(figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size, scale * figure_size, 0);
		glVertex3f(-figure_size, -scale * figure_size, 0);

		glVertex3f(-figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);


		glVertex3f(figure_size, -scale * figure_size, 0);
		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, -scale * figure_size, figure_size * sqrt(3) / 2);
		glVertex3f(-figure_size, -scale * figure_size, 0);

		glVertex3f(-figure_size, -scale * figure_size, 0);
		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(-figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);

		glVertex3f(figure_size * 0.5, -scale * figure_size, -figure_size * sqrt(3) / 2);
		glVertex3f(figure_size, -scale * figure_size, 0);

		glEnd();
		glPopMatrix();
	}
}

void DrawPawn(bool white, float figure_size)
{
	const double i = 0.5;// угол отклонения от высоты
	const double xi = 0.5;// угол отклонения от оси x
	short forvard = 0;
	if (white)
	{
		forvard = 1;
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
	}
	else
	{
		forvard = -1;
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
	}

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);

	glutSolidSphere(0.25f * figure_size, figure_size * 10, figure_size * 10);

	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(120, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(210, xi, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(210, -xi, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
	glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

	glEnd();
	glPopMatrix();

	if (show_lines)
	{
		if (white)
		{
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		else
		{
			glColor3f(0.8f, 0.8f, 0.8f);
		}

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(120, 0.0, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(210, xi, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(210, -xi, 0.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(-i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);

		glVertex3f(figure_size * cos(-i) * forvard, figure_size * sin(-i) * 0.5, figure_size * sin(i) * sqrt(3) / 2);
		glVertex3f(figure_size * cos(i) * forvard, figure_size * sin(i), 0);

		glEnd();
		glPopMatrix();
	}
}

void DrawKing(bool white, float figure_size)
{
	if (white)
	{
		DrawBishopDiagonal(WHITE, figure_size);

		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		DrawBishopDiagonal(WHITE, figure_size);
		glPopMatrix();

		glPushMatrix();
		glRotatef(45.0, 0.0, 1.0, 0.0);
		DrawBishopDiagonal(WHITE, figure_size);
		glPopMatrix();

		glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		DrawBishopDiagonal(WHITE, figure_size);
		glPopMatrix();
	}
	else
	{
		DrawBishopDiagonal(BLACK, figure_size);

		glPushMatrix();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		DrawBishopDiagonal(BLACK, figure_size);
		glPopMatrix();

		glPushMatrix();
		glRotatef(45.0, 0.0, 1.0, 0.0);
		DrawBishopDiagonal(BLACK, figure_size);
		glPopMatrix();

		glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		DrawBishopDiagonal(BLACK, figure_size);
		glPopMatrix();
	}
}

void DrawSuperQuin(bool white, float figure_size)
{
	if (white)
	{
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
		DrawRook(WHITE, figure_size * 0.25f);
		DrawBishop(WHITE, figure_size * 1.0f);
		DrawBishopDiagonal(WHITE, figure_size * 1.0f);
	}
	else
	{
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
		DrawRook(BLACK, figure_size * 0.25f);
		DrawBishop(BLACK, figure_size * 1.0f);
		DrawBishopDiagonal(BLACK, figure_size * 1.0f);
	}
}

void DrawQuinDiagonal(bool white, float figure_size)
{
	if (white)
	{
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
		DrawRook(WHITE, figure_size * 0.25f);
		DrawBishopDiagonal(WHITE, figure_size * 1.0f);
	}
	else
	{
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
		DrawRook(BLACK, figure_size * 0.25f);
		DrawBishopDiagonal(BLACK, figure_size * 1.0f);
	}
}

void DrawQuin(bool white, float figure_size)
{
	if (white)
	{
		glColor3f(0.5f + delta_red, 0.5f + delta_green, 0.5f + delta_blue);
		DrawRook(WHITE, figure_size * 0.25f);
		DrawBishop(WHITE, figure_size * 1.0f);
	}
	else
	{
		glColor3f(0.5f - delta_red, 0.5f - delta_green, 0.5f - delta_blue);
		DrawRook(BLACK, figure_size * 0.25f);
		DrawBishop(BLACK, figure_size * 1.0f);
	}
}

void DrawFigure(int figure_type, float figure_size)
{
	switch (figure_type)
	{
	case WHITE_KING:
		DrawKing(WHITE, figure_size * 1.0f);
		break;
	case WHITE_SUPER_QUIN:
		DrawSuperQuin(WHITE, figure_size * 1.0f);
		break;
	case WHITE_QUIN_DIAGONAL:
		DrawQuinDiagonal(WHITE, figure_size * 1.0f);
		break;
	case WHITE_QUIN:
		DrawQuin(WHITE, figure_size * 1.0f);
		break;
	case WHITE_BISHOP_DIAGONAL:
		DrawBishopDiagonal(WHITE, figure_size * 1.0f);
		break;
	case WHITE_BISHOP:
		DrawBishop(WHITE, figure_size * 1.0f);
		break;
	case WHITE_KNIGHT_DIAGONAL:
		DrawKnightDiagonal(WHITE, figure_size * 0.6f);
		break;
	case WHITE_KNIGHT:
		DrawKnight(WHITE, figure_size * 0.6f);
		break;
	case WHITE_ROOK:
		DrawRook(WHITE, figure_size * 0.25f);
		break;
	case WHITE_PAWN:
		DrawPawn(WHITE, figure_size * 1.0f);
		break;
	case BLACK_KING:
		DrawKing(BLACK, figure_size * 1.0f);
		break;
	case BLACK_SUPER_QUIN:
		DrawSuperQuin(BLACK, figure_size * 1.0f);
		break;
	case BLACK_QUIN_DIAGONAL:
		DrawQuinDiagonal(BLACK, figure_size * 1.0f);
		break;
	case BLACK_QUIN:
		DrawQuin(BLACK, figure_size * 1.0f);
		break;
	case BLACK_BISHOP_DIAGONAL:
		DrawBishopDiagonal(BLACK, figure_size * 1.0f);
		break;
	case BLACK_BISHOP:
		DrawBishop(BLACK, figure_size * 1.0f);
		break;
	case BLACK_KNIGHT_DIAGONAL:
		DrawKnightDiagonal(BLACK, figure_size * 0.56f);
		break;
	case BLACK_KNIGHT:
		DrawKnight(BLACK, figure_size * 0.56f);
		break;
	case BLACK_ROOK:
		DrawRook(BLACK, figure_size * 0.25f);
		break;
	case BLACK_PAWN:
		DrawPawn(BLACK, figure_size * 1.0f);
		break;
	}
}

void DrawAllFigures()
{
	glPushMatrix();
	glTranslatef(1000.0f, 1000.0f, 1000.0f);
	DrawCube();
	glPopMatrix();// баг + баг - костыль = 0

	for (int x_pos = 0; x_pos < 8; x_pos++)
	{
		for (int y_pos = 0; y_pos < 8; y_pos++)
		{
			for (int z_pos = 0; z_pos < 8; z_pos++)
			{
				glPushMatrix();
				glTranslatef(x_pos * distance_between_figures, y_pos * distance_between_figures, z_pos * distance_between_figures);
				DrawFigure(gamespase1->GetPoint(x_pos + y_pos * list->GetElement(0) + z_pos * list->GetElement(0) * list->GetElement(1)), 1.0f);
				glPopMatrix();
			}
		}
	}
}

void DrawAllVariants()
{
	for (int n = 0; n < list->GetElement(0) * list->GetElement(1) * list->GetElement(2); n++)
	{
		if (gamespase1->MeetGameRule(cell_x_position, cell_y_position, cell_z_position, n))
		{
			glPushMatrix();
			glTranslatef(n % list->GetElement(0) * distance_between_figures, (n / list->GetElement(0)) % list->GetElement(1) * distance_between_figures, (n / (list->GetElement(0) * list->GetElement(1))) % list->GetElement(2) * distance_between_figures);
			glColor3f(1.0f, 0.0f, 0.0f);
			glutSolidCube(0.2f);
			glPopMatrix();
		}
	}
}

void DrawAllVariants(int x_position, int y_position, int z_position, float red_pomponent, float blue_pomponent, float green_pomponent)
{
	for (int n = 0; n < list->GetElement(0) * list->GetElement(1) * list->GetElement(2); n++)
	{
		if (gamespase1->MeetGameRule(x_position, y_position, z_position, n))
		{
			glPushMatrix();
			glTranslatef(n % list->GetElement(0) * distance_between_figures, (n / list->GetElement(0)) % list->GetElement(1) * distance_between_figures, (n / (list->GetElement(0) * list->GetElement(1))) % list->GetElement(2) * distance_between_figures);
			glColor3f(red_pomponent, blue_pomponent, green_pomponent);
			glutSolidCube(0.2f);
			glPopMatrix();
			if (!target_any_variants)
			{
				target_any_variants = true;
			}
		}
	}
}

void DrawSceneGrid()
{
	if (gamespase1->IsMoveBlack())
	{
		glColor3f(0.0f, 0.0f, 0.0f);
	}
	else if(gamespase1->IsMoveWhite())
	{
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	for (int x = 0; x <= list->GetElement(0); x++)
	{
		for (int y = 0; y <= list->GetElement(1); y++)
		{
			glPushMatrix();
			glTranslatef((x - 0.5f) * distance_between_figures, (y - 0.5f) * distance_between_figures, -0.5f * distance_between_figures);
			glBegin(GL_LINES);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, list->GetElement(2) * distance_between_figures);
			glEnd();
			glPopMatrix();
		}
	}
	for (int y = 0; y <= list->GetElement(1); y++)
	{
		for (int z = 0; z <= list->GetElement(2); z++)
		{
			glPushMatrix();
			glTranslatef(-0.5f * distance_between_figures, (y - 0.5f) * distance_between_figures, (z - 0.5f) * distance_between_figures);
			glBegin(GL_LINES);
			glVertex3f(0, 0, 0);
			glVertex3f(list->GetElement(0) * distance_between_figures, 0, 0);
			glEnd();
			glPopMatrix();
		}
	}
	for (int z = 0; z <= list->GetElement(2); z++)
	{
		for (int x = 0; x <= list->GetElement(0); x++)
		{
			glPushMatrix();
			glTranslatef((x - 0.5f) * distance_between_figures, -0.5f * distance_between_figures, (z - 0.5f) * distance_between_figures);
			glBegin(GL_LINES);
			glVertex3f(0, 0, 0);
			glVertex3f(0, list->GetElement(1) * distance_between_figures, 0);
			glEnd();
			glPopMatrix();
		}
	}
}

void DrawAll()
{
	DrawAllFigures();
	if (draw_all_variants)
	{
		DrawAllVariants();
	}
	switch (draw_grid)
	{
	case 0:
		show_lines = false;
		break;
	case 1:
		DrawSceneGrid();
		break;
	case 3:
		DrawSceneGrid();
	case 2:
		show_lines = true;
		break;
	}
	if (draw_target_figure_all_variants && gamespase1->IsMoveBlack())
	{
		DrawAllVariants(x_figure_position, y_figure_position, z_figure_position, 0.1f, 0.1f, 0.1f);
	}
	else if (draw_target_figure_all_variants)
	{
		DrawAllVariants(x_figure_position, y_figure_position, z_figure_position, 0.9f, 0.9f, 0.9f);
	}
	DrawCell();
}

void DrawPoligon()
{
	glColor3f(0.2f, 0.9f, 0.2f);//Установка цвета фигуры.

	glBegin(GL_TRIANGLES); // полигон с коондинатами
	glVertex3f(-100.0f, -4.0f, -100.0f);
	glVertex3f(-100.0f, -4.0f, 100.0f);
	glVertex3f(100.0f, -4.0f, 100.0f);

	glVertex3f(-100.0f, -4.0f, -100.0f);
	glVertex3f(100.0f, -4.0f, -100.0f);
	glVertex3f(100.0f, -4.0f, 100.0f);
}

void RecalculateCamera()
{
	angle_xy += d_angle_xy;
	angle_xz += d_angle_xz;
	if (angle_xy > 1.57077)
	{
		angle_xy = 1.57077;
	}
	else if (angle_xy < -1.57077)
	{
		angle_xy = -1.57077;
	}
	if (angle_xz > PI)
	{
		angle_xz -= 2 * PI;
	}
	else if (angle_xz < -PI)
	{
		angle_xz += 2 * PI;
	}
	lx = sin(angle_xz) * cos(angle_xy);
	ly = sin(angle_xy);
	lz = -cos(angle_xz) * cos(angle_xy);
	y += camera_speed * move_y;
	if (forvard_backvard)
	{
		x += sin(angle_xz) * camera_speed * move_x;
		z += -cos(angle_xz) * camera_speed * move_z;
	}
	else
	{
		x += cos(angle_xz) * camera_speed * move_x;
		z += -sin(angle_xz) * camera_speed * move_z;
	}

}

void RenderCamera()
{
	RecalculateCamera();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);// установка камеры
}

void RenderScene()
{

	glClearColor(0.4f, 0.4f, 1.0f, 1.0f);// цвет фонa

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	glLoadIdentity();// обнуление трансформации

	RenderCamera();

	DrawAll();

	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();

	if (!mouse_motion)
	{
		d_angle_xy = 0;
		d_angle_xz = 0;
	}
	mouse_motion = false;
}

void ChangeSize(int window_wight_now, int window_hight_now)
{

	// предупредим деление на ноль
	// если окно сильно перетянуто будет
	if (window_hight_now == 0)
	{
		window_hight_now = 1;
	}

	float ratio = 1.0 * window_wight_now / window_hight_now;

	wight_d_hight = ratio;

	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);

	// Reset матрицы
	glLoadIdentity();

	// определяем окно просмотра
	glViewport(0, 0, window_wight_now, window_hight_now);

	// установить корректную перспективу.
	gluPerspective(angle_of_show, ratio, Z_NEAR, Z_FAR);

	// вернуться к модели
	glMatrixMode(GL_MODELVIEW);

	window_wight = window_wight_now;
	window_hight = window_hight_now;
}

//KEIS' FUNCTIONS...

void PressSpecialKey(int key, int mouse_x_position, int mouse_y_position)
{
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	special_key_number = key;
	switch (key)
	{
	case GLUT_KEY_PAGE_UP:
		cell_y_position++;
		if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
		{
			cell_y_position--;
		}
		break;
	case GLUT_KEY_PAGE_DOWN:
		cell_y_position--;
		if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
		{
			cell_y_position++;
		}
		break;
	case GLUT_KEY_UP:
		if (-0.75 * PI <= angle_xz && angle_xz <= -0.25 * PI)
		{
			cell_x_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position++;
			}
		}
		else if (-0.25 * PI <= angle_xz && angle_xz <= 0.25 * PI)
		{
			cell_z_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position++;
			}
		}
		else if(0.25 * PI <= angle_xz && angle_xz <= 0.75 * PI)
		{
			cell_x_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position--;
			}
		}
		else
		{
			cell_z_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position--;
			}
		}
		break;
	case GLUT_KEY_DOWN:
		if (-0.75 * PI <= angle_xz && angle_xz <= -0.25 * PI)
		{
			cell_x_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position--;
			}
		}
		else if (-0.25 * PI <= angle_xz && angle_xz <= 0.25 * PI)
		{
			cell_z_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position--;
			}
		}
		else if (0.25 * PI <= angle_xz && angle_xz <= 0.75 * PI)
		{
			cell_x_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position++;
			}
		}
		else
		{
			cell_z_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position++;
			}
		}
		break;
	case GLUT_KEY_LEFT:
		if (-0.75 * PI <= angle_xz && angle_xz <= -0.25 * PI)
		{
			cell_z_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position--;
			}
		}
		else if (-0.25 * PI <= angle_xz && angle_xz <= 0.25 * PI)
		{
			cell_x_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position++;
			}
		}
		else if (0.25 * PI <= angle_xz && angle_xz <= 0.75 * PI)
		{
			cell_z_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position++;
			}
		}
		else
		{
			cell_x_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position--;
			}
		}
		break;
	case GLUT_KEY_RIGHT:
		if (-0.75 * PI <= angle_xz && angle_xz <= -0.25 * PI)
		{
			cell_z_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position++;
			}
		}
		else if (-0.25 * PI <= angle_xz && angle_xz <= 0.25 * PI)
		{
			cell_x_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position--;
			}
		}
		else if (0.25 * PI <= angle_xz && angle_xz <= 0.75 * PI)
		{
			cell_z_position++;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_z_position--;
			}
		}
		else
		{
			cell_x_position--;
			if (!CellInSpace(cell_x_position, cell_y_position, cell_z_position))
			{
				cell_x_position++;
			}
		}
		break;
	default:
		std::cout << "Special: " << key << std::endl;
		break;
	}
}

void PressUpSpecialKey(int key, int mouse_x_position, int mouse_y_position)
{
	glutSetKeyRepeat(GLUT_KEY_REPEAT_DEFAULT);
	special_key_number = 0;
}

void PressNormalKey(unsigned char key, int mouse_x_position, int mouse_y_position)
{
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	normal_key_number = key;
	switch (key)
	{
	case 13://Enter
		if (!target_figure && (gamespase1->GetPoint(cell_x_position, cell_y_position, cell_z_position) > 0 && gamespase1->IsMoveWhite() || gamespase1->GetPoint(cell_x_position, cell_y_position, cell_z_position) < 0 && gamespase1->IsMoveBlack()) || !target_any_variants)
		{
			x_figure_position = cell_x_position;
			y_figure_position = cell_y_position;
			z_figure_position = cell_z_position;
			draw_target_figure_all_variants = true;
			target_figure = true;
			target_any_variants = false;
		}
		else if (target_figure && x_target_position == cell_x_position && y_target_position == cell_y_position && z_target_position == cell_z_position)
		{
			draw_target_figure_all_variants = false;
			target_figure = false;
		}
		else if(gamespase1->MeetGameRule(x_figure_position, y_figure_position, z_figure_position, cell_x_position, cell_y_position, cell_z_position))
		{
			gamespase1->ReplasePoints(cell_x_position, cell_y_position, cell_z_position, x_figure_position, y_figure_position, z_figure_position);
			gamespase1->SetPoint(x_figure_position, y_figure_position, z_figure_position, 0);
			if (gamespase1->IsMoveWhite())
			{
				gamespase1->MoveBlack();
			}
			else
			{
				gamespase1->MoveWhite();
			}
			draw_target_figure_all_variants = false;
			target_figure = false;
		}
		else
		{
			draw_target_figure_all_variants = false;
			target_figure = false;
		}
		break;
	case 27://Esc
		exit(0);
		break;
	case 'a':
	case 244://ф a
		forvard_backvard = false;
		move_x = -1;
		move_z = 1;
		break;
	case 'c':
	case 241:
		if (gamespase1->IsMoveBlack())
		{
			gamespase1->MoveWhite();
		}
		else
		{
			gamespase1->MoveBlack();
		}
		break;
	case 'd':
	case 226://в d
		forvard_backvard = false;
		move_x = 1;
		move_z = -1;
		break;
	case 'e':
	case 243://у e
		move_y = 1;
		break;
	case 'g':
	case 239://g п
		if (draw_grid < 3)
		{
			draw_grid++;
		}
		else
		{
			draw_grid = 0;
		}
		break;
	case 'q':
	case 233://й q
		move_y = -1;
		break;
	case 's':
	case 251://ы s
		forvard_backvard = true;
		move_x = -1;
		move_z = -1;
		break;
	case 'w':
	case 246://ц w
		forvard_backvard = true;
		move_x = 1;
		move_z = 1;
		break;
	case 'x':
	case 247://ч x
		std::cout << "x = " << x << '	' << "y = " << y << '	' << "z = " << z << std::endl
			<< "angle_xz = " << angle_xz << '	' << "angle_xy = " << angle_xy << std::endl
			<< "cell_x = " << cell_x_position << '	' << "cell_y = " << cell_y_position << '	' << "cell_z = " << cell_z_position << std::endl
			<< "grid_number = " << draw_grid << " angle_of_show = " << angle_of_show << std::endl
			<< "windows_wight " << window_wight << "	window_hight " << window_hight << std::endl;
		break;
	case '2':
		__angle__ -= 0.0001;
		break;
	case '8':
		__angle__ += 0.0001;
		break;
	case '=':
	case '+':
		if (distance_between_figures < MAX_DISTANCE_BETWEEN_FIGURES)
		distance_between_figures += DELTA_DISTANCE_BETWEEN_FIGURES;
		break;
	case '-':
	case '_':
		if (distance_between_figures > MIN_DISTANCE_BETWEEN_FIGURES)
		distance_between_figures -= DELTA_DISTANCE_BETWEEN_FIGURES;
		break;
	default:
		for (int n = 0; n < 500; n++)
		{
			if (key == n)
			{
				std::cout << "Normal: " << key << " Number: " << n << std::endl;
			}
		}
		break;
	}
}

void PressUpNormalKey(unsigned char key, int mouse_x_position, int mouse_y_position)
{
	normal_key_number = 0;
	switch (key)
	{
	case 'a':
	case 'd':
	case 244:
	case 226:
		move_x = 0;
		move_z = 0;
		break;
	case 'e':
	case 'q':
	case 243:
	case 233:
		move_y = 0;
		break;
	case 's':
	case 'w':
	case 251:
	case 246:
		move_x = 0;
		move_z = 0;
		break;
	}
	glutSetKeyRepeat(GLUT_KEY_REPEAT_DEFAULT);
}

//MOUSE's FUNCTIONS...

void MouseFunc(int buttom, int buttom_state, int mouse_x_position, int mouse_y_position)
{
	float ratio;
	if (buttom_state == GLUT_DOWN)
	{
		switch (buttom)
		{
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			bottoms[2] = true;
			mouse_x_position_last = mouse_x_position;
			mouse_y_position_last = mouse_y_position;
			break;
		case GLUT_MIDDLE_BUTTON:
			angle_of_show = DEFAULT_ANGLE_OF_SHOW;
			// предупредим деление на ноль если окно сильно перетянуто будет

			ratio = 1.0 * window_wight / window_hight;

			wight_d_hight = ratio;

			// используем матрицу проекции
			glMatrixMode(GL_PROJECTION);

			// Reset матрицы
			glLoadIdentity();

			// определяем окно просмотра
			glViewport(0, 0, window_wight, window_hight);

			// установить корректную перспективу.
			gluPerspective(angle_of_show, ratio, Z_NEAR, Z_FAR);

			// вернуться к модели
			glMatrixMode(GL_MODELVIEW);
			break;
		case 3://колёсико вверх
			angle_of_show -= 1;
			// предупредим деление на ноль если окно сильно перетянуто будет

			ratio = 1.0 * window_wight / window_hight;

			wight_d_hight = ratio;

			// используем матрицу проекции
			glMatrixMode(GL_PROJECTION);

			// Reset матрицы
			glLoadIdentity();

			// определяем окно просмотра
			glViewport(0, 0, window_wight, window_hight);

			// установить корректную перспективу.
			gluPerspective(angle_of_show, ratio, Z_NEAR, Z_FAR);

			// вернуться к модели
			glMatrixMode(GL_MODELVIEW);
			break;
		case 4:
			angle_of_show += 1;
			// предупредим деление на ноль если окно сильно перетянуто будет

			ratio = 1.0 * window_wight / window_hight;

			wight_d_hight = ratio;

			// используем матрицу проекции
			glMatrixMode(GL_PROJECTION);

			// Reset матрицы
			glLoadIdentity();

			// определяем окно просмотра
			glViewport(0, 0, window_wight, window_hight);

			// установить корректную перспективу.
			gluPerspective(angle_of_show, ratio, Z_NEAR, Z_FAR);

			// вернуться к модели
			glMatrixMode(GL_MODELVIEW);
			break;
			break;
		default://колёсико вниз
			std::cout << "Mouse buttom " << buttom << std::endl;
			break;
		}
	}
	if (buttom_state == GLUT_UP)
	{
		switch (buttom)
		{
		case GLUT_RIGHT_BUTTON:
			bottoms[2] = false;
			mouse_x_position_last = NULL;
			mouse_y_position_last = NULL;
			d_angle_xz = 0;
			d_angle_xy = 0;
			break;
		}
	}
}

void MotionFunc(int mouse_x_position, int mouse_y_position)
{
	mouse_motion = true;
	if (bottoms[2])
	{
		d_angle_xz = (mouse_x_position - mouse_x_position_last) * mouse_modification;
		d_angle_xy = (-mouse_y_position + mouse_y_position_last) * mouse_modification;
		mouse_x_position_last = mouse_x_position;
		mouse_y_position_last = mouse_y_position;
	}
}

void MotionPassiveFunc(int mouse_x_position, int mouse_y_position)
{

}

int main(int argc, char** argv)//* int argc - количество аргументов | char** argv - их описание в виде указателя на строку
{
	gamespase1->MoveWhite();

	glEnable(GL_DEPTH);

	glutInit(&argc, argv);
	glutInitWindowPosition(960 - window_wight / 2, 540 - window_hight / 2);
	glutInitWindowSize(window_wight, window_hight);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Chess3D");

	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 1.0f);
	glPopMatrix();

	glutDisplayFunc(RenderScene);

	glutReshapeFunc(ChangeSize);// регистрирует для GLUT функцию обратного вызова

	glutIdleFunc(RenderScene);// регистрирует функцию обратного вызова, которая будет вызываться когда само приложение находится в режиме ожидания

	glutKeyboardFunc(PressNormalKey);
	glutKeyboardUpFunc(PressUpNormalKey);
	glutSpecialFunc(PressSpecialKey);
	glutSpecialUpFunc(PressUpSpecialKey);// клавиатура

	glutMouseFunc(MouseFunc);
	glutMotionFunc(MotionFunc);
	glutPassiveMotionFunc(MotionPassiveFunc);// мышь

	glutMainLoop();

	glutSetKeyRepeat(GLUT_KEY_REPEAT_DEFAULT);
}
