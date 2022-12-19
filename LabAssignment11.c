// Lab Assignment 11 2021312460 Park Chae Rin
#include <stdio.h>
int main()
{
	int choice; // Declare the variable (choice: get choice from the user)
	FILE *fPtr1; // Declare the file pointer 1
	FILE *fPtr2; // Declare the file pointer 2
	int x[20]; // Declare the array(get the file value)
	fPtr1 = fopen("score.dat", "rb"); // Open the file in binary reading mode
	fPtr2 = fopen("score.dat", "rb+"); // Open the file in binary reading and writing mode
	
	while (choice != 3)
	{
		printf("1. Read and display all data from 'score.dat''. \n"); // Print out the choices
		printf("2. Multiply all the numbers in 'score.dat'' by 2. \n");
		printf("3. Quit. \n");
		printf("Enter your option: "); // Get choice from the user
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: // Choice 1
				{
					int i = 0;
					for(i; i< 20; i++)
					{
						fread(&x[i], sizeof(int), 1, fPtr1); // Read the values from the file
						printf("%d ", x[i]); // Print out the values
					}
					printf("\n");
					continue;
				}
			
			case 2:
				{
					int i = 0;
					for(i; i < 20; i++)
					{
						fread(&x[i],sizeof(int), i, fPtr1); // Read the values from the file
						x[i] = 2 * x[i]; // multiply values by 2
						fwrite(&x[i], sizeof(int), 1, fPtr2); // Write the values in the file
						}					
					continue;	
				}
				
			
			case 3:
				break; // Finish the program
				
				
		}
		
	}
	fclose(fPtr1);
	fclose(fPtr2);
}
