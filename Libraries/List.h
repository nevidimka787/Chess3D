#pragma once
class List
{
public:
	List(int type_of_game);
	int Get(int number);
private:
	int *number = new int;
	int *lenght = new int;
	int *weight = new int;
	int *height = new int;
	int *type = new int;; //lenght = X; weight = Y; height = Z;
	int *entities = new int[8 * 8 * 8];//(X, Y, Z) == points[X + Y * 8 + Z * 64]  start = (0, 0, 0)
};
