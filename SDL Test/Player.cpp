#include <cmath>

#include "Constants.h"
#include "Math.h"
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
	x += sin(Math::DegToRad(rotation)) * moveSpeed;
	y += cos(Math::DegToRad(rotation)) * moveSpeed;
}

void Player::MoveLeft() {
	x -= cos(Math::DegToRad(rotation)) * moveSpeed;
	y += sin(Math::DegToRad(rotation)) * moveSpeed;
}

void Player::MoveRight() {
	x += cos(Math::DegToRad(rotation)) * moveSpeed;
	y -= sin(Math::DegToRad(rotation)) * moveSpeed;
}

void Player::MoveBack() {
	x -= sin(Math::DegToRad(rotation)) * moveSpeed;
	y -= cos(Math::DegToRad(rotation)) * moveSpeed;
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
