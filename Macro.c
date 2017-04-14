#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct macro
{
	char mlabel[10][20], mopCode[10][20], moperand[10][20], mname[3];
	int mlength;
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
			strcpy(m[macroCount].mname, operand);

			printf("\n%s", m[macroCount].mname);
			while(strcmp(opCode, "MEND")!=0)
			{
				fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

				
				if(strcmp(opCode, "MEND")!=0)
				{
					strcpy(m[macroCount].mlabel[len], label);
					strcpy(m[macroCount].mopCode[len], opCode);
					strcpy(m[macroCount].moperand[len], operand);
					len++;
				}
				

			}
			m[macroCount].mlength=len;
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
				if(strcmp(operand, m[i].mname)==0)
				{
					for(j=0; j<m[i].mlength; j++)
					{
						printf("\n %d", m[i].mlength);
						fprintf(output, "%s\t%s\t%s\t\n", m[i].mlabel[j], m[i].mopCode[j], m[i].moperand[j]);
					}
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