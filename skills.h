#include "inventoryChests.h"

// �������� ������.
void skillsWatch(skills* skill)
{
	system("cls");

	cout << "\t\t\t\t _________________________________________" << endl;
	cout << "\t\t\t\t|\t\t������        " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "\t\t\t\t| " << i + 1 << ":      " << skill[i].name << endl;
	}
	cout << "\t\t\t\t|_________________________________________" << endl;
	cout << "0 - �����" << endl;
}

// �������� ������� ������.
void skillDetailsWatch(skills skill)
{
	system("cls");
	if (skill.details == " ")
	{
		system("cls");
		cout << "�� ��� �� ������� ������ ������." << endl;
		system("pause");
	}
	else
	{
		cout << "\t\t\t\t\t\t������" << endl << skill.details << endl;
		system("pause");
	}
}

// ������������� ������.
void useSkill(player& Kiver, skills skill, monsters& monster, int index)
{
	if (index == 1 & Kiver.lvl > 2)
	{
		if (Kiver.mp >= skill.amount)
		{
			cout << "\n\t\t\t\t�� ������� ���." << "\n\t\t\t\t��� ������� �� 50 ������.\n";
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
			cout << "� ��� ������������ ����. ��� ��������" << endl;
		}
		system("pause");
	}
	else if (index == 2 & Kiver.lvl > 3)
	{
		if (Kiver.mp >= skill.amount)
		{
			int incomingDamage = skill.strength;
			cout << "\n\t\t\t\t�� ������������ ����� �������������." << "\n\t\t\t\t�� ������� 75 ����� �����.\n";
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
			cout << "� ��� ������������ ����. ��� ��������" << endl;
			system("pause");
		}
	}
	else if (index == 0 & Kiver.lvl > 1)
	{
		if (Kiver.mp >= skill.amount)
		{
			cout << "\n\t\t\t\t�� ���������� �� 25 ������." << endl;
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
			cout << "� ��� ������������ ����. ��� ��������" << endl;
			;
		}
		system("pause");
	}
	else if (index == 3 & Kiver.lvl > 4)
	{
		if (Kiver.mp >= skill.amount)
		{
			cout << "\n\t\t\t\t�� ������� ����." << endl;
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
			cout << "� ��� ������������ ����. ��� ��������" << endl;
		}
		system("pause");
	}
	else
	{
		system("cls");
		cout << "������ ��� �� �������" << endl;
		system("pause");
	}
}

// �������� � ���� � ��������.
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

				cout << "��� �� ������ ������� � ������ �������?:" << endl << "1 - ������������\n2 - �������\n0 - �����" << endl << "> ";

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
					// ������������� ������.
					useSkill(Kiver, skill[playerChooseSkill], monster, playerChooseSkill);
					break;
				case 2:
					// �������� ������� ������.
					skillDetailsWatch(skill[playerChooseSkill]);
					break;
				case 0:
					break;
				default:
					cout << "�� ���� �������� �������" << endl;
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
			cout << "�� ���� �������� �������" << endl;
			system("pause");
		}
	} while (playerChooseSkill != -1);
}

// �������� � ���� � ��������. (��� ���)
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

				cout << "��� �� ������ ������� � ������ �������?:" << endl << "1 - ������������\n2 - �������\n0 - �����" << endl << "> ";

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
					// ������������� ������.
					system("cls");
					cout << "������ ������������ ��� ���." << endl;
					system("pause");
					break;
				case 2:
					// �������� ������� ������.
					skillDetailsWatch(skill[playerChooseSkill]);
					break;
				case 0:
					break;
				default:
					cout << "�� ���� �������� �������" << endl;
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
			cout << "�� ���� �������� �������" << endl;
			system("pause");
		}
	} while (playerChooseSkill != -1);
}