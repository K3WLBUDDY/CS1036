//© Sruthik P

#include <stdio.h>
#include <string.h>

int n;
char leadingArray[10][10];
char trailingArray[10][10];
char productions[10][10];
char nonTerminals[10][2];

void leading(char production)
{
	int i,j,k,l,s;
	
	for(i=0;i<n;i++)
		if(production==nonTerminals[i][0])
		{
			j=0;k=0;

			while(productions[i][j]!='\0')
			{
				
				s=productions[i][j];

				if(s>=65&&s<=90&&j==0)
				{
					leading(productions[i][j]);
					for(l=0;l<n;l++)
						if(nonTerminals[l][0]==s)
							strcpy(leadingArray[i], leadingArray[l]);
					k=strlen(leadingArray[i]);
				}
				else if(s>=97)
					leadingArray[i][k++]=productions[i][j];
				j++;
			}
			
		}		
}

void trailing(char production)
{
	int i,j,k,l,s;

	for(i=0;i<n;i++)
		if(production==nonTerminals[i][0])
		{
			k=0;
			for(j=strlen(productions[i])-1;j>=0;j--)
			{
				s=productions[i][j];

				if(s>=65&&s<=90&&j==strlen(productions[i])-1)
				{
					trailing(productions[i][j]);
					for(l=0;l<n;l++)
						if(nonTerminals[l][0]==s)
							strcpy(trailingArray[i], trailingArray[l]);
						k=strlen(trailingArray[i]);
				}
				else if (s>=97)
					trailingArray[i][k++]=productions[i][j];
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
	

	printf("\n\n\t TRAILING\n");

	for(i=0;i<n;i++)
	{
		printf("\n %c : ", nonTerminals[i][0]);
		trailing(nonTerminals[i][0]);
		printf(" %s ",trailingArray[i]);
	}

	return 0;
}