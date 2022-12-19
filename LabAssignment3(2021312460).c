// Lab Assignment 3 2021312460 Park Chae RIn
#include <stdio.h>
int main()
{
	int choice; // Declare the variable that get the choice from user
	int money; // Declare the variasble that get the value of money from user
	float change; // Delcare the variable that calculate exchange;
	float rate_KU = 0.000905; // Declare the exchange rate variable (WON to USD)
	float rate_KE = 0.000807350908; // Declare the exchange rate variable (WON to EUro)
	float rate_KY = 0.091906143; // Declare the exchange rate variable (WON to YEN)
	float rate_KR = 0.00603703605; // Declare the exchange rate variable (WON to RMB)
	
	while (choice != 5) // Repeat unless choice is 5
	{
		printf("Please choose which currency you want to convert:\n"); // Print the options
		printf("1 - Korean Won to US Dollar (Exchange Rate: 0.000905)\n");
		printf("2 - Korean Won to Euro (Exchange Rate: 0.000807350908)\n");
		printf("3 - Korean Won to Japanese Yen (Exchange Rate: 0.0919061643)\n");
		printf("4 - Korean Won to Chinese RMB (Exchange Rate: 0.00603703605)\n");
		printf("5 - Quit\n");
		printf("Enter your option:"); // Get the input value from user
		scanf("%d", &choice);
		
		switch(choice) // Calculate each currency
		{
			case 1:
				printf("Enter the amount in Korean Won:"); // Get the value of money from user
				scanf("%d", &money);
				change = (float) money * rate_KU; // Calculate the exchnage
				printf(" %d won equals to %f USD.\n", money, change); // Print the value of exchange
				break;
				
			case 2:
				printf("Enter the amount in Korean Won:"); // Get the value of money from user
				scanf("%d", &money);
				change = (float) money * rate_KE; // Calculate the exchnage
				printf(" %d won equals to %f Euro.\n", money, change); // Print the value of exchange
				break;
			
			case 3:
				printf("Enter the amount in Korean Won:"); // Get the value of money from user
				scanf("%d", &money);
				change = (float) money * rate_KY; // Calculate the exchnage
				printf(" %d won equals to %f Yen.\n", money, change); // Print the value of exchange
				break; 
				
			case 4:
				printf("Enter the amount in Korean Won:"); // Get the value of money from user
				scanf("%d", &money);
				change = (float) money * rate_KR; // Calculate the exchnage
				printf(" %d won equals to %f RMB.\n", money, change); // Print the value of exchange
				break;
				
			case 5:
				break; // Finish the repetition
			
			case 6:
				printf("You entered an invalid input.\n");
				break; // Get the option again 
		}
		
	}
}
