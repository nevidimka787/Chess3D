#pragma once

#include"List.h"

class GameSpace
{
public:
	GameSpace(List list);//Start game with started parameter.
	bool CanGo(int number, int end_number);//Figure can go from start positon on line to second position on line.
	bool CanGo(int number, int x_end, int y_end, int z_end);//Figure can go from start positon to second position on line.
	bool CanMove(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, bool is_white);//Figure can go from start position to end position ignore game rules.
	bool Check(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, bool to_white);//Check weel be after move.
	int GetPoint(int number);//Take information about indicated position on line.
	int GetPoint(int x, int y, int z);//Take information about indicated position.
	bool IsMoveWhite();//White can move.
	bool IsMoveBlack();//Black can move.
	bool Mat(bool to_black);//If parametr "to_black" is false, function verify mat to white party.
	void MoveWhite();//White party is moving now.
	void MoveBlack();//Black party is moving now.
	bool MeetGameRule(int position, int end_position);//Figure's movement between positions on line meet game rules.
	bool MeetGameRule(int x_start, int y_start, int z_start, int number);//Figure's movement between position and position on line meet game rules.
	bool MeetGameRule(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end);//Figure's movement between positions meet game rules.
	void ReplasePoints(int number1, int number2);//Take a figure from first position on line and replaset this with figure from second position on line.
	void ReplasePoints(int x1, int y1, int z1, int number2);//Take a figure from first position and replaset this with figure from second position on line.
	void ReplasePoints(int x1, int y1, int z1, int x2, int y2, int z2);//Take a figure from first position and replaset this with figure from second position.
	void SetPoint(int number, int number_of_figure);//Make a figure in the indicated position on line.
	void SetPoint(int x, int y, int z, int number_of_figure);//Make a figure in the indicated position.
	void Show(int plane_z, bool show_cordinats_vectors);//Show information about indikated plate.
	void ShowAll();//Show information about all plates.
	void ShowInformation();//Show dependence between figure's name and figure's number of type.
	bool Way();//Verify way in the game.
private:

	int* lenght = new int;
	int* weight = new int;
	int* height = new int;
	int* type = new int; //lenght = X; weight = Y; height = Z;
	int* points = new int[512 * 512 * 512];//(X, Y, Z) == points[X + Y * 8 + Z * 64]  start = (0, 0, 0)
	bool* start_points = new bool[512 * 512 * 512];
	bool* white_move = new bool;
	bool* black_move = new bool;
	bool* game = new bool;
};
