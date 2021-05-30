#include "roomsGameplay.h"

// Создание всего для игры.
void game()
{
	system("cls");

	// Создаём объект игрока.
	player Kiver = characterStart();

	// Создаём умения для персонажа.
	skills* skill = creatingEmptySkillSlots();

	// Создаём локации и отмечаем положение игрока в первой комнате.
	char** room = creatingEmptyRooms();
	room[0][2] = '!';

	// Создаём инвентарь и пустые слоты под вещи, которые будут на игроке.
	items* inventory = creatingEmptyInvSlots();
	items currentlyWeapon = emptySlot();
	items currentlySuit = emptySlot();

	// Создаём сундуки в комнатах и вещи внутри.
	items** chests = chestsCreate();
	
	// Создаём монстров в комнатах.
	monsters* monster = monstersCreate();

	// Сам игровой процесс.
	roomChoose(Kiver, room, inventory, currentlyWeapon, currentlySuit, skill, chests, monster);

	system("pause");
}