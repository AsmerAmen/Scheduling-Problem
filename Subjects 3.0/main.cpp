#include <iostream>
#include <stdio.h>
#include <ctime> 
#include <cstdlib> 
#include <list>
#include "schedular.h"

using namespace std;

int main(void)
{
	Schedular s1(NUM_SUBJECTS);
	
	s1.generateRegister();
//	printStudentReg();
/************************************/
	s1.obtainConflict();
/************************************/
	s1.makeGraph();
	
    s1.greedyColoring();
//	printConflictMatrix();
/************************************/
	s1.findNonConflictMatrix();
//	printNonConflictMatrix();
	
	system("PAUSE");
	return 0;
}