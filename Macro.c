#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct macro
{
	char label[10][2], opCode[10][10], operand[10][10];
	int length;
};

int main()
{
	FILE *input, *output;

	printf("\n Hello");

	char label[2], opCode[10], operand[10];

	int macroCount=0, i=0,j=0;

	struct macro m[10];

	input = fopen("Inputs/MacroInput.txt", "r");
	output = fopen("Outputs/MacroOutput.txt", "w");

	strcpy(opCode, "NULL");

	while(strcmp(opCode, "STOP")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "MACRO")==0)
		{
			m[macroCount].length=0;
			strcpy(m[macroCount].operand[m[macroCount].length], operand);
			

			fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

			while(strcmp(opCode, "MEND")!=0)
			{
				fscanf(input, "%s\t%s\t%s\t\n", m[macroCount].label[m[macroCount].length], m[macroCount].opCode[m[macroCount].length], m[macroCount].operand[m[macroCount].length]);
				m[macroCount].length++;
			}

			macroCount++;
		}
	}

	strcpy(opCode, "NULL");

	while(strcmp(opCode, "STOP")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "CALL")==0)
		{

			for(i=0;i<macroCount;i++)
			{
				if(strcmp(operand, m[i].operand[0])==0)
					for(j=0;j<m[i].length;j++)
						fprintf(output, "%s\t%s\t%s\t\n", m[i].label[j], m[i].opCode[j], m[i].operand[j]);
			}

		}

		else
			fprintf(output, "%s\t%s\t%s\t\n", label, opCode, operand);
	}

	fclose(input);
	fclose(output);
}