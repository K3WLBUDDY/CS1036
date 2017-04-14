#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct macro
{
	char mlabel[20], mopCode[20], moperand[20];
	//int mlength;
};

int main()
{
	FILE *input, *output;
	
	input = fopen("Inputs/MacroInput.txt", "r");
	output = fopen("Outputs/MacroOutput.txt", "w");

	char label[20], opCode[20], operand[20];

	printf("\n Hello2");

	int macroCount=0, i=0;

	printf("\n redsf");

	struct macro m[100];
	
	strcpy(opCode, "NULL");
	printf("%s", opCode);

	while(strcmp(opCode, "STOP")!=0)
	{
		printf("\n WOWOWO %s", opCode);
		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);
		printf("\n Test3");
		printf("\n %s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "MACRO")==0)
		{
			//m[macroCount].mlength=0;
			strcpy(m[macroCount].moperand, operand);
			

			fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);
			printf("\n %s\t%s\t%s\t\n", label, opCode, operand);

			while(strcmp(m[macroCount].mopCode, "MEND")!=0)
			{
				fscanf(input, "%s\t%s\t%s\t\n", m[macroCount].mlabel, m[macroCount].mopCode, m[macroCount].moperand);
				printf("\n %s\t%s\t%s\t\n", m[macroCount].mlabel, m[macroCount].mopCode, m[macroCount].moperand);
			}

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
				if(strcmp(operand, m[i].moperand)==0)
						fprintf(output, "%s\t%s\t%s\t\n", m[i].mlabel, m[i].mopCode, m[i].moperand);
					else
						printf("\n\n %d %s", i,m[i].moperand);
			}

		}

		else
			fprintf(output, "%s\t%s\t%s\t\n", label, opCode, operand);
	}

	fclose(input);
	fclose(output);

	return 0;
}