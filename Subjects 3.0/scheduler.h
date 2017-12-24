#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <stdio.h>
#include <ctime> 
#include <cstdlib> 
#include <list>

using namespace std;

#define NUM_STUDENTS 100	//number of students.
#define NUM_SUBJECTS 30		//number of subjects.
#define NUM 4				//number of subjects a student can enroll in.

class Scheduler
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
	int stdReg[NUM_STUDENTS][NUM_SUBJECTS];			//	Student/subjects matrix
	int conflictMatrix[NUM_SUBJECTS][NUM_SUBJECTS];	//	subject/subject matrix
	int nonConflictMatrix[NUM_SUBJECTS][NUM_SUBJECTS];
	int check[NUM_SUBJECTS];
	// function to add an edge to graph
	void addEdge(int v, int w);
	
	public:
		// Constructor and destructor
		Scheduler(int V);
		~Scheduler();
		
		//The function fill the student/subject matrix randomly
		void generateRegister(void);
		
		//The function fill the subject/subject conflict matrix
		void obtainConflict(void);

		//The function fill the subject/subject non-conflict matrix
		void findNonConflictMatrix(void);

		//	prints out the Student registry matrix
		void printStudentReg(void);

		//	prints out the subjects conflict matrix
		void printConflictMatrix(void);

		//	prints out the subjects non-conflict matrix
		void printNonConflictMatrix(void);
		// Puts the conflict matrix in the graph form
		void makeGraph(void);
		
		// Prints greedy coloring of the vertices
		void greedyColoring();
};
#endif