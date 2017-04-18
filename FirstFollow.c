#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n,i=0,x,j=0;

	char terminals[10][10], productions[10][10];
	char nonTerminal[10];

	char s;

	printf("\n Enter the No. of Productions in the Grammar : ");

	scanf("%d", &n);

	printf("\n Enter the Non Terminals of the Grammar : ");
	for(i=0;i<n;i++)
		scanf("%s",terminals[i]);

	printf("\n Enter the Productions for the Terminals : ");
	printf("\n Seperate the Productions with a comma!\n");

	for(i=0;i<n;i++)
	{
		printf("\n\n %s -----> ",terminals[i]);
		scanf("%s", &productions[i]);
	}

	printf("\n The Entered Grammar is :");

	for(i=0;i<n;i++)
	{
		printf("\n\n %s -----> %s", terminals[i], productions[i]);
	}

	for(i=0;i<n;i++)
	{
		printf("\n FIRST OF %s : ", terminals[i]);

		int x = productions[i][0];
		int y;

		if(x>=97)
			printf("%c", productions[i][0]);
		else
		do
		{
			printf("\n NOT FIRST");
			//strcpy(nonTerminal, productions[i][0]);
			s=productions[i][0];
			//strcpy(nonTerminal, productions[i]);
			printf("%c", productions[i][0]);


			for(j=0;j<n;j++)
			{
				if(strcmp(nonTerminal, terminals[i])==0)
					break;
			}

			y = productions[j][0];

			if(y>=97)
				printf("%c", productions[j][0]);
			else
				continue;

			//printf("%c", productions[j][0]);
			//x=productions[j][0];
		}
		while(y<=97);
	}

}