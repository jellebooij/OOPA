#pragma once
#include "Npc.h"
#include "NpcDecorator.h"

class Soldier : public NpcDecorator {

protected:


public:
	Soldier(Npc* npc) : NpcDecorator(npc) {}


	void render() override {
		npc->render();
		std::cout << "Je suis un Soldier ";
	}
};