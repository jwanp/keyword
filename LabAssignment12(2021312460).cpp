#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StuInfo { // Declare the structure
	char Name[10];
	int IDNo;
	int Exam[2];
	StuInfo *Next; // Declare the structure pointer
};

StuInfo *pStart = NULL; // Declare the pointer that pointing the first node
StuInfo *pEnd = NULL; // Declare the pointer that pointing the second node

void addStuInfo(char name[], int id, int exam[]) // Function Definition (addStuInfo: create new structure and link it)
{
	StuInfo *Current; // Delcare the structure pointer
	Current = (StuInfo *) malloc(sizeof(struct StuInfo)); // Put the data in structure
	strcpy(Current->Name, name);
	Current->IDNo = id;
	Current->Exam[0] = exam[0];
	Current->Exam[1] = exam[1];
	Current->Next = NULL; // Pointer pointing at nothing
	
	if(pStart == NULL) // If there is no first node
	{
		pStart = pEnd = Current; // current node become Firts and last node
	}
	else
	{
		pEnd->Next = Current; // If not, last node pointing at the current node
		pEnd = Current; // Current node become the last node
	}
}

void PrintAllName(StuInfo *Current) // Function Definition (PrintAllName: Print all student's name in linked structure)
{
	Current = pStart; // Start with the first node
	while (Current != NULL) { // Repeat to o the final node
		printf("Name: %s \n", Current->Name); // Print out the name of the students
		Current = Current->Next; // Move the pointer to the next node
	}
}

float AverageScore(StuInfo *Current) // Function Definition
{
	float sum; // Declare the variable (sum: sum of the exam scores)
	Current= pStart; // Start with the first node
	while (Current != NULL) // Repeat to the final node
	{
		sum = sum + Current->Exam[0] + Current->Exam[1]; // Calculate the sum of the structure
		Current = Current->Next; // Move the pointer to the next node
	}
	
	float average; // Declare the variabe (average: average of the exam scores)
	average = sum / 160; // Calculate the average
	return average; // Return the average
}

StuInfo * BestStudent(StuInfo *Current) // Function Definition (BestStudent: Check the best score and retun the best student's name and scores)
{
	Current = pStart; // Start with the first node
	StuInfo * Next; // Declare the new structure pointer
	Next = Current->Next; // Move the pointer to pointing next node of current node
	StuInfo * Bestscore = Current; // Best student is current node 
	while (Current != NULL) // Repeate to the last node
	{
		if(Current->Exam[0] + Current->Exam[1] < Next->Exam[0] + Next->Exam[1]) // If the next node's score is higher than that of current node
		{
			Bestscore = Next; // Best student is next node
		}
		Current = Current->Next; // Move the pointer to the next node
	}
	return Bestscore; // Return the best student 
}

int main()
{
	FILE *fPtr; // File pointer
	fPtr = fopen("lab12_datafile.txt", "r"); // Open the file in reading mode
	
	int i = 1;
	for(i; i <= 80; i++) // Get the file data 
	{
		char name[10];
		int id;
		int exam[2];
		fscanf(fPtr, "%s", &name);
		fscanf(fPtr, "%d", &id);
		fscanf(fPtr, "%d", &exam[0]);
		fscanf(fPtr, "%d", &exam[1]);
		addStuInfo(name, id, exam); // Make the linked list
	}
	PrintAllName(pStart); // Print all name of the students
	float average = AverageScore(pStart);
	printf("Average: %f \n", average); // Print out the average score of the students
	StuInfo *Bestscore = BestStudent(pStart);
	printf("Best Student is %s, Exam1: %d, Exam2: %d", Bestscore->Name, Bestscore->Exam[0], Bestscore->Exam[1]); // Print out the best student's name and scores
}
