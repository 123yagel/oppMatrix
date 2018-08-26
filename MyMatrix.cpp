//#include "stdafx.h"
#include "MyMatrix.h"
#include <iostream>
#include <string>
using namespace std;


MyMatrix::MyMatrix (int m, int n, double def_value)  :m_m(m), m_n(n)
{
	m_matrix = new double*[m];
	for (int i = 0; i < m; i++)
	{
		m_matrix[i] = new double[n];
		for (int j = 0; j < m; j++)
		{
			m_matrix[i][j] = def_value;
		}
	}
}

MyMatrix::MyMatrix(const MyMatrix& myMat)
{
	if (m_m != myMat.getM() || m_n != myMat.getN())
		throw string("math error-matrix cannot...copy");
	MyMatrix newMat(m_m, m_n);
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			newMat[i][j] = myMat[i][j];
		}
	}
}


MyMatrix::~MyMatrix()
{
	for (int i = 0; i < m_m; i++)
	{
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
}

int MyMatrix::getM() const
{
	return m_m;
}

int MyMatrix::getN() const
{
	return m_n;
}

MyMatrix MyMatrix::operator+(MyMatrix & mat2)
{
	if (m_m != mat2.getM() || m_n != mat2.getN())
		throw string("math error-matrix cannot...add");
	//we need to cheak the size of the matrix that we want to add by get or get it as argument of the operator
	MyMatrix newMat(m_m, m_n);
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{ 
			newMat[i][j] = m_matrix[i][j] + mat2[i][j];
		}
	}
	return newMat;
}

void MyMatrix::setOneElement(const double element, int i, int j)
{
	m_matrix[i][j] = element;
}

MyMatrix MyMatrix::operator-(MyMatrix & mat2)
{
	return mat2;
}

MyMatrix MyMatrix::operator*(MyMatrix & mat2)
{
	if (m_n != mat2.getM())
		throw string("math error-matrix cannot...multiply");
	//we need to cheak the size of the matrix that we want to multiply by get or get it as argument of the operator
	MyMatrix newMat(m_m, mat2.getN());
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			for (int k = 0; k < m_n ; k++)
			{
				newMat[i][j] = newMat[i][j]+(m_matrix[i][k]* mat2[k][j]);
			}
		}
	}
	return newMat;
	//return MyMatrix();
}

MyMatrix MyMatrix::operator-()
{
	return ((*this)*(-1));
	//return MyMatrix();
}

MyMatrix MyMatrix::operator*(double doubleConst)
{
	MyMatrix newMat(m_m, m_n);
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			newMat[i][j] = doubleConst*m_matrix[i][j];
		}
	}
	return newMat;
   //return MyMatrix();
}

MyMatrix & MyMatrix::operator=(MyMatrix & mat2)
{
	// TODO: insert return statement here

	return mat2;
}

bool MyMatrix::operator==(MyMatrix & mat2)
{
	if (m_m != mat2.getM() || m_n != mat2.getN())
		return false;
	//or we want to throw exeption in that^ case?
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			if (m_matrix[i][j] != mat2[i][j])
				return false;
		}
	}
	return true;
}
/*
std::ostream & operator<<(std::ostream & fout, MyMatrix & mat2print)
{
	// TODO: insert return statement here
}
*/

double* &MyMatrix::operator[](const int rowIndex) const
{
	return m_matrix[rowIndex];
}