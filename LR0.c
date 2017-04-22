#include <stdio.h>
#include <string.h>

char nonTerminals[10][2], productions[10][10];
int n,i;
int a,b;
int setNo=1;
int count;
int j,x;
char s;

//RECURSION FTW

void parse(int i, int pointer)
{

	x=productions[i][pointer];
	s=productions[i][pointer];
	if(productions[i][pointer]=='\0')
	{
		printf("\n\n I%d ",setNo++);
		printf("\n %s -----> %s", nonTerminals[i], productions[i]);
		printf(".");
	}

	else if(x<97)
	{
		printf("\n I%d ",setNo++);
		printf("\n %s -----> %c . %c", nonTerminals[i], productions[i][0], productions[i][1]);
		

		

		for(j=0;j<=n;j++)
		{
			a=nonTerminals[j][0];
			if(a==x)
			{	
				printf("\n %s -----> .%s", nonTerminals[j], productions[j]);
				break;
				
			}
		}
		parse(i,pointer+1);
		parse(j, 1);
	}
}

int main()
{

	int pointer=0;
	printf("\n\n Enter the No. of Productions : ");
	scanf("%d", &n);

	printf("\n Enter the Non Terminals : ");

	for(i=0;i<n;i++)
		scanf("%s", nonTerminals[i+1]);

	printf("\n Enter the Productions : ");

	for(i=0;i<n;i++)
	{
		printf("\n %s -----> ", nonTerminals[i+1]);
		scanf("%s", productions[i+1]);
	}

	printf("\n Entered Grammar : ");

	for(i=0;i<n;i++)
		printf("\n %s -----> %s ",nonTerminals[i+1], productions[i+1]);

	strcpy(nonTerminals[0], "X");

	strcpy(productions[0], nonTerminals[1]);

	printf("\n\n LR (0) PARSER ITEM SETS : \n\n");

	printf("\n I0 \n");

	for(i=0;i<n+1;i++)
		printf("\n %s -----> .%s", nonTerminals[i], productions[i]);

	for(i=0;i<=n;i++)
	{
		
		pointer = strlen(productions[i]);
		count=1;
		parse(i,count);
	}

	return 0;


	
}