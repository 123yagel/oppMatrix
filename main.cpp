// main.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "MyMatrix.h"
#include "UserMenu.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{    // we cannot print outside the usermenu
	//cout << endl << "welcome to the matrix math program" << endl;
	while (true)
	{
		try
		{
			UserMenu menu;
			menu.run();
		}
		catch (string error)
		{
			cout << error << endl;
		}

	}
    return 0;
}

