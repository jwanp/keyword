#include <stdio.h>

float CurrencyConversion(float AmountInWon, float rate); // Function Prototype 

int main()
{
	float AmountInWon; // Declare the variable that carries input value
	int choice; // Declare the variable that carries option input value
	
	while(choice != 5) // Repeat unless choice is 5
	{
		printf("Please choose which currency you want to convert:\n"); // Print the option
		printf("1 - Korean Won to US Dollar (Exchange Rate: 0.000905)\n");
		printf("2 - Korean Won to Euro (Exchange Rate: 0.000807350908)\n");
		printf("3 - Korean Won to Japanese Yen (Exchange Rate: 0.0919061643)\n");
		printf("4 - Korean Won to Chinese RMB (Exchange Rate: 0.00603703605)\n");
		printf("5 - Quit\n");
		printf("Enter your option:"); // Get the input value 
		scanf("%d", &choice);
				
		switch(choice) 
		{
			case 1: // When the choice is 1
				printf("Enter the amount in Korean Won:");
				scanf("%f", &AmountInWon); // Get the money value from user
				float rate_KU = 0.000905; // Declare the variable that carries currency rate (Won to USD)
				float change1 = CurrencyConversion((float) AmountInWon, (float) rate_KU); // Call the function
				printf("%f won equals to %f USD\n", AmountInWon, change1); // Print out the value
				break;
			
			case 2: // When the choice is 2
				printf("Enter the amount in Korean Won:"); 
				scanf("%f", &AmountInWon); // Get the money value from user
				float rate_KE = 0.000807350908; // Declare the variable that carries currency rate (Won to Euro)
				float change2 = CurrencyConversion((float) AmountInWon, (float) rate_KE); // Call the function
				printf("%f won equals to %f Euro\n", AmountInWon, change2); // Print out the value
				break;
				
			case 3: // When the choice is 3
				printf("Enter the amount in Korean Won:"); 
				scanf("%f", &AmountInWon); // Get the money value from user
				float rate_KY = 0.0919061643; // Declare the variable that carries currency rate (Won to Yen)
				float change3 = CurrencyConversion((float) AmountInWon, (float) rate_KY); // Call the function
				printf("%f won equals to %f Yen\n", AmountInWon, change3);  // Print out the value
				break;
			
			case 4: // When the choice is 4
				printf("Enter the amount in Korean Won:");
				scanf("%f", &AmountInWon); // Get the money value from user
				float rate_KR = 0.00603703605; // Declare the variable that carries currency rate (Won to RMB
				float change4 = CurrencyConversion((float) AmountInWon, (float) rate_KR); // Call the function
				printf("%f won equals to %f RMB\n", AmountInWon, change4); // Print out the value
				break;
				
			case 5: // When the choice is 5
				break;
				
			case 6: // When the choice is 6
				printf("You enter invalid input.");
				continue; // Go back to options	
		}
	}
}

float CurrencyConversion(float AmountInWon, float rate) // Define the function that calculate exchange
{
	float result = AmountInWon * rate; // calculate exchange
	return result; // return result
}
