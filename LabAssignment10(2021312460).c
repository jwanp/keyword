// Lab Assignment 10 2021312460 Park Chae Rin
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int WordCount(char * input, int size)
{
	int i = 0; // Declare the counter variable
	int count = 0; // Declare the variable (count: count the number of spaces in string)
	for(i; i< size; i++)
	{
		int a = isspace(input[i]); // If the char is space, a != 0
		
		if (a != 0)
		{
			count += 1; // Count the number of spaces
		}
	}
	return count+1; // Return count +1 (the number of words is the number of spaces + 1)
}

int PunctuationCount(char * input, int size)
{
	int i = 0; // Declare the counter variable 
	int count = 0; // Declare the variable (count: count the number of punctuations in string)
	for(i; i< size; i++)
	{
		int a = ispunct(input[i]); // If the char is punctuation, a != 0
		
		if(a != 0)
		{
			count = count + 1; // Count the number of punctuations 
		}
	}
	return count; // Retunr the variable 	
}

int main(void)
{ 
	char test1[] = "Hello, World!";
	char test2[] = "She sell sea shell on a sea shore. The shells she sells are sea-shells. I'm sure? For if she sells sea-shells on the sea-shore, then I'm sure she sells sea-shore shells!";
	char test3[] = "VISION 2020 embodies every SKKU student's dream, will, and destiny to make SKKU a global leading university. To successfully establish VISION 2020, SKKU will pursue 'The 5 Core Strategies' and '5 Divisional Strategies'. The Strategic Tasks for 5 Major Areas are the general tasks that influence SKKU's competitiveness.";
	printf("test1 has %d punctuations, %d words.\n", PunctuationCount(test1,sizeof(test1)/sizeof(char)), 
	WordCount(test1,sizeof(test1)/sizeof(char)));
	printf("test2 has %d punctuations, %d words.\n", PunctuationCount(test2,sizeof(test2)/sizeof(char)), 
	WordCount(test2,sizeof(test2)/sizeof(char)));
	printf("test3 has %d punctuations, %d words.\n", PunctuationCount(test3,sizeof(test3)/sizeof(char)), 
	WordCount(test3,sizeof(test3)/sizeof(char)));
	return 0;
}
