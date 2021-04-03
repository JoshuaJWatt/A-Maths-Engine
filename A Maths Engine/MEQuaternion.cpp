#include "MEQuaternion.h"

namespace MathsEngine{
	quaternion::quaternion(float S, vector3& V) {
		s = S;
		v = V;
	};

	quaternion::quaternion(float a, float b, float c, float d) {
		s = a;
		v = vector3(b, c, d);
	};

	quaternion& quaternion::operator=(const quaternion& val) {
		s = val.s;
		v = val.v;

		return *this;
	};

	void quaternion::operator+=(const quaternion& q) {
		s = s + q.s;
		v = v + q.v;
	};

	quaternion quaternion::operator+(const quaternion& q) {
		float s_out = s + q.s;
		vector3 v_out = v + q.v;

		return quaternion(s_out, v_out);
	};

	void quaternion::operator-=(const quaternion& q) {
		s = s - q.s;
		v = v - q.v;
	};

	quaternion quaternion::operator-(const quaternion& q) {
		float s_out = s - q.s;
		vector3 v_out = v - q.v;

		return quaternion(s_out, v_out);
	}


}