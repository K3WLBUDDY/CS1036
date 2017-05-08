//© Sruthik P
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* A valid Identifier cannot start with a number or
 * have any special characters inbetween except for underscore "_"
 */

int main()
{
	char identifier[20];
	int length,i,flag=0;

	printf("\n Enter an Identifier : ");
	scanf("%s", identifier);

	length = strlen(identifier);

	for(i=0;i<length;i++)
	{
		if(identifier[i]=='_')//Special Case for underscore
			flag=0;
		else if(!isalnum(identifier[i])||!isalpha(identifier[0]))
			flag=1;
	}
	
	if(flag==0)
		printf("\n %s is a Valid Identifier", identifier);
	else
		printf("\n %s is an Invalid Identifier", identifier);
}
