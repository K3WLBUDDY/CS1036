#include <stdio.h>
#include <string.h>

char nonTerminals[10][2], productions[10][10];
int n,i;
int a,b;
int setNo=1; //Holds the Int Value for Item Set (I0, I1, I2...)
int count;
int j,x;
char s;

//RECURSION FTW

void parse(int i, int pointer)
{

	x=productions[i][pointer];
	s=productions[i][pointer];
	if(productions[i][pointer]=='\0')//Check for Null Terminator after Shifting
	{
		printf("\n\n I%d ",setNo++);//setNo++ increments the Item Set Number
		printf("\n %s -----> %s", nonTerminals[i], productions[i]);
		printf(".");
	}

	else if(x<97)//Check for Non Terminal after Shifting
	{
		printf("\n I%d ",setNo++);
		printf("\n %s -----> %c . %c", nonTerminals[i], productions[i][0], productions[i][1]);
		

		

		for(j=0;j<=n;j++)
		{
			a=nonTerminals[j][0];
			if(a==x)//Check for equality of Non Terminals
			{	
				printf("\n %s -----> .%s", nonTerminals[j], productions[j]);
				break;
				
			}
		}
		parse(i,pointer+1); //Parse for the Base Production
		parse(j, 1);	//Parse for the New Production generated from Shifting "."
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

	//Get the Values at i+1 coz Augmented Grammar will be stored at index 0

	printf("\n Enter the Productions : ");

	for(i=0;i<n;i++)
	{
		printf("\n %s -----> ", nonTerminals[i+1]);
		scanf("%s", productions[i+1]);//Will work only for a max of 2 productions per Non Terminal
	}

	printf("\n Entered Grammar : ");

	for(i=0;i<n;i++)
		printf("\n %s -----> %s ",nonTerminals[i+1], productions[i+1]);

	strcpy(nonTerminals[0], "X");	//Copying Augmented Grammar to Index 0

	strcpy(productions[0], nonTerminals[1]);//Same as above

	printf("\n\n LR (0) PARSER ITEM SETS : \n\n");

	printf("\n I0 \n");	//Printing I0 Set Directly

	for(i=0;i<n+1;i++)
		printf("\n %s -----> .%s", nonTerminals[i], productions[i]); //Don't forget the "."

	for(i=0;i<=n;i++)	//Recursively Parsing for all the Productions
	{
		
		count=1;	//Counter Variable to imitate the shifting of the "."
		parse(i,count);
	}

	return 0;


	
}