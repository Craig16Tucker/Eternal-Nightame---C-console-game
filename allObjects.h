#include "menuFunc.h"

// Краткие сведения о событиях игры перед началом игрового процесса.
void gameLor()
{
	system("cls");
	cout << "\n\tКивер проснулся в неизвестном для него месте, считая, что его похитили, он решил попытаться выбраться" << endl << " \tиз этого подобия подземелья, однако он даже не помнит, что произошло прошлым днём и как он мог тут оказаться.\n\n" << endl;
	system("pause");
}


// Для создания пустой ячейки для предмета.
items emptySlot()
{
	items emptySlot;
	emptySlot.name = " ";
	emptySlot.details = " ";
	emptySlot.hp = 0;
	emptySlot.mp = 0;
	emptySlot.armor = 0;
	emptySlot.strength = 0;

	return emptySlot;
}

// Создание пустого инвенторя заполняя пустыми слотами.
items* creatingEmptyInvSlots()
{
	int inventorySize = 20;
	items* inventory = new items[inventorySize];
	for (int i = 0; i < inventorySize; i++)
	{
		inventory[i] = emptySlot();
	}

	return inventory;
}

// Создание пустых комнат для дальнейшего их использования
char** creatingEmptyRooms()
{
	int	row = 10;
	int col = 8;
	char** room = new char* [row];
	for (int i = 0; i < row; i++)
	{
		room[i] = new char[col];
	}
	
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			room[i][k] = ' ';
		}
	}
	return room;
}


// Создания персонажей со всеми начальными характеристиками.
player characterStart()
{
	player Kiver;
	Kiver.name = "Кивер";
	Kiver.hp = 100;
	Kiver.mp = 100;
	Kiver.armor = 5;
	Kiver.shield = 0;
	Kiver.strength = 17;
	Kiver.exp = 0;
	Kiver.lvl = 1;
	Kiver.weapon = "Руки";
	Kiver.suit = "Повседневная одежда";
	return Kiver;
}


// Для создания разных видов зелья лечения.
items smallHealPotion()
{
	items smallHealPotion;
	smallHealPotion.name = "Малое зелье лечения";
	smallHealPotion.details = "Востанавливает 25 HP.";
	smallHealPotion.hp = 25;
	smallHealPotion.mp = 0;
	smallHealPotion.armor = 0;
	smallHealPotion.strength = 0;

	return smallHealPotion;
}

items mediumHealPotion()
{
	items mediumHealPotion;
	mediumHealPotion.name = "Среднее зелье лечения";
	mediumHealPotion.details = "Востанавливает 50 HP.";
	mediumHealPotion.hp = 50;
	mediumHealPotion.mp = 0;
	mediumHealPotion.armor = 0;
	mediumHealPotion.strength = 0;

	return mediumHealPotion;
}

items bigHealPotion()
{
	items bigHealPotion;
	bigHealPotion.name = "Большое зелье лечения";
	bigHealPotion.details = "Востанавливает 100 HP.";
	bigHealPotion.hp = 100;
	bigHealPotion.mp = 0;
	bigHealPotion.armor = 0;
	bigHealPotion.strength = 0;

	return bigHealPotion;
}


// Для создания разных видов зелья маны.
items smallManaPotion()
{
	items smallManaPotion;
	smallManaPotion.name = "Малое зелье маны";
	smallManaPotion.details = "Востанавливает 25 MP.";
	smallManaPotion.hp = 0;
	smallManaPotion.mp = 25;
	smallManaPotion.armor = 0;
	smallManaPotion.strength = 0;

	return smallManaPotion;
}

items mediumManaPotion()
{
	items mediumManaPotion;
	mediumManaPotion.name = "Среднее зелье маны";
	mediumManaPotion.details = "Востанавливает 50 MP.";
	mediumManaPotion.hp = 0;
	mediumManaPotion.mp = 50;
	mediumManaPotion.armor = 0;
	mediumManaPotion.strength = 0;

	return mediumManaPotion;
}

items bigManaPotion()
{
	items bigManaPotion;
	bigManaPotion.name = "Большое зелье маны";
	bigManaPotion.details = "Востанавливает 100 MP.";
	bigManaPotion.hp = 0;
	bigManaPotion.mp = 100;
	bigManaPotion.armor = 0;
	bigManaPotion.strength = 0;

	return bigManaPotion;
}


// Для создания разных видов снаряжения.
items demonSword()
{
	items demonSword;
	demonSword.name = "Выкованный демоном меч";
	demonSword.details = "Урон равен 50 единицам";
	demonSword.hp = 0;
	demonSword.mp = 0;
	demonSword.armor = 0;
	demonSword.strength = 50;

	return demonSword;
}

items demonArmor()
{
	items demonArmor;
	demonArmor.name = "Выкованная демоном броня";
	demonArmor.details = "Броня равна 10 единицам";
	demonArmor.hp = 0;
	demonArmor.mp = 0;
	demonArmor.armor = 25;
	demonArmor.strength = 0;

	return demonArmor;
}

items ironSword()
{
	items ironSword;
	ironSword.name = "Железный меч";
	ironSword.details = "Урон равен 26 единицам";
	ironSword.hp = 0;
	ironSword.mp = 0;
	ironSword.armor = 0;
	ironSword.strength = 26;

	return ironSword;
}

items ironArmor()
{
	items ironArmor;
	ironArmor.name = "Железная броня";
	ironArmor.details = "Броня равна 5 единицам";
	ironArmor.hp = 0;
	ironArmor.mp = 0;
	ironArmor.armor = 13;
	ironArmor.strength = 0;
	
	return ironArmor;
}

items enchantedSword()
{
	items enchantedSword;
	enchantedSword.name = "Зачарованный меч";
	enchantedSword.details = "Урон равен 39 единицам";
	enchantedSword.hp = 0;
	enchantedSword.mp = 0;
	enchantedSword.armor = 0;
	enchantedSword.strength = 39;

	return enchantedSword;
}

items enchantedArmor()
{
	items enchantedArmor;
	enchantedArmor.name = "Зачарованная броня";
	enchantedArmor.details = "Броня равна 18 единицам";
	enchantedArmor.hp = 0;
	enchantedArmor.mp = 0;
	enchantedArmor.armor = 20;
	enchantedArmor.strength = 0;

	return enchantedArmor;
}

items blessedSword()
{
	items blessedSword;
	blessedSword.name = "Священный меч";
	blessedSword.details = "Урон равен 99 единицам";
	blessedSword.hp = 0;
	blessedSword.mp = 0;
	blessedSword.armor = 0;
	blessedSword.strength = 99;

	return blessedSword;
}

items blessedArmor()
{
	items blessedArmor;
	blessedArmor.name = "Священная броня";
	blessedArmor.details = "Броня равна 60 единицам";
	blessedArmor.hp = 0;
	blessedArmor.mp = 0;
	blessedArmor.armor = 60;
	blessedArmor.strength = 0;

	return blessedArmor;
}

// Создания сундуков для каждой локации.
items** chestsCreate()
{
	items** chests = new items * [10];
	for (int i = 0; i < 10; i++)
	{
		chests[i] = new items[5];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			chests[i][j] = emptySlot();
		}
	}

	// Сундук для комнаты [0][2].
	chests[0][0] = smallHealPotion();
	chests[0][1] = smallManaPotion();

	// Сундук для комнаты [0][4].
	chests[1][0] = mediumHealPotion();
	chests[1][1] = mediumManaPotion();
	chests[1][2] = ironSword();

	// Сундук для комнаты [3][4].
	chests[2][0] = bigHealPotion();
	chests[2][1] = mediumManaPotion();
	chests[2][2] = enchantedArmor();

	// Сундук для комнаты [3][6].
	chests[3][0] = smallHealPotion();
	chests[3][1] = bigManaPotion();
	chests[3][2] = ironArmor();

	// Сундук для комнаты [4][0].
	chests[4][0] = enchantedSword();
	chests[4][1] = mediumHealPotion();
	chests[4][2] = mediumManaPotion();

	// Сундук для комнаты [4][3].
	chests[5][1] = mediumHealPotion();
	chests[5][2] = mediumManaPotion();

	// Сундук для комнаты [6][1].
	chests[6][0] = demonSword();
	chests[6][1] = bigHealPotion();
	chests[6][2] = bigManaPotion();
	chests[6][3] = demonArmor();

	// Сундук для комнаты [6][6].
	chests[7][0] = bigHealPotion();
	chests[7][1] = bigManaPotion();

	// Сундук для комнаты [8][5].
	chests[8][0] = blessedSword();
	chests[8][1] = blessedArmor();

	return chests;
}


// Для создания монстров.
monsters engineer()
{
	monsters engineer;
	engineer.name = "Огр-инженер";
	engineer.skill = "Щит";
	engineer.hp = 35;
	engineer.mp = 100;
	engineer.lvl = 1;
	engineer.exp = 25;
	engineer.armor = 0;
	engineer.shield = 0;
	engineer.strength = 13;
	
	return engineer;
}

monsters range()
{
	monsters range;
	range.name = "Огр-лучник";
	range.skill = "Меткость";
	range.hp = 50;
	range.mp = 100;
	range.lvl = 2;
	range.exp = 46;
	range.armor = 10;
	range.shield = 0;
	range.strength = 20;

	return range;
}

monsters healer()
{
	monsters healer;
	healer.name = "Огр-целитель";
	healer.skill = "Лечение";
	healer.hp = 60;
	healer.mp = 100;
	healer.lvl = 3;
	healer.exp = 80;
	healer.armor = 0;
	healer.shield = 50;
	healer.strength = 25;

	return healer;
}

monsters warrior()
{
	monsters warrior;
	warrior.name = "Огр-воин";
	warrior.skill = "Ярость";
	warrior.hp = 80;
	warrior.mp = 100;
	warrior.lvl = 4;
	warrior.exp = 99;
	warrior.armor = 20;
	warrior.shield = 0;
	warrior.strength = 34;

	return warrior;
}

monsters boss()
{
	monsters boss;
	boss.name = "Король огров";
	boss.skill = "Казнь";
	boss.hp = 200;
	boss.mp = 100;
	boss.lvl = 5;
	boss.exp = 0;
	boss.armor = 25;
	boss.shield = 0;
	boss.strength = 50;

	return boss;
}

// Создания монстров для каждой локации.
monsters* monstersCreate()
{
	monsters* monster = new monsters[9];

	// Монстры для комнаты [0][4] и [8][3].
	monster[0] = engineer();
	monster[1] = engineer();

	// Монстры для комнаты [3][0] и [3][6].
	monster[2] = range();
	monster[3] = range();

	// Монстры для комнаты [4][3] и [6][4].
	monster[4] = healer();
	monster[5] = healer();

	// Монстры для комнаты [6][1] и [8][6].
	monster[6] = warrior();
	monster[7] = warrior();

	// Босс для комнаты [9][1]
	monster[8] = boss();
	
	return monster;
}

// Создание умений персонажей.
skills emptySlotSkill()
{
	skills emptySlotSkill;

	emptySlotSkill.name = " ";
	emptySlotSkill.details = "Вы ещё не изучили данное умение";
	emptySlotSkill.amount = 0;
	emptySlotSkill.hp = 0;
	emptySlotSkill.mp = 0;
	emptySlotSkill.shield = 0;
	emptySlotSkill.armor = 0;
	emptySlotSkill.strength = 0;

	return emptySlotSkill;
}

skills shield()
{
	skills shield;

	shield.name = "Щит";
	shield.details = "Добавляет щит на 50 единиц";
	shield.amount = 50;
	shield.hp = 0;
	shield.mp = 0;
	shield.shield = 50;
	shield.armor = 0;
	shield.strength = 0;

	return shield;
}

skills electrocute()
{
	skills electrocute;

	electrocute.name = "Казнь электричеством";
	electrocute.details = "Наносит 75 урона врагу";
	electrocute.amount = 40;
	electrocute.hp = 0;
	electrocute.mp = 0;
	electrocute.shield = 0;
	electrocute.armor = 0;
	electrocute.strength = 50;

	return electrocute;
}

skills heal()
{
	skills heal;

	heal.name = "Лечение";
	heal.details = "Востановление здоровья на 25 единиц";
	heal.amount = 25;
	heal.hp = 25;
	heal.mp = 0;
	heal.shield = 0;
	heal.armor = 0;
	heal.strength = 0;

	return heal;
}

skills fury()
{
	skills fury;

	fury.name = "Ярость";
	fury.details = "Удваивает урон";
	fury.amount = 50;
	fury.hp = 0;
	fury.mp = 0;
	fury.shield = 0;
	fury.armor = 0;
	fury.strength = 2;

	return fury;
}

// Создаём умения для каждого уровня.
skills* creatingEmptySkillSlots()
{
	int inventorySize = 4;
	skills* skill = new skills[inventorySize];
	for (int i = 0; i < inventorySize; i++)
	{
		skill[i] = emptySlotSkill();
	}

	return skill;
}
