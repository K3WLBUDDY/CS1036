//© Sruthik P

/*Directed Acyclic Graph Primer : 
 *Every Leaf Node must be either a Constant or a Variable.
 *Interior Nodes must be either Operators or Results of Concatenated Operations
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define UNDEFINED 69 //Ayy lmao

struct node
{
	int leftChild, rightChild;
	char contents[2];
};

int main()
{
	char expression[100];
	int length, leftPar=0, rightPar=0,count=0,len=0,found=0,i,j,k,childLength;
	char childExp[100][10];
	struct node n[100];

	printf("\n Enter an Expression with Parenthesis : "); //For brevity consider (a+b)*(c+d)
	scanf("%s", expression);

	length = strlen(expression);

	for(i=0;i<length;i++)
	{
		if(expression[i] == '(')
		{
			leftPar++;//Holds the count of the No. of Left parenthesis
			childLength=0;

			k=i+1;
			while(expression[k]!=')')
			{
				childExp[count][childLength++]=expression[k];
				k++;
			}
			
		}
		else if(expression[i] == ')')
		{
			if(expression[i+2]=='('&& !isalnum(expression[i+1]))//Checks if an operator is inbetween ) and (
				n[0].contents[0]=expression[i+1];//If yes it becomes the root operator
			rightPar++;//Holds the count of the No. of Right Parenthesis
		}
	}

	if(leftPar!=rightPar)//For a correct Expression the No. of left and right Pars must be equal
	{
		printf("\n Incorrect Expression!");
		return 0;
	}

	len=length-leftPar*2;//The Length of the Expression without the Parenthesis. Leftpar*2 because the count is same

	for(i=0;i<len;i++)
		//Initializing the Left and Right child fields of nodes with UNDEFINED
		n[i].leftChild=n[i].rightChild=UNDEFINED;
	k=1;

	for(i=0;i<count;i++)
	{
		for(j=0;childExp[i][j]!='\0';j++)
		{
			if(!isalnum(childExp[i][j]))//Pushes Operators into the Nodes
			{
				n[k].contents[0]=childExp[i][j]; 
				n[++k].contents[0]=childExp[i][j-1];//Gets the Previous Operand of the Current Operator
				n[++k].contents[0]=childExp[i][j+1];//Gets the Next Operand
				k++;
				break;
			}
		}
	}

	for(i=1;i<len;i++)
	{
		if(!isalnum(n[i].contents[0])&&n[0].leftChild==UNDEFINED)//Figures out the Childs for all Nodes
		{
			n[0].leftChild=i;
			n[i].leftChild=i+1;
			n[i].rightChild=i+2;
		}
		else if(!isalnum(n[i].contents[0])&&n[0].rightChild==UNDEFINED)
		{	
			n[0].rightChild=i;
			n[i].leftChild=i+1;
			n[i].rightChild=i+2;
		}
	}



	printf("\n Left Child %d \t Right Child %d \n", n[0].leftChild, n[0].rightChild);

	printf("\n Contents of Direced Acyclic Graph : ");
	printf("\n Node \t Value \t Left Child \t Right Child");

	for(i=0;i<len;i++)
	{
		if(isalnum(n[i].contents[0]))
			printf("\n\n   %d \t   %c \t    LEAF \t    LEAF", i, n[i].contents[0]);
		else
			printf("\n\n   %d \t   %c \t    %d \t              %d", i, n[i].contents[0], n[i].leftChild, n[i].rightChild);
	}


	return 0;
}
