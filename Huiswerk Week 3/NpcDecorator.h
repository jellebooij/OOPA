#pragma once
#include "Npc.h"

class NpcDecorator : public Npc {

protected:
	Npc* npc;

public:
	NpcDecorator(Npc* npc) : npc(npc){}
	
	virtual void render(){
		npc->render();
	}
};
