#pragma once
class MyMatrix
{

private:

	int m_m;
	int m_n;
	double *m_mat = nullptr;

public:
	
	/*************************************************************************
	*  Function name: MyMatrix
	*  The input: ---------
	*  The output: --------
	*  The function operation: ----------
	*************************************************************************/
	MyMatrix(int m = 2, int n = 2, double def_value = 0);

	/*************************************************************************
	*  Function name: MyMatrix
	*  The input: ---------
	*  The output: --------
	*  The function operation: ----------
	*************************************************************************/
	MyMatrix(const MyMatrix& myMat);

	/*************************************************************************
	*  Function name: MyMatrix
	*  The input: none
	*  The output: none
	*  The function operation: default constructor that creates 2*2 zeroes matrix
	*************************************************************************/
	MyMatrix();
	
	/*************************************************************************
	*  Function name: ~MyMatrix
	*  The input: none
	*  The output: none
	*  The function operation: destructor for deleting matrix and cleaning
								the memory afterwards.
	*************************************************************************/
	~MyMatrix();

	// get&set:
	// set size only in the constructor.
	// get and set values, only using Mat[i][j]

	/*************************************************************************
	*  Function name: getM
	*  The input: none
	*  The output: int
	*  The function operation: returns the number of rowes in the matrix
	*************************************************************************/
	int getM();


	/*************************************************************************
	*  Function name: getN
	*  The input: none
	*  The output: int
	*  The function operation: returns the number of colomnes in the matrix
	*************************************************************************/
	int getN();

	// operator[][] can throw "out of bounds".
	// double& operator[](const int m, const int n);
	// that's not so simple to implememt: needed proxy object:..

	// so this isn't the real line in the .h file.
	// https://stackoverflow.com/questions/6969881/operator-overload

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
	MyMatrix operator*(MyMatrix& mat2);



	MyMatrix operator-(); // unary minus: new_mat = - old_mat
						  // equal to: (-1) * mat
	MyMatrix operator*(double float_const);

	// the opposite operator* with scalar, like 3*Mat, is non-member operator, out of the class.
	// TODO: maybe it can be inside somehow?
	// https://stackoverflow.com/questions/14482380/multiplying-an-object-with-a-constant-from-left-side


	MyMatrix& operator=(MyMatrix& mat2);  // the return value is needed in a = (b = c);
	
	bool operator==(MyMatrix& mat2);
	
	std::ostream& friend operator<<(std::ostream& fout, MyMatrix& mat2print);  // print to output stream.
																			   // the return is for case like: cout << 1 << 2;
																			   // that equal to (cout << 1) << 2;

};


// 7 * mat <==> mat * 7
// inline, so implementaion here
MyMatrix inline operator*(double float_const, MyMatrix& mat) { return mat * float_const; }