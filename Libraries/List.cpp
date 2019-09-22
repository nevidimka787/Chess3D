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
		for (int n = 0; n < *lenght * *weight * *height; n++)
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
					entities[x + y * *lenght + z * *lenght * *weight] = 10;//(0, 1 , 1):(1, 6, 6) -> WHITE pawns
				}
			}
		}
		for (int x = 6; x < 8; x++)
		{
			for (int y = 1; y < 7; y++)
			{
				for (int z = 1; z < 7; z++)
				{
					entities[x + y * *lenght + z * *lenght * *weight] = -10;//(6, 1 , 1):(7, 6, 6) -> BLACK pawns
				}
			}
		}
		entities[0 + 2 * *lenght + 2 * *lenght * *weight] = 9;//WHITE rooks
		entities[0 + 5 * *lenght + 2 * *lenght * *weight] = 9;
		entities[0 + 2 * *lenght + 5 * *lenght * *weight] = 9;
		entities[0 + 5 * *lenght + 5 * *lenght * *weight] = 9;
		entities[7 + 2 * *lenght + 2 * *lenght * *weight] = -9;//BLACK rooks
		entities[7 + 5 * *lenght + 2 * *lenght * *weight] = -9;
		entities[7 + 2 * *lenght + 5 * *lenght * *weight] = -9;
		entities[7 + 5 * *lenght + 5 * *lenght * *weight] = -9;

		entities[0 + 4 * *lenght + 2 * *lenght * *weight] = 8;//WHITE knigth
		entities[0 + 3 * *lenght + 5 * *lenght * *weight] = 8;
		entities[7 + 4 * *lenght + 2 * *lenght * *weight] = -8;//BLACK knigth
		entities[7 + 3 * *lenght + 5 * *lenght * *weight] = -8;

		entities[0 + 2 * *lenght + 3 * *lenght * *weight] = 7;//WHITE knigth diagonal
		entities[0 + 5 * *lenght + 4 * *lenght * *weight] = 7;
		entities[7 + 2 * *lenght + 3 * *lenght * *weight] = -7;//BLACK knigth diagonal
		entities[7 + 5 * *lenght + 4 * *lenght * *weight] = -7;

		entities[0 + 2 * *lenght + 4 * *lenght * *weight] = 6;//WHITE bishop
		entities[0 + 5 * *lenght + 3 * *lenght * *weight] = 6;
		entities[7 + 2 * *lenght + 4 * *lenght * *weight] = -6;//BLACK bishop
		entities[7 + 5 * *lenght + 3 * *lenght * *weight] = -6;

		entities[0 + 3 * *lenght + 2 * *lenght * *weight] = 5;//WHITE bishop diagonal
		entities[0 + 4 * *lenght + 5 * *lenght * *weight] = 5;
		entities[7 + 3 * *lenght + 2 * *lenght * *weight] = -5;//BLACK bishop diagonal
		entities[7 + 4 * *lenght + 5 * *lenght * *weight] = -5;

		entities[0 + 3 * *lenght + 4 * *lenght * *weight] = 4;//WHITE queen
		entities[7 + 3 * *lenght + 4 * *lenght * *weight] = -4;//BLACK queen

		entities[0 + 4 * *lenght + 3 * *lenght * *weight] = 3;//WHITE queen diagonal
		entities[7 + 4 * *lenght + 3 * *lenght * *weight] = -3;//BLACK queen diagonal

		entities[0 + 3 * *lenght + 3 * *lenght * *weight] = 2;//WHITE super queen
		entities[7 + 3 * *lenght + 3 * *lenght * *weight] = -2;//BLACK super queen

		entities[0 + 4 * *lenght + 4 * *lenght * *weight] = 1;//WHITE king
		entities[7 + 4 * *lenght + 4 * *lenght * *weight] = -1;//BLACK king
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

int List::GetElement(int number)
{
	switch (number)
	{
	case 0:
	{
		return *lenght;
		break;
	}
	case 1:
	{
		return *weight;
		break;
	}
	case 2:
	{
		return *height;
		break;
	}
	case 3:
	{
		return *type;
		break;
	}
	return 0;
	}
}
