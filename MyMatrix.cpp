#include "stdafx.h"
#include "MyMatrix.h"
#include <iostream>

using namespace std;


MyMatrix::MyMatrix(int m, int n, float def_value)
{
}

MyMatrix::MyMatrix(const MyMatrix & myMat)
{
}

MyMatrix::MyMatrix()
{
}


MyMatrix::~MyMatrix()
{
}

int MyMatrix::getM()
{
	return 0;
}

int MyMatrix::getN()
{
	return 0;
}

MyMatrix MyMatrix::operator+(MyMatrix & mat2)
{
	return MyMatrix();
}

MyMatrix MyMatrix::operator-(MyMatrix & mat2)
{
	return MyMatrix();
}

MyMatrix MyMatrix::operator*(MyMatrix & mat2)
{
	return MyMatrix();
}

MyMatrix MyMatrix::operator-()
{
	return MyMatrix();
}

MyMatrix MyMatrix::operator*(float float_const)
{
	return MyMatrix();
}

MyMatrix & MyMatrix::operator=(MyMatrix & mat2)
{
	// TODO: insert return statement here
}

bool MyMatrix::operator==(MyMatrix & mat2)
{
	return false;
}

std::ostream & operator<<(std::ostream & fout, MyMatrix & mat2print)
{
	// TODO: insert return statement here
}
