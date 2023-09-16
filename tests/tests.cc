#include <gtest/gtest.h>
#include <matrix/matrix.h>
#include <iostream>
using namespace M;

TEST(MatrixTests, Cons) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12};
	Matrix<int> a(3, 4, array,12);
	cout << a;
}
TEST(MatrixTests, get_rows) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };	
	Matrix<int> a(3, 4, array, 12);
	int check = a.get_rows();
	EXPECT_EQ(check, 3);
}
TEST(MatrixTests, get_cols) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	int check = a.get_cols();
	EXPECT_EQ(check, 4);
}
TEST(MatrixTests, acces_by_index) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	int check = a(2, 2);
	EXPECT_EQ(check, 11);
}
TEST(MatrixTests, operator_equal) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	Matrix<int> b = a;
	int check = b(2, 2);
	EXPECT_EQ(check, 11);
}
TEST(MatrixTests, operator_plus_equal) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	Matrix<int> b(3, 4);
	b += a;
	int check = b(2, 2);
	EXPECT_EQ(check, 11);
}
TEST(MatrixTests, operator_minus_equal) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	Matrix<int> b(3, 4, array, 12);
	b -= a;
	int check = b(2, 2);
	EXPECT_EQ(check, 0);
}
TEST(MatrixTests, operator_plus) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	Matrix<int> b(3, 4, array, 12);
	Matrix c = a + b;
	int check = c(2, 2);
	cout << c;
	EXPECT_EQ(check, 22);
}
TEST(MatrixTests, operator_minus) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	Matrix<int> b(3, 4, array, 12);
	Matrix c = a - b;
	c = c - b;
	int check = c(2, 2);
	cout << c;
	EXPECT_EQ(check,-11);
}
TEST(MatrixTests, operator_multiply_by_num) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);	
	a = a * 8;
	int check = a(2, 2);
	EXPECT_EQ(check, 88);
}
TEST(MatrixTests, operator_devision_by_num) {
	double array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<double> a(3, 4, array, 12);
	a = a / 8;
	double check = a(2, 2);
	EXPECT_EQ(check, 1.375);
}
TEST(MatrixTests, operator_multiply_by_matrix) {
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Matrix<int> a(3, 4, array, 12);
	Matrix<int> b(4, 3, array, 12);
	a = a * b;
	cout << a;
	int check = a(2, 2);
	EXPECT_EQ(check, 330);
}
TEST(MatrixTests, trace) {
	int array[] = { 1,2,3,4,5,6,7,8,9};
	Matrix<int> a(3, 3, array, 9);
	int check = a.trace();
	EXPECT_EQ(check, 330);
}