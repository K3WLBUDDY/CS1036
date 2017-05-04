//© Sruthik P
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char expression[20], search[2];
	int length,i,flag=0;
	void *address[20];

	printf("\n Enter an Expression : ");
	scanf("%s", expression);

	printf("\n The Entered Expression was : %s \n", expression);

	length = strlen(expression);

	for(i=0;i<length;i++)
	{
		address[i]=malloc(expression[i]);
		printf("\n Address of %c : %d",expression[i], address[i]);

		if(isalnum(expression[i]))
			printf("\n Type : Variable \n");
		else
			printf("\n Type : Operator \n");
			
	}

	printf("\n Enter a Symbol to be Searched for : ");
	scanf("%s", search);

	for(i=0;i<length;i++)
		if(expression[i]==search[0])
		{
			printf("\n Symbol %s found at the following Address : %d", search, address[i]);
			flag = 1;
		}
		
	if(flag==0)
		printf("\n Symbol %s could not be found in the Entered Expression", search, expression);

}