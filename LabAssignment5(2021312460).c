// Lab Assignment5 2021312460 Park Chae Rin
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL)); // Generate random seed
	int dice_1 = rand() % 6 + 1; // Declare the variable that carries the value of the first dice
	int dice_2 = rand() % 6 + 1; // Declare the variable that carries the value of the second dice
	int dice_3 = rand() % 6 + 1; // Declare the variable that carries the value of the third dice
	int sum = dice_1 + dice_2 + dice_3; // Declare the sum of three dices
	printf("Result: %d %d %d \n", dice_1, dice_2, dice_3); // Print out the values of three dices
	
	if(dice_1 == dice_2 && dice_2 == dice_3 && dice_1 == dice_3) // In case of values are the same
	{
		printf("TRIPLE!"); // Print out "TRIPLE!"
	}
	else if(3 < sum && sum < 10) // In case of sum of values are 3 to 10
	{
		printf("SMALL!"); // Print out "SMALL!"
	}
	else
	{
		printf("BIG!"); // Print out "BIG!"
	}
}
