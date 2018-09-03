
#pragma once
#include "MyMatrix.h"

#define NUM_OF_MATS 3

class MyMatrix;

class UserMenu
{
private:
	MyMatrix m_mats[NUM_OF_MATS];

	/*************************************************************************
	*  Function name: editData
	*  The input: none
	*  The output: none
	*  The function operation: reating matrices (for calucate) by the user
	*************************************************************************/
	void editData();

public:
	/*************************************************************************
	*  Function name: run
	*  The input: none
	*  The output: none
	*  The function operation: management the  interface of the program
	*************************************************************************/
	void run();

	/********************************************************************************************
	*  Function name: srChooseMatNu
	*  The input: none
	*  The output: int, which is number of matrix.
	*  The function operation: return the  the number of the matrix which the user want to insert.
	********************************************************************************************/
	int usrChooseMatNum();

	/************************************************************************************
	*  Function name: srChooseMatNu
	*  The input: none
	*  The output: int, which is the the user's choice.
	*  The function operation: printing the user menuand getting the user's choice
	************************************************************************************/
	int printMenu();


	MyMatrix setMatrix();
	void setSomeMatrix(int num, MyMatrix[]);
	MyMatrix UserMenu::calucateMatrix(int, MyMatrix[], char);
};

