
#pragma once
#include "MyMatrix.h"

#define NUM_OF_MATS 3

class MyMatrix;

class UserMenu
{
private:
	MyMatrix m_mats[NUM_OF_MATS];
	void edit_data();
public:
	void run();
	int usrChooseMatNum();
	int printMenu();
	MyMatrix setMatrix();
	void setSomeMatrix(int num, MyMatrix[]);
	MyMatrix UserMenu::calucateMatrix(int, MyMatrix[], char);
};

