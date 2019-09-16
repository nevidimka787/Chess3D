#include"Liraries/GameSpace.h"
#include"Liraries/List.h"

#include<iostream>
#include<string>

using namespace std;

int main()
{
	GameSpace *gamespase1 = new GameSpace(1);
	gamespase1->ShowInformation();
	gamespase1->ShowAll();
	gamespase1->MoveWhite();
	int *figure_x = new int, *figure_y = new int, *figure_z = new int, *target_x = new int, *target_y = new int, *target_z = new int;
	while (true)
	{
		cin >> *figure_x >> *figure_y >> *figure_z >> *target_x >> *target_y >> *target_z;
		while (!gamespase1->MeetGameRule(*figure_x, *figure_y, *figure_z, *target_x, *target_y, *target_z))
		{
			cout << "Move is possible." << endl;
			cin >> *figure_x >> *figure_y >> *figure_z >> *target_x >> *target_y >> *target_z;
		}
		gamespase1->ReplasePoints(*figure_x, *figure_y, *figure_z, *target_x, *target_y, *target_z);
		gamespase1->SetPoint(*figure_x, *figure_y, *figure_z, 0);
		gamespase1->ShowInformation();
		gamespase1->ShowAll();
		gamespase1->MoveWhite();
	}
}

