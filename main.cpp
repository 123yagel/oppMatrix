// main.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "MyMatrix.h"
#include "UserMenu.h"
#include <iostream>
#include <string>
#include <time.h> // for srand()

using namespace std;

int main()
{
	srand(time(NULL));
	UserMenu menu;
	menu.run();
	return 0;
}

