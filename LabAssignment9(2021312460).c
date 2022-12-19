// Lab Assingment 9 2021312460 Park Chae Rin
#include <stdio.h>
int main()
{
	int numbers[10]; // Declare the array
	
	int i = 0; // Declare the counter variable
	for(i; i < 10; i++)
	{
		int n; // Declare the variable that takes user's input
		printf("Enter number %d:", i);
		scanf("%d", &n); // Get the input from the user
		numbers[i] = n; // Save the value in the array
	}
	
	printf("User Entered: "); 
	int m = 0; // Declare the counter variable
	for(m; m < 10; m++)
	{
		printf("%d ", numbers[m]); // Print out the array values
	}
	printf("\n");
	
	int *head = &numbers[0]; // Declare the head pointer
	int *tail = &numbers[9]; // Delcare the tail pointer
	
	int choice = 0; // Delcare the choice variable ( 1: palindrome, 2: no palindrome)
	
	int j = 0; // Declare the counter variable 
	for(j; j < 5; j++)
	{
		if(*head == *tail) // Check whether the array is palindrome
		{
			head = head + 1; 
			tail = tail - 1;
			
		}
		else
		{
			choice = 2; // It is not a palindrome
			break;
		}
		choice = 1; // It is a palindrome
	}
	
	
	switch(choice)
	{
		case 1:
			printf("YES!!! It is a palindrome");
			break;
		case 2:
			printf("NO!!! It is not a palindrome.");
	}
}
