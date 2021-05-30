#include "menuFunc.h"

// ������� �������� � �������� ���� ����� ������� �������� ��������.
void gameLor()
{
	system("cls");
	cout << "\n\t����� ��������� � ����������� ��� ���� �����, ������, ��� ��� ��������, �� ����� ���������� ���������" << endl << " \t�� ����� ������� ����������, ������ �� ���� �� ������, ��� ��������� ������� ��� � ��� �� ��� ��� ���������.\n\n" << endl;
	system("pause");
}


// ��� �������� ������ ������ ��� ��������.
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

// �������� ������� ��������� �������� ������� �������.
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

// �������� ������ ������ ��� ����������� �� �������������
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


// �������� ���������� �� ����� ���������� ����������������.
player characterStart()
{
	player Kiver;
	Kiver.name = "�����";
	Kiver.hp = 100;
	Kiver.mp = 100;
	Kiver.armor = 5;
	Kiver.shield = 0;
	Kiver.strength = 17;
	Kiver.exp = 0;
	Kiver.lvl = 1;
	Kiver.weapon = "����";
	Kiver.suit = "������������ ������";
	return Kiver;
}


// ��� �������� ������ ����� ����� �������.
items smallHealPotion()
{
	items smallHealPotion;
	smallHealPotion.name = "����� ����� �������";
	smallHealPotion.details = "�������������� 25 HP.";
	smallHealPotion.hp = 25;
	smallHealPotion.mp = 0;
	smallHealPotion.armor = 0;
	smallHealPotion.strength = 0;

	return smallHealPotion;
}

items mediumHealPotion()
{
	items mediumHealPotion;
	mediumHealPotion.name = "������� ����� �������";
	mediumHealPotion.details = "�������������� 50 HP.";
	mediumHealPotion.hp = 50;
	mediumHealPotion.mp = 0;
	mediumHealPotion.armor = 0;
	mediumHealPotion.strength = 0;

	return mediumHealPotion;
}

items bigHealPotion()
{
	items bigHealPotion;
	bigHealPotion.name = "������� ����� �������";
	bigHealPotion.details = "�������������� 100 HP.";
	bigHealPotion.hp = 100;
	bigHealPotion.mp = 0;
	bigHealPotion.armor = 0;
	bigHealPotion.strength = 0;

	return bigHealPotion;
}


// ��� �������� ������ ����� ����� ����.
items smallManaPotion()
{
	items smallManaPotion;
	smallManaPotion.name = "����� ����� ����";
	smallManaPotion.details = "�������������� 25 MP.";
	smallManaPotion.hp = 0;
	smallManaPotion.mp = 25;
	smallManaPotion.armor = 0;
	smallManaPotion.strength = 0;

	return smallManaPotion;
}

items mediumManaPotion()
{
	items mediumManaPotion;
	mediumManaPotion.name = "������� ����� ����";
	mediumManaPotion.details = "�������������� 50 MP.";
	mediumManaPotion.hp = 0;
	mediumManaPotion.mp = 50;
	mediumManaPotion.armor = 0;
	mediumManaPotion.strength = 0;

	return mediumManaPotion;
}

items bigManaPotion()
{
	items bigManaPotion;
	bigManaPotion.name = "������� ����� ����";
	bigManaPotion.details = "�������������� 100 MP.";
	bigManaPotion.hp = 0;
	bigManaPotion.mp = 100;
	bigManaPotion.armor = 0;
	bigManaPotion.strength = 0;

	return bigManaPotion;
}


// ��� �������� ������ ����� ����������.
items demonSword()
{
	items demonSword;
	demonSword.name = "���������� ������� ���";
	demonSword.details = "���� ����� 50 ��������";
	demonSword.hp = 0;
	demonSword.mp = 0;
	demonSword.armor = 0;
	demonSword.strength = 50;

	return demonSword;
}

items demonArmor()
{
	items demonArmor;
	demonArmor.name = "���������� ������� �����";
	demonArmor.details = "����� ����� 10 ��������";
	demonArmor.hp = 0;
	demonArmor.mp = 0;
	demonArmor.armor = 25;
	demonArmor.strength = 0;

	return demonArmor;
}

items ironSword()
{
	items ironSword;
	ironSword.name = "�������� ���";
	ironSword.details = "���� ����� 26 ��������";
	ironSword.hp = 0;
	ironSword.mp = 0;
	ironSword.armor = 0;
	ironSword.strength = 26;

	return ironSword;
}

items ironArmor()
{
	items ironArmor;
	ironArmor.name = "�������� �����";
	ironArmor.details = "����� ����� 5 ��������";
	ironArmor.hp = 0;
	ironArmor.mp = 0;
	ironArmor.armor = 13;
	ironArmor.strength = 0;
	
	return ironArmor;
}

items enchantedSword()
{
	items enchantedSword;
	enchantedSword.name = "������������ ���";
	enchantedSword.details = "���� ����� 39 ��������";
	enchantedSword.hp = 0;
	enchantedSword.mp = 0;
	enchantedSword.armor = 0;
	enchantedSword.strength = 39;

	return enchantedSword;
}

items enchantedArmor()
{
	items enchantedArmor;
	enchantedArmor.name = "������������ �����";
	enchantedArmor.details = "����� ����� 18 ��������";
	enchantedArmor.hp = 0;
	enchantedArmor.mp = 0;
	enchantedArmor.armor = 20;
	enchantedArmor.strength = 0;

	return enchantedArmor;
}

items blessedSword()
{
	items blessedSword;
	blessedSword.name = "��������� ���";
	blessedSword.details = "���� ����� 99 ��������";
	blessedSword.hp = 0;
	blessedSword.mp = 0;
	blessedSword.armor = 0;
	blessedSword.strength = 99;

	return blessedSword;
}

items blessedArmor()
{
	items blessedArmor;
	blessedArmor.name = "��������� �����";
	blessedArmor.details = "����� ����� 60 ��������";
	blessedArmor.hp = 0;
	blessedArmor.mp = 0;
	blessedArmor.armor = 60;
	blessedArmor.strength = 0;

	return blessedArmor;
}

// �������� �������� ��� ������ �������.
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

	// ������ ��� ������� [0][2].
	chests[0][0] = smallHealPotion();
	chests[0][1] = smallManaPotion();

	// ������ ��� ������� [0][4].
	chests[1][0] = mediumHealPotion();
	chests[1][1] = mediumManaPotion();
	chests[1][2] = ironSword();

	// ������ ��� ������� [3][4].
	chests[2][0] = bigHealPotion();
	chests[2][1] = mediumManaPotion();
	chests[2][2] = enchantedArmor();

	// ������ ��� ������� [3][6].
	chests[3][0] = smallHealPotion();
	chests[3][1] = bigManaPotion();
	chests[3][2] = ironArmor();

	// ������ ��� ������� [4][0].
	chests[4][0] = enchantedSword();
	chests[4][1] = mediumHealPotion();
	chests[4][2] = mediumManaPotion();

	// ������ ��� ������� [4][3].
	chests[5][1] = mediumHealPotion();
	chests[5][2] = mediumManaPotion();

	// ������ ��� ������� [6][1].
	chests[6][0] = demonSword();
	chests[6][1] = bigHealPotion();
	chests[6][2] = bigManaPotion();
	chests[6][3] = demonArmor();

	// ������ ��� ������� [6][6].
	chests[7][0] = bigHealPotion();
	chests[7][1] = bigManaPotion();

	// ������ ��� ������� [8][5].
	chests[8][0] = blessedSword();
	chests[8][1] = blessedArmor();

	return chests;
}


// ��� �������� ��������.
monsters engineer()
{
	monsters engineer;
	engineer.name = "���-�������";
	engineer.skill = "���";
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
	range.name = "���-������";
	range.skill = "��������";
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
	healer.name = "���-��������";
	healer.skill = "�������";
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
	warrior.name = "���-����";
	warrior.skill = "������";
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
	boss.name = "������ �����";
	boss.skill = "�����";
	boss.hp = 200;
	boss.mp = 100;
	boss.lvl = 5;
	boss.exp = 0;
	boss.armor = 25;
	boss.shield = 0;
	boss.strength = 50;

	return boss;
}

// �������� �������� ��� ������ �������.
monsters* monstersCreate()
{
	monsters* monster = new monsters[9];

	// ������� ��� ������� [0][4] � [8][3].
	monster[0] = engineer();
	monster[1] = engineer();

	// ������� ��� ������� [3][0] � [3][6].
	monster[2] = range();
	monster[3] = range();

	// ������� ��� ������� [4][3] � [6][4].
	monster[4] = healer();
	monster[5] = healer();

	// ������� ��� ������� [6][1] � [8][6].
	monster[6] = warrior();
	monster[7] = warrior();

	// ���� ��� ������� [9][1]
	monster[8] = boss();
	
	return monster;
}

// �������� ������ ����������.
skills emptySlotSkill()
{
	skills emptySlotSkill;

	emptySlotSkill.name = " ";
	emptySlotSkill.details = "�� ��� �� ������� ������ ������";
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

	shield.name = "���";
	shield.details = "��������� ��� �� 50 ������";
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

	electrocute.name = "����� ��������������";
	electrocute.details = "������� 75 ����� �����";
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

	heal.name = "�������";
	heal.details = "������������� �������� �� 25 ������";
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

	fury.name = "������";
	fury.details = "��������� ����";
	fury.amount = 50;
	fury.hp = 0;
	fury.mp = 0;
	fury.shield = 0;
	fury.armor = 0;
	fury.strength = 2;

	return fury;
}

// ������ ������ ��� ������� ������.
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
