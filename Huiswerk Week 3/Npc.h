#pragma once
#include <iostream>
#include <string>
class Npc {

public:
	std::string name;
	Npc() {}
	Npc(std::string name) : name(name) {}
	virtual void render() { std::cout << "Je suis " << name << ", "; }

};