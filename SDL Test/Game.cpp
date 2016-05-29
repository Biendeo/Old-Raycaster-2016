#include <SDL.h>

#include "Constants.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Timer.h"

#include <iostream>



Game::Game(SDL_Window *window, SDL_Renderer *renderer) {
	this->window = window;
	this->renderer = renderer;
	player = new Player();
	map = new Map();
	int refreshRate = 20;
	timer = new Timer(1000000 / refreshRate);
	exiting = false;
}


Game::~Game() {
	delete player;
	delete map;
	delete timer;
}

int Game::Run() {
	while (!exiting) {
		while (!timer->GetUpdate()) {
			SDL_Delay(1);
		}

		HandleInput();
		timer->DismissUpdate();

		Render();
	}

	return 0;
}

void Game::Render() {
	SDL_RenderClear(renderer);

	for (int x = 0; x < WINDOW_WIDTH; x++) {
		for (int y = 0; y < WINDOW_HEIGHT; y++) {
			Uint32 foundColor = SpotPixel(x, y);
			Uint8 r = foundColor / (256 * 256 * 256);
			Uint8 g = foundColor / (256 * 256);
			Uint8 b = foundColor / (256);
			Uint8 a = foundColor;
			SDL_SetRenderDrawColor(renderer, r, g, b, a);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}

	/*

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	SDL_Rect rectangleBackground;
	rectangleBackground.x = 0;
	rectangleBackground.y = 0;
	rectangleBackground.w = WINDOW_WIDTH;
	rectangleBackground.h = WINDOW_HEIGHT;

	SDL_RenderFillRect(renderer, &rectangleBackground);

	SDL_SetRenderDrawColor(renderer, 255, 50, 0, SDL_ALPHA_OPAQUE);

	SDL_Rect rectangleForeground;
	rectangleForeground.x = 100;
	rectangleForeground.y = 100;
	rectangleForeground.w = 100;
	rectangleForeground.h = 100;

	SDL_RenderFillRect(renderer, &rectangleForeground);

	SDL_RenderDrawPoint(renderer, 300, 300);
	*/

	SDL_RenderPresent(renderer);

	std::cout << "Drawn" << std::endl;
}

Uint32 Game::SpotPixel(int pixelX, int pixelY) {
	double trail = 0;
	const double updateInterval = 0.2;
	const double drawDistance = 6;

	Uint32 foundColor = 0x00000000;

	double x = player->GetX();
	double y = player->GetY();
	double z = 0;

	double deltaX = sin((player->GetRotation() + ((double)(pixelX - (WINDOW_WIDTH / 2)) / WINDOW_WIDTH * player->GetFOV())) * PI / 180) * updateInterval;
	double deltaY = cos((player->GetRotation() + ((double)(pixelX - (WINDOW_WIDTH / 2)) / WINDOW_WIDTH * player->GetFOV())) * PI / 180) * updateInterval;
	double deltaZ = ((double)(pixelY - (WINDOW_HEIGHT / 2)) / WINDOW_WIDTH * player->GetFOV()) * updateInterval;

	while (trail < drawDistance && foundColor == 0x00000000 && z > -1 && z <= 1) {
		foundColor = map->GetBlockColor(x, y);

		trail += updateInterval;
		x += deltaX;
		y += deltaY;
		z += deltaZ;
	}

	if (foundColor == 0x00000000) {
		foundColor = 0x000000FF;
	}

	return foundColor;
}

void Game::HandleInput() {
	SDL_PumpEvents();
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE]) {
		exiting = true;
	}
	if (state[SDL_SCANCODE_W]) {
		player->MoveForward();
	}
	if (state[SDL_SCANCODE_A]) {
		player->MoveLeft();
	}
	if (state[SDL_SCANCODE_S]) {
		player->MoveBack();
	}
	if (state[SDL_SCANCODE_D]) {
		player->MoveRight();
	}
	if (state[SDL_SCANCODE_LEFT]) {
		player->TurnLeft();
	}
	if (state[SDL_SCANCODE_RIGHT]) {
		player->TurnRight();
	}
}
