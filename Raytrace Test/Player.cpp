#include <cmath>

#include "Constants.h"
#include "Math.h"
#include "Player.h"



Player::Player() {
	pos = Math::Vector2(0, 0);
	rotation = 0;
	fov = 90;
	moveSpeed = 0.05;
	turnSpeed = 5;
}


Player::~Player() {
}

double Player::GetX() {
	return pos.x;
}

double Player::GetY() {
	return pos.y;
}

Math::Vector2 Player::GetPos() {
	return pos;
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
	pos.x += sin(Math::DegToRad(rotation)) * moveSpeed;
	pos.y += cos(Math::DegToRad(rotation)) * moveSpeed;
}

void Player::MoveLeft() {
	pos.x -= cos(Math::DegToRad(rotation)) * moveSpeed;
	pos.y += sin(Math::DegToRad(rotation)) * moveSpeed;
}

void Player::MoveRight() {
	pos.x += cos(Math::DegToRad(rotation)) * moveSpeed;
	pos.y -= sin(Math::DegToRad(rotation)) * moveSpeed;
}

void Player::MoveBack() {
	pos.x -= sin(Math::DegToRad(rotation)) * moveSpeed;
	pos.y -= cos(Math::DegToRad(rotation)) * moveSpeed;
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
