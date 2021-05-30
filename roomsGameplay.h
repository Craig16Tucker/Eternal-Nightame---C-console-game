#include "battleSystem.h"

// Основной код игры. (Для комнат с сундуком и монстром)
int inRoomGameplay(player& Kiver, char** (&room), int x, int y, items*& inventory, items& currentlyWeapon, items& currentlySuit, skills* skill, items*& chest, monsters& monster)
{
	if (monster.hp > 0)
	{
		battleGameplay(Kiver, inventory, monster, skill);
	}

	// Создаём переменную для выбора игрока.
	int playerChoose = 0;
	do
	{
		// Интерфейс с выбором действия
		interfaceBars(Kiver);
		roomDetails(room, x, y);
		interfaceActions();
		cout << "\n\t9 - Открыть сундук" << endl << "> ";

		bool flag = false;
		do
		{
			cin >> playerChoose;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		switch (playerChoose)
		{
		case 1:
			// Идти вперёд
			return playerChoose;
			break;
		case 2:
			// Идти назад
			return playerChoose;
			break;
		case 3:
			// Идти налево
			return playerChoose;
			break;
		case 4:
			// Идти направо
			return playerChoose;
			break;
		case 5:
			// Инвентарь.
			inventoryUse(Kiver, inventory, currentlyWeapon, currentlySuit);
			break;
		case 6:
			// Умения.
			skillsInv(Kiver, skill);
			break;
		case 7:
			// Карта.
			minimapWatch(room);
			break;
		case 8:
			// Статистика.
			playerStats(Kiver);
			break;
		case 9:
			// Открыть сундук.
			chestUse(inventory, chest);
			break;
		default:
			cout << "Вы вели значение неверно" << endl;
			system("pause");
			break;
		}
	} while (true);
}

// Основной код игры. (Для комнат без сундука и монстра)
int inRoomGameplay(player& Kiver, char** (&room), int x, int y, items*& inventory, items& currentlyWeapon, items& currentlySuit, skills* skill)
{
	// Создаём переменную для выбора игрока.
	int playerChoose = 0;
	do
	{
		// Интерфейс с выбором действия
		interfaceBars(Kiver);
		roomDetails(room, x, y);
		interfaceActions();
		
		bool flag = false;
		do
		{
			cin >> playerChoose;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		switch (playerChoose)
		{
		case 1:
			// Идти вперёд
			return playerChoose;
			break;
		case 2:
			// Идти назад
			return playerChoose;
			break;
		case 3:
			// Идти налево
			return playerChoose;
			break;
		case 4:
			// Идти направо
			return playerChoose;
			break;
		case 5:
			// Инвентарь.
			inventoryUse(Kiver, inventory, currentlyWeapon, currentlySuit);
			break;
		case 6:
			// Умения.
			skillsInv(Kiver, skill);
			break;
		case 7:
			// Карта.
			minimapWatch(room);
			break;
		case 8:
			// Статистика.
			playerStats(Kiver);
			break;
		default:
			cout << "Вы вели значение неверно" << endl;
			system("pause");
			break;
		}
	} while (true);
}

// Основной код игры. (Для комнат с сундуком)
int inRoomGameplay(player& Kiver, char** (&room), int x, int y, items*& inventory, items& currentlyWeapon, items& currentlySuit, skills* skill, items*& chest)
{
	// Создаём переменную для выбора игрока.
	int playerChoose = 0;
	do
	{
		// Интерфейс с выбором действия
		interfaceBars(Kiver);
		roomDetails(room, x, y);
		interfaceActions();
		cout << "\n\t9 - Открыть сундук" << endl << "> ";

		bool flag = false;
		do
		{
			cin >> playerChoose;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		switch (playerChoose)
		{
		case 1:
			// Идти вперёд
			return playerChoose;
			break;
		case 2:
			// Идти назад
			return playerChoose;
			break;
		case 3:
			// Идти налево
			return playerChoose;
			break;
		case 4:
			// Идти направо
			return playerChoose;
			break;
		case 5:
			// Инвентарь.
			inventoryUse(Kiver, inventory, currentlyWeapon, currentlySuit);
			break;
		case 6:
			// Умения.
			skillsInv(Kiver, skill);
			break;
		case 7:
			// Карта.
			minimapWatch(room);
			break;
		case 8:
			// Статистика.
			playerStats(Kiver);
			break;
		case 9:
			// Открыть сундук.
			chestUse(inventory, chest);
			break;
		default:
			cout << "Вы вели значение неверно" << endl;
			system("pause");
			break;
		}
	} while (true);
}

// Основной код игры. (Для комнат с монстром)
int inRoomGameplay(player& Kiver, char** (&room), int x, int y, items*& inventory, items& currentlyWeapon, items& currentlySuit, skills* skill, monsters& monster)
{
	if (monster.hp > 0)
	{
		battleGameplay(Kiver, inventory, monster, skill);
	}

	// Создаём переменную для выбора игрока.
	int playerChoose = 0;
	do
	{
		// Интерфейс с выбором действия
		interfaceBars(Kiver);
		roomDetails(room, x, y);
		interfaceActions();

		bool flag = false;
		do
		{
			cin >> playerChoose;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		switch (playerChoose)
		{
		case 1:
			// Идти вперёд
			return playerChoose;
			break;
		case 2:
			// Идти назад
			return playerChoose;
			break;
		case 3:
			// Идти налево
			return playerChoose;
			break;
		case 4:
			// Идти направо
			return playerChoose;
			break;
		case 5:
			// Инвентарь.
			inventoryUse(Kiver, inventory, currentlyWeapon, currentlySuit);
			break;
		case 6:
			// Умения.
			skillsInv(Kiver, skill);
			break;
		case 7:
			// Карта.
			minimapWatch(room);
			break;
		case 8:
			// Статистика.
			playerStats(Kiver);
			break;
		default:
			cout << "Вы вели значение неверно" << endl;
			system("pause");
			break;
		}
	} while (true);
}

// Отметка комнаты на карте и запуск скрипта для конкретной локации.
void roomChoose(player& Kiver, char** (&room), items*& inventory, items& currentlyWeapon, items& currentlySuit, skills* skill, items**& chests, monsters*& monster)
{
	bool gameEnded = false;
	do {
		// Комната [0][2].
		if (room[0][2] == '!')
		{
			short x = 0;
			short y = 2;
			short chestID = 0;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill , chests[chestID]))
			{
			case 1:
				goForward(room, x, y);
				room[x][y] = 'S';
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [0][4].
		else if (room[0][4] == '!')
		{
			short x = 0;
			short y = 4;
			short chestID = 1;
			short monsterID = 0;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID], monster[monsterID]))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [1][1].
		else if (room[1][1] == '!')
		{
			short x = 1;
			short y = 1;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [1][2].
		else if (room[1][2] == '!')
		{
			short x = 1;
			short y = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [1][3].
		else if (room[1][3] == '!')
		{
			short x = 1;
			short y = 3;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}

		}

		// Комната [1][4].
		else if (room[1][4] == '!')
		{
			short x = 1;
			short y = 4;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [1][5].
		else if (room[1][5] == '!')
		{
			short x = 1;
			short y = 5;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [1][6].
		else if (room[1][6] == '!')
		{
			short x = 1;
			short y = 6;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}

		}

		// Комната [2][1].
		else if (room[2][1] == '!')
		{
			short x = 2;
			short y = 1;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [2][3].
		else if (room[2][3] == '!')
		{
			short x = 2;
			short y = 3;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}

		}

		// Комната [2][6].
		else if (room[2][6] == '!')
		{
			short x = 2;
			short y = 6;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [3][0].
		else if (room[3][0] == '!')
		{
			short x = 3;
			short y = 0;
			short monsterID = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, monster[monsterID]))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [3][1].
		else if (room[3][1] == '!')
		{
			short x = 3;
			short y = 1;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [3][2].
		else if (room[3][2] == '!')
		{
			short x = 3;
			short y = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [3][4].
		else if (room[3][4] == '!')
		{
			short x = 3;
			short y = 4;
			short chestID = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID]))
			{
			case 1:
				goForward(room, x, y);
				room[3][4] = 'L';
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [3][6].
		else if (room[3][6] == '!')
		{
			short x = 3;
			short y = 6;
			short chestID = 3;
			short monsterID = 3;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID], monster[monsterID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				room[3][6] = 'L';
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [4][0].
		else if (room[4][0] == '!')
		{
			short x = 4;
			short y = 0;
			short chestID = 4;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				room[4][0] = 'L';
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [4][2].
		else if (room[4][2] == '!')
		{
			short x = 4;
			short y = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [4][3].
		else if (room[4][3] == '!')
		{
			short x = 4;
			short y = 3;
			short chestID = 5;
			short monsterID = 4;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID], monster[monsterID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [4][4].
		else if (room[4][4] == '!')
		{
			short x = 4;
			short y = 4;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [5][2].
		else if (room[5][2] == '!')
		{
			short x = 5;
			short y = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [5][4].
		else if (room[5][4] == '!')
		{
			short x = 5;
			short y = 4;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [6][1].
		else if (room[6][1] == '!')
		{
			short x = 6;
			short y = 1;
			short chestID = 6;
			short monsterID = 6;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID], monster[monsterID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				room[6][1] = 'L';
				break;
			}
		}

		// Комната [6][2].
		else if (room[6][2] == '!')
		{
			short x = 6;
			short y = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [6][4].
		else if (room[6][4] == '!')
		{
			short x = 6;
			short y = 4;
			short monsterID = 5;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, monster[monsterID]))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [6][5].
		else if (room[6][5] == '!')
		{
			short x = 6;
			short y = 5;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [6][6].
		else if (room[6][6] == '!')
		{
			short x = 6;
			short y = 6;
			short chestID = 7;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID]))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [7][2].
		else if (room[7][2] == '!')
		{
			short x = 7;
			short y = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [7][4].
		else if (room[7][4] == '!')
		{
			short x = 7;
			short y = 4;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [7][6].
		else if (room[7][6] == '!')
		{
			short x = 7;
			short y = 6;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [8][1].
		else if (room[8][1] == '!')
		{
			short x = 8;
			short y = 1;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				goForward(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [8][2].
		else if (room[8][2] == '!')
		{
			short x = 8;
			short y = 2;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				break;
			}
		}

		// Комната [8][3].
		else if (room[8][3] == '!')
		{
			short x = 8;
			short y = 3;
			short monsterID = 1;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, monster[monsterID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [8][5].
		else if (room[8][5] == '!')
		{
			short x = 8;
			short y = 5;
			short chestID = 8;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, chests[chestID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				errorChoose(room, x, y);
				break;
			case 4:
				goRight(room, x, y);
				room[8][5] = 'L';
				break;
			}
		}

		// Комната [8][6].
		else if (room[8][6] == '!')
		{
			short x = 8;
			short y = 6;
			short monsterID = 7;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, monster[monsterID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				goBack(room, x, y);
				break;
			case 3:
				goLeft(room, x, y);
				break;
			case 4:
				errorChoose(room, x, y);
				break;
			}
		}

		// Комната [9][0]. Первая концовка.
		else if (room[9][0] == '!')
		{
			system("cls");
			cout << "Вы всё это время были в коме, из которой вам удалось выбраться." << endl << "Монстров убито : " << monstersKilledCount << endl;
			gameEnded = true;
		}

		// Комната [9][1]. Босс.
		else if (room[9][1] == '!')
		{
			short x = 9;
			short y = 1;
			short monsterID = 8;

			switch (inRoomGameplay(Kiver, room, x, y, inventory, currentlyWeapon, currentlySuit, skill, monster[monsterID]))
			{
			case 1:
				errorChoose(room, x, y);
				break;
			case 2:
				errorChoose(room, x, y);
				break;
			case 3:
				if (Kiver.lvl != 5)
				{
					goLeft(room, x, y);
					room[9][1] = 'B';
				}
				else {
					errorChoose(room, x, y);
				}
				break;
			case 4:
				if (Kiver.lvl == 5)
				{
					goRight(room, x, y);
					room[9][1] = 'B';
				}
				else {
					errorChoose(room, x, y);
				}
				break;
			}
		}
		// Комната [9][2]. Вторая концовка.
		else if (room[9][2] == '!')
		{
			system("cls");
			cout << "Вы заняли место короля огров и сошли с ума. Вы были убиты таким же странствующим, каким были до этого вы." << endl << "Монстров убито : " << monstersKilledCount << endl;
			gameEnded = true;
		}

	} while (gameEnded == false);
}
