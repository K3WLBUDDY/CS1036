#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int states, inputs,i=0,j=0;

	char transition[10][10][10];

	int transitionLength[10];

	int inputSymbol = 65;

	printf("\n Enter the No. of Statess : ");
	scanf("%d", &states);

	printf("\n Enter the No. of Inputs : ");
	scanf("%d", &inputs);

	for(i=0; i<states; i++)
	{
		transitionLength[i][0]=0;

		printf("\n Enter NFA for State %d", i);
		printf("\n Seperate State Transitions with a Comma");

		for(j=0;j<inputs;j++)
		{
			printf("\n      %c", inputSymbol++);
			printf("\n &d ----->  ", states);

			scanf("%s", transition[i][j][k++]);
		}


	for(i=0; i<states; i++)
	{
		printf("\n Entered NFA For State %d : \n", i);

		printf("\t");

		for(j=0;j<inputs;j++)
		{
			printf("")
		}
	}

	return 0;
}