#include <vector>

#include "Math.h"
#include "WallBlock.h"

#pragma once
class Map {
	public:
	Map();
	~Map();

	Uint32 GetBlockColor(Math::Vector2 v);
	bool InWall(Math::Vector2 v);

	private:
	std::vector<WallBlock> walls;
};

