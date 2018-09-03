
#include "UserMenu.h"
#include <iostream>
#include <string>

using namespace std;

void UserMenu::editData()
{
	int mat2edit = usrChooseMatNum();
	unsigned int m, n;
	cout << "sizes? m:";
	cin >> m;
	cout << "n:";
	cin >> n;
	if (m == 0 || n == 0)
		throw string("dimentions mustn't be zero");
	cout << "rand? (y/n)";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		m_mats[mat2edit] = MyMatrix::RandMatrix(m, n);
		cout << m_mats[mat2edit] << endl;
		return;
	}

	MyMatrix newMatrix(m, n, 0);
	cout << "please write the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		cout << "row " << (i + 1) << ": ";
		for (int j = 0; j < n; j++)
			cin >> newMatrix[i][j];
	}
	cout << "got it!" << endl;
	m_mats[mat2edit] = newMatrix;
}

void UserMenu::run()
{
	while (true) {
		try {
			switch (printMenu())
			{
			case 1:// edit data
				editData();
				break;
			case 2:// add matrix
				cout << "1: mat[0] = mat[0] + mat[1]" << endl;
				cout << "2: mat[0] = mat[0] + mat[1] + mat[2]" << endl;
				cout << ">>";
				int input;
				cin >> input;
				if (input == 1)
				{
					m_mats[0] = m_mats[0] + m_mats[1];
				}
				else
				{
					m_mats[0] = m_mats[0] + m_mats[1] + m_mats[2];
				}
				cout << "mat[0]:" << endl << m_mats[0];
				break;
			case 3:// subtruct matrix
				cout << "1: mat[0] = mat[0] - mat[1]" << endl;
				cout << "2: mat[0] = mat[0] - mat[1] - mat[2]" << endl;
				cout << ">>";
				// int input; defined before
				cin >> input;
				if (input == 1)
				{
					m_mats[0] = m_mats[0] - m_mats[1];
				}
				else
				{
					m_mats[0] = m_mats[0] - m_mats[1] - m_mats[2];
				}
				cout << "mat[0]:" << endl << m_mats[0];
				break;
			case 4:// multiple matrix
				cout << "1: mat[0] = mat[0] * mat[1]" << endl;
				cout << "2: mat[0] = mat[0] * mat[1] * mat[2]" << endl;
				cout << ">>";
				// int input; defined before
				cin >> input;
				if (input == 1)
				{
					m_mats[0] = m_mats[0] * m_mats[1];
				}
				else
				{
					m_mats[0] = m_mats[0] * m_mats[1] * m_mats[2];
				}
				cout << "mat[0]:" << endl << m_mats[0];
				break;
			case 5:// multiple matrix by scalar
				double scalar;
				cout << "enter scalar: >>";
				cin >> scalar;
				m_mats[0] = m_mats[0] * scalar;
				cout << "now mat[0] = mat[0] * " << scalar << "." << endl;
				cout << "mat[0]:" << endl << m_mats[0];
				break;
			case 6:// compare two matrices
				cout << "mat[0] is ";
				if (m_mats[0] != m_mats[1]) cout << "not ";
				cout << "equal to mat[1]" << endl;
				break;
			case 7:// print matrix
				cout << m_mats[usrChooseMatNum()];
				break;
			case 8:// find value in a matrix
				unsigned int mat, i, j;

				mat = usrChooseMatNum();

				cout << "enter i: ";
				cin >> i;
				if (i >= m_mats[mat].getM() || i < 0)
					throw string("i out of range. i = ") + std::to_string(i);

				cout << "enter j: ";
				cin >> j;
				if (j >= m_mats[mat].getN() || j < 0)
					throw string("j out of range. j = ") + std::to_string(j);

				cout << "mat[" << mat << "][" << i << "][" << j << "] = " << m_mats[mat][i][j] << endl;

				break;
			case 9:// exit
				return;
			default:
				// another chance
				break;
			}
		}
		catch (string e) {
			cerr << "error :(" << endl; // cerr is like cout, but for errors.
			cerr << "details: " << e << endl; // cout good enough but cerr is better.
			cerr << "try again." << endl;
		}
		catch (...) {
			cerr << "unknown error :(" << endl;
			cerr << " try again." << endl;
		}
	}
}

int UserMenu::usrChooseMatNum()
{
	int mat;
	cout << "choose matrix (0-" << (NUM_OF_MATS-1) << ")";
	cin >> mat;
	if (mat < 0 || mat >= NUM_OF_MATS)
		throw string("there is no matrix labeled ") + std::to_string(mat);
	return mat;
}

int UserMenu::printMenu()
{
	cout << endl;
	cout << "Choose action:" << endl;
	cout << "    1: edit data" << endl;
	cout << "    2: add matrices" << endl;
	cout << "    3: subtract matrices" << endl;
	cout << "    4: multiple matrices" << endl;
	cout << "    5: multiple matrix by scalar" << endl;
	cout << "    6: compare two matrices" << endl;
	cout << "    7: print matrix" << endl;
	cout << "    8: find value in a matrix" << endl;
	cout << "    9: exit" << endl;
	cout << ">>";
	int number;
	cin >> number;
	return number;
}

MyMatrix UserMenu::setMatrix()
{
	unsigned int rows, columns;
	double element;
	cout << "which size of matrix do you want?" << endl << "rows: ";
	cin >> rows;
	cout << "columns: ";
	cin >> columns;
	if (rows < 1 || columns < 1)
		throw string("invalid size, negative or zero");
	MyMatrix newMatrix(rows, columns, 0);
	cout << "please write the matrix:" << endl;
	for (int i = 0; i < rows; i++) {
		cout << "row " << (i + 1) << ": ";
		for (int j = 0; j < columns; j++)
		{
			//cout << "Enter " << i << "," << j << " element="; 
			// we don't really need this^

			cin >> newMatrix[i][j];
		}
	}
	cout << "got it!" << endl;
	return newMatrix;
}