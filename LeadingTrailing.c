//© Sruthik P

#include <stdio.h>
#include <string.h>

int n;
char leadingArray[10][10];
char productions[10][10];
char nonTerminals[10][2];

void leading(char production)
{
	int i,k,s,j,l;
	
	for(i=0;i<n;i++)
		if(production==nonTerminals[i][0])
		{
			k=0;j=0;

			while(productions[i][k]!='\0')
			{
				
				s=productions[i][k];

				if(s>=65&&s<=90&&k==0)
				{
					leading(productions[i][k]);
					for(l=0;l<n;l++)
						if(nonTerminals[l][0]==s)
							strcpy(leadingArray[i], leadingArray[l]);
					j=strlen(leadingArray[i]);
				}
				else if(s>=97)
					leadingArray[i][j++]=productions[i][k];
				k++;
			}
			
		}
		
		
}

int main()
{
	
	int i,j;

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

	printf("\n\n\t LEADING\n");

	for(i=0;i<n;i++)
	{
		printf("\n %c : ", nonTerminals[i][0]);
		leading(nonTerminals[i][0]);
		printf(" %s ",leadingArray[i]);
	}

	return 0;
}