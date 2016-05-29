#include <cmath>

#include "Constants.h"
#include "Player.h"



Player::Player() {
	x = 0;
	y = 0;
	rotation = 0;
	fov = 90;
	moveSpeed = 0.05;
	turnSpeed = 5;
}


Player::~Player() {
}

double Player::GetX() {
	return x;
}

double Player::GetY() {
	return y;
}

double Player::GetRotation() {
	return rotation;
}

double Player::GetFOV() {
	return fov;
}

double Player::GetMoveSpeed() {
	return moveSpeed;
}

double Player::GetTurnSpeed() {
	return turnSpeed;
}

void Player::MoveForward() {
	x += sin(rotation * PI / 180) * moveSpeed;
	y += cos(rotation * PI / 180) * moveSpeed;
}

void Player::MoveLeft() {
	x -= cos(rotation * PI / 180) * moveSpeed;
	y += sin(rotation * PI / 180) * moveSpeed;
}

void Player::MoveRight() {
	x += cos(rotation * PI / 180) * moveSpeed;
	y -= sin(rotation * PI / 180) * moveSpeed;
}

void Player::MoveBack() {
	x -= sin(rotation * PI / 180) * moveSpeed;
	y -= cos(rotation * PI / 180) * moveSpeed;
}

void Player::TurnLeft() {
	rotation -= turnSpeed;

	while (rotation < 0) {
		rotation += 360;
	}
}

void Player::TurnRight() {
	rotation += turnSpeed;

	while (rotation >= 360) {
		rotation -= 360;
	}
}
