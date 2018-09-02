//#include "stdafx.h"
#include "MyMatrix.h"
#include <iostream>
#include <string>
using namespace std;


MyMatrix::MyMatrix (unsigned int m, unsigned int n, double def_value)
{
	if (m == 0 || n == 0)
		throw string("dimentions musn't be zero");
	m_m = m;
	m_n = n;
	m_matrix = new double[m * n];
	std::fill_n(m_matrix, m * n, def_value);
}

MyMatrix::MyMatrix(const MyMatrix& myMat)
{
	m_m = myMat.m_m;
	m_n = myMat.m_n;
	m_matrix = new double[m_n * m_m];
	std::copy_n(myMat.m_matrix, m_m * m_n, m_matrix);
}

MyMatrix::~MyMatrix()
{
	delete[] m_matrix;
}

unsigned int MyMatrix::getM() const
{
	return m_m;
}

unsigned int MyMatrix::getN() const
{
	return m_n;
}

MyMatrix MyMatrix::operator+(MyMatrix & mat2)
{
	if (m_m != mat2.getM() || m_n != mat2.getN())
		throw string("inequal matrices sizes");
	//we need to cheak the size of the matrix that we want to add by get or get it as argument of the operator
	
	MyMatrix newMat(mat2); // copy ctor
	int size = m_m * m_n; // temp to prevent re-calculations
	for (int i = 0; i < size; i++)
	{
		newMat.m_matrix[i] += m_matrix[i];
	}
	return newMat;
}

MyMatrix MyMatrix::operator-(MyMatrix & mat2) // binary (a-b)
{
	return (*this) + (-mat2);  // the '-' here is unary
}

// TODO: change to private operators?

MyMatrix MyMatrix::operator-()  // unary (-a)
{
	return ((*this)*(-1));
}

MyMatrix MyMatrix::operator*(double doubleConst)
{
	MyMatrix newMat(*this);  // copy ctor
	int size = m_m * m_n; // temp to prevent re-calculations
	for (int i = 0; i < size; i++)
	{
			newMat.m_matrix[i] *= doubleConst;
	}
	return newMat;
}

MyMatrix MyMatrix::operator*(MyMatrix & mat2)
{
	if (m_n != mat2.m_m)
		throw string("not suitable matrices sizes for matrix multiplication");
	//we need to cheak the size of the matrix that we want to multiply by get or get it as argument of the operator

	MyMatrix newMat(m_m, mat2.m_n, 0);
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < mat2.m_n; j++)  //  just m_n ?
		{
			for (int k = 0; k < m_n; k++) // the sum
			{
				newMat[i][j] = newMat[i][j] + ((*this)[i][k] * mat2[k][j]);
			}
		}
	}
	return newMat;
}

MyMatrix & MyMatrix::operator=(MyMatrix & mat2)
{
	if (mat2.m_m != m_m || mat2.m_n != m_n)
	{	// (only) if needed, re-allocate memory
		delete[] m_matrix;
		m_m = mat2.m_m;
		m_n = mat2.m_n;
		m_matrix = new double[m_m * m_n];
	}

	// copy values
	std::copy_n(mat2.m_matrix, m_m * m_n, m_matrix);
	return *this; // so we can do a = (b = c);
}

bool MyMatrix::operator==(MyMatrix & mat2)
{
	if (m_m != mat2.m_m || m_n != mat2.m_n)
		throw string("inequal matrices sizes"); // it's an error..
		//return false; 
	
	int size = m_m * m_n; // temp to prevent re-calculations
	for (int i = 0; i < size; i++)
	{
		if (m_matrix[i] != mat2.m_matrix[i])
			return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& fout, MyMatrix& mat2print)
{
	fout << "Matrix: " << mat2print.m_m << " x " << mat2print.m_n << endl;
	fout << "[ ";
	for (int i = 0; i < mat2print.m_m; i++)
	{
		if (i > 0)
			fout << "  ";
		for (int j = 0; j < mat2print.m_n; j++)
		{
			fout << mat2print[i][j] << " ";
		}
		if (i + 1 != mat2print.m_m) fout << endl;
	}
	fout << " ]" << endl;
	return fout;
}

double& MyMatrix::Proxy::operator[](int index) {
	if (index >= m_size)
		throw string("out of bounds");
	return m_array[index];
}

MyMatrix::Proxy MyMatrix::operator[](const int rowIndex) const
{			// mat[m][n]
	if (rowIndex >= m_m)
		throw string("out of bounds");
	return MyMatrix::Proxy(&(m_matrix[m_n * rowIndex]), m_n);
}

// static function, can be used like ctor: randMat = MyMatrix::RandMatrix(m, n);
// need to do srand(...) in the beginning..
MyMatrix MyMatrix::RandMatrix(int m, int n, int min, int max) {
	MyMatrix retMat(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			retMat[i][j] = min + rand() % (max - min);
		}
	}
	return retMat;
}
