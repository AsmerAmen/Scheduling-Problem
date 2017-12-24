#include <iostream>
#include <stdio.h>
#include <ctime> 
#include <cstdlib> 
#include <list>
#include "scheduler.h"

using namespace std;

    // Constructor and destructor
Scheduler::Scheduler(int V){ 
	this->V = V; 
	adj = new list<int>[V]; 
}
	
Scheduler::~Scheduler(){ 
	delete [] adj; 
}
 
/*
 * The function fill the student/subject matrix
 *					(Student Registery)
 * it chooses 5 subjects for each student randomly
 * @param: void
 * @return: void
 */
void Scheduler::generateRegister(void){
	srand( time(0) );
	int counter;
	int x;
	
	// Loops on the students
	for(int i = 0; i<NUM_STUDENTS; i++){
		counter = 0;
		// Chooses 5 random subjects.
		while(counter<= NUM)
		{
			//generate random subject number
			x=rand()%NUM_SUBJECTS;
			//if the subject is already chosen, skip it.
			if(stdReg[i][x] == 1)	continue;
			//choose the subject.
			stdReg[i][x] = 1;
			counter++;
		}	//end while
	}
}	// end generateRegister

/*
 * The function fill the subject/subject matrix
 *					(Conflict matrix)
 * checks for the number of student enrolled in two subjects.
 * @param: void
 * @return: void
 */
void Scheduler::obtainConflict(void){
	for(int sub=0; sub<NUM_SUBJECTS; sub++)
		for(int st = 0; st<NUM_STUDENTS; st++)
			for(int subj=0; subj<NUM_SUBJECTS; subj++)
				//if the same student has those 2 subjects,
				//increment the conflict counter.
				if(stdReg[st][subj] == 1 && stdReg[st][sub]==1)
					conflictMatrix[subj][sub]++;		
			
}// end obtainConflict

/*
 * The function fill the subject/subject matrix
 *					(nonConflict matrix)
 * @param: void
 * @return: void
 */
void Scheduler::findNonConflictMatrix(void){
	for(int i=0; i<NUM_SUBJECTS; i++){
		for(int j=0; j<NUM_SUBJECTS; j++){
			if(conflictMatrix[i][j]==0 || i==j && check[j]!=1){
				nonConflictMatrix[i][j] =1;
				check[j]=1;
			}		
		}
	}
}




//	prints out the Student registry matrix
void Scheduler::printStudentReg(void){
	for(int i=0; i<NUM_STUDENTS; i++){
		for(int j=0; j<NUM_SUBJECTS; j++)
			cout<<stdReg[i][j];
		cout<<endl<<endl;
	}	
}
//	prints out the subjects conflict matrix
void Scheduler::printConflictMatrix(void){		
	for(int sub=0; sub<NUM_SUBJECTS; sub++){
		for(int subj=0; subj<NUM_SUBJECTS; subj++)
			cout<<conflictMatrix[sub][subj]<<"\t";
		cout<<endl<<endl;
	}
}

//	prints out the subjects non-conflict matrix
void Scheduler::printNonConflictMatrix(void){
	for(int i=0; i<NUM_SUBJECTS; i++){
		cout<<"Sub["<<i<<"]: ";
		for(int j=0; j<NUM_SUBJECTS; j++){
			if(nonConflictMatrix[i][j]==1)
				cout<<j<<"\t";
		}
		cout<<endl<<endl;
	}
}
 
/* Puts the conflict matrix in the graph form
 * @param: void
 * @return: void
 */
void Scheduler::makeGraph(void){
	for(int i=0; i<NUM_SUBJECTS; i++)
		for(int j = i; j<NUM_SUBJECTS; j++)
			if(conflictMatrix[i][j] != 0)
				addEdge(i, j);
} 

/* represents an undirected graph
 * @param: first point : int: v,
 * @param: second point : int: w
 * @return: void
 */
void Scheduler::addEdge(int v, int w)
{
	// Note: the graph is undirected
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
/*
 * Assigns colors (starting from 0) to all vertices,
 * and prints the assignment of colors.
 * @param: void
 * @return: void
 */
void Scheduler::greedyColoring()
{
    int result[V];
 
    // Assign the first color to first vertex
    result[0]  = 0;
 
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        result[u] = -1;  // no color is assigned to u
 
    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
 
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
 
 
        // Find the first available color
		int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;
 
        result[u] = cr; // Assign the found color
 
        // Reset the values back to false for the next iteration
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
 
    // print the Graph coloring
	cout<<"Graph Coloring:"<<endl;
     for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
              << result[u] << endl;
		 
	 // print the optimum Days
	cout<<"Days:"<<endl;
	for (int u = 0; u < V; u++){
		cout<<"\nDay["<<u<<"]:";
		for (int s = 0; s<V; s++)
			if(result[s] == u)
				cout<<"\t"<<s;
	}
	
}