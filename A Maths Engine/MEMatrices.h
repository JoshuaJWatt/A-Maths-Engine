#pragma once

#ifndef MEMATRICES_H_
#define MEMATRICES_H_

#include <iostream>
//#include "MEVectors.h"

namespace MathsEngine{

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
		vector3 operator*(const vector3 &v);
		matrix operator*(const float &k);
		matrix operator*(const matrix& m);
		void operator*=(const float &k);
		void operator*=(const matrix& m);
		matrix operator/(const float k);
		matrix operator+(const matrix &m);
		matrix operator-(const matrix &m); 
		friend std::ostream& operator<<(std::ostream& os, const matrix &m);
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