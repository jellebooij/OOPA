#include "Farmer.h"
#include "Soldier.h"
#include "Orc.h"
#include "Shaman.h"

int main() {

	Npc* henk = new Soldier(new Farmer(new Shaman(new Orc("Piet"))));
	(henk)->render();

	std::cin.get();

	return 0;

}