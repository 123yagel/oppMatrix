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
		case 1:
			
			setMatrix();
			break;

		case 2:
			break;

		case 3:

			/*
			int num, rows, columns, newRows, newColumns;
			cout << "How many matrices do you want to multiply?" << endl;
			cin >> num;
			cout << "What is the size of the matrices you want to multiply?" << endl;
			for (int i = 0; i < num; i++)
			{

				cout << "matrix" << i + 1 << " - rows: ";
				cin >> rows;
				cout << " columns: ";
				cin >> columns;
				if (1)
					throw string("error math size of matrices");
				newRows = rows;
			}
			*/
			break;

		case 4:
			break;

		case 5:
			break;

		case 6: cout << "deleteing cars" << endl;
			break;

		case 7:
			break;

		case 8:
			cout << "exiting..." << endl;
			return;
			// break;

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
	cout << "    1: addition two or more matrices" << endl;
	cout << "    2: subtruction two or more matrices" << endl;
	cout << "    3: multiplication two or more matrices" << endl;
	cout << "    4: CarsFromToPrices" << endl;
	cout << "    5: printCar" << endl;
	cout << "    6: delete all Cars" << endl;
	cout << "    7: printAll" << endl;
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
			newMatrix.setOneElement(element, i, j);
		}
	cout << endl;
}