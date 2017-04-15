#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *input, *output, *optab, *symbol;

	input = fopen("Outputs/AssemblerPassOneOutput.txt", "r");
	output = fopen("Outputs/AssemblerPassTwoOutput.txt", "w");
	optab = fopen("Inputs/AssemblerOptab.txt", "r");
	symbol = fopen("Outputs/AssemblerSymbol.txt", "r");

	char label[10], mnemonic[5], reg[5], operand[10], regNum[5], locctr[10];

	char sym[10], symAddr[10], mnemAddr[3], mnemInfo[10], symbolAddress[10];

	int count=0;

	

	strcpy(mnemonic, "NULL");
	strcpy(mnemInfo, "NULL");
	strcpy(operand, "NULL");

	while(strcmp(operand, "==")!=0 && strcpy(mnemonic, "AD+00")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t%s\t%s\t\n", locctr, label, mnemonic, reg, operand);

		strncpy(mnemAddr, mnemonic+2, 3);

		if(strcmp(mnemonic, "AD+01")==0)
			continue;
		
		if(strcmp(reg, "==")==0)
			strcpy(regNum, "0");

		else if(strcmp(reg, "AREG")==0)
			strcpy(regNum, "1");

		else if(strcmp(reg, "BREG")==0)
			strcpy(regNum, "2");

		else if(strcmp(reg, "CREG")==0)
			strcpy(regNum, "3");

		else
			strcpy(regNum, "*");

		while(!feof(symbol))
		{
			fscanf(symbol, "%s\t%s\t\n", sym, symbolAddress);
			printf("\n %s\t%s\t\n", sym, symbolAddress);

			if(strcmp(sym, operand)==0)
			{
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

	fclose(input);
	fclose(output);
	fclose(optab);
	fclose(symbol);

	return 0;
}