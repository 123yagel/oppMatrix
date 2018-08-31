
#pragma once
#include "MyMatrix.h"


class MyMatrix;

class UserMenu
{
public:
	UserMenu();
	~UserMenu();
	void run();
	int printMenu();
	MyMatrix setMatrix();
	void setSomeMatrix(int num, MyMatrix[]);
};

