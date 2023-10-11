#include <matrix/matrix.h>
#include <iostream>
#include <complex>
using namespace std;
using namespace M;
int main() {
	int lower_limit = -100;
	int upper_limit = 100;
	std::complex <double> num(1, 1);
	std::complex<double> num_2(2, 2);
	std::complex<double> array[] = { num,num_2,3,4,5,6,7,8,11 };
	Matrix <std::complex<double>> a(3, 3, array, 9);
	/*Matrix <double> a(3, 3, -100, 100);*/
	Matrix<std::complex<double>> b = a.inverse_matrix();
	cout << a<<endl;
	cout << b<<endl;
	Matrix<std::complex<double>> c = a * b;
	cout << c<<endl;
}