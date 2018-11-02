#pragma once
#include "Npc.h"
#include "NpcDecorator.h"

class Farmer : public NpcDecorator {

protected:


public:
	Farmer(Npc* npc) : NpcDecorator(npc){}


	void render() override {
		npc->render();
		std::cout << "Je suis un farmer ";
	}
};
