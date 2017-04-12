//TO-DO - CHECK VALUES OF LOCATION COUNTER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	FILE *input, *output, *symbol, *optab; 

	char label[10], opCode[10], symCode[10], reg[4], operand[10], instructionType[2], mnemonicInfo[2];

	int start, locctr=0, length;

	input = fopen("Inputs/AssemblerInput.txt", "r");
	symbol = fopen("Outputs/AssemblerSymbol.txt", "w");
	optab = fopen("Inputs/AssemblerOptab.txt", "r");
	output = fopen("Outputs/AssemblerPassOneOutput.txt", "w");

	strcpy(opCode, "NULL");
	strcpy(symCode, "NULL");

	while(strcmp(opCode, "END")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t%s\t\n", label, opCode, reg, operand);

		if(strcmp(opCode, "START")==0)
		{	
			start = atoi(operand);
			locctr = start;
		}

		else if(strcmp(opCode, "DS")==0)
			locctr+=1;	

		else if(strcmp(opCode, "DC")==0)
			locctr+= atoi(operand);

		else
			locctr+=1;

		if(strcmp(label, "**")!=0)
			fprintf(symbol, "%s\t%d\n", label, locctr);
		
		while(strcmp(symCode, opCode)!=0)
		{
			fscanf(optab, "%s\t%s\t%s\n", symCode, instructionType, mnemonicInfo);
		}

		strcpy(symCode, "NULL");
		rewind(optab);
		

		fprintf(output, "%d\t%s\t%s%s%s\t%s\t%s\t\n", locctr, label, instructionType,"+",mnemonicInfo, reg, operand);
	}

	length = locctr - start;

	printf("\n Length of Pass 1 of 2 Pass Assembler : %d", length);

	fclose(input);
	fclose(symbol);
	fclose(optab);
	fclose(output);

	return 0;
}
