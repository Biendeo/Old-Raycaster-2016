#pragma once
class Player {
	public:
	Player();
	~Player();
	double GetX();
	double GetY();
	double GetRotation();
	double GetFOV();
	double GetMoveSpeed();
	double GetTurnSpeed();

	void MoveForward();
	void MoveLeft();
	void MoveRight();
	void MoveBack();
	void TurnLeft();
	void TurnRight();

	private:
	double x;
	double y;
	double rotation;
	double fov;
	double moveSpeed;
	double turnSpeed;
};

