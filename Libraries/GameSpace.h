#pragma once
class GameSpace
{
public:
	GameSpace(int type_of_game);

	bool CanGo(int number, int x_end, int y_end, int z_end);
	void MoveWhite();
	void MoveBlack();
	int GetPoint(int number);
	int GetPoint(int x, int y, int z);
	bool MeetGameRule(int x_start, int y_start, int z_start, int x_end, int y_end, int z_end);
	void ReplasePoints(int number1, int number2);
	void ReplasePoints(int x1, int y1, int z1, int number2);
	void ReplasePoints(int x1, int y1, int z1, int x2, int y2, int z2);
	void SetPoint(int number, int number_of_figure);
	void SetPoint(int x, int y, int z, int number_of_figure);
	void Show(int plane_z);
	void ShowAll();
	void ShowInformation();
private:

	int *lenght = new int;
	int *weight = new int;
	int *height = new int;
	int *type = new int; //lenght = X; weight = Y; height = Z;
	int *points = new int[8 * 8 * 8];//(X, Y, Z) == points[X + Y * 8 + Z * 64]  start = (0, 0, 0)
	bool *start_points = new bool[8 * 8 * 8];
	bool *white_move = new bool;
	bool *black_move = new bool;
	bool *game = new bool;
};
