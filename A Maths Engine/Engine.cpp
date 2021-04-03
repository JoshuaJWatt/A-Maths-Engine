#include "MEVectors.cpp"
#include "MEMatrices.cpp"

using namespace MathsEngine;

int main() {
	MathsEngine::matrix m(1, 2, 7, 4, 5, 6, 12, 8, 9);
	//m.Show();
	std::cout<<(m);

	//m.transpose();
	//std::cout << (m);

	//MathsEngine::vector3 v(1, 3, 5);
	//std::cout<<(v);

	//float md[6] = { 1, 2, 3, 4, 5, 6 };
	//MathsEngine::newmatrix m2(3, 2, md);
	//std::cout << (m2.matrixData[4]);

	MathsEngine::matrix invm = m.inverse(1);
	std::cout << (invm);

	return(0);
}