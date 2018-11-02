#pragma once
#include <vector>
#include "Rule.h"

class Grid {

private:
	std::vector<std::vector<bool>> grid;
	int xSize, ySize;

public:
	Grid(int xSize, int ySize);
	bool getNode(int x, int y) const;
	int countNeighbours(int xPos, int yPos);
	void setNode(int x, int y, bool value);
	int getXSize() const { return xSize; } 
	int getYSize() const { return ySize; } 
	void Update(const Rule& rule);

};