#include "allLibrariesAndStruct.h"

// ������� � ������� ����, ������� ���������� ����� ������.
char showMenu()
{
	
	system("cls");

	char c = ' ';

	cout << "\t\t\t\t _________________________________"<< endl;
	cout << "\t\t\t\t|\tEternal Nightmare \t  |" << endl;

	cout << "\t\t\t\t|1 - ����� ����    \t\t  |" << endl;
	cout << "\t\t\t\t|2 - ��������      \t\t  |" << endl;
	cout << "\t\t\t\t|0 - ����� �� ���� \t\t  |" << endl;
	cout << "\t\t\t\t|_________________________________|" << endl;
	
	cout << "> ";

	bool flag = false;
	do
	{
		cin >> c;
		if (cin.get() != (int)'\n')
			flag = true;
		else
			flag = false;
		
	} while (flag == true);
	
	return c;
}

// ����� ��������� �������� �� ���� � ���������.
void detailsMenu()
{
	system("cls");
	cout << "\n\t��� ���� �������� ��������������� ������� ��� ITStep academy.\n\t����������������� ��������� �������� ������ (Craig16Tucker)" << endl;
	system("pause");
}

// ����� ��� ������, ��� ����� ������������� ��������.
void errorMenu()
{
	system("cls");
	cout << "\n\t�� ����� �������� �����������" << endl;
	system("pause");
}