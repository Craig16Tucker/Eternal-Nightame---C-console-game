#include "skills.h"

// ������� ��� ������ �������� �������.
int random()
{
	srand(time(NULL));
	return 1 + rand() % 5;
}

// ������� ��� ���������� �� ����� ���.
void battleBars(player Kiver, monsters monster)
{
	system("cls");

	cout << "HP  " << Kiver.hp << " / 100" << "\t\t\t\t" << "����� � "<< monster.name << "\t\t\t\t\t" << "HP  " << monster.hp << " / 100" << endl;
	cout << "MP  " << Kiver.mp << " / 100" << "\t\t\t\t\t\t\t\t\t\t\t" << "MP  " << monster.mp << " / 100" << endl;
	cout << "SH  " << Kiver.shield << " / 100" << "\t\t\t\t\t\t\t\t\t\t\t" << "SH  " << monster.shield << " / 100" << endl;
}

// ������� ��� ����������� �������� �� ����� ���.
void battleActions()
{
	cout << "________________________________________________________________________________________________________________________\n\n" << endl;
	cout << "\t\t1 - �����\t\t\t2 - ������\t\t\t3 - ���������" << endl;
}

// ������� ��� ����������� ���������� ����� ������.
void battleAttackNotificationsMonsters(monsters monster, int incomingDamage, player Kiver)
{
	cout << "\n\t\t\t\t" << monster.name << " ������� " << monster.strength - Kiver.armor << " �����." << endl;
}

// ������� ��� ����������� ��������������� ������ ����������� � ��� ��������.
void battleSkillNotificationsMonsters(player &Kiver, monsters &monster)
{
	if (monster.mp > 49)
	{
		if (monster.skill == "���")
		{
			cout << "\n\t\t\t\t������� ������ ���� ���." << "\n\t\t\t\t� ���������� �������� ��� �� 65 ������.\n";

			monster.shield += 65;
			if (monster.shield > 100)
			{
				monster.shield = 100;
			}
		}
		else if (monster.skill == "��������")
		{
			cout << "\n\t\t\t\t������ ������ �������� ����� �����." << "\n\t\t\t\t���� ����� ������� �� 20 ������.\n";

			Kiver.armor = Kiver.armor - 20;
			if (Kiver.armor < 0)
			{
				Kiver.armor = 0;
			}
		}
		else if (monster.skill == "�������")
		{
			cout << "\n\t\t\t\t�������� ��������������� ���� ��������." << "\n\t\t\t\t�������� ���������� �������� �� 75 ������.\n";

			monster.hp = monster.hp + 75;
			if (monster.hp > 100)
			{
				monster.hp = 100;
			}
		}
		else if (monster.skill == "������")
		{
			cout << "\n\t\t\t\t���� � ������." << "\n\t\t\t\t���� ���������� �������� �� 20 ������.\n";

			monster.strength = monster.strength + 20;
		}
		else if (monster.skill == "�����")
		{
			cout << "\n\t\t\t\t��� ����� ������ ���������� �� ���." << "\n\t\t\t\t���� ����� ������� �� 0, � �������� �� 50 ������.\n";

			Kiver.armor = 0;
			Kiver.hp = 50;
		}
		monster.mp = monster.mp - 50;
	}
	else {
		cout << "\n\t\t\t\t������� �� ������� ���� ��� ������." << "\n\t\t\t\t��� ��� ��������.\n";
	}
}

// ������� ��� ����������� ���������� ����� �������.
void battleAttackNotificationsPlayer(player Kiver, int incomingDamage, monsters monster)
{
	cout << "\n\t\t\t\t" << Kiver.name << " ������� " << Kiver.strength - monster.armor << " �����." << endl;
}

// ������� ����� ����� ������.
void attackPlayer(player& Kiver, monsters& monster, int& incomingDamage)
{
	if (monster.shield == 0)
	{
		incomingDamage = Kiver.strength - monster.armor;
		if (incomingDamage < 0)
		{
			incomingDamage = 0;
		}
		else if (incomingDamage > 0)
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
}

// ������� ����� ����� �������.
void attackMonster(player& Kiver, monsters &monster, int &incomingDamage)
{
	if (Kiver.shield == 0)
	{
		incomingDamage = monster.strength - Kiver.armor;
		if (incomingDamage > 0)
		{
			Kiver.hp = Kiver.hp - incomingDamage;
		}
	}
	else if (Kiver.shield > 0)
	{
		incomingDamage = monster.strength - Kiver.armor;
		if (incomingDamage < 0)
		{
			incomingDamage = 0;
		}
		else if (incomingDamage > 0)
		{
			if (incomingDamage >= Kiver.shield)
			{
				incomingDamage = incomingDamage - Kiver.shield;
				Kiver.shield = 0;
				if (incomingDamage > 0)
				{
					Kiver.hp = Kiver.hp - incomingDamage;
				}
			}
			else
			{
				Kiver.shield = Kiver.shield - incomingDamage;
			}
		}
	}
}

// �������� ��������.
void monsterAlgoritm(player& Kiver, monsters& monster, int &incomingDamage)
{ 

	if (random() != 5)
	{
		attackMonster(Kiver, monster, incomingDamage);
		battleBars(Kiver, monster);
		battleAttackNotificationsMonsters(monster, incomingDamage, Kiver);
		battleActions();
	}
	else
	{
		battleBars(Kiver, monster);
		battleSkillNotificationsMonsters(Kiver, monster);
		battleActions();
	}
}

// ������� ����, ����� ������� ������.
void lvlLore(player Kiver, skills* &skill)
{
	if (Kiver.lvl == 2)
	{
		system("cls");
		cout << "\n\t\t\t\t�� �������� 2 �������. ������� �������." << endl;
		skill[0] = heal();
		system("pause");
	}
	else if (Kiver.lvl == 3)
	{
		system("cls");
		cout << "\n\t\t\t\t�� �������� 3 �������. ������ ���." << endl;
		skill[1] = shield();
		system("pause");
	}
	else if (Kiver.lvl == 4)
	{
		system("cls");
		cout << "\n\t\t\t\t�� �������� 4 �������. ������� ����� ��������������." << endl;
		skill[2] = electrocute();
		system("pause");
	}
	else if (Kiver.lvl == 5)
	{
		system("cls");
		cout << "\n\t\t\t\t�� �������� 5 �������. �� �������� ������, ������� ���������� ��� ���-����� �����.\n\t\t\t\t������ �� ������ ������� � ������" << endl;
		skill[3] = fury();
		system("pause");
	}
}

// �������� �������� �� ����� ��� ���.
void battleGameplay(player& Kiver, items*& inventory, monsters& monster, skills* skill)
{
	int incomingDamage = 0;
	int playerChoose = 0;

	system("cls");

	battleBars(Kiver, monster);
	cout << "\n\t\t\t\t�� ��� ����� " << monster.name << endl;
	battleActions();

	do {

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
			attackPlayer(Kiver, monster, incomingDamage);
			battleBars(Kiver, monster);
			battleAttackNotificationsPlayer(Kiver, incomingDamage, monster);
			battleActions();
			system("pause");
			if (monster.hp > 0)
			{
				monsterAlgoritm(Kiver, monster, incomingDamage);
			}
			break;
		case 2:
			skillsInv(Kiver, skill, monster);
			battleBars(Kiver, monster);
			battleActions();
			system("pause");
			if (monster.hp > 0)
			{
				monsterAlgoritm(Kiver, monster, incomingDamage);
			}
			break;
		case 3:
			inventoryUse(Kiver, inventory);
			battleBars(Kiver, monster);
			battleActions();
			system("pause");
			monsterAlgoritm(Kiver, monster, incomingDamage);
			break;
		default:
			cout << "�� ���� �������� �������" << endl;
			system("pause");
			battleBars(Kiver, monster);
			battleActions();
			break;
		}

	} while (Kiver.hp > 0 & monster.hp > 0);

	if (Kiver.hp > 0)
	{
		Kiver.exp = Kiver.exp + monster.exp;
		cout << "\t\t\t\t�� ��������. �������� " << monster.exp << " �����." << endl;
		system("pause");
		if (Kiver.exp > 99)
		{
			Kiver.lvl = Kiver.lvl + 1;
			Kiver.exp = Kiver.exp - 100;
			lvlLore(Kiver, skill);
			monstersKilledCount += 1;
		}
	}
	else
	{
		cout << "�� ���������" << endl;
		system("pause");
		exit(0);
	}
}