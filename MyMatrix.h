#pragma once
 
#include <iostream>

class MyMatrix
{
private:
	unsigned int m_m; // rows
	unsigned int m_n; // columns
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
	*  The output: int, which is the number of rows in the matrix.
	*************************************************************************/
	unsigned int getM() const;

	/*************************************************************************
	*  Function name: getN
	*  The output: int, which is the number of columns in the matrix.
	*************************************************************************/
	unsigned int getN() const;


	// transparent to the user; don't worry about it. if you want to understand better, read the comment below.
	class Array2DOperatorHelper {
/*
2 words about the Array2DOperatorHelper object:
there is no [][] operator.
so we use it in 2 steps:
1. MyMatrix::operator[]
2. Array2DOperatorHelper::operator[]

the first step return the 2nd step object, so we can technically use mat[][] 
this object is transparent to the user

the big pro of using it, is that throw "out of bounds" exceptions, what an array-by-ref don't do.

*/
	private:
		double* m_array;
		unsigned int m_size;
	public:
		Array2DOperatorHelper(double* array, int size) : m_array(array), m_size(size) { }
		double& operator[](int index);
	};
	
	
	/*************************************************************************
	*  Function name: operator[][]
	*  The input: MyMatrix object
	*  The output: double 
	*  The function operation: returns the value of the [i][j] in the matrix, by ref.
	*  it uses un helper object that is transperent to the user
	*  i.e. you don't need to worry about it, and just naturally use mat[i][j]
	*  more explanation in the Array2DOperatorHelper definition.
	*  can throw string "out of bounds"
	*  can used to get & set values of the matrix.
	*************************************************************************/
	Array2DOperatorHelper operator[](const int rowIndex) const;
	
	
	/************************************************************************************************
	*  Function name: operator+
	*  The input: MyMatrix object, which has to be added to te matrix which operates the operator
	*  The output: MyMatrix object, which is the result of the addition of the matrices.
	*  The function operation: returns the addition of 2 matrices
		can throw "unequal matrices sizes" for two matrices in different size , which cannot be added
		according to the mathematical definition.
	***********************************************************************************************/
	MyMatrix operator+(MyMatrix& mat2);
	
	/*************************************************************************************************
	*  Function name: operator- (binary)
	*  The input: MyMatrix object, which has to be subtracted from the matrix which operates the operator
	*  The output: MyMatrix object, which is the result of the substruction of the matrices.
	*  The function operation: returns the substruction of 2 matrices
	*  can throw string "unequal matrices sizes" for two matrices in different size , which cannot be subtracted
	    according to the mathematical definition
	**************************************************************************************************/
	MyMatrix operator-(MyMatrix& mat2);
	

	/*************************************************************************************************
	*  Function name: operator- (unary)
	*  The input: none (just lhs matrix)
	*  The output: MyMatrix object, which is the minus of the input matrix
	**************************************************************************************************/
	MyMatrix operator-(); 

   /*******************************************************************************************
	*  Function name: operator*
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation: returns the multiplication of 2 matrices
	can throw string "not suitable matrices sizes for matrix multiplication" for two matrices which
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

	/*******************************************************************************************
	*  Function name: operator*
	*  The input: double, which is the scalar that the matrix is multiplied by it, and a matrix
	*  The output: MyMatrix object
	*  The function operation: returns the multiplication of the matrix by the scalar.
	*  allows multipliction in const from right (7 * mat <==> mat * 7)
	*  it just simple, so inline & implemented here
	******************************************************************************************/
	friend inline MyMatrix operator*(double float_const, MyMatrix& mat) { return mat * float_const; }

	/*******************************************************************************************
	*  Function name: operator=
	*  The input: MyMatrix object by-ref
	*  The output: MyMatrix object by-ref
	*  The function operation:  making a copy of the matrix. better then the copy ctor in cases the new matrix is in the same size
	******************************************************************************************/
	MyMatrix& operator=(MyMatrix& mat2);  
	

/*******************************************************************************************
	*  Function name: operator==
	*  The input: MyMatrix object
	*  The output: true if the 2 matrices are equal. if the sizes not equal, throws a string "unequal matrices sizes"
	******************************************************************************************/
	bool operator==(MyMatrix& mat2);

	
	/*******************************************************************************************
	*  Function name: operator!=
	*  The input: MyMatrix object
	*  The output: true if the 2 matrices are inequal. if the sizes not equal, throws a string "unequal matrices sizes"
	*  just the opposite of the == operator
	******************************************************************************************/
	bool inline operator!=(MyMatrix & mat2) {
		return !((*this) == mat2);
	}

	/*******************************************************************************************
	*  Function name: operator<<
	*  The input:  MyMatrix object
	*  The output: the given ostream, by ref. in that way one can write cout << 1 << 2;  <==> (cout << 1) << 2;
	*  The function operation: print the mat to the given ostream (mostly cout)
	******************************************************************************************/
	 friend std::ostream& operator<<(std::ostream& fout, MyMatrix& mat2print);  // print to output stream.
										// the return is for case like: cout << 1 << 2;
										// that equal to (cout << 1) << 2
	 
	 /*******************************************************************************************
	*  Function name: RandMatrix
	*  The input:  int - #row, int - #columns, int - min value, int - max value
	*  The output: MyMatrix object
	*  The function operation: create a random matrix in the required size and range of values. mainly for debugging proposes
	******************************************************************************************/
	 static MyMatrix RandMatrix(int m, int n, int min = 0, int max = 20);
};