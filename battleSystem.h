#include "skills.h"

// Функция для выбора действия монстра.
int random()
{
	srand(time(NULL));
	return 1 + rand() % 5;
}

// Функция для интерфейса во время боя.
void battleBars(player Kiver, monsters monster)
{
	system("cls");

	cout << "HP  " << Kiver.hp << " / 100" << "\t\t\t\t" << "Битва с "<< monster.name << "\t\t\t\t\t" << "HP  " << monster.hp << " / 100" << endl;
	cout << "MP  " << Kiver.mp << " / 100" << "\t\t\t\t\t\t\t\t\t\t\t" << "MP  " << monster.mp << " / 100" << endl;
	cout << "SH  " << Kiver.shield << " / 100" << "\t\t\t\t\t\t\t\t\t\t\t" << "SH  " << monster.shield << " / 100" << endl;
}

// Функция для отображения действий во время боя.
void battleActions()
{
	cout << "________________________________________________________________________________________________________________________\n\n" << endl;
	cout << "\t\t1 - Атака\t\t\t2 - Умения\t\t\t3 - Инвентарь" << endl;
}

// Функиця для отображения наносимого урона врагом.
void battleAttackNotificationsMonsters(monsters monster, int incomingDamage, player Kiver)
{
	cout << "\n\t\t\t\t" << monster.name << " наносит " << monster.strength - Kiver.armor << " урона." << endl;
}

// Функиця для отображения использованного умения противником и его эффектов.
void battleSkillNotificationsMonsters(player &Kiver, monsters &monster)
{
	if (monster.mp > 49)
	{
		if (monster.skill == "Щит")
		{
			cout << "\n\t\t\t\tИнженер создал себе щит." << "\n\t\t\t\tУ противника появился щит на 65 единиц.\n";

			monster.shield += 65;
			if (monster.shield > 100)
			{
				monster.shield = 100;
			}
		}
		else if (monster.skill == "Меткость")
		{
			cout << "\n\t\t\t\tЛучник теперь стреляет более метко." << "\n\t\t\t\tВаша броня снижена на 20 единиц.\n";

			Kiver.armor = Kiver.armor - 20;
			if (Kiver.armor < 0)
			{
				Kiver.armor = 0;
			}
		}
		else if (monster.skill == "Лечение")
		{
			cout << "\n\t\t\t\tЦелитель восстанавливает себе здоровье." << "\n\t\t\t\tЗдоровье противника повышено на 75 единиц.\n";

			monster.hp = monster.hp + 75;
			if (monster.hp > 100)
			{
				monster.hp = 100;
			}
		}
		else if (monster.skill == "Ярость")
		{
			cout << "\n\t\t\t\tВоин в ярости." << "\n\t\t\t\tУрон противника увеличен на 20 единиц.\n";

			monster.strength = monster.strength + 20;
		}
		else if (monster.skill == "Казнь")
		{
			cout << "\n\t\t\t\tОгр хочет скорее избавиться от вас." << "\n\t\t\t\tВаша броня снижена до 0, а здоровье до 50 единиц.\n";

			Kiver.armor = 0;
			Kiver.hp = 50;
		}
		monster.mp = monster.mp - 50;
	}
	else {
		cout << "\n\t\t\t\tМонстру не хватает маны для умения." << "\n\t\t\t\tЕго ход пропущен.\n";
	}
}

// Функиця для отображения наносимого урона игроком.
void battleAttackNotificationsPlayer(player Kiver, int incomingDamage, monsters monster)
{
	cout << "\n\t\t\t\t" << Kiver.name << " наносит " << Kiver.strength - monster.armor << " урона." << endl;
}

// Рассчёт урона атаки игрока.
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

// Рассчёт урона атаки монстра.
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

// Алгоритм монстров.
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

// История игры, после каждого уровня.
void lvlLore(player Kiver, skills* &skill)
{
	if (Kiver.lvl == 2)
	{
		system("cls");
		cout << "\n\t\t\t\tВы получили 2 уровень. Изучено лечение." << endl;
		skill[0] = heal();
		system("pause");
	}
	else if (Kiver.lvl == 3)
	{
		system("cls");
		cout << "\n\t\t\t\tВы получили 3 уровень. Изучен щит." << endl;
		skill[1] = shield();
		system("pause");
	}
	else if (Kiver.lvl == 4)
	{
		system("cls");
		cout << "\n\t\t\t\tВы получили 4 уровень. Изучена казнь єлектричеством." << endl;
		skill[2] = electrocute();
		system("pause");
	}
	else if (Kiver.lvl == 5)
	{
		system("cls");
		cout << "\n\t\t\t\tВы получили 5 уровень. Вы услышали голоса, которые рассказали вам кое-какую тайну.\n\t\t\t\tТеперь вы можете впадать в ярость" << endl;
		skill[3] = fury();
		system("pause");
	}
}

// Основной геймплей во время боя тут.
void battleGameplay(player& Kiver, items*& inventory, monsters& monster, skills* skill)
{
	int incomingDamage = 0;
	int playerChoose = 0;

	system("cls");

	battleBars(Kiver, monster);
	cout << "\n\t\t\t\tНа вас напал " << monster.name << endl;
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
			cout << "Вы вели значение неверно" << endl;
			system("pause");
			battleBars(Kiver, monster);
			battleActions();
			break;
		}

	} while (Kiver.hp > 0 & monster.hp > 0);

	if (Kiver.hp > 0)
	{
		Kiver.exp = Kiver.exp + monster.exp;
		cout << "\t\t\t\tВы победили. Получено " << monster.exp << " опыта." << endl;
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
		cout << "Вы проиграли" << endl;
		system("pause");
		exit(0);
	}
}