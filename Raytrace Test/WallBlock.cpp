#include "WallBlock.h"



WallBlock::WallBlock(int x, int y, Uint32 color) {
	this->x = x;
	this->y = y;
	this->color = color;
}

WallBlock::~WallBlock() {
}

int WallBlock::GetX() {
	return x;
}

int WallBlock::GetY() {
	return y;
}

Uint32 WallBlock::GetColor() {
	return color;
}
