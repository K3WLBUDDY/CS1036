#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n,i=0,x;

	char terminals[10][10], productions[10][10];

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

		if(x>=97)
			printf("%c", productions[i][0]);
	}

}