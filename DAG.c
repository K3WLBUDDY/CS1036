//© Sruthik P

/*Directed Acyclic Graph Primer : 
 *Every Leaf Node must be either a Constant or a Variable.
 *Interior Nodes must be either Operators or Results of Concatenated Operations
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char expression[100];
	int length; leftPar=0, rightPar=0,count=0;
	int childExp[100][10];
	char rootOperator[2];

	printf("\n Enter an Expression with Parenthesis : "); //For brevity consider d=(a+b)*(e+f)
	scanf("%s", expression);

	length = strlen(expression);

	for(i=0;i<length;i++)
	{
		if(expression[i] == '(')
		{
			lefPar++;
			childLength=0;

			k=i;
			while(expression[k]!=')')
			{
				childExp[count][childLength++]=expression[k];
				k++;
			}

			leftPar++;
		}
		else if(expression[i] == ')')
		{
			if(expression[i+2]=='('&& !isalnum(expression[i+1]))
				rootOperator=expression[i+1];
			rightPar++;
		}
	}

	if(leftPar!=rightPar)
		printf("\n Incorrect Expression");
	else
	{
		printf("\n Root : %s", rootOperator);

		for(i=0;i<leftPar;i++)
		{
			printf("\n Left Child: ")//Err......
		}
	}
