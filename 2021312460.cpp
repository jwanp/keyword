#include <stdio.h>
#include <string.h>

struct node {
	char country[80];
	char country_code[3];
	int totalCases;
	int totalDeaths;
	struct node * NextPtr;
};

// This function takes a pointer to a linked list as parameter, and calculate the length (i.e. number of node) in the linked list as return value.
int Length(node * chain) 
{
	int length; // Declare the variable (length: calculate the length of the list)
	while(chain->NextPtr != NULL) // Repeat until the structure pointer is null
	{
		length += 1; // calculate the length
		chain = chain->NextPtr; // Move to the next node
	}
	
	return length;
}

// This function takes a pointer to a linked list as parameter, and then print out all the data in the linked list. This function does not have any return value.
void PrintALL(node * chain) 
{
	while(chain->NextPtr != NULL) // Repeat until the structure pointer is null
	{
		printf("Country: %s ", chain->country); // Print out the information in the node
		printf("Country Code: %s", chain->country_code);
		printf("\nTotal Cases: %d", chain->totalCases);
		printf("\nTotal Deaths: %d\n", chain->totalDeaths);
		chain = chain->NextPtr; // Move to the next node
	}
}

// This function takes a pointer to a linked list and a character string as input, and then find if there ia any node that matches the country_code with the 
// character string. The function returns a pointer pointing to the node if a match is found, and returns 0 if no found.
node * Find(node * chain, char * input) 
{
	node * target = 0; // Declare the structure pointer (targer: return the target node)
	while(chain->NextPtr != NULL) // Repeat until the structure pointer is null
	{
		if(strcmp(chain->country_code, input) == 0) // If the input and structure's county code is equal
		{
			target = chain; // Target pointer pointg at the node
		}
		chain = chain->NextPtr; // Move to the next node
	}
	return target; // Return the target pointer	
}

int main(void)
{	node chain[500];			// The linked list!
	node * maxTotalCases=0;		// A pointer pointing at the node with max total infection cases
	node * maxTotalDeaths=0;	// A pointer pointing at the node with max total death cases
	node * head=&chain[0];		// A pointer pointing at the first node of the linked list
	
	FILE *fPtr; // Declare the file pointer
	fPtr = fopen("covid-19.csv", "r"); // open the file in reading mode
	
	int n;
	printf("how many days that you want to calculate?: "); // Get the number of the days from the user
	scanf("%d", &n);
	
	int i = 0;
	for(i; i < 500; i++)
	{
		if(feof(fPtr))
		{
			break; // If the file is end, break the repetition
		}
		else
		{
			char date[20]; // Declare the variable 
			char code[3];
			char name[80];
			int infection = 0;
			int death = 0;
			int sum_infection = 0;
			int sum_death = 0;
			
			int j = 0;
			for(j; j < n; j++)
			{
				fscanf(fPtr, "%s", &date); // Read from the file
				fscanf(fPtr, "%s", &code);
				fscanf(fPtr, "%s", &name);
				fscanf(fPtr, "%d", &infection);
				fscanf(fPtr, "%d", &death);
				sum_infection += infection; // Calculate the sum of the cases
				sum_death += death; // Calculate the sum of the deaths
			}
		
			
			strcpy(chain[i].country, name); // Put the values into the structure
			strcpy(chain[i].country_code, code);
			chain[i].totalCases = sum_infection;
			chain[i].totalDeaths = sum_death;
			chain[i].NextPtr = &chain[i+1];	// Link the nodes		
		}
	}
	
	maxTotalCases = head;
	maxTotalDeaths = head;
	while(head->NextPtr != NULL) // Repeat until the next pointer is null
	{
		if(maxTotalCases->totalCases < head->totalCases) // If the max pointer is smaller than the current pointer
		{
			maxTotalCases = head; // max pointer pointing at the current pointer
		}
		if(maxTotalDeaths->totalDeaths < head->totalDeaths) // If the max pointer is smaller than the current pointer
		{
			maxTotalDeaths = head; // max pointer pointing at the current pointer
		}
		head = head->NextPtr;
	}
	
	
	

	printf("There are %d countries in the data.\n",Length(chain));		// Display number of countries
	printf("Max Total Cases: %s %d\n",maxTotalCases->country,maxTotalCases->totalCases);		// Display country with maximum total infection cases
	printf("Max Total Deaths: %s %d\n",maxTotalDeaths->country,maxTotalDeaths->totalDeaths);	// Display country with maximum total death cases
		
	char Input[4];
	while(strcmp(Input,"q"))		// A loop asking for user input, and then display the corresponding data
	{	printf("===============================\n");
		printf("Enter the country code to display the total number of cases and total number of death of the country.\n");
		printf("Enter \"ALL\" to display all data.\n");
		printf("Enter (q to quit): ");
		scanf("%s",Input);
		
		if(!strcmp(Input,"ALL"))	// Display all data in the linked list
			PrintALL(chain);
		else
		{	node * ResultPtr = Find(chain,Input);
			if (ResultPtr == 0)		// Country code not found in the linked list
				printf("Country Code not found!\n");
			else					// Country code found, display data of that country
				printf("Country: %s; Country code: %s\nTotal Cases: %d\nTotal Deaths: %d\n",ResultPtr->country,ResultPtr->country_code,ResultPtr->totalCases,ResultPtr->totalDeaths);
		}
	}

	return 0;
}
