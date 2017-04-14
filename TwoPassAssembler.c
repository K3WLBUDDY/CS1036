#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *input, *output, *optab, *symbol;

	input = fopen("Outputs/AssemblerPassOneOutput.txt", "r");
	output = fopen("Outputs/AssemblerPassTwoOutput.txt", "w");
	optab = fopen("Inputs/AssemblerOptab.txt", "r");
	symbol = fopen("Outputs/AssemblerSymbol.txt");

	
}