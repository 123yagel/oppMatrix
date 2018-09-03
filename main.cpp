

//#include "stdafx.h"
#include "MyMatrix.h"
#include "UserMenu.h"
#include <iostream>
#include <string>
#include <time.h> // for srand()

using namespace std;

int main()
{
	/*srand function is used for the usage 
	of random later in the program.*/ 
	srand(time(NULL));
	
	//declaring a menu object and run
	UserMenu menu;
	menu.run();
	
	return 0;
}

