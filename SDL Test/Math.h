#pragma once
namespace Math {
	class Vector2 {
		public:
		double x;
		double y;

		Vector2(double x, double y);
		~Vector2();

		Vector2 operator-() const;
		Vector2 operator+(const Vector2 &v);
		Vector2 &operator+=(const Vector2 &v);
		Vector2 operator-(const Vector2 &v);
		Vector2 &operator-=(const Vector2 &v);
		// TODO: Add multiplication and division (more work though).

		double Modulus();
		double Argument();
	};

	class Vector3 {
		public:
		double x;
		double y;
		double z;

		Vector3(double x, double y, double z);
		~Vector3();

		Vector3 operator-() const;
		Vector3 operator+(const Vector3 &v);
		Vector3 &operator+=(const Vector3 &v);
		Vector3 operator-(const Vector3 &v);
		Vector3 &operator-=(const Vector3 &v);
		// TODO: Add multiplication and division (more work though).

		double Modulus();
		double XYArgument();
		double XZArgument();
		double YXArgument();
		double YZArgument();
		double ZXArgument();
		double ZYArgument();
	};

	const double PI = 3.141592653589793;

	double RadToDeg(double radians);
	double DegToRad(double degrees);
}