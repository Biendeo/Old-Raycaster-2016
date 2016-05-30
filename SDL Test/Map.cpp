#include "Map.h"



Map::Map() {
	// A default field.
	walls.emplace_back(WallBlock(0, 5, 0x00CCDDFF));
	walls.emplace_back(WallBlock(2, 5, 0xDDAA11FF));
	walls.emplace_back(WallBlock(-1, 5, 0x00CC00FF));
	walls.emplace_back(WallBlock(-1, 6, 0xFFDDFFFF));
}


Map::~Map() {
}

Uint32 Map::GetBlockColor(double x, double y) {
	for (WallBlock &wb : walls) {
		if (x >= wb.GetX() && x - 1 < wb.GetX() && y >= wb.GetY() && y - 1 < wb.GetY()) {
			return wb.GetColor();
		}
	}
	return NULL;
}
