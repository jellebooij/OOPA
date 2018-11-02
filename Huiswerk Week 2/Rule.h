#pragma once

class Rule {

public:
	virtual bool check(int aliveNeightbours, bool alive) const { return false; };

};