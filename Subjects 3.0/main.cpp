/*	School exams scheduler problem
 *	Solved using Graph coloring algorithm 
 *	
 *	@author: Ahmed "Asmer" Amen
 *	24/8/2017
 */
#include <iostream>
#include <stdio.h>
#include <ctime> 
#include <cstdlib> 
#include <list>
#include "scheduler.h"

using namespace std;

int main(void)
{
	Scheduler s1(NUM_SUBJECTS);
	
	s1.generateRegister();
//	s1.printStudentReg();
/************************************/
	s1.obtainConflict();
/************************************/
	s1.makeGraph();
	
    s1.greedyColoring();
//	s.1printConflictMatrix();
/************************************/
	s1.findNonConflictMatrix();
//	s1.printNonConflictMatrix();
	
	system("PAUSE");
	return 0;
}