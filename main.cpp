#include "gameStart.h"

void main()
{
	setlocale(LC_ALL, "RUS");

	do
	{	
		switch (showMenu())
		{
		case '1':
			gameLor();
			game();
			break;
		case '2':
			detailsMenu();
			break;
		case '0':
			system("cls");
			exit(0);
			break;
		default:
			errorMenu();
			break;
		}
	} while (showMenu() != '0');
}