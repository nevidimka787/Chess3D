#include"List.h"
#include<iostream>

using namespace std;
List::List(int type_of_game)
{
	switch (type_of_game)
	{
	case 1://6 x 6 x 2
	{
		*type = type_of_game;
		*lenght = 8;
		*weight = 8;
		*height = 8;
		//entities = new int[*lenght * *weight * *height];
		/*
		0 - void
		WHITE
		1 - King
		2 - Super Queen
		3 - Queen diagonal
		4 - Queen
		5 - Super Bishop
		6 - Bishop
		7 - Super Knight
		8 - Knight
		9 - Rook
		10 - Pawn
		BLACK
		-1 - King
		-2 - Super Queen
		-3 - Queen diagonale
		-4 - Queen
		-5 - Super Bishop
		-6 - Bishop
		-7 - Super Knight
		-8 - Knight
		-9 - Rook
		-10 - Pawn
		*/
		for (int n = 0; n < 512; n++)
		{
			entities[n] = 0;
		}
		/*

			0	1	2	3	4	5	6	7 >	Y
		0

		1		p	p	p	p	p	p

		2		p	r	bd	k	r	p

		3		p	kd	sq	qd	b	p

		4		p	b	q	ki	kd	p

		5		p	r	k	bd	r	p

		6		p	p	p	p	p	p

		7
		v
		Z

		*/
		for (int x = 0; x < 2; x++)
		{
			for (int y = 1; y < 7; y++)
			{
				for (int z = 1; z < 7; z++)
				{
					entities[x + y * 8 + z * 64] = 10;//(0, 1 , 1):(1, 6, 6) -> WHITE pawns
				}
			}
		}
		for (int x = 6; x < 8; x++)
		{
			for (int y = 1; y < 7; y++)
			{
				for (int z = 1; z < 7; z++)
				{
					entities[x + y * 8 + z * 64] = -10;//(6, 1 , 1):(7, 6, 6) -> BLACK pawns
				}
			}
		}
		entities[0 + 2 * 8 + 2 * 64] = 9;//WHITE rooks
		entities[0 + 5 * 8 + 2 * 64] = 9;
		entities[0 + 2 * 8 + 5 * 64] = 9;
		entities[0 + 5 * 8 + 5 * 64] = 9;
		entities[7 + 2 * 8 + 2 * 64] = -9;//BLACK rooks
		entities[7 + 5 * 8 + 2 * 64] = -9;
		entities[7 + 2 * 8 + 5 * 64] = -9;
		entities[7 + 5 * 8 + 5 * 64] = -9;

		entities[0 + 4 * 8 + 2 * 64] = 8;//WHITE knigth
		entities[0 + 3 * 8 + 5 * 64] = 8;
		entities[7 + 4 * 8 + 2 * 64] = -8;//BLACK knigth
		entities[7 + 3 * 8 + 5 * 64] = -8;

		entities[0 + 2 * 8 + 3 * 64] = 7;//WHITE knigth diagonal
		entities[0 + 5 * 8 + 4 * 64] = 7;
		entities[7 + 2 * 8 + 3 * 64] = -7;//BLACK knigth diagonal
		entities[7 + 5 * 8 + 4 * 64] = -7;

		entities[0 + 2 * 8 + 4 * 64] = 6;//WHITE bishop
		entities[0 + 5 * 8 + 3 * 64] = 6;
		entities[7 + 2 * 8 + 4 * 64] = -6;//BLACK bishop
		entities[7 + 5 * 8 + 3 * 64] = -6;

		entities[0 + 3 * 8 + 2 * 64] = 5;//WHITE bishop diagonal
		entities[0 + 4 * 8 + 5 * 64] = 5;
		entities[7 + 3 * 8 + 2 * 64] = -5;//BLACK bishop diagonal
		entities[7 + 4 * 8 + 5 * 64] = -5;

		entities[0 + 3 * 8 + 4 * 64] = 4;//WHITE queen
		entities[7 + 3 * 8 + 4 * 64] = -4;//BLACK queen

		entities[0 + 4 * 8 + 3 * 64] = 3;//WHITE queen diagonal
		entities[7 + 4 * 8 + 3 * 64] = -3;//BLACK queen diagonal

		entities[0 + 3 * 8 + 3 * 64] = 2;//WHITE super queen
		entities[7 + 3 * 8 + 3 * 64] = -2;//BLACK super queen

		entities[0 + 4 * 8 + 4 * 64] = 1;//WHITE king
		entities[7 + 4 * 8 + 4 * 64] = -1;//BLACK king
	}
	default:
		break;
	}
}

int List::Get(int number)
{
	if (number < *lenght * *weight * *height)
	{
		return entities[number];
	}
	else
	{
		return 0;
	}
}
