//© Sruthik P
#include <stdio.h>

int main()
{
	char operator[3];

	printf("\n Enter an Operator : ");
	scanf("%s", operator);
	printf("\n Entered Operator : ");

	switch(operator[0])
	{
		case '+':
			printf("Addition");
			break;

		case '-':
			printf("Subtraction");
			break;

		case '*':
			printf("Multiplication");
			break;

		case '/':
			printf("Division");
			break;

		case '%':
			printf("Modulus");
			break;

		case '=':
			if(operator[1]=='=')
				printf("Equal To");
			else
				printf("Assignment");
			break;

		case '!':
			if(operator[1]=='!')
				printf("Logical NOT");
			else
				printf("Bitwise NOT");
			break;

		case '&':
			if(operator[1]=='&')
				printf("Logical AND");
			else
				printf("Bitwise AND");
			break;

		case '|':
			if(operator[1]=='|')
				printf("Logical OR");
			else
				printf("Bitwise OR");
			break;

		case '>':
			if(operator[1]=='=')
				printf("Greater than Or Equal To");
			else
				printf("Greater than");
			break;

		case '<':
			if(operator[1]=='=')
				printf("Less than Or Equal To");
			else
				printf("Less than");
			break;

		default:
			printf("\n Invalid Operator");
	}

	return 0;
}