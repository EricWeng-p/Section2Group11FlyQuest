// C program to Open a File,
// Write in it, And Close the File
#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>
# include <string.h>

void filewrite(char fname, char lname, double cardnumber, int cvv)
{
	FILE* filePointer;

	filePointer = fopen("Test.txt", "w");
	if (filePointer == NULL)
	{
		printf("Test.txt file failed to open.");
	}
	else
	{

		printf("The file is now opened.\n");


		fprintf(filePointer, "%c \n", fname);
		fprintf(filePointer, "%c \n", lname);
		fprintf(filePointer, "%lf \n", cardnumber);
		fprintf(filePointer, "%d \n", cvv);


		fclose(filePointer);

		printf("Data successfully written in file Test.txt\n");
		printf("The file is now closed.");
	}
}

void fileread(char fname, char lname, double cardnumber, int cvv)
{

	char firstname = { 0 };

	FILE* filePointer;

	filePointer = fopen("Test.txt", "r");

	if (filePointer == NULL)
	{
		printf("Test.txt file failed to open.");
	}
	else
	{
		printf("The file is now opened.\n");

		fscanf(filePointer, "%c %c %lf %d", &fname, &lname, &cardnumber, &cvv);
		printf("%c \n", fname);
		printf("%c \n", lname);
		printf("%lf \n", cardnumber);
		printf("%d \n", cvv);

		fclose(filePointer);

		printf("Data successfully read from file Test.txt\n");
		printf("The file is now closed.");
	}
}





void main()
{
	char fname = 'S';
	char lname = 'A';
	double cardnumber = 17;
	int cvv = 101;

	filewrite(fname, lname, cardnumber, cvv);
	fileread(fname, lname, cardnumber, cvv);

}
