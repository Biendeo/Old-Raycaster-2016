#include "Constants.h"
#include "Map.h"
#include "Math.h"


Map::Map() {
	// A default field.
	walls.emplace_back(WallBlock(0, 5, COLOR_CYAN));
	walls.emplace_back(WallBlock(2, 5, COLOR_ORANGE));
	walls.emplace_back(WallBlock(-1, 5, COLOR_GREEN));
	walls.emplace_back(WallBlock(-1, 6, COLOR_WHITE));
}


Map::~Map() {
}

Uint32 Map::GetBlockColor(Math::Vector2 v) {
	for (WallBlock &wb : walls) {
		if (v.x >= wb.GetX() && v.x - 1 < wb.GetX() && v.y >= wb.GetY() && v.y - 1 < wb.GetY()) {
			return wb.GetColor();
		}
	}
	return COLOR_NONE;
}

bool Map::InWall(Math::Vector2 v) {
	if (GetBlockColor(v) == COLOR_NONE) {
		return false;
	} else {
		return true;
	}
}