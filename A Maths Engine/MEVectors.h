#pragma once

#ifndef MEVECTORS_H_
#define MEVECTORS_H_

#include <iostream> // might not be necessary, idk

namespace MathsEngine {
	class vector3 {

	public:
		float X;
		float Y;
		float Z;

		vector3();
		vector3(float x, float y, float z);
		float Length();
		float DotProduct(const vector3 v);
		vector3 CrossProduct(const vector3 v);
		vector3 operator*(const float k);
		void operator*=(const float k);
		vector3 operator/(const float k);
		vector3 operator+(const vector3 v);
		vector3 operator-(const vector3 v);
		friend std::ostream& operator<<(std::ostream &os, const vector3 v);

	};
}
#endif