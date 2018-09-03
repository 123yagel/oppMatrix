
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
	*  The function operation: seting matrices (for calucations) by the user
	*************************************************************************/
	void editData();

public:

	/*************************************************************************
	*  Function name: run
	*  The input: none
	*  The output: none
	*  The function operation: management of the interface of the program
	*************************************************************************/
	void run();

	/********************************************************************************************
	*  Function name: usrChooseMatNu
	*  The input: none
	*  The output: int, which is the number of the matrix.
	*  The function operation: return the  the number of the matrix which the user want to insert.
	********************************************************************************************/
	int usrChooseMatNum();

	/************************************************************************************
	*  Function name: printMenu
	*  The input: none
	*  The output: int, which is the the user's choice.
	*  The function operation: printing the user menu and getting the user's choice
	************************************************************************************/
	int printMenu();

	/************************************************************************************
	*  Function name: setMatrix
	*  The input: none
	*  The output: MyMatrix object
	*  The function operation: get a matrix from the user.
	************************************************************************************/
	MyMatrix setMatrix();
	
	
};

