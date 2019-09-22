
#include"Libraries/GameSpace.h"
#include"Libraries/List.h"

#include<iostream>
#include<string>

using namespace std;

int main()
{
	
	bool* game_go = new bool;
	*game_go = true;
	List* list = new List(1);
	GameSpace* gamespase1 = new GameSpace(*list);
	int* figure_x = new int, * figure_y = new int, * figure_z = new int, * target_x = new int, * target_y = new int, * target_z = new int;
	cout << "Game start." << endl;
	gamespase1->ShowInformation();
	gamespase1->ShowAll();
	gamespase1->MoveWhite();
	cout << "White's move." << endl;
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
		if (gamespase1->Mat(true))
		{
			cout << "White win!" << endl;
			break;
		}
		gamespase1->MoveBlack();
		cout << "Black's move.";
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
		if (gamespase1->Mat(false))
		{
			cout << "Black win!" << endl;
			break;
		}
		gamespase1->MoveWhite();
		cout << "White's move." << endl;
		}
	cout << "Game over" << endl;
	cin >> *game_go;
	
}
