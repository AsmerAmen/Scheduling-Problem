#ifndef SCHEDULAR_H
#define SCHEDULAR_H


#include <iostream>
#include <stdio.h>
#include <ctime> 
#include <cstdlib> 
#include <list>

using namespace std;

#define NUM_STUDENTS 100	//number of students.
#define NUM_SUBJECTS 30		//number of subjects.
#define NUM 4				//number of subjects a student can enroll in.

class Schedular
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
		Schedular(int V);
		~Schedular();
		
		void generateRegister(void);
		
		void obtainConflict(void);

		void findNonConflictMatrix(void);

		void printStudentReg(void);

		void printConflictMatrix(void);

		void printNonConflictMatrix(void);
		
		void makeGraph(void);
		
		// Prints greedy coloring of the vertices
		void greedyColoring();
};
#endif