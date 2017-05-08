#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char terminals[10][2], productions[10][10];
char firstArray[10][10];

int n,i=0,x,j=0,k=0,len=0,y=0,success=0,z,pos,a,b,l=0;

char s;


void first(char production,int index)
{
	int x,l,z;
	int s = production;


	if(s>=97)
		firstArray[index][0]=production;

	else if(s>=65&&s<=90)
	{
		for(x=0;x<n;x++)
		{
			if(terminals[x][0]==production)
			{	
				j=x;
				first(productions[j][0], j);
				for(l=0;l<n;l++)
					if(terminals[l][0]==production)
						firstArray[index][0]=firstArray[l][0];
			}
		}

	}
						
}

int main()
{
	
	printf("\n Enter the No. of Productions in the Grammar : ");

	scanf("%d", &n);

	printf("\n Enter the Non Terminals of the Grammar : ");
	for(i=0;i<n;i++)
		scanf("%s",terminals[i]);

	printf("\n Enter the Productions for the Non Terminals : ");

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
		first(productions[i][0],i);
		printf(" %s ", firstArray[i]);
	}
	
	
	return 0;

}
