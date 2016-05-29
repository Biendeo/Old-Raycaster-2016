#pragma once

class Player;
class Map;
class Timer;

class Game {
	public:
	Game(SDL_Window *window, SDL_Renderer *renderer);
	~Game();
	int Run();

	private:
	SDL_Window *window;
	SDL_Renderer *renderer;

	Player *player;
	Map *map;
	Timer *timer;

	bool exiting;

	void Render();
	Uint32 SpotPixel(int x, int y);
	void HandleInput();
};

