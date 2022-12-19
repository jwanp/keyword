// Lab Assignment8 2021312460 Park Chae Rin
#include <stdio.h>

void ArrayReverse(int * InputPtr,int size)
{
	if (size % 2 == 0) // If the size is even number, repete size/2 times
	{
		int i = 0;
		for(i; i < size /2; i++)
		{
			int temp = InputPtr[i]; // save the value in temporary variable
			InputPtr[i] = InputPtr[size - 1 - i]; // swap the value
			InputPtr[size - 1 - i] = temp;
		}
	}
	else // If the size is odd number, repete size/2 + 1 tims
	{
		int i = 0;
		for(i; i < size / 2 + 1; i++)
		{
			int temp = InputPtr[i]; // save the value in temporary variable
			InputPtr[i] = InputPtr[size - 1 - i]; // swap the value
			InputPtr[size - 1 - i] = temp;
		}
	}
}

int main(void)
{ 
	int Test1[10] = {10,20,30,40,50,60,70,80,90,100};
	int Test2[6] = {112,110,108,106,14,12};
	int Test3[7] = {18,35,1024,23,68,51,51};
	
	printf("Test1 contains %d items: ",sizeof(Test1)/sizeof(int));
	
	for(int i=0;i<sizeof(Test1)/sizeof(int);i++)
	printf("%d ",Test1[i]);
	printf("\n"); // Print Array Test1
	
	printf("Test2 contains %d items: ",sizeof(Test2)/sizeof(int));
	
	for(int i=0;i<sizeof(Test2)/sizeof(int);i++)
	printf("%d ",Test2[i]);
	printf("\n"); // Print Array Test2
	
	printf("Test3 contains %d items: ",sizeof(Test3)/sizeof(int));
	
	for(int i=0;i<sizeof(Test3)/sizeof(int);i++)
	printf("%d ",Test3[i]);
	printf("\n"); // Print Array Test3
	
	ArrayReverse(Test1,sizeof(Test1)/sizeof(int));
	ArrayReverse(Test2,sizeof(Test2)/sizeof(int));
	ArrayReverse(Test3,sizeof(Test3)/sizeof(int));
	
	printf("Test1 after Reverse: ");
	for(int i=0;i<sizeof(Test1)/sizeof(int);i++)
	printf("%d ",Test1[i]);
	printf("\n"); // Print Array Test1
	
	printf("Test2 after Reverse: ");
	for(int i=0;i<sizeof(Test2)/sizeof(int);i++)
	printf("%d ",Test2[i]);
	printf("\n"); // Print Array Test2
	
	printf("Test3 after Reverse: ");
	for(int i=0;i<sizeof(Test3)/sizeof(int);i++)
	printf("%d ",Test3[i]);
	printf("\n"); // Print Array Test3
	return 0;
}

