#include "interface.h"

// Всплывающий текст при попытке в недоступную зону.
void errorChoose(char** (&room), int x, int y)
{
	system("cls");
	cout << "Прохода нет" << endl;
	room[x][y] = '!';
	system("pause");
}

// Идти вперёд.
void goForward(char** (&room), int x, int y)
{
	room[x + 1][y] = '!';
	room[x][y] = '-';
}

// Идти назад.
void goBack(char** (&room), int x, int y)
{
	room[x - 1][y] = '!';
	room[x][y] = '-';
}

// Идти налево.
void goLeft(char** (&room), int x, int y)
{
	room[x][y - 1] = '!';
	room[x][y] = '-';
}

// Идти направо.
void goRight(char** (&room), int x, int y)
{
	room[x][y + 1] = '!';
	room[x][y] = '-';
}

// Просмотр карты.
void minimapWatch(char** room)
{
	system("cls");
	cout << "\t\t\t\t _________________________" << endl;
	cout << "\t\t\t\t|\tКарта местности   |" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t\t|";
		for (int j = 0; j < 8; j++)
		{
			cout << "[" << room[i][j] << "]";
		}
		cout << " |" << endl;
	}
	cout << "\t\t\t\t|_________________________|" << endl;
	cout << "\n\t ! - Текущее местоположение. S - Стартовая зона. - - Иследованная зона. L - Секретные зоны \n\n" << endl;
	system("pause");
}

// Просмотр статистики.
void playerStats(player Kiver)
{
	system("cls");
	cout << "\t\t\t\t _________________________________________" << endl;
	cout << "\t\t\t\t|\t\tСтатистика        " << endl;
	cout << "\t\t\t\t|\t\t                  " << endl;
	cout << "\t\t\t\t|\t\tКивер             " << endl;
	cout << "\t\t\t\t| HP:      " << Kiver.hp << " / 100        " << endl;
	cout << "\t\t\t\t| MP:      " << Kiver.mp << " / 100        " << endl;
	cout << "\t\t\t\t| Броня:   " << Kiver.armor << "             " << endl;
	cout << "\t\t\t\t| Щит:     " << Kiver.shield << "               " << endl;
	cout << "\t\t\t\t| Сила:    " << Kiver.strength << "             " << endl;
	cout << "\t\t\t\t| EXP:     " << Kiver.exp << " / 100			" << endl;
	cout << "\t\t\t\t| LVL:     " << Kiver.lvl << "                " << endl;
	cout << "\t\t\t\t| Оружие:  " << Kiver.weapon << "         " << endl;
	cout << "\t\t\t\t| Одежда:  " << Kiver.suit << "  " << endl;
	cout << "\t\t\t\t|_________________________________________" << endl;
	system("pause");
}
