#include <vector>

#include "WallBlock.h"

#pragma once
class Map {
	public:
	Map();
	~Map();
	Uint32 GetBlockColor(double x, double y);

	private:
	std::vector<WallBlock> walls;
};

