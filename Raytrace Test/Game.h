#pragma once

class Player;
class Map;
class Timer;

class Game {
	public:
	Game(SDL_Window *window, SDL_Renderer *renderer);
	~Game();
	int Run();

	protected:
	SDL_Window *window;
	SDL_Renderer *renderer;

	Player *player;
	Map *map;
	Timer *timer;

	bool exiting;

	void Render();
	SDL_Rect SpotVerticalRay(int pixelX, Uint32 &foundColor, double &distance);
	Uint32 SpotPixel(int x, int y);
	void HandleInput();
};

