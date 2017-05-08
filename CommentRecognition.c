//© Sruthik P
#include <stdio.h>
#include <string.h>

// Recognizes comments of both Single Line "//" and Multi Line "/*......*/" type

int main()
{
	char input[100];
	int length;

	printf("\n Enter the Input : ");
	scanf("%s", input);

	length = strlen(input);
	//if condition checks for presence of / in first and second index or / and * in the first and second index
	//and the vice versa at the end
	if((input[0]=='/'&&input[1]=='/')||(input[0]=='/'&&input[1]=='*'&&input[length-2]=='*'&&input[length-1]=='/'))
			printf("\n %s is a Comment", input);
	else
		printf("\n %s is not a Comment", input);

	return 0;
}
