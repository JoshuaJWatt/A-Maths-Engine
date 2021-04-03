#include "MEVectors.h"
//#include "MEMatrices.h"
#include <cmath>
#include <iostream>


using namespace std;

namespace MathsEngine {
		float X;
		float Y;
		float Z;

		vector3::vector3() {
			X = 0;
			Y = 0;
			Z = 0;
		}

		vector3::vector3(float x, float y, float z) {	// Constructor
			X = x;
			Y = y;
			Z = z;
		}

		//// No idea how this stuff works. we'll put them in when I understand what the fuck a definition class is
		//// Apparently this is a destructor
		//~vector3();

		//// Copy constructors (?????)
		//vector3(const vector3& v);
		//vector3& operator = (const vector3& v);

		float vector3::Length() {	// Calc the absolute value of the Vector/Magnitude
			float val = sqrt(X * X + Y * Y + Z * Z);
			return(val);
		}

		// U.V = u_x*v_x + u_y*v_y + u_z*v_z = |u||v|Cos(\theta)
		float vector3::DotProduct(const vector3 v) {
			float dp = X * v.X + Y * v.Y + Z * v.Z;
			return dp;
		}

		vector3 vector3::CrossProduct(const vector3 v) {
			vector3 result = vector3(Y * v.Z - Z * v.Y,
				Z * v.X - X * v.Z,
				X * v.Y - Y * v.X);
			return result;
		}

		// Some overloads, hopefully
		// Scalar Multiplication
		vector3 vector3::operator*(const float k) {
			X *= k;
			Y *= k;
			Z *= k;
			return vector3(X, Y, Z);
		}

		void vector3::operator*=(const float k) {
			X *= k;
			Y *= k;
			Z *= k;
		}

		// Scalar Division
		vector3 vector3::operator/(const float k) {
			X /= k;
			Y /= k;
			Z /= k;
			return vector3(X, Y, Z);
		}

		vector3 vector3::operator+(const vector3 v) {
			X += v.X;
			Y += v.Y;
			Z += v.Z;
			return vector3(X, Y, Z);
		}

		vector3 vector3::operator-(const vector3 v) {
			X -= v.X;
			Y -= v.Y;
			Z -= v.Z;
			return vector3(X, Y, Z);
		}

		// Overload << so that we can get 3 Vectors to output
		std::ostream& operator<<(std::ostream &os, const vector3 v) { //  
			os << "(" << v.X << "," << v.Y << "," << v.Z << ")";
			return os;
		}

	};
