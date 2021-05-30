#include "actions.h"

// Просмотр инвентаря.
void inventoryWatch(items* inventory)
{
	system("cls");

	cout << "\t\t\t\t _________________________________________" << endl;
	cout << "\t\t\t\t|\t\tИнвентарь        " << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << "\t\t\t\t| " << i + 1 << ":      " << inventory[i].name << endl;
	}
	cout << "\t\t\t\t|_________________________________________" << endl;
	cout << "0 - Выйти" << endl;
}

// Просмотр сундука.
void chestWatch(items* chest)
{
	system("cls");

	cout << "\t\t\t\t _________________________________________" << endl;
	cout << "\t\t\t\t|\t\tСундук        " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t\t\t| " << i + 1 << ":      " << chest[i].name << endl;
	}
	cout << "\t\t\t\t|_________________________________________" << endl;
	cout << "0 - Выйти" << endl;
}

// Просмотр деталей предмета.
void itemDetailsWatch(items item)
{
	system("cls");
	if (item.details == " ")
	{
		system("cls");
		cout << "Предмета нету в данной ячейке" << endl;
		system("pause");
	}
	else
	{
		cout << "\t\t\t\t\t\tДетали" << endl << item.details << endl;
		system("pause");
	}
}

// Использование предмета.
void useItem(player& Kiver, items*& inventory, int choose, items& currentlyWeapon, items& currentlySuit)
{
	system("cls");

	items usedItem = inventory[choose];

	if (inventory[choose].hp > 0 || inventory[choose].mp > 0)
	{
		Kiver.hp = Kiver.hp + inventory[choose].hp;
		Kiver.mp = Kiver.mp + inventory[choose].mp;

		if (Kiver.hp > 100)
		{
			Kiver.hp = 100;
		}
		else if (Kiver.mp > 100)
		{
			Kiver.mp = 100;
		}

		inventory[choose] = emptySlot();

		cout << "Успешно" << endl;
	}
	else if (inventory[choose].strength > 0)
	{
		Kiver.strength = inventory[choose].strength;
		Kiver.weapon = inventory[choose].name;

		inventory[choose] = currentlyWeapon;
		currentlyWeapon = usedItem;

		cout << "Успешно" << endl;
	}
	else if (inventory[choose].armor > 0)
	{
		Kiver.armor = inventory[choose].armor;
		Kiver.suit = inventory[choose].name;

		inventory[choose] = currentlySuit;
		currentlySuit = usedItem;

		cout << "Успешно" << endl;
	}
	else
	{
		cout << "Предмета нету в данной ячейке" << endl;
	}
	system("pause");
}

// Использование предмета. (Во время боя)
void useItem(player& Kiver, items*& inventory, int choose)
{
	system("cls");

	items usedItem = inventory[choose];

	if (inventory[choose].hp > 0 || inventory[choose].mp > 0)
	{
		Kiver.hp = Kiver.hp + inventory[choose].hp;
		Kiver.mp = Kiver.mp + inventory[choose].mp;

		if (Kiver.hp > 100)
		{
			Kiver.hp = 100;
		}
		else if (Kiver.mp > 100)
		{
			Kiver.mp = 100;
		}

		inventory[choose] = emptySlot();

		cout << "Успешно" << endl;
	}
	else if (inventory[choose].strength > 0)
	{
		cout << "Нельзя сменить оружие во время боя." << endl;
	}
	else if (inventory[choose].armor > 0)
	{
		cout << "Нельзя сменить броню во время боя." << endl;
	}
	else
	{
		cout << "Предмета нету в данной ячейке" << endl;
	}
	system("pause");
}

// Взятие предмета из сундука.
void takeItem(items*& chest, items*& inventory, int choose)
{
	int i = 0;

	do {
		if (inventory[i].name == " ")
		{
			inventory[i] = chest[choose];
			chest[choose] = emptySlot();
			i = 21;
		}
		else 
		{
			i++;
		}
	} while (i != 21);
}

// Действия с инвентарём.
void inventoryUse(player& Kiver, items*& inventory, items& currentlyWeapon, items& currentlySuit)
{
	int playerChooseItem;
	int playerChooseAction;

	do {
		inventoryWatch(inventory);

		cout << "> ";

		bool flag = false;
		do
		{
			cin >> playerChooseItem;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		playerChooseItem = playerChooseItem - 1;

		if (playerChooseItem > -1 & playerChooseItem < 20)
		{
			do
			{
				system("cls");

				cout << "Что вы хотите сделать с данным предметом?:" << endl << "1 - Использовать\n2 - Изучить\n0 - Назад" << endl << "> ";
				
				bool flag = false;
				do
				{
					cin >> playerChooseAction;
					if (cin.get() != (int)'\n')
						flag = true;
					else
						flag = false;

				} while (flag == true);


				switch (playerChooseAction)
				{
				case 1:
					// Использования предмета.
					useItem(Kiver, inventory, playerChooseItem, currentlyWeapon, currentlySuit);
					break;
				case 2:
					// Просмотр деталей предмета.
					itemDetailsWatch(inventory[playerChooseItem]);
					break;
				case 0:
					break;
				default:
					cout << "Вы вели значение неверно" << endl;
					system("pause");
					break;
				}
			} while (playerChooseAction != 0);
		}
		else if (playerChooseItem == -1)
		{

		}
		else
		{
			cout << "Вы вели значение неверно" << endl;
			system("pause");
		}
	} while (playerChooseItem != -1);
}

// Использование сундука.
void chestUse(items*& inventory, items*& chest)
{
	int playerChooseItem;
	int playerChooseAction;

	do {
		chestWatch(chest);

		cout << "> ";

		bool flag = false;
		do
		{
			cin >> playerChooseItem;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		playerChooseItem = playerChooseItem - 1;

		if (playerChooseItem > -1 & playerChooseItem < 5)
		{
			do
			{
				system("cls");

				cout << "Что вы хотите сделать с данным предметом?:" << endl << "1 - Забрать\n2 - Изучить\n0 - Назад" << endl << "> ";
				
				bool flag = false;
				do
				{
					cin >> playerChooseAction;
					if (cin.get() != (int)'\n')
						flag = true;
					else
						flag = false;

				} while (flag == true);


				switch (playerChooseAction)
				{
				case 1:
					// Использования предмета.
					takeItem(chest, inventory, playerChooseItem);
					break;
				case 2:
					// Просмотр деталей предмета.
					itemDetailsWatch(chest[playerChooseItem]);
					break;
				case 0:
					break;
				default:
					cout << "Вы вели значение неверно" << endl;
					system("pause");
					break;
				}
			} while (playerChooseAction != 0);
		}
		else if (playerChooseItem == -1)
		{

		}
		else
		{
			cout << "Вы вели значение неверно" << endl;
			system("pause");
		}
	} while (playerChooseItem != -1);
}

// Использование инвентаря во время боя.
void inventoryUse(player& Kiver, items*& inventory)
{
	int playerChooseItem;
	int playerChooseAction;

	do {
		inventoryWatch(inventory);

		cout << "> ";

		bool flag = false;
		do
		{
			cin >> playerChooseItem;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		playerChooseItem = playerChooseItem - 1;

		if (playerChooseItem > -1 & playerChooseItem < 20)
		{
			do
			{
				system("cls");

				cout << "Что вы хотите сделать с данным предметом?:" << endl << "1 - Использовать\n2 - Изучить\n0 - Назад" << endl << "> ";

				bool flag = false;
				do
				{
					cin >> playerChooseAction;
					if (cin.get() != (int)'\n')
						flag = true;
					else
						flag = false;

				} while (flag == true);


				switch (playerChooseAction)
				{
				case 1:
					// Использования предмета.
					useItem(Kiver, inventory, playerChooseItem);
					break;
				case 2:
					// Просмотр деталей предмета.
					itemDetailsWatch(inventory[playerChooseItem]);
					break;
				case 0:
					break;
				default:
					cout << "Вы вели значение неверно" << endl;
					system("pause");
					break;
				}
			} while (playerChooseAction != 0);
		}
		else if (playerChooseItem == -1)
		{

		}
		else
		{
			cout << "Вы вели значение неверно" << endl;
			system("pause");
		}
	} while (playerChooseItem != -1);
}
