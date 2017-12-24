#include <iostream>
#include <stdio.h>
# include <ctime> 
# include <cstdlib> 

#define NUM_STUDENTS 100	//number of students.
#define NUM_SUBJECTS 30	//number of subjects.
#define NUM 4	//number of subjects a student can enroll in.

using namespace std;

int stdReg[NUM_STUDENTS][NUM_SUBJECTS];		//	Student/subjects matrix
int conflictMatrix[NUM_SUBJECTS][NUM_SUBJECTS];	//	subject/subject matrix
int nonConflictMatrix[NUM_SUBJECTS][NUM_SUBJECTS];
int check[NUM_SUBJECTS];
/*
 * The function fill the student/subject matrix
 *					(Student Registery)
 * it chooses 5 subjects for each student randomly
 * @param: void
 * @return: void
 */
void generateRegister(void){
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
void obtainConflict(void){
	for(int sub=0; sub<NUM_SUBJECTS; sub++)
		for(int st = 0; st<NUM_STUDENTS; st++)
			for(int subj=0; subj<NUM_SUBJECTS; subj++)
				//if the same student has those 2 subjects,
				//increment the conflict counter.
				if(stdReg[st][subj] == 1 && stdReg[st][sub]==1)
					conflictMatrix[subj][sub]++;		
			
}// end obtainConflict


void findNonConflictMatrix(void){
	for(int i=0; i<NUM_SUBJECTS; i++){
		for(int j=0; j<NUM_SUBJECTS; j++){
			if(conflictMatrix[i][j]==0 || i==j && check[j]!=1){
				nonConflictMatrix[i][j] =1;
				check[j]=1;
			}		
		}
	}
}





void printStudentReg(void){
	for(int i=0; i<NUM_STUDENTS; i++){
		for(int j=0; j<NUM_SUBJECTS; j++)
			cout<<stdReg[i][j];
		cout<<endl<<endl;
	}	
}

void printConflictMatrix(void){		
	for(int sub=0; sub<NUM_SUBJECTS; sub++){
		for(int subj=0; subj<NUM_SUBJECTS; subj++)
			cout<<conflictMatrix[sub][subj]<<"\t";
		cout<<endl<<endl;
	}
}

void printNonConflictMatrix(void){
	for(int i=0; i<NUM_SUBJECTS; i++){
		cout<<"Sub["<<i<<"]: ";
		for(int j=0; j<NUM_SUBJECTS; j++){
			if(nonConflictMatrix[i][j]==1)
				cout<<j<<"\t";
		}
		cout<<endl<<endl;
	}
}

int main(void)
{
	generateRegister();
//	printStudentReg();
/************************************/
	obtainConflict();
//	printConflictMatrix();
/************************************/
	findNonConflictMatrix();
	printNonConflictMatrix();
	
	system("PAUSE");
	return 0;
}