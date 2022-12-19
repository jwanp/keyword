// Lab Assignment 7 2021312460 Park Chae Rin
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayFunction(int array[], int num); // Function Prototype (arrayFunction: check that the values of the number inputted and the values of the array are the same)

int main() 
{
	srand(time(NULL)); // Initialize random seed
	int array[10]; // Declare the array
	
	int i = 0; // Declare the counter variable
	for(i; i <=9; i++)
	{
		array[i] = rand() % 99 + 1; // Allocate the random value to the array
		printf("array[%d]: %d ", i, array[i]); // Print out the array values
	}
	
	int num; // Declare the variable (num: inputted value)
	printf("\nEnter the number you want to search:"); // Get the input from the user
	scanf("%d", &num);
	
	int result = arrayFunction(array, num); // Call the function 
	
	switch(result)
	{
		case 1:
			printf("The number you entered is in the array"); // print out the inputted number is in the array
			break;
		
		case 2:
			printf("The number you entered is not in the array"); // print out the inputted number is not in the array
			break;
	}
}

int arrayFunction(int array[], int num) // Functon definition 
{
	int i = 0;
	for(i; i <= 9; i++)
	{
		if(array[i] == num) // if the values are the same
		{
			return 1;  // return value is 1
		}
	}
	return 2; // different, return value is 2
}
