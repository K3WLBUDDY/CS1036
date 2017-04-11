#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *input, *symbol, *optab, *output;

	char label[10], opCode[10], symCode[10], reg[4], operand[10], instructionType[2], mnemonicInfo[2];

	int start, locctr, length;

	input = fopen("Inputs/input.txt", "r");
	symbol = fopen("Inputs/symbol.txt", "w");
	optab = fopen("Inputs/optab.txt", "r");
	output = fopen("Inputs/output.txt", "w");

	locctr = 0;
	strcpy(opcode, "NULL");
	strcpy(symCode, "NULL");
	while(strcmp(opCode, "END"!=0))
	{
		fscanf("%s\t%s\t%s\t%s\t\n", label, opCode, reg, operand);

		if(strcmp(opCode, "START")==0)
			locctr=atoi(operand);

		if(strcmp(opCode, "DS")==0)
			locctr+=1;	

		if(strcmp(opCode, "DC")==0)
			locctr = atoi(operand);

		if(strcmp(label, "**")!=0)
			fprintf(symbol, "%s\t%d\n", label, locctr);

		while(strcmp(symCode, opCode)!=0)
			fscanf(optab, "%s\t%s\t%d\n", symCode, instructionType, mnemonicInfo);

		locctr++;

		fprintf(input, "%d\t%s\t%s\t%s\t%s\t\n", locctr, label, instructionType+mnemonicInfo, reg, operand);
	}

	length = locctr - start;

	printf("\n Length of Pass 1 of 2 Pass Assembler : %d", length);

	fclose(input);
	fclose(symbol);
	fclose(optab);
	fclose(output);

	return 0;
}
