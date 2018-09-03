#pragma once
 
#include <iostream>
#include <vector>

class MyMatrix
{
private:
	unsigned int m_m; // rows
	unsigned int m_n; // colunms
	double* m_matrix = nullptr;
	// the sizes is known.
	// so the size is m * n
	// mat[m][n]
	// for example
	// [ 1 2 3 4]
	// <==>
	// mat[0] = [1 2], mat[1] = [3 4]

public:
	
	/********************************************************************************
	*  Function name: MyMatrix (c'tor)
	*  The input: size of the matrix, default value, no input = def c'tor
	*  The output: new MyMatrix object
	*  The function operation: creating new matrix whose elements has default value
	********************************************************************************/
	MyMatrix(unsigned int m = 2 , unsigned int n = 2 , double def_value =0);
	//MyMatrix();
	// MyMatrix(int m, int n, bool rand);
	// TODO: maybe code it?

	/*************************************************************************
	* Function name: MyMatrix (copy c'tor)
	* The input: size of the matrix, default value, no input = def ctor
	* The output: new MyMatrix object
	* The function operation: 
	*************************************************************************/
	MyMatrix(const MyMatrix& myMat);


	/*************************************************************************
	* Function name: destructor
	*  The input: none
	*  The output: none
	*  destructor for deleting the matrix and cleaning the memory afterwards.
    *  The function operation: deleting the dynamic memory.
	*************************************************************************/
	~MyMatrix();


	/*************************************************************************
	*  Function name: getM
	*  The input: none
	*  The output: int, which is the number of rows in the matrix.
	*  The function operation: returns the number of rowes in the matrix.
	*************************************************************************/
	unsigned int getM() const;

	/*************************************************************************
	*  Function name: getN
	*  The input: none
	*  The output: int, which is the number of columns in the matrix.
	*  The function operation: returns the number of colomnes in the matrix
	*************************************************************************/
	unsigned int getN() const;


	/*************************************************************************
	*  Function name: operator[][]   ???????????
	*  The input: MyMatrix object
	*  The output: double 
	*  The function operation: returns the addition of 2 matrices
	*************************************************************************/

// helper object for the [][] operator. transperent to the programer
	class Proxy {
	private:
		double* m_array;
		unsigned int m_size;
	public:
		Proxy(double* array, int size) : m_array(array), m_size(size) { }
		double& operator[](int index);
	};


	
	Proxy operator[](const int rowIndex) const;
	
	
	/************************************************************************************************
	*  Function name: operator+
	*  The input: MyMatrix object, which has to be added to te matrix which operates the operator
	*  The output: MyMatrix object, which is the result of the addition of the matrices.
	*  The function operation: returns the addition of 2 matrices
		can throw "inequal matrices sizes" for two matrices in different size , which cannot be added
		according to the mathematical definition.
	***********************************************************************************************/
	MyMatrix operator+(MyMatrix& mat2);
	
	/*************************************************************************************************
	*  Function name: operator-
	*  The input: MyMatrix object, which has to be subtracted from the matrix which operates the operator
	*  The output: MyMatrix object, which is the result of the substruction of the matrices.
	*  The function operation: returns the substruction of 2 matrices
	can throw "inequal matrices sizes" for two matrices in different size , which cannot be subtracted
	according to the mathematical definition
	**************************************************************************************************/
	MyMatrix operator-(MyMatrix& mat2);
	

	/*************************************************************************************************
	*  Function name: operator-
	*  The input: none
	*  The output: MyMatrix object, which is the result of the original matrix multiplied by -1.
	*  The function operation: returns the substruction of 2 matrices
	can throw "inequal matrices sizes" for two matrices in different size , which cannot be subtracted
	according to the mathematical definition
	**************************************************************************************************/
	MyMatrix operator-(); 

   /*******************************************************************************************
	*  Function name: operator*
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation: returns the multiplication of 2 matrices
	can throw "not suitable matrices sizes for matrix multiplication" for two matrices which
	cannot be multiple according to the mathematical definition
	******************************************************************************************/
	MyMatrix operator*(MyMatrix& mat2);

	/*******************************************************************************************
	*  Function name: operator*
	*  The input: double, which is the scalar that the matrix is multiplied by it.
	*  The output: MyMatrix object
	*  The function operation: returns the multiplication of the matrix by the scalar.
	******************************************************************************************/
	MyMatrix operator*(double float_const);

	friend inline MyMatrix operator*(double float_const, MyMatrix& mat) { return mat * float_const; }
	// 7 * mat <==> mat * 7
	// inline, so implementaion here


	/*******************************************************************************************
	*  Function name: operator=
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation:  making a copy of the matrix.
	******************************************************************************************/
	MyMatrix& operator=(MyMatrix& mat2);  
	

	/*******************************************************************************************
	*  Function name: operator==
	*  The input: MyMatrix object
	*  The output: bool
	*  The function operation: check if the 2 matrices are equal
	******************************************************************************************/
	bool operator==(MyMatrix& mat2);

	bool inline operator!=(MyMatrix & mat2) {
		return !((*this) == mat2);
	}

	// TODO: code it :) (done?)
	 friend std::ostream& operator<<(std::ostream& fout, MyMatrix& mat2print);  // print to output stream.
										// the return is for case like: cout << 1 << 2;
										// that equal to (cout << 1) << 2
	 
	 // for debugging
	 static MyMatrix RandMatrix(int m, int n, int min = 0, int max = 20);
};