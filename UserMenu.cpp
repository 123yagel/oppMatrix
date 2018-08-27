//#include "stdafx.h"
#include "UserMenu.h"
#include "MyMatrix.h"
#include <iostream>
#include <string>
using namespace std;
// TODO: make a menu :)
UserMenu::UserMenu()
{
}


UserMenu::~UserMenu()
{
}

void UserMenu::run()
{
	while (true) {


		switch (printMenu())
		{
			
			//add
		case 1:
			
			setMatrix();
			break;
			//sub
		case 2:
			break;
			//multi
		case 3:

			
			break;
			scalar multi
		case 4:
			break;
			//compare
		case 5:
			break;
			//print
		case 6: cout << "deleteing cars" << endl;
			break;
			//find value
		case 7:
			break;
			
			//exit
		case 8:
			cout << "exiting..." << endl;
			return;
			break;

			
		default:
			// another chance
			break;
		}
	}
}

int UserMenu::printMenu()
{
	cout << endl;
	cout << "Choose action:" << endl;
	cout << "    1: add two matrices" << endl;
	cout << "    2: subtract two matrices" << endl;
	cout << "    3: multiply two matrices" << endl;
	cout << "    4: multiply by scalar" << endl;
	cout << "    5: compare two matrices" << endl;
	cout << "    6: print matrix" << endl;
	cout << "    7: find value in a matrix" << endl;
	cout << "    8: exit" << endl;
	cout << ">>";
	int number;
	cin >> number;
	return number;
}

void UserMenu::setMatrix()
{
	int rows, columns;
	double element;
	cout << "which size of matrix do you want?" << endl << "rows: ";
	cin >> rows ;
	cout << "columns: ";
	cin >> columns;
	if (rows < 1 || columns < 1)
		throw string("invalid size, negative or zero");
	if (rows > MAX_SIZE || columns > MAX_SIZE)
		throw string("invalid size, bigger than the maximum");
	MyMatrix newMatrix(rows, columns);
	cout << "please write the matrix:" << endl;
	for (int i=0 ; i< rows ;i++)
		for (int j = 0; j < columns; j++)
		{
			cout << "Enter " << i << "," << j << " element=";
			cin >> element ;
			newMatrix[i][j] = element;
		}
	cout << endl;
}