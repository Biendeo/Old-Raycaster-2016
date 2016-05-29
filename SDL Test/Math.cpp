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
}