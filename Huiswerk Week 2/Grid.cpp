#include "Grid.h"
#include "BasicRule.h"

Grid::Grid(int xSize, int ySize) : grid(xSize, (std::vector<bool>(ySize, false))), xSize(xSize), ySize(ySize){

	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			if (std::rand() % 2 == 1) {
				setNode(x, y, true);
			}
		}
	}
}

bool Grid::getNode(int x, int y) const 
{
	if (x > xSize - 1)
		x = xSize - 1;
	if (y > ySize - 1)	
		y = ySize - 1;
	
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;

	return grid[x][y];
}

int Grid::countNeighbours(int xPos, int yPos)
{
	
	int count = 0;
	
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			
			if (x == 0 && y == 0)
				continue;
			if (xPos + x > xSize)
				continue;
			if (xPos + x < 0)
				continue;
			if (yPos + y > ySize)
				continue;
			if (yPos + y < 0)
				continue;


			if(getNode(xPos + x,yPos + y)){
				count++;
			}
		}
	
	}

	return count;
}

void Grid::setNode(int x, int y, bool value)
{
	if (x > xSize)
		x = xSize;
	if (y > ySize)
		y = ySize;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;

	grid[x][y] = value;
}

void Grid::Update(const Rule& rule)
{
	
	Grid gridCopy = *this;
	
	for (int x = 0; x < getXSize(); x++)
	{
		for (int y = 0; y < getYSize(); y++)
		{
			setNode(x, y, rule.check(gridCopy.countNeighbours(x, y), gridCopy.getNode(x, y)));
		}
	}
	
}
