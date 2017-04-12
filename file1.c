#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf("\n WTF");
	FILE *f1;

	if(f1==NULL)
		printf("\n Seriously");

	printf("\n WTF Returns");
	char c;
	//c = malloc(sizeof(char));
	printf("\n Hello");

	f1 = fopen("Inputs/input.txt", "r");

	if(f1==NULL)
		perror("\n AYY FOOK");
	else
		printf("\n DANK");
	while((c=fgetc(f1))!=EOF)
		printf("\n %c", c);

	fclose(f1);

	return 0;

}