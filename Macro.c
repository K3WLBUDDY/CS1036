//© Sruthik P

/*This Code works for Macros containing more than one line of code in them.
 *To make the code even easier you can assume a max Length of 1 for each macro
 *and chuck any Length Variables in the Structure and the rest of the program
 *along with any While and For loops that consider Length
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to Hold details of every Macro
struct macro
{
	char mLabel[10][20], mOpCode[10][20], mOperand[10][20], mName[3];
	int mLength;//Not necessary for Macros of Length One
};

int main()
{
	//File Streams
	FILE *input, *output;
	
	char label[20], opCode[20], operand[20];

	int macroCount=0, i=0,j=0,len=0;

	struct macro m[100];
	input = fopen("Inputs/MacroInput.txt", "r");
	output = fopen("Outputs/MacroOutput.txt", "w");

	
	strcpy(opCode, "NULL");

	/*The Following While Loop scans the Input File and gets Information about the Macros by copying them
	 *into local variables inside the macro Structure
	 */
	
	while(strcmp(opCode, "STOP")!=0)
	{
		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "MACRO")==0)
		{
			len=0;//Not necessary for Macros of Length One

			strcpy(m[macroCount].mName, operand);//Copies Operand of Macro into Structure Member

			while(strcmp(opCode, "MEND")!=0)//While Loop isn't necessary for Macros of Length One
			{

				fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);//Gets input of the lines under Macro
				
				if(strcmp(opCode, "MEND")!=0)//Checks if the copied value isn't an MEND
				{
					strcpy(m[macroCount].mLabel[len], label);//Replace len with 0 for Macros of Length One
					strcpy(m[macroCount].mOpCode[len], opCode);
					strcpy(m[macroCount].mOperand[len], operand);

					len++;//Not necessary for Macros of Length One
				}
				

			}

			m[macroCount].mLength=len;//Not necessary for Macros of Length One
			macroCount++;
		}
	}

	strcpy(opCode, "NULL");
	rewind(input);
	
	/*The Following while loop is concerned with writing to the output file while
	 *replacing any CALL opCode with the Functions of the particular Macro
	 */
	
	while(strcmp(opCode, "STOP")!=0)
	{

		fscanf(input, "%s\t%s\t%s\t\n", label, opCode, operand);

		if(strcmp(opCode, "CALL")==0)//If the current opCode is a CALL opCode
		{
			
			//For loop to iterate through the list of Macros and find a match for the called macro
			for(i=0;i<macroCount;i++)
			{

				if(strcmp(operand, m[i].mName)==0)
				{
					for(j=0; j<m[i].mLength; j++)//For Loop isn't necessary for Macro of Length One
						//Replace j with 0
						fprintf(output, "%s\t%s\t%s\t\n", m[i].mLabel[j], m[i].mOpCode[j], m[i].mOperand[j]);
				}
			}

		}

		else
			fprintf(output, "%s\t%s\t%s\t\n", label, opCode, operand);
	}

	//Always close the bloody streams
	fclose(input);
	fclose(output);

	printf("\n Total No. of Macros : %d", macroCount);

	return 0;
}
