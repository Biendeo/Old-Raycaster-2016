#include <cmath>

#include "Math.h"



namespace Math {
	Vector2::Vector2() : Vector2(0, 0) {

	}

	Vector2::Vector2(double x, double y) {
		this->x = x;
		this->y = y;
	}

	Vector2::~Vector2() {
	}

	Vector2 Vector2::operator-() const {
		return Vector2(-x, -y);
	}

	Vector2 Vector2::operator+(const Vector2 &v) {
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 &Vector2::operator+=(const Vector2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2 Vector2::operator-(const Vector2 &v) {
		return *this + -v;
	}

	Vector2 &Vector2::operator-=(const Vector2 &v) {
		return *this += -v;
	}

	double Vector2::Modulus() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	double Vector2::Argument() {
		return atan(y / x);
	}


	Vector3::Vector3() : Vector3(0, 0, 0) {

	}

	Vector3::Vector3(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3::~Vector3() {
	}

	Vector3 Vector3::operator-() const {
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator+(const Vector3 &v) {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 &Vector3::operator+=(const Vector3 &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3 Vector3::operator-(const Vector3 &v) {
		return *this + -v;
	}

	Vector3 &Vector3::operator-=(const Vector3 &v) {
		return *this += -v;
	}

	double Vector3::Modulus() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	double Vector3::XYArgument() {
		return atan(y / x);
	}

	double Vector3::XZArgument() {
		return atan(z / x);
	}

	double Vector3::YXArgument() {
		return atan(x / y);
	}

	double Vector3::YZArgument() {
		return atan(z / y);
	}

	double Vector3::ZXArgument() {
		return atan(x / z);
	}

	double Vector3::ZYArgument() {
		return atan(y / z);
	}


	double RadToDeg(double radians) {
		return radians * 180 / PI;
	}

	double DegToRad(double degrees) {
		return degrees * PI / 180;
	}
	Vector2 RayToNextGrid(Vector2 origin, Vector2 delta) {
		bool goingForX;
		double nextX = NextGrid(origin.x, delta.x);
		double nextY = NextGrid(origin.y, delta.y);
		double timeToNextX = (nextX - origin.x) / delta.x;
		double timeToNextY = (nextY - origin.y) / delta.y;
		if (delta.x == 0 && delta.y == 0) {
			return origin;
		} else {
			if (timeToNextX < timeToNextY) {
				goingForX = true;
			} else {
				goingForX = false;
			}

			if (goingForX) {
				origin.y += timeToNextX * delta.y;
				origin.x = nextX;
			} else {
				origin.x += timeToNextY * delta.x;
				origin.y = nextY;
			}
			return origin;
		}
	}

	double NextGrid(double p, double delta) {
		if (delta > 0) {
			return floor(p + 1);
		} else if (delta < 0) {
			return ceil(p - 1);
		} else {
			return p;
		}
	}

	bool Epsilon(double d) {
		const double epsilon = 0.00002;
		
		int x = (int)d;

		if (abs(d - x) <= epsilon) {
			return true;
		} else {
			return false;
		}
	}
}