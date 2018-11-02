#pragma once
#include "Npc.h"
#include "NpcDecorator.h"

class Shaman : public NpcDecorator {

protected:


public:
	Shaman(Npc* npc) : NpcDecorator(npc) {}


	void render() override {
		npc->render();
		std::cout << "Je suis un Shaman ";
	}
};