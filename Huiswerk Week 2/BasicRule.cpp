#include "BasicRule.h"

bool BasicRule::check(int aliveNeightbours, bool alive) const
{

	if (alive && (aliveNeightbours == 2 || aliveNeightbours == 3)) {
		return true;
	}

	if (aliveNeightbours >= 4 || aliveNeightbours < 2)
		return false;

	if (aliveNeightbours == 3) {
		return true;
	}

	return false;
}
