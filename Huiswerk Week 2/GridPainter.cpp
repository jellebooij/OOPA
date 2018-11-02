#include "GridPainter.h"
#include <iostream>

const char alive = 'a' + 219 - 97;
const char dead = ' ';

void GridPainter::DrawGrid(const Grid& grid)
{
	for (int y = 0; y < grid.getYSize(); y++)
	{
		for (int x = 0; x < grid.getXSize(); x++)
		{
			if (x == 0)
				std::cout << std::endl;

			if (grid.getNode(x,y))
				std::cout << alive;
			else
				std::cout << dead;
		}
	}
}
