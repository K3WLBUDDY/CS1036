//© Sruthik P

/*Directed Acyclic Graph Primer : 
 *Every Leaf Node must be either a Constant or a Variable.
 *Interior Nodes must be either Operators or Results of Concatenated Operations
 */


/* Currently the Code does not take into Consideration any Nodes/Childs/Pointers 
 * because the Record output is wrong and I'm lazy. Will add Nodes in some time
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char expression[100];
	int length, leftPar=0, rightPar=0,count=0,len=0,found=0,i,j,k,childLength;
	char childExp[100][10];
	char finalArray[100];

	printf("\n Enter an Expression with Parenthesis : "); //For brevity consider (a+b)*(c+d)
	scanf("%s", expression);

	length = strlen(expression);

	for(i=0;i<length;i++)
	{
		if(expression[i] == '(')
		{
			leftPar++;
			childLength=0;

			k=i+1;
			while(expression[k]!=')')
			{
				childExp[count][childLength++]=expression[k];
				k++;
			}

			count++;
		}
		else if(expression[i] == ')')
		{
			if(expression[i+2]=='('&& !isalnum(expression[i+1]))
				finalArray[0]=expression[i+1];
			rightPar++;
		}
	}

	if(leftPar!=rightPar)
	{
		printf("\n Incorrect Expression!");
		return 0;
	}

	len=length-leftPar*2;//The Length of the Expression without the Parenthesis

	k=1;

	for(i=0;i<count;i++)
	{
		for(j=0;childExp[i][j]!='\0';j++)
		{
			if(!isalnum(childExp[i][j]))
			{
				finalArray[k]=childExp[i][j]; 
				finalArray[++k]=childExp[i][j-1];//Gets the Operands of the Current Operator
				finalArray[++k]=childExp[i][j+1];
				k++;
				break;
			}
		}
	}

	printf("\n Contents of DAG : ");
	for(i=0;i<len;i++)
		printf("\n\n  %c", finalArray[i]);

	return 0;
}