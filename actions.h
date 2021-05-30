#include "interface.h"

// ����������� ����� ��� ������� � ����������� ����.
void errorChoose(char** (&room), int x, int y)
{
	system("cls");
	cout << "������� ���" << endl;
	room[x][y] = '!';
	system("pause");
}

// ���� �����.
void goForward(char** (&room), int x, int y)
{
	room[x + 1][y] = '!';
	room[x][y] = '-';
}

// ���� �����.
void goBack(char** (&room), int x, int y)
{
	room[x - 1][y] = '!';
	room[x][y] = '-';
}

// ���� ������.
void goLeft(char** (&room), int x, int y)
{
	room[x][y - 1] = '!';
	room[x][y] = '-';
}

// ���� �������.
void goRight(char** (&room), int x, int y)
{
	room[x][y + 1] = '!';
	room[x][y] = '-';
}

// �������� �����.
void minimapWatch(char** room)
{
	system("cls");
	cout << "\t\t\t\t _________________________" << endl;
	cout << "\t\t\t\t|\t����� ���������   |" << endl;

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
	cout << "\n\t ! - ������� ��������������. S - ��������� ����. - - ������������ ����. L - ��������� ���� \n\n" << endl;
	system("pause");
}

// �������� ����������.
void playerStats(player Kiver)
{
	system("cls");
	cout << "\t\t\t\t _________________________________________" << endl;
	cout << "\t\t\t\t|\t\t����������        " << endl;
	cout << "\t\t\t\t|\t\t                  " << endl;
	cout << "\t\t\t\t|\t\t�����             " << endl;
	cout << "\t\t\t\t| HP:      " << Kiver.hp << " / 100        " << endl;
	cout << "\t\t\t\t| MP:      " << Kiver.mp << " / 100        " << endl;
	cout << "\t\t\t\t| �����:   " << Kiver.armor << "             " << endl;
	cout << "\t\t\t\t| ���:     " << Kiver.shield << "               " << endl;
	cout << "\t\t\t\t| ����:    " << Kiver.strength << "             " << endl;
	cout << "\t\t\t\t| EXP:     " << Kiver.exp << " / 100			" << endl;
	cout << "\t\t\t\t| LVL:     " << Kiver.lvl << "                " << endl;
	cout << "\t\t\t\t| ������:  " << Kiver.weapon << "         " << endl;
	cout << "\t\t\t\t| ������:  " << Kiver.suit << "  " << endl;
	cout << "\t\t\t\t|_________________________________________" << endl;
	system("pause");
}
