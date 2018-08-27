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
	
	int condition = 1;
	
	while (condition == 1)
	{
		try
		{
			UserMenu menu;
			menu.run();
			condition = -1;
		}
		catch (string error)
		{
			cout << error << endl;
		}

	}
    return 0;
}

