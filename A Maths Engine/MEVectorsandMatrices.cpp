#include<cmath>
//#include<iostream>
#include "MEVectorsandMatrices.h"

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
	std::ostream& operator<<(std::ostream& os, const vector3 v) { //  
		os << "(" << v.X << "," << v.Y << "," << v.Z << ")";
		return os;
	}

	// This will make doing a determinant of 3x3 easier. For now I'll just define the determinant of 2x2, and do the others later if I need them (and I can't get the general one working)
	//class matrix2x2 {
		//float matrix2x2::matrixData[4] = { 0.0 };

	matrix2x2::matrix2x2() {
		for (int i = 0; i < 4; i++) {
			matrixData[i] = 0.0f;
		}
		matrixData[0] = matrixData[3] = 1.0f;
	}

	matrix2x2::matrix2x2(float m0, float m1, float m2, float m3) {
		matrixData[0] = m0;		matrixData[2] = m2;

		matrixData[1] = m1;		matrixData[3] = m3;
	}

	float matrix2x2::det() {
		// ad - bc
		float out = (matrixData[0] * matrixData[3]) - (matrixData[2] * matrixData[1]);
		return out;
	}
	//};
	// I think this method for doing a matrix, vs just using the built in ones is dumb, but I'm sure there's a reason for it. Making a generalised one is hard, and not currently working, so here is a 3x3 one
	// The matrix is arranged as:
	// 0 3 6
	// 1 4 7
	// 2 5 8 
	// (cos otherwise OpenGL will throw a hissyfit apparently, we'll see)
	//class matrix {
		//float matrixData[9] = { 0.0 };

		// Constructors
		// This seems a bit pointless when we can just set it to the values in a single line
	matrix::matrix() {
		for (int i = 0; i < 9; i++) {
			matrixData[i] = 0.0f;
		}
		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	}

	matrix::matrix(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8) {
		matrixData[0] = m0;			matrixData[3] = m3;			matrixData[6] = m6;

		matrixData[1] = m1;			matrixData[4] = m4;			matrixData[7] = m7;

		matrixData[2] = m2;			matrixData[5] = m5;			matrixData[8] = m8;
	}

	matrix matrix::Identity() {
		matrix(out);
		for (int i = 0; i < 9; i++) {
			if (i == 0 || i == 4 || i == 8) {
				out.matrixData[i] = 1.0f;
			}
			else {
				out.matrixData[i] = 0.0f;
			}
		}
		return(out);
	}

	void matrix::becomeIdentity() {
		matrix(out) = Identity();
		for (int i = 0; i < 9; i++) {
			matrixData[i] = out.matrixData[i];
		}
	}

	//// Copy Constructor (Still dunno what these are, but they make the compiler unhappy)
	//matrix& operator=(const matrix& value);

	//// Destructor
	//~matrix();

	// So that we can check what the matrix looks like. Replace with a << overload one we get that to work
	void matrix::Show() {
		std::cout << "[" << matrixData[0] << "," << matrixData[3] << "," << matrixData[6] << "]" << std::endl;
		std::cout << "[" << matrixData[1] << "," << matrixData[4] << "," << matrixData[7] << "]" << std::endl;
		std::cout << "[" << matrixData[2] << "," << matrixData[5] << "," << matrixData[8] << "]" << std::endl;
	}

	vector3 matrix::operator*(const vector3& v) {
		vector3 out;
		out.X = matrixData[0] * v.X + matrixData[3] * v.Y + matrixData[6] * v.Z;
		out.Y = matrixData[1] * v.X + matrixData[4] * v.Y + matrixData[7] * v.Z;
		out.Z = matrixData[2] * v.X + matrixData[5] * v.Y + matrixData[8] * v.Z;
		return out;
	}

	matrix matrix::operator*(const float& k) {
		matrix out;

		for (int i = 0; i < 9; i++) {
			out.matrixData[i] = matrixData[i] * k;
		}
		return(out);
	}

	void matrix::operator*=(const float& k) {
		for (int i = 0; i < 9; i++) {
			matrixData[i] *= k;
		};
	}

	matrix matrix::operator/(const float k) {
		matrix(out);
		for (int i = 0; i < 9; i++) {
			out.matrixData[i] = matrixData[i] / k;
		};
		return(out);
	}

	matrix matrix::operator+(const matrix& m) {
		matrix(out);
		for (int i = 0; i < 9; i++) {
			out.matrixData[i] = m.matrixData[i] + matrixData[i];
		};
		return(out);
	}

	matrix matrix::operator-(const matrix& m) {
		matrix(out);
		for (int i = 0; i < 9; i++) {
			out.matrixData[i] = matrixData[i] - m.matrixData[i];
		}
		return(out);
	}

	// This could have been done with for loops, but it's not super simple, and would make it much harder to read
	matrix matrix::operator*(const matrix& m) {
		matrix(out);
		out.matrixData[0] = matrixData[0] * m.matrixData[0] + matrixData[3] * m.matrixData[1] + matrixData[6] * m.matrixData[2];
		out.matrixData[1] = matrixData[0] * m.matrixData[3] + matrixData[3] * m.matrixData[4] + matrixData[6] * m.matrixData[5];
		out.matrixData[2] = matrixData[0] * m.matrixData[6] + matrixData[3] * m.matrixData[7] + matrixData[6] * m.matrixData[8];
		out.matrixData[3] = matrixData[1] * m.matrixData[0] + matrixData[4] * m.matrixData[1] + matrixData[7] * m.matrixData[2];
		out.matrixData[4] = matrixData[1] * m.matrixData[3] + matrixData[4] * m.matrixData[4] + matrixData[7] * m.matrixData[5];
		out.matrixData[5] = matrixData[1] * m.matrixData[6] + matrixData[4] * m.matrixData[7] + matrixData[7] * m.matrixData[8];
		out.matrixData[6] = matrixData[2] * m.matrixData[0] + matrixData[5] * m.matrixData[1] + matrixData[8] * m.matrixData[2];
		out.matrixData[7] = matrixData[2] * m.matrixData[3] + matrixData[5] * m.matrixData[4] + matrixData[8] * m.matrixData[5];
		out.matrixData[8] = matrixData[2] * m.matrixData[6] + matrixData[5] * m.matrixData[7] + matrixData[8] * m.matrixData[8];

		return(out);
	}

	void matrix::operator*=(const matrix& m) {
		matrix(out); // We need to be able to store our new values before writing them to the original matrix
		// IDK how to call/address/whatever the matrix being modified, so we'll just copy-paste the * operator code:
		out.matrixData[0] = matrixData[0] * m.matrixData[0] + matrixData[3] * m.matrixData[1] + matrixData[6] * m.matrixData[2];
		out.matrixData[1] = matrixData[0] * m.matrixData[3] + matrixData[3] * m.matrixData[4] + matrixData[6] * m.matrixData[5];
		out.matrixData[2] = matrixData[0] * m.matrixData[6] + matrixData[3] * m.matrixData[7] + matrixData[6] * m.matrixData[8];
		out.matrixData[3] = matrixData[1] * m.matrixData[0] + matrixData[4] * m.matrixData[1] + matrixData[7] * m.matrixData[2];
		out.matrixData[4] = matrixData[1] * m.matrixData[3] + matrixData[4] * m.matrixData[4] + matrixData[7] * m.matrixData[5];
		out.matrixData[5] = matrixData[1] * m.matrixData[6] + matrixData[4] * m.matrixData[7] + matrixData[7] * m.matrixData[8];
		out.matrixData[6] = matrixData[2] * m.matrixData[0] + matrixData[5] * m.matrixData[1] + matrixData[8] * m.matrixData[2];
		out.matrixData[7] = matrixData[2] * m.matrixData[3] + matrixData[5] * m.matrixData[4] + matrixData[8] * m.matrixData[5];
		out.matrixData[8] = matrixData[2] * m.matrixData[6] + matrixData[5] * m.matrixData[7] + matrixData[8] * m.matrixData[8];

		// Overwrite the old matrix data with the new data
		for (int i = 0; i < 9; i++) {
			matrixData[i] = out.matrixData[i];
		};
	}

	// Overload << so that we can get matrices to output -- friend 
	std::ostream& operator<<(std::ostream& os, const matrix& m) { //  
		os << "[" << m.matrixData[0] << "," << m.matrixData[3] << "," << m.matrixData[6] << "]" << std::endl <<
			"[" << m.matrixData[1] << "," << m.matrixData[4] << "," << m.matrixData[7] << "]" << std::endl <<
			"[" << m.matrixData[2] << "," << m.matrixData[5] << "," << m.matrixData[8] << "]" << std::endl;
		return os;
	}

	// Stuff we need to find the inverse of a matrix.
	matrix matrix::matrixOfMinors() {
		matrix out;

		out.matrixData[0] = matrixData[4] * matrixData[8] - matrixData[7] * matrixData[5];		out.matrixData[3] = matrixData[1] * matrixData[8] - matrixData[7] * matrixData[2];		out.matrixData[6] = matrixData[1] * matrixData[5] - matrixData[4] * matrixData[2];
		out.matrixData[1] = matrixData[3] * matrixData[8] - matrixData[6] * matrixData[5];		out.matrixData[4] = matrixData[0] * matrixData[8] - matrixData[6] * matrixData[2];		out.matrixData[7] = matrixData[0] * matrixData[5] - matrixData[3] * matrixData[2];
		out.matrixData[2] = matrixData[3] * matrixData[7] - matrixData[6] * matrixData[4];		out.matrixData[5] = matrixData[0] * matrixData[7] - matrixData[6] * matrixData[1];		out.matrixData[8] = matrixData[0] * matrixData[4] - matrixData[3] * matrixData[1];

		return out;
	}

	matrix matrix::cofactor() {
		return(matrix(1, -1, 1, -1, 1, -1, 1, -1, 1));
	}

	void matrix::becomeTranspose() {
		matrix(out);
		out.matrixData[0] = matrixData[0];
		out.matrixData[1] = matrixData[3];
		out.matrixData[2] = matrixData[6];
		out.matrixData[3] = matrixData[1];
		out.matrixData[4] = matrixData[4];
		out.matrixData[5] = matrixData[7];
		out.matrixData[6] = matrixData[2];
		out.matrixData[7] = matrixData[5];
		out.matrixData[8] = matrixData[8];

		for (int i = 0; i < 9; i++) {
			matrixData[i] = out.matrixData[i];
		}
	}

	// Cover my bases. We can now both modify the current matrix and return a separate one
	matrix matrix::transpose() {
		matrix(out);
		out.matrixData[0] = matrixData[0];
		out.matrixData[1] = matrixData[3];
		out.matrixData[2] = matrixData[6];
		out.matrixData[3] = matrixData[1];
		out.matrixData[4] = matrixData[4];
		out.matrixData[5] = matrixData[7];
		out.matrixData[6] = matrixData[2];
		out.matrixData[7] = matrixData[5];
		out.matrixData[8] = matrixData[8];
		return out;
	}

	// We're going to use the Laplace fomula, so that we can scale this up more easily if needed. And it makes me feel smarter than just doing a load of addition at once
	float matrix::det() {
		matrix mat;
		for (int i = 0; i < 9; i++) {
			mat.matrixData[i] = matrixData[i];
		}
		// Make the 3 2x2 matrices we need:
		matrix2x2 X(mat.matrixData[4], mat.matrixData[5], mat.matrixData[7], mat.matrixData[8]);
		matrix2x2 Y(mat.matrixData[1], mat.matrixData[2], mat.matrixData[7], mat.matrixData[8]);
		matrix2x2 Z(mat.matrixData[1], mat.matrixData[2], mat.matrixData[4], mat.matrixData[5]);

		float A = X.det();
		float B = Y.det();
		float C = Z.det();

		float out = mat.matrixData[0] * A - mat.matrixData[3] * B + mat.matrixData[6] * C;

		return out;
	}

	matrix matrix::inverse(bool debug) { // Had some issues so added some debug to it
		// matrix of minors * cofactors -> Transpose it -> * 1/determinant
		matrix(out);
		float det;
		for (int i = 0; i < 9; i++) {
			out.matrixData[i] = matrixData[i];
		}
		if (debug == 1) {
			std::cout << "\n" << "Data Copy In: " << "\n" << out << "\n";
		};

		// This is horrible, but it works
		det = out.det();
		if (debug == 1) {
			std::cout << "\n" << "Determinant: " << "\n" << det << "\n";
		};
		out = out.matrixOfMinors() * cofactor();
		if (debug == 1) {
			std::cout << "\n" << "Matrix Of Minors * Cofactor: " << "\n" << out << "\n";
		};
		out = out.transpose();
		if (debug == 1) {
			std::cout << "\n" << "Transpose: " << "\n" << out << "\n";
		};

		out = out * (1 / det);
		if (debug == 1) {
			std::cout << "\n" << "Out: " << "\n" << out << "\n";
		};
		return out;
	}

	vector3 matrix::transform(const vector3& v) {
		return((*this) * v);
	}
};















































//// At some point I'd like to repalce our matrix class with a complete version of this, a more generalised version that should allow for any size or shape of matrix.
//	int rows = 1;
//	int columns = 1;
//	float *matrixData = new float[1]; // allocate a memory block to matrixData

//	// The input data should be arranged column-major
//	newmatrix(int x, int y, float md[]) {
//		rows = x;
//		columns = y;
//		matrixData = new float[x*y]; // move the matrixData pointer to a new memory block of the correct size

//		int matrixSize = sizeof(md);
//		if (matrixSize != rows * columns) {
//			// Do some kind of error
//		}

//		for (int i = 0; i < matrixSize - 1; i++) {
//			matrixData[i] = md[i];
//		}


//	}
//};   