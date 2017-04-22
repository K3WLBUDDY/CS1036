#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char terminals[10][2], productions[10][10];
//char nonTerminal[10];

int n,i=0,x,j=0,k=0,len=0,y=0,success=0,z,pos,a,b;

char s;


void first(int index)
{
	
		int x = productions[index][0];

		if(x>=97)
			printf("%c", productions[index][0]);
		else
		{
			s=productions[index][0];
			x=productions[index][0];

			l1:
				for(k=0;k<n;k++)
				{
					z = terminals[k][0];
					
					if(x==z)
					{
						y=productions[k][0];
						s=productions[k][0];
					}
					
				}

				if(y>=97)
					printf("%c", s);
				
				else
				{
					x=s;
					goto l1;
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
		first(i);
	}
	
	for(i=0;i<n;i++)
	{
		printf("\n FOLLOW OF %s : ", terminals[i]);

		len=strlen(productions[i]);

		for(j=0;j<len;j++)
		{
			x=productions[i][j];
			y=terminals[i][0];
			//if(strcmp(productions[i][j], terminals[i])==0)
			if(x==y)
			{
				pos=j+1;

				z=productions[i][pos];

				if(z>=97)
					printf("%c", productions[i][pos]);
				else if(z>=65&&z<=90)
					{
						for(k=0;k<n;k++)
						{
							a=terminals[k][0];
							b=productions[i][pos];

							//if(strcmp(terminals[k], productions[i][pos])==0)
							if(a==b)
								first(k); 
						}
					}
				success=1;
			}
		}
		if(success==0)
			printf("NULL");
		success=0;

	}
	
	return 0;

}