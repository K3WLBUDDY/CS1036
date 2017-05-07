//© Sruthik P

#include <stdio.h>
#include <string.h>

int n;
char leadingArray[10][10];//Stores all the Leading Elementes of a Grammar
char trailingArray[10][10];//Stores all the Trailing Elementes of a Grammar
char productions[10][10];//Stores the Productions of each Non Terminal
char nonTerminals[10][2];//Stores the Non Terminals

void leading(char production)
{
	int i,j,k,l,s;
	
	for(i=0;i<n;i++)
		if(production==nonTerminals[i][0])//To find the match for the Character passed to the function
		{				  //from the list of the Non Terminals
			j=0;k=0;

			while(productions[i][j]!='\0')//Loop to traverse the entire productions of the given Non Term
			{
				
				s=productions[i][j];//The Symbol is converted to its ASCII value. For A -> 65 a->97

				/*The below if Condition checks if the current Symbol stored in s is capital
				 *or small and also checks if it is the first element in the production. For Capitals
				 *the leading should be found only if they are the first element in the Production
				 */
				if(s>=65&&s<=90&&j==0)
				{		      
					leading(productions[i][j]);//Recursively finds the Leading for the Capital Sym
					
					/*The below for loop adds the Leading Elements found in the above line
					 *to the Leading Array of the current Production
					 */
					
					for(l=0;l<n;l++)
						if(nonTerminals[l][0]==s)
							strcpy(leadingArray[i], leadingArray[l]);
					k=strlen(leadingArray[i]);//To move the Array Pointer to the end
				}
				else if(s>=97)//Just add the Symbol into the array if it's a small letter (Terminal)
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
			//j=strlen(productions[i])-1 because j must point to the final index of the array
			for(j=strlen(productions[i])-1;j>=0;j--)//Logic is same as Leading but traversal is done from R-L
			{
				s=productions[i][j];
				
				/*Since the Traversal is done from Right to Left for Trailing
				 *only those Capitals (Non Terminals) that appear at the end
				 *of the productions must be considered for Recursion
				 */
				
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
		leading(nonTerminals[i][0]);//Calls the leading function for each Non Terminal present in the Grammar
		printf(" %s ",leadingArray[i]);
	}
	

	printf("\n\n\t TRAILING\n");

	for(i=0;i<n;i++)
	{
		printf("\n %c : ", nonTerminals[i][0]);
		trailing(nonTerminals[i][0]);//Calls the trailing function for each Non Terminal present in the Grammar
		printf(" %s ",trailingArray[i]);
	}

	return 0;
}
