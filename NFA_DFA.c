// Use strtok(str, delimiter). Sends it to a char*. Don't use malloc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char finalArray[20][10];

int length = 0;

void checkRepeat(int currentLength)
{
	int i,j,k, repeatCount;
	char temp[10];

	for(i=0;i<currentLength;i++)
	{
		strcpy(temp, finalArray[i]);
		repeatCount=0;

		for(j=0;j<currentLength;j++)
		{
			if(strcmp(temp, finalArray[j])==0)
				repeatCount++;
		}

		if(repeatCount>1)
		{
			for(k=i;k<currentLength-1;k++)
				strcpy(finalArray[k], finalArray[k+1]);
			currentLength--;
			length--;
		}
	}

	printf("\n Final Array of Unique Symbols : ");

	for(i=0;i<currentLength;i++)
		printf("\n\n %s", finalArray[i]);
}

int main()
{
	int states, inputs,i=0,j=0;

	char transition[10][10][10];

	//int transitionLength[10][10];

	int size;

	int inputSymbol = 65;

	char uniqueSymbols[10][10];

	printf("\t\t NFA TO DFA CONVERTER");

	printf("\n Seperate State Transitions with a Comma\n");
	printf("\n Enter X for No Transition for a particular Input");


	printf("\n Enter the No. of States : ");
	scanf("%d", &states);

	printf("\n Enter the No. of Inputs : ");
	scanf("%d", &inputs);

	for(i=0; i<states; i++)
	{

		printf("\n Enter NFA for State %d : \n", i);

		for(j=0;j<inputs;j++)
		{

			printf("\n      %c", inputSymbol++);
			printf("\n %d ----->  ", i);
			scanf("%s", &transition[i][j]);
			printf("\n");
		}

		inputSymbol=65;
	}


	for(i=0; i<states; i++)
	{
		printf("\n\n Entered NFA For State %d : \n", i);

		printf("\t");

		for(j=0;j<inputs;j++)
		{
			printf("\n      %c", inputSymbol++);
			printf("\n %d ----->  %s", i, transition[i][j]);
		}

		inputSymbol=65;
	}

	printf("\n THE NFA CONVERTED TO DFA : ");

	strcpy(finalArray[0],"0");
	length++;

	for(i=0;i<states;i++)
	{
		for(j=0;j<inputs;j++)
		{
			strcpy(finalArray[length++],transition[i][j]);
			checkRepeat(length);
		}
	return 0;
	}
}