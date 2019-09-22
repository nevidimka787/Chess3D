#pragma once
class List
{
public:
	List(int type_of_game);
	int Get(int number);
	int GetElement(int number);//0 - lenght; 1 - weight; 2 - height; 3 - type;
private:
	int* lenght = new int;
	int* weight = new int;
	int* height = new int;
	int* type = new int;
	int* entities = new int[8 * 8 * 8];//(X, Y, Z) == points[X + Y * 8 + Z * 64]  start = (0, 0, 0)
};
