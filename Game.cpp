
#include"Libraries/GameSpace.h"
#include"Libraries/List.h"

#include<iostream>
#include<string>

using namespace std;

List* list = new List(1);
GameSpace* gamespase1 = new GameSpace(*list);

void ShowAllVariants(int figure_position_x, int figure_position_y, int figure_position_z)
{
	for (int n = 0; n < list->GetElement(0) * list->GetElement(1) * list->GetElement(2); n++)
	{
		if (gamespase1->MeetGameRule(figure_position_x, figure_position_y, figure_position_z, n))
		{
			cout << n % list->GetElement(0) << "	" << (n / list->GetElement(0)) % list->GetElement(1) << "	" << (n / (list->GetElement(0) * list->GetElement(1))) % list->GetElement(2) << endl;
		}
	}
}

int main()
{
	
	bool* game_go = new bool, * break_all = new bool,* move_white = new bool;
	*game_go = true;
	*break_all = false;
	*move_white = true;
	int* figure_x = new int, * figure_y = new int, * figure_z = new int, * target_x = new int, * target_y = new int, * target_z = new int;
	*figure_x = 0;
	*figure_y = 0;
	*figure_z = 0;
	*target_x = 0;
	*target_y = 0;
	*target_z = 0;
	cout << "Game start." << endl;
	gamespase1->ShowInformation();
	gamespase1->ShowAll();
	gamespase1->MoveWhite();
	cout << "White's move." << endl;
	while (true)
	{
		*game_go = true;
		cout << "Targe figure position." << endl;
		cin >> *figure_x >> *figure_y >> *figure_z;
		cout << "You can move this figure on positions:" << endl;
		ShowAllVariants(*figure_x, *figure_y, *figure_z);
		cout << "If you don't wont move this figure, input coordinates of this target." << endl;
		cin >> *target_x >> *target_y >> *target_z;
		if (!(*figure_x == *target_x && *figure_y == *target_y && *figure_z == *target_z))
		{
			while (!gamespase1->MeetGameRule(*figure_x, *figure_y, *figure_z, *target_x, *target_y, *target_z) && *game_go)
			{

				cout << "Move is possible." << endl << "If you don't wont move this figure, input coordinates of this target." << endl;
				cin >> *target_x >> *target_y >> *target_z;
				if ((*figure_x == *target_x && *figure_y == *target_y && *figure_z == *target_z))
				{
					*game_go = false;
				}
			}
			if (*game_go)
			{
				gamespase1->ReplasePoints(*figure_x, *figure_y, *figure_z, *target_x, *target_y, *target_z);
				gamespase1->SetPoint(*figure_x, *figure_y, *figure_z, 0);
				gamespase1->ShowInformation();
				gamespase1->ShowAll();
				if (gamespase1->Mat(true))
				{
					cout << "White win!" << endl;
					break;
				}
				else if (gamespase1->Mat(false))
				{
					cout << "Black win!" << endl;
					break;
				}
				if (*move_white)
				{
					gamespase1->MoveBlack();
					*move_white = false;
					cout << "Move black." << endl;
				}
				else
				{
					gamespase1->MoveWhite();
					*move_white = true;
					cout << "Move white." << endl;
				}
			}
		}
	}
	cout << "Game over" << endl;
	cin >> *game_go;
	
}
