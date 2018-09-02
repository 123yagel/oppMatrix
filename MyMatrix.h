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
	
	/*************************************************************************
	*  Function name: MyMatrix (ctor)
	*  The input: size of the matrix, default value, no input = def ctor
	*  The output: new MyMatrix object
	*************************************************************************/
	MyMatrix(unsigned int m = 2 , unsigned int n = 2 , double def_value =0);
	//MyMatrix();

	// MyMatrix(int m, int n, bool rand);
	// TODO: maybe code it?

	/*************************************************************************
	*  Function name: MyMatrix (copy ctor)
	*************************************************************************/
	MyMatrix(const MyMatrix& myMat);

	
	/*************************************************************************
	*  dtor
	*  destructor for deleting matrix and cleaning
								the memory afterwards.
	*************************************************************************/
	~MyMatrix();

// getters:

	// set size only in the constructor.
	// get and set values of the matrix, only using Mat[i][j]

	/*************************************************************************
	*  Function name: getM
	*  The input: none
	*  The output: int
	*  The function operation: returns the number of rowes in the matrix
	*************************************************************************/
	unsigned int getM() const;

	/*************************************************************************
	*  Function name: getN
	*  The input: none
	*  The output: int
	*  The function operation: returns the number of colomnes in the matrix
	*************************************************************************/
	unsigned int getN() const;

	// operator[][] can throw "out of bounds".
	//double& operator[](const int m, const int n);

	/*************************************************************************
	*  Function name: operator[][]
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


	// TODO: doc..
	Proxy operator[](const int rowIndex) const;
	
// TODO: add description: what can be thrown (as string("error")) for all operators
	// matrix addition, substruction and multiplication can throw "dimensions not agree".
	
	/*************************************************************************
	*  Function name: operator+
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation: returns the addition of 2 matrices
	*************************************************************************/
	MyMatrix operator+(MyMatrix& mat2);
	
	/*************************************************************************
	*  Function name: operator-
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation: returns the substruction of 2 matrices
	*************************************************************************/
	MyMatrix operator-(MyMatrix& mat2);
	
	/*************************************************************************
	*  Function name: operator*
	*  The input: MyMatrix object
	*  The output: MyMatrix object
	*  The function operation: returns the multiplication of 2 matrices
	*************************************************************************/
	MyMatrix operator-(); // unary minus: new_mat = - old_mat
						  // equal to: (-1) * mat
	// TODO: add doc of all operators, including exceptions
	MyMatrix operator*(MyMatrix& mat2);

	MyMatrix operator*(double float_const);

	friend inline MyMatrix operator*(double float_const, MyMatrix& mat) { return mat * float_const; }
	// 7 * mat <==> mat * 7
	// inline, so implementaion here

	MyMatrix& operator=(MyMatrix& mat2);  // the return value is needed in a = (b = c);
	
	// operator to check equality, like if (Mat1 == Mat2) cout << "equal".
	// return 
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