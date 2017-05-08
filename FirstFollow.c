#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char terminals[10][2], productions[10][10];
char firstArray[10][10];
char followArray[10][10];

int n,i=0,x,j=0,k=0,len=0,y=0,success=0,pos,a,b,l=0;

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

void follow(char production, int position, int index, int count)
{
	int z=0;
	int a;
	int s=productions[position][++count];
	char next=productions[position][count];

	if(s>=97)
		followArray[index][z++]=next;

	else if(s>=65&&s<=90)
	{
		for(a=0;a<n;a++)
			if(terminals[a][0]==next)
				strcpy(followArray[index], firstArray[a]);
	}

	else 
	{
		strcpy(followArray[index], followArray[position]);
	}
}

int main()
{
	
	int z,count=0;

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

	
	printf("\n FIRST : \n");
	for(i=0;i<n;i++)
	{
		printf("\n %s : ", terminals[i]);
		first(productions[i][0],i);
		printf(" %s ", firstArray[i]);
	}

	printf("\n FOLLOW : \n");
	for(i=0;i<n;i++)
	{
		printf("\n %s : ", terminals[i]);

		for(z=0;z<n;z++)
		{	
			count=0;

			while(productions[z][count]!='\0')
			{
				if(terminals[i][0]==productions[z][count])
					follow(productions[z][count], z, i,count);
				count++;
			}
		}

		printf(" %s ", followArray[i]);

	}
	
	return 0;

}
