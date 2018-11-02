#pragma once
#include "Npc.h"

class Orc : public Npc {

public:
	Orc(std::string name) : Npc(name) {}
	void render() override { 
	
		Npc::render();  
		std::cout << "Je suis un orc, ";
	}
};