//© Sruthik P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	//File Streams
	FILE *input, *output, *symbol, *optab; 

	char label[10], opCode[10], symCode[10], reg[4], operand[10], instructionType[2], mnemonicInfo[2];

	int start, locctr=0, length;

	input = fopen("Inputs/AssemblerInput.txt", "r");//R for reading i.e Input files
	symbol = fopen("Outputs/AssemblerSymbol.txt", "w");//W for writing i.e output files
	optab = fopen("Inputs/AssemblerOptab.txt", "r");
	output = fopen("Outputs/AssemblerPassOneOutput.txt", "w");

	//Pre Defining Variables needed for comparision in while Loops
	strcpy(opCode, "NULL");
	strcpy(symCode, "NULL");

	while(strcmp(opCode, "END")!=0)//Read till Opcode not END
	{
		fscanf(input, "%s\t%s\t%s\t%s\t\n", label, opCode, reg, operand);

		if(strcmp(opCode, "START")==0)
		{	
			//Gets Starting address and converts it to an integer.
			start = atoi(operand);
			locctr = start;
		}

		else if(strcmp(opCode, "DC")==0)
			//Increments the Location Counter by the value specified in the Operand for DC Instruction
			locctr+= atoi(operand);

		else
			locctr+=1;

		//If Label Field is not Empty print Label Info in Symbol Table
		if(strcmp(label, "**")!=0)
			fprintf(symbol, "%s\t%d\n", label, locctr);
		
		//Scan the OpCode Table till the Opcode and the Scanned Opcode from the OpTab match 
		while(strcmp(symCode, opCode)!=0)
		{
			fscanf(optab, "%s\t%s\t%s\n", symCode, instructionType, mnemonicInfo);
		}

		strcpy(symCode, "NULL");//Copy NULL again because it will be used for comparision again
		rewind(optab);//Places the File Pointer at the beginning of the File
		
		//Print to the Output File
		fprintf(output, "%d\t%s\t%s%s%s\t%s\t%s\t\n", locctr, label, instructionType,"+",mnemonicInfo, reg, operand);
	}

	length = locctr - start;//Calculates the Length of the generated Output File

	printf("\n Length of Pass 1 of 2 Pass Assembler : %d", length);

	//Always close your bloody streams
	fclose(input);
	fclose(symbol);
	fclose(optab);
	fclose(output);

	return 0;
}
