//© Sruthik P, Uma

/*This isn't a sophisticated Text Editor like Emacs or Vim
 *or Notepad so don't input strings with spaces.
 */

/*The inbuilt function perror() provides information about
 *file operations such as Error Messages related to Opening
 *and closing files
 */

#include<stdio.h>

void read(char fileName[100])
{
	FILE* s=fopen(fileName, "r");
	char buffer[100];

	if(s==NULL)
		perror("Error Opening File : ");
	else
	{
		fscanf(s, "%s", buffer);
		printf("\n Contents of File : %s", buffer);
	}

	fclose(s);
}

void write(char fileName[100])
{
	int buffer[100];
	FILE* s=fopen(fileName, "w");

	if(s==NULL)
		perror("Error Writing to File : ");
	else
		{
			printf("\n Enter the Contents to be written : ");
			scanf("%s", buffer);
			fprintf(s, "%s", buffer);
		}

	fclose(s);
}

void create(char fileName[100])
{
	FILE* s=fopen(fileName, "w");

	if(s==NULL)
		perror("Error Creating File : ");
	else
		printf("\n File %s created Successfully", fileName);

	fclose(s);
}

void deleteFile(char fileName[100])
{
	int i = remove(fileName);

	if(i==0)
		printf("\n File %s Deleted Successfully", fileName);
	else
		printf("\n Error 404! File not Found");
}

int main()
{
	char input[100];
	int option;

	do
	{
		printf("\n\n\t TEXT EDITOR \n");
		printf("\n 1. Create File\n");
		printf("\n 2. Write to File\n");
		printf("\n 3. Read from File\n");
		printf("\n 4. Delete File\n");
		printf("\n 5. Exit\n");
		printf("\n Select your choice : ");
		scanf("%d",&option);

		switch(option)
		{
			case 1:
				printf("\n Enter Name of File to be Created : ");
				scanf("%s", input);
				create(input);
				break;

			case 2:
				printf("\n Enter Name of File to Write to : ");
				scanf("%s", input);
				write(input);
				break;

			case 3:
				printf("\n Enter Name of File to be Read from : ");
				scanf("%s", input);
				read(input);
				break;

			case 4:
				printf("\n Enter the Name of File to be Deleted : ");
				scanf("%s", input);
				deleteFile(input);
				break;

			case 5:
				break;

			default:
				printf("\n Wrong Choice. Check input again!");

		}

	}
	while(option!=5);

	return 0;

}