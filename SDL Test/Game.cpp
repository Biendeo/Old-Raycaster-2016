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
	int refreshRate = 144;
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
		Uint32 foundColor;
		double distance;
		SDL_Rect rect = SpotVerticalRay(x, foundColor, distance);
		if (rect.h < WINDOW_HEIGHT) {
			SDL_Rect topRect;
			topRect.x = rect.x;
			topRect.y = 0;
			topRect.w = 1;
			topRect.h = rect.y;
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderDrawRect(renderer, &topRect);
			SDL_Rect bottomRect;
			bottomRect.x = rect.x;
			bottomRect.y = rect.y + rect.h;
			bottomRect.w = 1;
			bottomRect.h = WINDOW_HEIGHT - bottomRect.y;
			SDL_RenderDrawRect(renderer, &bottomRect);
		}
		Uint8 r = foundColor / (256 * 256 * 256);
		Uint8 g = foundColor / (256 * 256);
		Uint8 b = foundColor / (256);
		Uint8 a = foundColor;
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
		SDL_RenderDrawRect(renderer, &rect);
	}

	SDL_RenderPresent(renderer);
}

SDL_Rect Game::SpotVerticalRay(int pixelX, Uint32 &foundColor, double &distance) {
	distance = 0;
	const double updateInterval = 0.2;
	const double drawDistance = 6;

	foundColor = 0x00000000;

	double x = player->GetX();
	double y = player->GetY();

	double deltaX = sin((player->GetRotation() + ((double)(pixelX - (WINDOW_WIDTH / 2)) / WINDOW_WIDTH * player->GetFOV())) * PI / 180) * updateInterval;
	double deltaY = cos((player->GetRotation() + ((double)(pixelX - (WINDOW_WIDTH / 2)) / WINDOW_WIDTH * player->GetFOV())) * PI / 180) * updateInterval;

	while (distance < drawDistance && foundColor == 0x00000000) {
		foundColor = map->GetBlockColor(x, y);

		distance += updateInterval;
		x += deltaX;
		y += deltaY;
	}

	double heightAngle = atan(1 / distance) * 180 / PI;
	double screenHeightAngle = ((double)WINDOW_HEIGHT / WINDOW_WIDTH * player->GetFOV());
	int screenY;
	if (heightAngle >= screenHeightAngle || foundColor == 0x00000000) {
		screenY = 0;
		if (foundColor == 0x00000000) {
			foundColor = 0x000000FF;
		}
	} else {
		screenY = (screenHeightAngle - heightAngle) / screenHeightAngle * WINDOW_HEIGHT / 2;
	}

	SDL_Rect rect;
	rect.x = pixelX;
	rect.y = screenY;
	rect.w = 1;
	rect.h = WINDOW_HEIGHT - 2 * rect.y;

	return rect;
}

/**
*  \deprecated {Too slow, use SpotVerticalRay instead.}
*/
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
