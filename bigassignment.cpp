#include <stdio.h>
#define N 51700000

void DisplayResult();
void Histogram();

int main()
{
	DisplayResult();
}

void DisplayResult()
{
	float day0;
	float Beta;
	float Sigma;
	float Gamma;
	int days;
	printf("Enter the number of infected people in Day 0:");
	scanf("%f", &day0);
	printf("Enter the value of Beta (Transmission Rate):");
	scanf("%f", &Beta);
	printf("Enter the value of Sigma (Incubation Rate):");
	scanf("%f", &Sigma);
	printf("Enter the value of Gamma (Recovery Rate):");
	scanf("%f", &Gamma);
	printf("How many days do you want to run the simulation:");
	scanf("%d", &days);	
	
	double S[days] = {N};
	double E[days] = {0};
	double I[days] = {day0};
	double R[days] = {0};
	
	int i = 1;
	for(i; i <= days; i++)
	{
		S[i] = S[i-1] - Beta * (S[i-1] * I[i-1] / N);
		if(S[i] <= 0)
		{
			S[i] = 0;
			
		}
		
		E[i] = E[i-1] + Beta * (S[i-1] * I[i-1] / N) - Sigma * (E[i-1]);
		if(E[i] <= 0)
		{
			E[i] = 0;
		}
		
		I[i] = I[i-1] + Sigma * (E[i-1]) - Gamma * E[i-1];
		if(I[i] <= 0)
		{
			I[i] = 0;
		}
		
		R[i] = R[i-1] + Gamma * E[i-1];
		if(R[i] <= 0)
		{
			R[i] = 0;
		}
	}
	
	printf("Day\tS\t\tE\t\tI\t\tR\t\t\n");
	printf("==========================================================================================================");
	
	int j = 0;
	for(j; j <= days; j++)
	{
		printf("\nDay %d: ", j);
		printf("%lf ", S[j]);
		printf("%lf \t", E[j]);
		printf("%lf \t", I[j]);
		printf("%lf \n", R[j]);
	}
	
	char choice1();
	while (choice1 != 'n')
	{
		printf("Do you want to plot the result [y/n]? \n");
		scanf("%c", &choice1);
	
		switch(choice1)
		{
			case 'y':
				Histogram();
				Decision1();
				break;
			
			case 'n':
				Decision2();
				break;
			
			default:
				printf("Input Error! Please enter [y/n] \n");
				continue;		
		}
			}	
}



void Histogram()
{
}

void Decision2()
{
	char choice3;
	printf("Do you want to run simulation again? [y/n]?");
	scanf("%c", &choice3);
	
	swtich(choice3)
	{
		case 'y':
			DisplayResuilt();
			break;
		
		case 'n':
			break;
			
		default:
			printf("Input error! Please enter [y/n]");
			Decision2();
	}
}
