// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyMatrix.h"
#include "UserMenu.h"
#include <iostream>

using namespace std;

int main()
{
	cout << endl << "welcome to the matrix math program" << endl;

	UserMenu menu;
	menu.run();

    return 0;
}

