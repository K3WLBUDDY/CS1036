//TO-DO - CHECK VALUES OF LOCATION COUNTER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	FILE *ft1, *ft2, *ft3, *ft4; 

	char label[10], opCode[10], symCode[10], reg[4], operand[10], instructionType[2], mnemonicInfo[2];

	int start, locctr=0, length;

	ft1 = fopen("Inputs/input.txt", "r");
	ft2 = fopen("Inputs/symbol.txt", "w");
	ft3 = fopen("Inputs/optab.txt", "r");
	ft4 = fopen("Inputs/output.txt", "w");

	strcpy(opCode, "NULL");
	strcpy(symCode, "NULL");

	while(strcmp(opCode, "END")!=0)
	{
		fscanf(ft1, "%s\t%s\t%s\t%s\t\n", label, opCode, reg, operand);

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
			fprintf(ft2, "%s\t%d\n", label, locctr);
		
		while(strcmp(symCode, opCode)!=0)
		{
			fscanf(ft3, "%s\t%s\t%s\n", symCode, instructionType, mnemonicInfo);
		}

		strcpy(symCode, "NULL");
		rewind(ft3);
		

		fprintf(ft4, "%d\t%s\t%s%s%s\t%s\t%s\t\n", locctr, label, instructionType,"+",mnemonicInfo, reg, operand);
	}

	length = locctr - start;

	printf("\n Length of Pass 1 of 2 Pass Assembler : %d", length);

	fclose(ft1);
	fclose(ft2);
	fclose(ft3);
	fclose(ft4);

	return 0;
}
