#include"GameSpace.h"
#include"List.h"
#include<iostream>

using namespace std;

GameSpace::GameSpace(int type_of_game)
{
	*type = type_of_game;
	*lenght = 8;
	*weight = 8;
	*height = 8;
	//int *points = new int[*lenght * *weight * *height];
	List* list = new List(type_of_game);
	for (int n = 0; n < *lenght * *weight * *height; n++)
	{
		points[n] = list->Get(n);
		if (points[n] == 0)
		{
			start_points[n] = false;
		}
		else
		{
			start_points[n] = true;
		}
	}
	delete list;
}

bool GameSpace::CanGo(int number, int x_end, int y_end, int z_end)
{

	int x_start = number % 8, y_start = (number / 8) % 8, z_start = (number / 64) % 8;
	int x, y, z;
	switch (points[number])
	{
	case 1://WHITE king
	{
		if (abs(x_start - x_end) == 1 || abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1)
		{//can go on the one point in all sides
			x = x_start;
			y = y_start;
			z = z_start;
			while (x_start != x_end || y_start != y_end || z_start != z_end)
			{
				if (x_start < x_end)
				{
					x++;
				}
				else if (x_start > x_end)
				{
					x--;
				}
				if (y_start < y_end)
				{
					y++;
				}
				else if (y_start > y_end)
				{
					y--;
				}
				if (z_start < z_end)
				{
					z++;
				}
				else if (z_start > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{
					return false;
				}
			}
			return true;
		}
		break;
	}
	case 2://WHITE super queen
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end || x_start == x_end || y_start == y_end || z_start == z_end))
		{//can go on all points in all sides
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case 3://WHITE queen diagonal
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end) || x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{//can go on all points can't go on diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case 4://WHITE queen
	{
		if ((x_start == x_end || y_start == y_end || z_start == z_end) && (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end)))
		{//can't go in double diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case 5://WHITE bishop diadonal
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end))
		{//can go on only double diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case 6://WHITE bishop
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && z_start == z_end || abs(y_start - y_end) == abs(x_start - z_end) && x_start == x_end || abs(z_start - z_end) == abs(x_start - x_end) || y_start == y_end)
		{//can go on only diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case 7://WHITE knight diagonal
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2)
		{//it is knight diagonal
			if (points[x_end + y_end * 8 + z_end * 64] > 0)
			{
				return false;
			}
		}
		return true;
		break;
	}
	case 8://WHITE knight
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 2 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1)
		{//it is knight diagonal
			if (points[x_end + y_end * 8 + z_end * 64] > 0)
			{
				return false;
			}
		}
		return true;
		break;
	}
	case 9://WHITE rook
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end))
		{
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case 10://WHITE pawn
	{
		if (x_start - x_end == -1 || start_points[x_start + y_start * 8 + z_start * 64] && x_start - x_end == -2 || (x_start - x_end == 1 && (abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1) && points[x_end + y_end * 8 + z_end * 64] < 0))
		{// can go only forvard OR eat figures on diagonals OR doouble diagonals
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case -1://BLACK king
	{
		if (abs(x_start - x_end) == 1 || abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1)
		{//can go on the one point in all sides
			x = x_start;
			y = y_start;
			z = z_start;
			while (x_start != x_end || y_start != y_end || z_start != z_end)
			{
				if (x_start < x_end)
				{
					x++;
				}
				else if (x_start > x_end)
				{
					x--;
				}
				if (y_start < y_end)
				{
					y++;
				}
				else if (y_start > y_end)
				{
					y--;
				}
				if (z_start < z_end)
				{
					z++;
				}
				else if (z_start > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] < 0)
				{
					return false;
				}
			}
			return true;
		}
		break;
	}
	case -2://BLACK super queen
	{

		if (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end || x_start == x_end || y_start == y_end || z_start == z_end))
		{//can go on all points in all sides
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] < 0)
				{

					return false;
				}
			}
			return true;
		}
		break;

	}
	case -3://BLACK queen diagonal
	{

		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end) || x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{//can go on all points can't go on diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] < 0)
				{

					return false;
				}
			}
			return true;
		}
		break;

	}
	case -4://BLACK queen
	{
		if ((x_start == x_end || y_start == y_end || z_start == z_end) && (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end)))
		{//can't go in double diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] < 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case -5://BLACK bishop diagonal
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end))
		{//can go on only double diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] < 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case -6://BLACK bishop
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && z_start == z_end || abs(y_start - y_end) == abs(x_start - z_end) && x_start == x_end || abs(z_start - z_end) == abs(x_start - x_end) || y_start == y_end)
		{//can go on only diagonal
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] > 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case -7://BLACK knight diagonal
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2)
		{//it is knight diagonal
			if (points[x_end + y_end * 8 + z_end * 64] < 0)
			{
				return false;
			}
		}
		return true;
		break;
	}
	case -8://BLACK knight
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 2 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1)
		{//it is knight diagonal
			if (points[x_end + y_end * 8 + z_end * 64] < 0)
			{
				return false;
			}
		}
		return true;
		break;
	}
	case -9://BLACK rook
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end))
		{
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] < 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	case -10://BLACK pawn
	{
		if (x_start - x_end == 1 || start_points[x_start + y_start * 8 + z_start * 64] && x_start - x_end == 2 || (x_start - x_end == 1 && (abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1) && points[x_end + y_end * 8 + z_end * 64] > 0))
		{// can go only forvard OR eat figures on diagonals OR doouble diagonals
			x = x_start;
			y = y_start;
			z = z_start;
			while (x != x_end || y != y_end || z != z_end)
			{
				if (x < x_end)
				{
					x++;
				}
				else if (x > x_end)
				{
					x--;
				}
				if (y < y_end)
				{
					y++;
				}
				else if (y > y_end)
				{
					y--;
				}
				if (z < z_end)
				{
					z++;
				}
				else if (z > z_end)
				{
					z--;
				}
				if ((points[x + y * 8 + z * 64] != 0 && !(x == x_end && y == y_end && z == z_end)) || points[x + y * 8 + z * 64] < 0)
				{

					return false;
				}
			}
			return true;
		}
		break;
	}
	default:
		break;
	}
	return false;
}

void GameSpace::MoveWhite()//white_move = true; black_move = false
{
	*white_move = true;
	*black_move = false;
}

void GameSpace::MoveBlack()//white_move = false; black_move = true
{
	*white_move = false;
	*black_move = true;
}

int GameSpace::GetPoint(int number)
{
	return points[number];
}

int GameSpace::GetPoint(int x, int y, int z)
{
	return points[x + y * 8 + z * 64];
}

bool GameSpace::MeetGameRule(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end)
{
	if (x_end > 7 || x_end < 0 || y_end > 7 || y_end < 0 || z_end > 7 || z_end < 0 || x_start > 7 || x_start < 0 || y_start > 7 || y_start < 0 || z_start > 7 || z_start < 0 || (x_start == x_end && y_start == y_end && z_start == z_end))
	{
		return false;
	}
	else if (*white_move && points[x_start + y_start * 8 + z_start * 64] <= 0 || *black_move && points[x_start + y_start * 8 + z_start * 64] >= 0)
	{//(in space ) AND ( start != end )
		return false;
	}
	switch (points[x_start + y_start * 8 + z_start * 64])
	{
	case 1://WHITE king
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int number = 0; number < 512; number++)
			{
				if (points[number] < 0 && CanGo(number, x_end, y_end, z_end))
				{//no shakh
					return false;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 1;
			return true;
		}
		break;
	}
	case 2://WHITE super queen
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 2;
			return true;
		}
		break;
	}
	case 3://WHITE queen diagonal
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 3;
			return true;
		}
		break;
	}
	case 4://WHITE queen
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 4;
			return true;
		}
		break;
	}
	case 5://WHITE bishop diadonal
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 5;
			return true;
		}
		break;
	}
	case 6://WHIT bishop
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 6;
			return true;
		}
		break;
	}
	case 7://WHITE knight diagonal
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 7;
			return true;
		}
		break;
	}
	case 8://WHITE knght
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 8;
			return true;
		}
		break;
	}
	case 9://WHITE rook
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 9;
			return true;
		}
		break;
	}
	case 10://WHITE pawn
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] < 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = 10;
			return true;
		}
		break;
	}
	case -1://BLACK king
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int number = 0; number < 512; number++)
			{
				if (points[number] > 0 && CanGo(number, x_end, y_end, z_end))
				{//no shakh
					return false;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -1;
			return true;
		}
		break;
	}
	case -2://BLACK super queen
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = -1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -2;
			return true;
		}
		break;
	}
	case -3://BLACK queen diagonal
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -3;
			return true;
		}
		break;
	}
	case -4://BLACK queen
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -4;
			return true;
		}
		break;
	}
	case -5://BLACK bishop diagonal
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -5;
			return true;
		}
		break;
	}
	case -6://BLACK bishop
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -6;
			return true;
		}
		break;
	}
	case -7://BLACK knight diagonal
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -7;
			return true;
		}
		break;
	}
	case -8://BLACK khight
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -8;
			return true;
		}
		break;
	}
	case -9://BLACK rook
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -9;
			return true;
		}
		break;
	}
	case -10://BLACK pawn
	{
		if (CanGo(x_start + y_start * 8 + z_start * 64, x_end, y_end, z_end))
		{
			points[x_start + y_start * 8 + z_start * 64] = 0;
			for (int num_w_king = 0; num_w_king < 512; num_w_king++)
			{
				if (points[num_w_king] = 1)
				{
					for (int number = 0; number < 512; number++)
					{
						if (CanGo(number, num_w_king % 8, (num_w_king / 8) % 8, (num_w_king / 64) % 8) && points[number] > 0)
						{//no shakh
							return false;
						}
					}
					break;
				}
			}
			points[x_start + y_start * 8 + z_start * 64] = -10;
			return true;
		}
		break;
	}
	default:
		break;
		return false;
	}
}

void GameSpace::ReplasePoints(int number1, int number2)
{
	int* point = new int;
	*point = points[number1];
	points[number1] = points[number2];
	points[number2] = *point;
	delete point;
}

void GameSpace::ReplasePoints(int x1, int y1, int z1, int number2)
{
	int* point = new int;
	*point = points[x1 + y1 * 8 + z1 * 64];
	points[x1 + y1 * 8 + z1 * 64] = points[number2];
	points[number2] = *point;
	delete point;
}

void GameSpace::ReplasePoints(int x1, int y1, int z1, int x2, int y2, int z2)
{
	int* point = new int;
	*point = points[x1 + y1 * 8 + z1 * 64];
	points[x1 + y1 * 8 + z1 * 64] = points[x2 + y2 * 8 + z2 * 64];
	points[x2 + y2 * 8 + z2 * 64] = *point;
	delete point;
}

void GameSpace::SetPoint(int number, int number_of_figure)
{
	points[number] = number_of_figure;
}

void GameSpace::SetPoint(int x, int y, int z, int number_of_figure)
{
	points[x + y * 8 + z * 64] = number_of_figure;
}

void GameSpace::Show(int plane_z)
{
	if (plane_z < *height)
	{
		cout << endl;
		for (int x = 0; x < *lenght; x++)
		{
			for (int y = 0; y < *weight; y++)
			{
				if ((points[x + y * 8 + plane_z * 64] < 0 && points[x + y * 8 + plane_z * 64] > -10) || points[x + y * 8 + plane_z * 64] > 9)
				{
					cout << " " << points[x + y * 8 + plane_z * 64] << " ";
				}
				else if (points[x + y * 8 + plane_z * 64] < -9)
				{
					cout << points[x + y * 8 + plane_z * 64] << " ";
				}
				else
				{
					cout << "  " << points[x + y * 8 + plane_z * 64] << " ";
				}
			}
			cout << endl << endl;
		}
	}
}

void GameSpace::ShowAll()
{
	for (int z = 0; z < 8; z++)
	{
		Show(z);
		cout << endl << "-------------------------------" << endl << endl;
	}
}

void GameSpace::ShowInformation()
{
	switch (*type)
	{
	case 1:
	{
		cout <<
			"WHITE" << endl <<
			"1 - King" << endl <<
			"2 - Super Queen" << endl <<
			"3 - Queen diagonale" << endl <<
			"4 - Queen" << endl <<
			"5 - Super Bishop" << endl <<
			"6 - Bishop" << endl <<
			"7 - Super Knigaht" << endl <<
			"8 - Knigaht" << endl <<
			"9 - Rook" << endl <<
			"10 - Pawn" << endl << endl <<
			"BLACK" << endl <<
			"-1 - King" << endl <<
			"-2 - Super Queen" << endl <<
			"-3 - Queen diagonale" << endl <<
			"-4 - Queen" << endl <<
			"-5 - Super Bishop" << endl <<
			"-6 - Bishop" << endl <<
			"-7 - Super Knigaht" << endl <<
			"-8 - Knigaht" << endl <<
			"-9 - Rook" << endl <<
			"-10 - Pawn" << endl;
	}
	default:
		break;
	}
}
