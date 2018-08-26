#pragma once
 
#define MAX_SIZE 10

class MyMatrix
{

private:

	int m_m;
	int m_n;
	double** m_matrix = nullptr;
// TODO: make it one alocation, one big array in size m*n, update code all over the files, dtor
public:
	
	/*************************************************************************
	*  Function name: MyMatrix (ctor)
	*  The input: size of the matrix, default value, no input = def ctor
	*  The output: new MyMatrix object
	*************************************************************************/
	MyMatrix(int m = 2, int n = 2, double def_value = 0);

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
	int getM() const;

	/*************************************************************************
	*  Function name: getN
	*  The input: none
	*  The output: int
	*  The function operation: returns the number of colomnes in the matrix
	*************************************************************************/
	int getN() const;

	// operator[][] can throw "out of bounds".
	//double& operator[](const int m, const int n);

	/*************************************************************************
	*  Function name: operator[][]
	*  The input: MyMatrix object
	*  The output: double 
	*  The function operation: returns the addition of 2 matrices
	*************************************************************************/

// TODO: move the code to .cpp, add decomontation
	class Proxy {
	public:
		Proxy(double* array, int size) : _array(array), _size(size) { }

		double operator[](int index) {
			if (index >= _size)
				throw string("out of bounds");
			return _array[index];
		}
	private:
		double* _array;
		int _size;
	};

	Proxy operator[](const int rowIndex) const;
	// that's not so simple to implememt: needed proxy object:..

	// so this isn't the real line in the .h file.
	// https://stackoverflow.com/questions/6969881/operator-overload


// TODO: add description: what can be thrown (as string("error"))
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
	
	MyMatrix operator*(MyMatrix& mat2);

	// TODO: replace with [][] in the proxy
	void setOneElement(const double element, int i, int j);

	MyMatrix operator*(double float_const);

	// the opposite operator* with scalar, like 3*Mat, is non-member operator, out of the class.
	// TODO: maybe it can be inside somehow?
	// https://stackoverflow.com/questions/14482380/multiplying-an-object-with-a-constant-from-left-side


	MyMatrix& operator=(MyMatrix& mat2);  // the return value is needed in a = (b = c);
	
	// operator to check equality, like if (Mat1 == Mat2) cout << "equal".
	// return 
	bool operator==(MyMatrix& mat2);
	
	// TODO: code it :)
	friend std::ostream& operator<<(std::ostream& fout, MyMatrix& mat2print);  // print to output stream.
										// the return is for case like: cout << 1 << 2;
										// that equal to (cout << 1) << 2
};


// 7 * mat <==> mat * 7
// inline, so implementaion here
MyMatrix inline operator*(double float_const, MyMatrix& mat) { return mat * float_const; }