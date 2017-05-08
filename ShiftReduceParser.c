//© Sruthik P

#include <stdio.h>
#include <string.h>

void check();
{
	
}

int main()
{
	char input[20], nonTerminals;
	int length,i,n;

	printf("\n Enter the No. of Productions in the Grammar : ");

	scanf("%d", &n);

	printf("\n Enter the Non Terminals of the Grammar : ");
	for(i=0;i<n;i++)
		scanf("%s",nonTerminals[i]);

	printf("\n Enter the Productions for the Non Terminals : ");

	for(i=0;i<n;i++)
	{
		printf("\n\n %s -----> ",nonTerminals[i]);
		scanf("%s", &productions[i]);
	}


	printf("\n Enter the Input String : ");
	scanf("%s",input);

	length = strlen(input);

	printf("\n\n OUTPUT \t STACK \t OPERATION \n");

	for(i=0;i<length;i++)
}