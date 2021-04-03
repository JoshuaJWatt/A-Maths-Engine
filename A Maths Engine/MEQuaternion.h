#pragma once

#ifndef MEQUATERNION_H_
#define MEQUATERNION_H_


#include "MEVectors.h"

namespace MathsEngine {
	class quaternion {
	public:
		float s;
		vector3 v;

		quaternion();
		quaternion(float S, vector3& V);
		quaternion(float a, float b, float c, float d); //allows input of all real values as formula a+bi+cj+dk

		quaternion& operator=(const quaternion& val);

		void operator+=(const quaternion& q);
		quaternion operator+(const quaternion& q);

		void operator-=(const quaternion& q);
		quaternion operator-(const quaternion& q);


	};
}
#endif