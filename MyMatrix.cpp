//#include "stdafx.h"
#include "MyMatrix.h"
#include <iostream>
#include <string>
using namespace std;

/********************************************************************************
	*  Function name: MyMatrix (c'tor)
	*  The input: size of the matrix (2D), default value, no input = def c'tor
	*  The output: new MyMatrix object
	*  The function operation: creating a new matrix whose elements has default value
	********************************************************************************/
MyMatrix::MyMatrix (unsigned int m, unsigned int n, double def_value)
{
	if (m == 0 || n == 0)
		throw string("dimentions musn't be zero");
	m_m = m;
	m_n = n;
	m_matrix = new double[m * n];
	std::fill_n(m_matrix, m * n, def_value);
}

/*************************************************************************
	* Function name: MyMatrix (copy c'tor)
	* The input: MyMatrix object
	* The output: new MyMatrix object
	* The function operation: gets an exsiting matrix and creating a copy.
	*************************************************************************/
MyMatrix::MyMatrix(const MyMatrix& myMat)
{
	m_m = myMat.m_m;
	m_n = myMat.m_n;
	m_matrix = new double[m_n * m_m];
	std::copy_n(myMat.m_matrix, m_m * m_n, m_matrix);
}


/*************************************************************************
	* Function name: destructor
	*  The input: none
	*  The output: none
	*  destructor for deleting the matrix and cleaning the memory afterwards.
    *  The function operation: deleting the dynamic memory.
	*************************************************************************/
MyMatrix::~MyMatrix()
{
	delete[] m_matrix;
}


/*************************************************************************
	*  Function name: getM
	*  The input: none
	*  The output: int, which is the number of rows in the matrix.
	*  The function operation: returns the number of rowes in the matrix.
	*************************************************************************/
unsigned int MyMatrix::getM() const
{
	return m_m;
}

	/*************************************************************************
	*  Function name: getN
	*  The input: none
	*  The output: int, which is the number of columns in the matrix.
	*  The function operation: returns the number of colomnes in the matrix
	*************************************************************************/
unsigned int MyMatrix::getN() const
{
	return m_n;
}

	
	/************************************************************************************************
	*  Function name: operator+
	*  The input: MyMatrix object, which has to be added to te matrix which operates the operator
	*  The output: MyMatrix object, which is the result of the addition of the matrices.
	*  The function operation: returns the addition of 2 matrices
		can throw "inequal matrices sizes" for two matrices in different size , which cannot be added
		according to the mathematical definition.
	***********************************************************************************************/
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



	/*************************************************************************************************
	*  Function name: operator-
	*  The input: MyMatrix object, which has to be subtracted from the matrix which operates the operator
	*  The output: MyMatrix object, which is the result of the substruction  of the matrices.
	*  The function operation: returns the substruction of 2 matrices
	can throw "inequal matrices sizes" for two matrices in different size , which cannot be subtracted
	according to the mathematical definition.
	**************************************************************************************************/
MyMatrix MyMatrix::operator-(MyMatrix & mat2) // binary (a-b)
{
	MyMatrix matA = *this;
	MyMatrix matB = -mat2;

	return matA + matB ;  
}



	/*************************************************************************************************
	*  Function name: operator-
	*  The input: none
	*  The output: MyMatrix object, which is the result of the original matrix multiplied by -1.
	*  The function operation: returns the substruction of 2 matrices
	can throw "inequal matrices sizes" for two matrices in different size , which cannot be subtracted
	according to the mathematical definition
	**************************************************************************************************/
MyMatrix MyMatrix::operator-()  
{
	return ((*this)*(-1));
}

/*******************************************************************************************
	*  Function name: operator*
	*  The input: double, which is the scalar that the matrix is multiplied by it.
	*  The output: MyMatrix object
	*  The function operation: returns the multiplication of the matrix by the scalar.
	******************************************************************************************/
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


/*******************************************************************************************
	*  Function name: operator*
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation: returns the multiplication of 2 matrices
	can throw "not suitable matrices sizes for matrix multiplication" for two matrices which
	cannot be multiple according to the mathematical definition
	******************************************************************************************/
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


/*******************************************************************************************
	*  Function name: operator=
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation:  making a copy of the matrix.
	******************************************************************************************/
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


/*******************************************************************************************
	*  Function name: operator==
	*  The input: MyMatrix object
	*  The output: bool
	*  The function operation: check if the 2 matrices are equal
	******************************************************************************************/
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
