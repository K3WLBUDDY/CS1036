#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct macro
{
	char mLabel[10][20], mOpCode[10][20], mOperand[10][20], mName[3];
	int mLength;
};

int main()
{
	FILE *input, *output;
	
	input = fopen("Inputs/MacroInput.txt", "r");
	output = fopen("Outputs/MacroOutput.txt", "w");

	char label[20], opCode[20], operand[20];

	int macroCount=0, i=0,j=0,len=0;

	struct macro m[100];
	
	strcpy(opCode, "NULL");

	while(strcmp(opCode, "STOP")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "MACRO")==0)
		{
			len=0;

			strcpy(m[macroCount].mName, operand);

			while(strcmp(opCode, "MEND")!=0)
			{

				fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);
				
				if(strcmp(opCode, "MEND")!=0)
				{
					strcpy(m[macroCount].mLabel[len], label);
					strcpy(m[macroCount].mOpCode[len], opCode);
					strcpy(m[macroCount].mOperand[len], operand);

					len++;
				}
				

			}

			m[macroCount].mLength=len;
			macroCount++;
		}
	}

	strcpy(opCode, "NULL");
	rewind(input);

	while(strcmp(opCode, "STOP")!=0)
	{

		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "CALL")==0)
		{

			for(i=0;i<macroCount;i++)
			{

				if(strcmp(operand, m[i].mName)==0)
				{
					for(j=0; j<m[i].mLength; j++)
						fprintf(output, "%s\t%s\t%s\t\n", m[i].mLabel[j], m[i].mOpCode[j], m[i].mOperand[j]);
				}
			}

		}

		else
			fprintf(output, "%s\t%s\t%s\t\n", label, opCode, operand);
	}

	fclose(input);
	fclose(output);

	printf("\n Total No. of Macros : %d", macroCount);

	return 0;
}