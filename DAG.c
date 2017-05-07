//© Sruthik P

/*Directed Acyclic Graph Primer : 
 *Every Leaf Node must be either a Constant or a Variable.
 *Interior Nodes must be either Operators or Results of Concatenated Operations
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
struct node
{
	int leftChild, rightChild;
	char contents[3];
};
*/

int main()
{
	char expression[100];
	int length, leftPar=0, rightPar=0,count=0,len=0,found=0,i,j,k,childLength;
	char childExp[100][10];
	char finalArray[100];

	//struct node n[100];

	printf("\n Enter an Expression with Parenthesis : "); //For brevity consider d=(a+b)*(e+f)
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

	printf("\n CHild Expression : ");
	for(i=0;i<count;i++)
		printf("\n\n %s", childExp[i]);

	len=length-leftPar*2;

	for(i=1;i<len;i++)
	{
		for(j=0;j<count;j++)
		{	
			found=0;

			for(k=0;childExp[j][k]!='\0';k++)
			{
				if(!isalnum(childExp[j][k])&&found==0)
				{
					found=1;
					finalArray[i]=childExp[j][k]; 
				}
				else if(isalnum(childExp[j][k])&&found==1)
					finalArray[i]=childExp[j][k];
			}
		}
	}

	printf("\n Contents of DAG and Length : \n  %d ", len);
	for(i=0;i<len;i++)
		printf("\n\n teest %c", finalArray[i]);

	return 0;
}