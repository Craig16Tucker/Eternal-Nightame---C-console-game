#include "allLibrariesAndStruct.h"

// Функция с показом меню, которая возвращает выбор игрока.
char showMenu()
{
	
	system("cls");

	char c = ' ';

	cout << "\t\t\t\t _________________________________"<< endl;
	cout << "\t\t\t\t|\tEternal Nightmare \t  |" << endl;

	cout << "\t\t\t\t|1 - Новая игра    \t\t  |" << endl;
	cout << "\t\t\t\t|2 - Сведения      \t\t  |" << endl;
	cout << "\t\t\t\t|0 - Выйти из игры \t\t  |" << endl;
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

// Вывод некоторых сведений об игре и создателе.
void detailsMenu()
{
	system("cls");
	cout << "\n\tЭта игра является экзаменационной работой для ITStep academy.\n\tПрограммированием занимался Гаврилов Сергей (Craig16Tucker)" << endl;
	system("pause");
}

// Текст для вывода, при вводе неправильного значения.
void errorMenu()
{
	system("cls");
	cout << "\n\tВы ввели значение неправильно" << endl;
	system("pause");
}