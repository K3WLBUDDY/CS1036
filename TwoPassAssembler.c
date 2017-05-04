//© Sruthik P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *input, *output, *optab, *symbol;
	
	char label[10], mnemonic[5], reg[5], operand[10], regNum[5], locctr[10];

	char sym[10], symAddr[10], mnemAddr[3], mnemInfo[10], symbolAddress[10];

	int count=0;


	input = fopen("Outputs/AssemblerPassOneOutput.txt", "r");
	output = fopen("Outputs/AssemblerPassTwoOutput.txt", "w");
	optab = fopen("Inputs/AssemblerOptab.txt", "r");
	symbol = fopen("Outputs/AssemblerSymbol.txt", "r");

	
	

	strcpy(mnemonic, "NULL");
	strcpy(mnemInfo, "NULL");
	strcpy(operand, "NULL");

	//Complicated While loop condition due to the same mnemonic for START and END
	while(strcmp(operand, "==")!=0 && strcpy(mnemonic, "AD+00")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t%s\t%s\t\n", locctr, label, mnemonic, reg, operand);

		/*strncpy creates a substring from a gives string. The substring is copied
		 *into a char variable. Here mnemonic+2 means the substring to be taken 
		 *starts from the 2nd INDEX (not the 2nd Character) and the 3 is the length
		 *of the substring to be taken. Eg : AD+00 is the input and for the
		 *output to be +00 the Index should be 2 and the length of the string is 3
		 */
		
		strncpy(mnemAddr, mnemonic+2, 3);

		if(strcmp(mnemonic, "AD+01")==0)//Skips the first Line of the Input File
			continue;
		
		if(strcmp(reg, "==")==0)//Sets values for the various registers
			strcpy(regNum, "0");

		else if(strcmp(reg, "AREG")==0)
			strcpy(regNum, "1");

		else if(strcmp(reg, "BREG")==0)
			strcpy(regNum, "2");

		else if(strcmp(reg, "CREG")==0)
			strcpy(regNum, "3");

		else
			strcpy(regNum, "*");

		while(!feof(symbol))//Scans till the end of the Symbol Table
		{
			fscanf(symbol, "%s\t%s\t\n", sym, symbolAddress);

			if(strcmp(sym, operand)==0)
			{
				//Gets the address of the Current Operand from the Symbol Table
				strcpy(symAddr, symbolAddress);	
				break;
			}

			else if(strcmp(mnemonic, "AD+00")==0)
				strcpy(symAddr, "000");

			else 
				strcpy(symAddr, "*");
		}
		rewind(symbol);

		fprintf(output, "%s\t%s\t%s\t%s\t\n", locctr, mnemAddr, regNum, symAddr);

	}

	//Always close the bloody streams
	fclose(input);
	fclose(output);
	fclose(optab);
	fclose(symbol);

	return 0;
}
