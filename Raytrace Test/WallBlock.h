#include <SDL.h>

#pragma once
class WallBlock {
	public:
	WallBlock(int x, int y, Uint32 color);
	~WallBlock();
	int GetX();
	int GetY();
	Uint32 GetColor();

	protected:
	// These are from the south-west of the blocks.
	int x;
	int y;
	Uint32 color;
};

