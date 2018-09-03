#pragma once

#include "MyMatrix.h"

#define NUM_OF_MATS 3

class UserMenu
{
private:
	MyMatrix m_mats[NUM_OF_MATS];

	/*************************************************************************
	*  Function name: editData
	*  The input: none
	*  The output: none
	*  The function operation: let the user edit the saved mats
	*************************************************************************/
	void editData();
/********************************************************************************************
	*  Function name: usrChooseMatNum
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

	// get matrix from the user
	MyMatrix setMatrix();
	
	
public:
	/*************************************************************************
	*  Function name: run
	*  The input: none
	*  The output: none
	*  The function operation: management the  interface of the program
	*************************************************************************/
	void run();
};

