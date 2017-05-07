//© Sruthik P
//TODO - Special Case for input string b -> Accepted by a*b+

/*Primer on Regular Expressions:
 * '*' indicates zero or more occurances of the preceding element
 * '+' indicates one or more occurances of the preceding element
 * Accepted Strings must be of the form a* or a*b+ or abb
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char input[100];
	int length=0,i,flag=0;

	printf("\n Enter a String : ");
	scanf("%s", input);

	length = strlen(input);

	if(input[0]='a')
	{
		flag=1;

		for(i=1;i<length;i++)
			if(input[i]=='b')
				flag=2;
			else
				flag=0;
	}
	
		

	else if(length==0)//Since a* is accepted which means a Null String is accepted too
		flag=1;

	else if(strcmp(input, "abb")==0)//Not sure about abb. Don't quote me on this!
		flag=3;

	if(flag==1)
		printf("\n %s is Accepted under a*",input);
	else if(flag==2)
		printf("\n %s is Accepted under a*b+",input);
	else if(flag==3)
		printf("\n %s is Accepted under abb",input);
	else if(flag==0)
		printf("\n %s is not Accepted under a* or a*b+ or abb", input);

	return 0;
}
