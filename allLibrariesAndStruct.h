#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::string;
using std::cin;
using std::endl;

short monstersKilledCount = 0;

// Структура игрока со всеми его характеристиками.
struct player
{
	string name;
	int hp;
	int mp;
	int exp;
	int lvl;
	int armor;
	int shield;
	int strength;
	string weapon;
	string suit;
};

// Структура предметов со всеми характеристиками, которые они могут давать.
struct items
{
	string name;
	string details;
	int amount;
	int hp;
	int mp;
	int armor;
	int strength;
};

// Структура умений со всеми характеристиками, с которыми они взаимодействуют.
struct skills
{
	string name;
	string details;
	int amount;
	int hp;
	int mp;
	int armor;
	int shield;
	int strength;
};

// Структура монстров со всеми их характеристиками.
struct monsters
{
	string name;
	string skill;
	int hp;
	int mp;
	int lvl;
	int exp;
	int armor;
	int shield;
	int strength;
};