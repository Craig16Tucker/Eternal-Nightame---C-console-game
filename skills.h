#include "inventoryChests.h"

// Просмотр умений.
void skillsWatch(skills* skill)
{
	system("cls");

	cout << "\t\t\t\t _________________________________________" << endl;
	cout << "\t\t\t\t|\t\tУмения        " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "\t\t\t\t| " << i + 1 << ":      " << skill[i].name << endl;
	}
	cout << "\t\t\t\t|_________________________________________" << endl;
	cout << "0 - Выйти" << endl;
}

// Просмотр деталей умения.
void skillDetailsWatch(skills skill)
{
	system("cls");
	if (skill.details == " ")
	{
		system("cls");
		cout << "Вы ещё не выучили данное умение." << endl;
		system("pause");
	}
	else
	{
		cout << "\t\t\t\t\t\tДетали" << endl << skill.details << endl;
		system("pause");
	}
}

// Использование умения.
void useSkill(player& Kiver, skills skill, monsters& monster, int index)
{
	if (index == 1 & Kiver.lvl > 2)
	{
		if (Kiver.mp >= skill.amount)
		{
			cout << "\n\t\t\t\tВы создали щит." << "\n\t\t\t\tЩит повышен на 50 единиц.\n";
			Kiver.shield = Kiver.shield + 50;
			if (Kiver.shield > 100)
			{
				Kiver.shield = 100;
			}
			Kiver.mp = Kiver.mp - skill.amount;
			if (Kiver.mp < 0)
			{
				Kiver.mp = 0;
			}
		}
		else
		{
			system("cls");
			cout << "У вас недостаточно маны. Ход пропущен" << endl;
		}
		system("pause");
	}
	else if (index == 2 & Kiver.lvl > 3)
	{
		if (Kiver.mp >= skill.amount)
		{
			int incomingDamage = skill.strength;
			cout << "\n\t\t\t\tВы использовали казнь электичеством." << "\n\t\t\t\tВы нанесли 75 урона врагу.\n";
			if (monster.shield == 0)
			{
				incomingDamage = Kiver.strength - monster.armor;
				if (incomingDamage > 0)
				{
					monster.hp = monster.hp - incomingDamage;
				}
			}
			else if (monster.shield > 0)
			{
				incomingDamage = Kiver.strength - monster.armor;
				if (incomingDamage > 0)
				{
					if (incomingDamage >= monster.shield)
					{
						incomingDamage = incomingDamage - monster.shield;
						monster.shield = 0;
						if (incomingDamage > 0)
						{
							monster.hp = monster.hp - incomingDamage;
						}
					}
					else
					{
						monster.shield = monster.shield - incomingDamage;
					}
				}
			}
			system("pause");
		}
		else
		{
			system("cls");
			cout << "У вас недостаточно маны. Ход пропущен" << endl;
			system("pause");
		}
	}
	else if (index == 0 & Kiver.lvl > 1)
	{
		if (Kiver.mp >= skill.amount)
		{
			cout << "\n\t\t\t\tВы излечились на 25 единиц." << endl;
			Kiver.hp = Kiver.hp + skill.hp;
			if (Kiver.hp > 100)
			{
				Kiver.hp = 100;
			}
			Kiver.mp = Kiver.mp - skill.amount;
			if (Kiver.mp < 0)
			{
				Kiver.mp = 0;
			}
		}
		else
		{
			system("cls");
			cout << "У вас недостаточно маны. Ход пропущен" << endl;
			;
		}
		system("pause");
	}
	else if (index == 3 & Kiver.lvl > 4)
	{
		if (Kiver.mp >= skill.amount)
		{
			cout << "\n\t\t\t\tВы удвоили урон." << endl;
			Kiver.hp = Kiver.hp * skill.strength;
			Kiver.mp = Kiver.mp - skill.amount;
			if (Kiver.mp < 0)
			{
				Kiver.mp = 0;
			}
		}
		else
		{
			system("cls");
			cout << "У вас недостаточно маны. Ход пропущен" << endl;
		}
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Умение ещё не изучено" << endl;
		system("pause");
	}
}

// Действия с меню с умениями.
void skillsInv(player &Kiver, skills* skill, monsters &monster)
{
	int playerChooseSkill;
	int playerChooseAction;

	do {
		skillsWatch(skill);

		cout << "> ";

		bool flag = false;
		do
		{
			cin >> playerChooseSkill;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		playerChooseSkill = playerChooseSkill - 1;

		if (playerChooseSkill > -1 & playerChooseSkill < 4)
		{
			do
			{
				system("cls");

				cout << "Что вы хотите сделать с данным умением?:" << endl << "1 - Использовать\n2 - Изучить\n0 - Назад" << endl << "> ";

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
					// Использование умения.
					useSkill(Kiver, skill[playerChooseSkill], monster, playerChooseSkill);
					break;
				case 2:
					// Просмотр деталей умения.
					skillDetailsWatch(skill[playerChooseSkill]);
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
		else if (playerChooseSkill == -1)
		{
			
		}
		else
		{
			cout << "Вы вели значение неверно" << endl;
			system("pause");
		}
	} while (playerChooseSkill != -1);
}

// Действия с меню с умениями. (Вне боя)
void skillsInv(player& Kiver, skills* skill)
{
	int playerChooseSkill;
	int playerChooseAction;

	do {
		skillsWatch(skill);

		cout << "> ";

		bool flag = false;
		do
		{
			cin >> playerChooseSkill;
			if (cin.get() != (int)'\n')
				flag = true;
			else
				flag = false;

		} while (flag == true);

		playerChooseSkill = playerChooseSkill - 1;

		if (playerChooseSkill > -1 & playerChooseSkill < 4)
		{
			do
			{
				system("cls");

				cout << "Что вы хотите сделать с данным умением?:" << endl << "1 - Использовать\n2 - Изучить\n0 - Назад" << endl << "> ";

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
					// Использование умения.
					system("cls");
					cout << "Нельзя использовать вне боя." << endl;
					system("pause");
					break;
				case 2:
					// Просмотр деталей умения.
					skillDetailsWatch(skill[playerChooseSkill]);
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
		else if (playerChooseSkill == -1)
		{

		}
		else
		{
			cout << "Вы вели значение неверно" << endl;
			system("pause");
		}
	} while (playerChooseSkill != -1);
}