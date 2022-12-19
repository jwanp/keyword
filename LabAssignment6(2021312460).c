// Lab Assignment 6 2021312460 Park Chae Rin
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL)); // Initialize the random seed
	int Array[8][10]; // Declare the array
	
	int i = 0; // Declare the counter variable
	for(i; i <8; i++) // Repete the number of the row times
	{
		int j = 0; // Declare the counter variable
		for(j; j< 10; j++) // Repete the number of the column times
		{
			Array[i][j] = rand() % 91 + 10;} // Put the random integer to the array
	}
	
	int m = 0; // Declare the counter variable
	for(m; m <10; m++) // Repete the number of the colunm times
	{
		int n = 0; // Declare the counter variable
		for(n; n<8; n++) // Repete the number of the row times
		{
			printf("%d ", Array[n][m]); //Print out the value of the array
		}
		printf("\n");
	}
	
	int SmallestValue = 100; // Declare the variable that carries the smallest value
	int p = 0; // Declare the counter variable
	for(p; p<8; p++) // Repete the number of the row times
	{
		int q = 0; // Declare the counter variable
		for(q; q<10; q++) // Repete the number of the colunm times
		{
			if(Array[p][q] < SmallestValue) // If the value of the array is smaller than variable, put the value to the variable
			{
				SmallestValue = Array[p][q];
			}
			else
			{
				continue;
			}
		}
	}
	printf("\nThe smallest value is %d\n", SmallestValue); // Print out the smallest value of the array
	
	int LargestValue = 10; // Declare the variable that carries the smallest value
	int a = 0; // Declare the counter variable
	for(a; a<8; a++) // Repete the number of the row times
	{
		int b = 0; // Declare the counter variable
		for(b; b<10; b++) // Repete the number of the colunm times
		{
			if(Array[a][b] > LargestValue) // If the value of the array is larger than variable, put the value to the variable
			{
				LargestValue = Array[a][b];
			}
			else
			{
				continue;
			}
		}
	}
	printf("The largest value is %d\n", LargestValue); // Print out the largest value of the array
	
	float sum = 0; // Delcare the variable that carries the sum of values 
	int c = 0; // Declare the counter variable
	for(c; c<8; c++) // Repete the number of the row times
	{
		int d = 0; // Declare the counter variable
		for(d; d<10; d++) // Repete the number of the column times 
		{
			sum = sum+ Array[c][d]; // Calculate the sum of the values
		}
	}
	float average = sum / 80; // Calculate the average
	printf("The average value is %f\n", average); // Print out the average of the value of the array
}


