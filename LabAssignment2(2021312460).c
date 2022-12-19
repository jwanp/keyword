// Lab Assignment 2 2021312460 Park Chae RIn
#include <stdio.h>
int main()
{
	int date; //Declare the variable of input value
	int month; //Declare the month variable
	int day; //Declare the day variable
	int year; //Declare the year variable
	
	printf("Enter a date in numerical form(MMDDYYYY):"); //Get the value of date from user
	scanf("%d", &date);
	
	month = date / 1000000; //Calculate month
	
	day = (date / 10000) % 100; //Calculate day
	
	year = date % 10000; //Calculate year
	
	if (day == 1 || day == 11 || day == 21 || day == 31) //In the case of the value of the day is end with '1'
	{
		switch (month) //print the sentence of the date in English form
		{
			case 1:
				printf("%dst January %d", day, year);
				break;
			case 2:
				printf("%dst February %d", day, year);
				break;
			case 3:
				printf("%dst March %d", day, year);
				break;
			case 4:
				printf("%dst April %d", day, year);
				break;
			case 5:
				printf("%dst May %d", day, year);
				break;
			case 6:
				printf("%dst June %d", day, year);
				break;
			case 7:
				printf("%dst July %d", day, year);
				break;
			case 8:
				printf("%dst August %d", day, year);
				break;
			case 9:
				printf("%dst September %d", day, year);
				break;
			case 10:
				printf("%dst October %d", day, year);
				break;
			case 11:
				printf("%dst November %d", day, year);
				break;
			case 12:
				printf("%dst December %d", day, year);
				break;
		}
	}
	else if (day == 2 || day == 12 || day == 22) //In the case of the value of the day is end with '2'
	{
		switch (month) //print the sentence of the date in English form
		{
			case 1:
				printf("%dnd January %d", day, year);
				break;
			case 2:
				printf("%dnd February %d", day, year);
				break;
			case 3:
				printf("%dnd March %d", day, year);
				break;
			case 4:
				printf("%dnd April %d", day, year);
				break;
			case 5:
				printf("%dnd May %d", day, year);
				break;
			case 6:
				printf("%dnd June %d", day, year);
				break;
			case 7:
				printf("%dnd July %d", day, year);
				break;
			case 8:
				printf("%dnd August %d", day, year);
				break;
			case 9:
				printf("%dnd September %d", day, year);
				break;
			case 10:
				printf("%dnd October %d", day, year);
				break;
			case 11:
				printf("%dnd November %d", day, year);
				break;
			case 12:
				printf("%dnd December %d", day, year);
				break;
		}
	}
	else if (day == 3 || day == 13 || day == 23) //In the case of the value of the day is end with '3'
	{
		switch (month) //print the sentence of the date in English form
		{
			case 1:
				printf("%drd January %d", day, year);
				break;
			case 2:
				printf("%drd February %d", day, year);
				break;
			case 3:
				printf("%drd March %d", day, year);
				break;
			case 4:
				printf("%drd April %d", day, year);
				break;
			case 5:
				printf("%drd May %d", day, year);
				break;
			case 6:
				printf("%drd June %d", day, year);
				break;
			case 7:
				printf("%drd July %d", day, year);
				break;
			case 8:
				printf("%drd August %d", day, year);
				break;
			case 9:
				printf("%drd September %d", day, year);
				break;
			case 10:
				printf("%drd October %d", day, year);
				break;
			case 11:
				printf("%drd November %d", day, year);
				break;
			case 12:
				printf("%drd December %d", day, year);
				break;
		}
	}
	else //In the case of the value of the day is end with others
	{
		switch (month) //print the sentence of the date in English form
		{
			case 1:
				printf("%dth January %d", day, year);
				break;
			case 2:
				printf("%dth February %d", day, year);
				break;
			case 3:
				printf("%dth March %d", day, year);
				break;
			case 4:
				printf("%dth April %d", day, year);
				break;
			case 5:
				printf("%dth May %d", day, year);
				break;
			case 6:
				printf("%dth June %d", day, year);
				break;
			case 7:
				printf("%dth July %d", day, year);
				break;
			case 8:
				printf("%dth August %d", day, year);
				break;
			case 9:
				printf("%dth September %d", day, year);
				break;
			case 10:
				printf("%dth October %d", day, year);
				break;
			case 11:
				printf("%dth November %d", day, year);
				break;
			case 12:
				printf("%dth December %d", day, year);
				break;
		}
	}
}

