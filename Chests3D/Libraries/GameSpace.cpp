#ifndef GAME_SPACE_H
#define GAME_SPACE_H
#include"GameSpace.h"
#endif

#include<iostream>

using namespace std;

GameSpace::GameSpace(List list)
{
	*type = list.GetElement(3);
	*lenght = list.GetElement(0);
	*wight = list.GetElement(1);
	*hight = list.GetElement(2);
	for (int n = 0; n < *lenght * *wight * *hight; n++)
	{
		points[n] = list.Get(n);
		if (points[n] == 0)
		{
			start_points[n] = false;
		}
		else
		{
			start_points[n] = true;
		}
	}
}

bool GameSpace::CanGo(int number, int end_number)
{
	return CanGo(number, end_number % *lenght, (end_number / *wight) % *lenght, (end_number / *wight / *hight) % *lenght);
}

bool GameSpace::CanGo(int number, int x_end, int y_end, int z_end)
{

	int x_start = number % *lenght, y_start = (number / *lenght) % *wight, z_start = (number / (*lenght * *wight)) % *hight;
	switch (points[number])
	{
	case 1://WHITE king
	{
		if (abs(x_start - x_end) == 1 || abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1)
		{//can go on the one point in all sides
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 2://WHITE super queen
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end) || abs(x_start - x_end) == abs(y_start - y_end) && z_start == z_end || abs(y_start - y_end) == abs(z_start - z_end) && x_start == x_end || abs(z_start - z_end) == abs(x_start - x_end) && y_start == y_end || x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{//can go on all points in all sides
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 3://WHITE queen diagonal
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end) || x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{//can go on all points can't go on diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 4://WHITE queen
	{
		if ((x_start == x_end || y_start == y_end || z_start == z_end) && (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end)))
		{//can't go in double diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 5://WHITE bishop diadonal
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end))
		{//can go on only double diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 6://WHITE bishop
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && z_start == z_end || abs(y_start - y_end) == abs(x_start - z_end) && x_start == x_end || abs(z_start - z_end) == abs(x_start - x_end) || y_start == y_end)
		{//can go on only diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 7://WHITE knight diagonal
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2)
		{//it is knight diagonal
			if (points[x_end + y_end * *lenght + z_end * *lenght * *wight] <= 0)
			{
				return true;
			}
		}
		return false;
		break;
	}
	case 8://WHITE knight
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 2 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1)
		{//it is knight diagonal
			if (points[x_end + y_end * *lenght + z_end * *lenght * *wight] <= 0)
			{
				return true;
			}
		}
		return false;
		break;
	}
	case 9://WHITE rook
	{
		if (x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 10://WHITE pawn
	{
		if (x_start - x_end == -1 && y_start == y_end && z_start == z_end && points[x_end + y_end * *lenght + z_end * *lenght * *wight] == 0 || start_points[x_start + y_start * *lenght + z_start * *lenght * *wight] && x_start - x_end == -2 && y_start == y_end && z_start == z_end && points[x_end + y_end * *lenght + z_end * *lenght * *wight] == 0 || (x_start - x_end == -1 && (abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1) && points[x_end + y_end * *lenght + z_end * *lenght * *wight] < 0))
		{// can go only forvard OR eat figures on diagonals OR doouble diagonals
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case -1://BLACK king
	{
		if (abs(x_start - x_end) == 1 || abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1)
		{//can go on the one point in all sides
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -2://BLACK super queen
	{

		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end) || abs(x_start - x_end) == abs(y_start - y_end) && z_start == z_end || abs(y_start - y_end) == abs(z_start - z_end) && x_start == x_end || abs(z_start - z_end) == abs(x_start - x_end) && y_start == y_end || x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{//can go on all points in all sides
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;

	}
	case -3://BLACK queen diagonal
	{

		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end) || x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{//can go on all points can't go on diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;

	}
	case -4://BLACK queen
	{
		if ((x_start == x_end || y_start == y_end || z_start == z_end) && (abs(x_start - x_end) == abs(y_start - y_end) || abs(y_start - y_end) == abs(z_start - z_end) || abs(z_start - z_end) == abs(x_start - x_end)))
		{//can't go in double diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -5://BLACK bishop diagonal
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && abs(y_start - y_end) == abs(z_start - z_end))
		{//can go on only double diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -6://BLACK bishop
	{
		if (abs(x_start - x_end) == abs(y_start - y_end) && z_start == z_end || abs(y_start - y_end) == abs(x_start - z_end) && x_start == x_end || abs(z_start - z_end) == abs(x_start - x_end) || y_start == y_end)
		{//can go on only diagonal
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -7://BLACK knight diagonal
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2)
		{//it is knight diagonal
			if (points[x_end + y_end * *lenght + z_end * *lenght * *wight] >= 0)
			{
				return true;
			}
		}
		return false;
		break;
	}
	case -8://BLACK knight
	{
		if (abs(x_start - x_end) == 2 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 2 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 1 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 0 || abs(x_start - x_end) == 1 && abs(y_start - y_end) == 0 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 1 && abs(z_start - z_end) == 2 || abs(x_start - x_end) == 0 && abs(y_start - y_end) == 2 && abs(z_start - z_end) == 1)
		{//it is knight diagonal
			if (points[x_end + y_end * *lenght + z_end * *lenght * *wight] >= 0)
			{
				return true;
			}
		}
		return false;
		break;
	}
	case -9://BLACK rook
	{
		if (x_start == x_end && y_start == y_end || y_start == y_end && z_start == z_end || z_start == z_end && x_start == x_end)
		{
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -10://BLACK pawn
	{
		if (x_start - x_end == 1 && y_start == y_end && z_start == z_end && points[x_end + y_end * *lenght + z_end * *lenght * *wight] == 0 || start_points[x_start + y_start * *lenght + z_start * *lenght * *wight] && x_start - x_end == 2 && y_start == y_end && z_start == z_end && points[x_end + y_end * *lenght + z_end * *lenght * *wight] == 0 || (x_start - x_end == 1 && (abs(y_start - y_end) == 1 || abs(z_start - z_end) == 1) && points[x_end + y_end * *lenght + z_end * *lenght * *wight] > 0))
		{// can go only forvard OR eat figures on diagonals OR doouble diagonals
			return CanMove(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	default:
		break;
	}
	return false;
}

bool GameSpace::CanMove(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, bool is_white)
{
	int x = x_start;
	int y = y_start;
	int z = z_start;
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
		if ((points[x + y * *lenght + z * *lenght * *wight] != 0 && !(x == x_end && y == y_end && z == z_end)) || (points[x + y * *lenght + z * *lenght * *wight] > 0 && is_white) || (points[x + y * *lenght + z * *lenght * *wight] < 0 && !is_white))
		{
			return false;
		}
	}
	return true;
}

bool GameSpace::Check(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, bool to_white)
{
	int type_of_figure0 = points[x_start + y_start * *lenght + z_start * *lenght * *wight];
	int type_of_figure1 = points[x_end + y_end * *lenght + z_end * *lenght * *wight];
	int type_of_figure_king = -1;
	if (to_white)
	{
		type_of_figure_king = 1;
	}
	points[x_start + y_start * *lenght + z_start * *lenght * *wight] = 0;
	points[x_end + y_end * *lenght + z_end * *lenght * *wight] = type_of_figure1;
	for (int num_w_king = 0; num_w_king < *lenght * *wight * *hight; num_w_king++)
	{
		if (points[num_w_king] == type_of_figure_king)
		{
			for (int number = 0; number < *lenght * *wight * *hight; number++)
			{
				if (CanGo(number, num_w_king) && (points[number] < 0 && to_white || points[number] > 0 && !to_white))
				{
					points[x_start + y_start * *lenght + z_start * *lenght * *wight] = type_of_figure0;
					points[x_end + y_end * *lenght + z_end * *lenght * *wight] = type_of_figure1;
					return true;
				}
			}
			break;
		}
	}
	points[x_start + y_start * *lenght + z_start * *lenght * *wight] = type_of_figure0;
	points[x_end + y_end * *lenght + z_end * *lenght * *wight] = type_of_figure1;
	return false;
}

int GameSpace::GetPoint(int number)
{
	return points[number];
}

int GameSpace::GetPoint(int x, int y, int z)
{
	return points[x + y * *lenght + z * *lenght * *wight];
}

bool GameSpace::IsMoveWhite()
{
	return *white_move;
}

bool GameSpace::IsMoveBlack()
{
	return *black_move;
}

bool GameSpace::Mat(bool to_black)
{
	int king_number = 0;
	if (to_black)//If mat is to black.
	{
		for (int start_position = 0; start_position < *lenght * *wight * *hight; start_position++)
		{
			for (int end_position = 0; end_position < *lenght * *wight * *hight; end_position++)
			{
				if (points[start_position] < 0 && MeetGameRule(start_position, end_position))
				{
					return false;
				}
			}
		}
	}
	else//If mat is to white.
	{
		for (int start_position = 0; start_position < *lenght * *wight * *hight; start_position++)
		{
			for (int end_position = 0; end_position < *lenght * *wight * *hight; end_position++)
			{
				if (points[start_position] > 0 && MeetGameRule(start_position, end_position))
				{
					return false;
				}
			}
		}
	}
	return true;
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

bool GameSpace::MeetGameRule(int number, int end_number)
{
	return MeetGameRule(number % *lenght, (end_number / *lenght) % *wight, (end_number / (*lenght * *wight)) % *hight, end_number % *lenght, (end_number / *lenght) % *wight, (end_number / (*lenght * *wight)) % *hight);
}

bool GameSpace::MeetGameRule(int x_start, int y_start, int z_start, int end_number)
{
	return MeetGameRule(x_start, y_start, z_start, end_number % *lenght, (end_number / *lenght) % *wight, (end_number / (*lenght * *wight)) % *hight);
}

bool GameSpace::MeetGameRule(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end)
{
	if (x_end > * lenght - 1 || x_end < 0 || y_end > * wight - 1 || y_end < 0 || z_end > * hight - 1 || z_end < 0 || x_start > * lenght - 1 || x_start < 0 || y_start > * wight - 1 || y_start < 0 || z_start > * hight - 1 || z_start < 0 || (x_start == x_end && y_start == y_end && z_start == z_end))
	{//(in space ) AND ( start != end )
		return false;
	}
	else if (*white_move && points[x_start + y_start * *lenght + z_start * *lenght * *wight] <= 0 || *black_move && points[x_start + y_start * *lenght + z_start * *lenght * *wight] >= 0)
	{
		return false;
	}
	switch (points[x_start + y_start * *lenght + z_start * *lenght * *wight])
	{
	case 1://WHITE king
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			points[x_start + y_start * *lenght + z_start * *lenght * *wight] = 0;
			for (int number = 0; number < *lenght * *wight * *hight; number++)
			{
				if (points[number] < 0 && CanGo(number, x_end, y_end, z_end))
				{//no shakh
					return false;
				}
			}
			points[x_start + y_start * *lenght + z_start * *lenght * *wight] = 1;
			return true;
		}
		break;
	}
	case 2://WHITE super queen
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 3://WHITE queen diagonal
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 4://WHITE queen
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 5://WHITE bishop diadonal
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 6://WHIT bishop
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 7://WHITE knight diagonal
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 8://WHITE knght
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 9://WHITE rook
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, true);
		}
		break;
	}
	case 10://WHITE pawn
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			if (!Check(x_start, y_start, z_start, x_end, y_end, z_end, true))
			{
				return true;
			}
		}
		break;
	}
	case -1://BLACK king
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			points[x_start + y_start * *lenght + z_start * *lenght * *wight] = 0;
			for (int number = 0; number < *lenght * *wight * *hight; number++)
			{
				if (points[number] > 0 && CanGo(number, x_end, y_end, z_end))
				{//no shakh
					return false;
				}
			}
			points[x_start + y_start * *lenght + z_start * *lenght * *wight] = -1;
			return true;
		}
		break;
	}
	case -2://BLACK super queen
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -3://BLACK queen diagonal
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -4://BLACK queen
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -5://BLACK bishop diagonal
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -6://BLACK bishop
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -7://BLACK knight diagonal
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -8://BLACK khight
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -9://BLACK rook
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			return !Check(x_start, y_start, z_start, x_end, y_end, z_end, false);
		}
		break;
	}
	case -10://BLACK pawn
	{
		if (CanGo(x_start + y_start * *lenght + z_start * *lenght * *wight, x_end, y_end, z_end))
		{
			if (!Check(x_start, y_start, z_start, x_end, y_end, z_end, false))
			{
				return true;
			}
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
	*point = points[x1 + y1 * *lenght + z1 * *lenght * *wight];
	points[x1 + y1 * *lenght + z1 * *lenght * *wight] = points[number2];
	points[number2] = *point;
	delete point;
}

void GameSpace::ReplasePoints(int x1, int y1, int z1, int x2, int y2, int z2)
{
	int* point = new int;
	*point = points[x1 + y1 * *lenght + z1 * *lenght * *wight];
	points[x1 + y1 * *lenght + z1 * *lenght * *wight] = points[x2 + y2 * *lenght + z2 * *lenght * *wight];
	points[x2 + y2 * *lenght + z2 * *lenght * *wight] = *point;
	delete point;
}

void GameSpace::SetPoint(int number, int number_of_figure)
{
	points[number] = number_of_figure;
}

void GameSpace::SetPoint(int x, int y, int z, int number_of_figure)
{
	points[x + y * *lenght + z * *lenght * *wight] = number_of_figure;
}

void GameSpace::Show(int plane_z, bool show_cordinats_vectors)
{
	if (plane_z < *hight)
	{
		int string_number = 0;
		cout << endl;
		for (int x = 0; x < *lenght; x++)
		{
			for (int y = 0; y < *wight; y++)
			{
				if ((points[x + y * *lenght + plane_z * *lenght * *wight] < 0 && points[x + y * *lenght + plane_z * *lenght * *wight] > -10) || points[x + y * *lenght + plane_z * *lenght * *wight] > 9)
				{
					cout << " " << points[x + y * *lenght + plane_z * *lenght * *wight] << " ";
				}
				else if (points[x + y * *lenght + plane_z * *lenght * *wight] < -9)
				{
					cout << points[x + y * *lenght + plane_z * *lenght * *wight] << " ";
				}
				else
				{
					cout << "  " << points[x + y * *lenght + plane_z * *lenght * *wight] << " ";
				}
			}
			if (show_cordinats_vectors)
			{
				switch (string_number)
				{
				case 0:
				{
					cout << "   Z = " << plane_z;
					break;
				}
				case 2:
				{
					cout << "   +  -  >  Y";
					break;
				}
				case 3:
				{
					cout << "   |";
					break;
				}
				case 4:
				{
					cout << "   v";
					break;
				}
				case 5:
				{
					cout << "   X";
					break;
				}
				default:
				{
					break;
				}
				}
				string_number++;
			}
			cout << endl << endl;
		}
	}
}

void GameSpace::ShowAll()
{
	for (int z = 0; z < *hight; z++)
	{
		Show(z, true);
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
			"5 - Bishop Diagonal" << endl <<
			"6 - Bishop" << endl <<
			"7 - Knight Diagonal" << endl <<
			"8 - Knight" << endl <<
			"9 - Rook" << endl <<
			"10 - Pawn" << endl << endl <<
			"BLACK" << endl <<
			"-1 - King" << endl <<
			"-2 - Super Queen" << endl <<
			"-3 - Queen diagonale" << endl <<
			"-4 - Queen" << endl <<
			"-5 - Bishop Diagonal" << endl <<
			"-6 - Bishop" << endl <<
			"-7 - Knight Diagonal" << endl <<
			"-8 - Knight" << endl <<
			"-9 - Rook" << endl <<
			"-10 - Pawn" << endl;
	}
	default:
		break;
	}
}

bool GameSpace::Way()
{
	bool way = false, white_king_is_only = true, black_king_is_only = true;
	int white_king_number = 0, black_king_number = 0;
	for (int number = 0; number < *lenght * *wight * *hight; number++)
	{
		if (points[number] == 1)
		{
			white_king_number = number;
			break;
		}
		if (points[number] == -1)
		{
			black_king_number = number;
			break;
		}
		if (points[number] > 0)
		{
			white_king_is_only = false;
		}
		if (points[number] < 0)
		{
			black_king_is_only = false;
		}
	}
	for (int number = 0; number < *lenght * *wight * *hight; number++)
	{
		if (MeetGameRule(points[white_king_number], number) || !white_king_is_only)
		{
			way = false;
		}
		if (MeetGameRule(points[black_king_number], number) || !black_king_is_only)
		{
			way = false;
		}
	}
	return way;
}
