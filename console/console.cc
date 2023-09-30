#include <matrix/matrix.h>
#include <iostream>
#include <complex>
using namespace std;
using namespace M;
int main() {
	int lower_limit = -100;
	int upper_limit = 100;
	Matrix < double > a(3, 3, lower_limit, upper_limit);
	Matrix<double> b = a.inverse_matrix();
	cout << a<<endl;
	cout << b<<endl;
	Matrix<double> c = a * b;
	cout << c<<endl;
}