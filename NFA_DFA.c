// Okay, this gets complicated :s

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

	
}

int main()
{
	int states, inputs,i=0,j=0,x=0,k=0;

	char transition[10][10][10];

	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			strcpy(transition[i][j], "NULL");

	int size;

	int inputSymbol = 65;
	int symbol;

	char uniqueSymbols[10][10];
	char individualSymbol[10];
	char *token;

	const char delimiter[2] = ",";

	printf("\t\t NFA TO DFA CONVERTER\n");

	printf("\n Seperate State Transitions with a Comma\n");
	printf("\n Enter X for No Transition for a particular Input\n");


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

	printf("\n\n THE NFA CONVERTED TO DFA : \n\n");

	strcpy(finalArray[0],"0");
	length++;

	for(i=0;i<states;i++)
	{
		for(j=0;j<inputs;j++)
		{
			strcpy(finalArray[length++],transition[i][j]);
			checkRepeat(length);
		}
	
	}

	for(i=0; i<length; i++)
	{
		strcpy(individualSymbol, finalArray[i]);

		if(strlen(individualSymbol)==1)
		{
			symbol = atoi(individualSymbol);

			for(j=0;j<inputs;j++)
			{
				if(strcmp(transition[symbol][j],"NULL")==0)
					strcpy(transition[symbol][j], "X");
				printf("\n  	%c", inputSymbol++);
				printf("\n  %d -----> %s", symbol, transition[symbol][j]);
			}
			inputSymbol=65;
		}

		else
		{
			k=0;

			token = strtok(individualSymbol, delimiter);

			while(token!=NULL)
			{
				strcpy(uniqueSymbols[k++], token);

				token = strtok(NULL, delimiter);
			}

			for(j=0;j<inputs;j++)
			{
				printf("\n        %c", inputSymbol++);
				printf("\n  %s -----> ",finalArray[i]);

				for(x=0;x<k;x++)
					printf("%s ,",transition[atoi(uniqueSymbols[x])][j]);

			}

			inputSymbol=65;
		}

	}

	return 0;
}