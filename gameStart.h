#include "roomsGameplay.h"

// �������� ����� ��� ����.
void game()
{
	system("cls");

	// ������ ������ ������.
	player Kiver = characterStart();

	// ������ ������ ��� ���������.
	skills* skill = creatingEmptySkillSlots();

	// ������ ������� � �������� ��������� ������ � ������ �������.
	char** room = creatingEmptyRooms();
	room[0][2] = '!';

	// ������ ��������� � ������ ����� ��� ����, ������� ����� �� ������.
	items* inventory = creatingEmptyInvSlots();
	items currentlyWeapon = emptySlot();
	items currentlySuit = emptySlot();

	// ������ ������� � �������� � ���� ������.
	items** chests = chestsCreate();
	
	// ������ �������� � ��������.
	monsters* monster = monstersCreate();

	// ��� ������� �������.
	roomChoose(Kiver, room, inventory, currentlyWeapon, currentlySuit, skill, chests, monster);

	system("pause");
}