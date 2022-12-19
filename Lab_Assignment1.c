// lab assingment made by ChaeRin Park 2021312460
#include <stdio.h>
int main()
{
	int John_Score; //Declare the variables 
	int Mary_Score;
	int Peter_Score;
	int Jane_Score;
	int Student_Number = 4; //Declare Student numbers variable to calculate average
	
	printf("Enter John's Score:"); //print the sentence to get input
	scanf("%d", &John_Score);
	printf("Enter Mary's Score:");
	scanf("%d", &Mary_Score);
	printf("Enter Peter's Score:");
	scanf("%d", &Peter_Score);
	printf("Enter Jane's Score: ");
	scanf("%d", &Jane_Score);
	
	int Sum;
	Sum = John_Score + Mary_Score + Peter_Score + Jane_Score; // declare variable of sum and get the value
	int Average;
	Average = Sum / Student_Number; // declare variable of average and get the value
	
	printf("The Average is: %d", Average); //print the value of average
}
