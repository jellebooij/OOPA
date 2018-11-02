#pragma once
#include "Rule.h"

class BasicRule : public Rule{

public:
	bool check(int aliveNeightbours, bool alive) const override;
	

};