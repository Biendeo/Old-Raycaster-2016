#pragma once
class Player {
	public:
	Player();
	~Player();
	double GetX();
	double GetY();
	Math::Vector2 GetPos();
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
	Math::Vector2 pos;
	double rotation;
	double fov;
	double moveSpeed;
	double turnSpeed;
};

