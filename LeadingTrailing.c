//© Sruthik P

#include <stdio.h>

int main()
{
	char productions[10][10];
	char nonTerminals[10][2];
	int n,i;

	printf("\n Enter the No. of Productions : ");
	scanf("%d", &n);

	printf("\n Enter the Non Terminals of the Productions : ");

	for(i=0;i<n;i++)
		scanf("%s", nonTerminals[i]);

	printf("\n Enter the Productions for the Non Terminals : ");

	for(i=0;i<n;i++)
	{
		printf("\n %c -----> ", nonTerminals[i][0]);
		scanf("%s", productions[i]);
	}

	printf("\n The Entered Grammar is : ");

	for(i=0;i<n;i++)
		printf("\n %c -----> %s", nonTerminals[i][0], productions[i]);

	return 0;
}