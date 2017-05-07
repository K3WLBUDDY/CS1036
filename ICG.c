//© Sruthik P

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char expression[10];
	int length,i,regNo=0;
	char operands[10][2],count=0;
	char result;

	printf("\n Enter an Expression : ");//Example Input : d=a+b
	scanf("%s", expression);

	length = strlen(expression);

	for(i=0;i<length;i++)
		if(isalnum(expression[i])&&expression[i+1]!='=')
			printf("\n MOV %c R%d",expression[i], regNo++);

	for(i=0;i<length;i++)
	{
		if(expression[i]=='+')
			printf("\n ADD R0 R1");
		else if(expression[i]=='-')
			printf("\n SUB R0 R1");
		else if(expression[i] == '/')
			printf("\n DIV R0 R1");
		else if(expression[i]=='*')
			printf("\n MUL R0 R1");
	}

	if(expression[1]=='=')
		printf("\n MOV R1 %c", expression[0]);

	return 0;
}


/* The Intermediate code generated as per the record
 * doesn't fall under either Intel or AT&T x86 Syntax.
 * So the program generates some gibberish intermediate code.
 * Don't ask why.
 */

/* For those even more Curious about the difference between 
 * Intel and AT&T x86 Syntax :
 * Intel - MOV Destination Source
 * AT&T - MOV Source Destination; but constants must be prefixed with $ and
 * registers with %. 
 */
