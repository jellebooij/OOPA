#pragma once
#include "Npc.h"

class Elf : public Npc {

public:
	void render() override {
		Npc::render();
		std::cout << "Je suis un elf";
	}
};