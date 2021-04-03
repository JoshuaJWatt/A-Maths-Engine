#pragma once

#ifndef MEVECTORSANDMATRICES_H_
#define MEVECTORSANDMATRICES_H_

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
		friend std::ostream& operator<<(std::ostream& os, const vector3 v);

	};

	class matrix2x2 {
	public:
		float matrixData[4];

		matrix2x2();
		matrix2x2(float m0, float m1, float m2, float m3);
		float det();
	};

	class matrix {
	public:
		float matrixData[9];

		matrix();
		matrix(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
		void Show();
		matrix Identity();
		void becomeIdentity();
		vector3 operator*(const vector3& v);
		matrix operator*(const float& k);
		matrix operator*(const matrix& m);
		void operator*=(const float& k);
		void operator*=(const matrix& m);
		matrix operator/(const float k);
		matrix operator+(const matrix& m);
		matrix operator-(const matrix& m);
		friend std::ostream& operator<<(std::ostream& os, const matrix& m);
		matrix matrixOfMinors();
		matrix cofactor();
		void becomeTranspose();
		matrix transpose();
		float det();
		matrix inverse(bool debug = 0);
		vector3 transform(const vector3& v);

	};
	//
	//	class newmatrix {
	//	public:
	//		float matrixData;
	//		int rows;
	//		int columns;
	//
	//		newmatrix();
	//		newmatrix(int x, int y, float md[]);
	//	};
}

#endif