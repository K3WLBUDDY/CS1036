#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct macro
{
	char label[5], opCode[5], operand[5];
	int length;
};


int main()
{
	FILE *input, *output;

	struct macro m[10];

	int macroCount = 0, i=0;

	char label[2], opCode[10], operand[10];

	input = fopen("Inputs/MacroInput.txt");
	output = fopen("Outputs/MacroOutput.txt");

	strcpy(opCode, "NULL");

	while(strcmp(opCode, "STOP")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "MACRO")==0)
		{
			while((opCode, "MEND")!=0)
			{
				m[macroCount].label[i] = label;
				m[macroCount].opCode[i] = opCode;
				m[macroCount].operand[i] = operand;
				i++;

				fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);
			}
			m[macroCount].length = i;
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
					for(j=0;j<m[i].length,j++)
						while(strcmp(m[i].operand[j], "MACRO")!=0 && strcmp(m[i].operand[j], "MEND"))
			}
		}
	}




}