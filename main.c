// C program to Open a File,
// Write in it, And Close the File
#define _CRT_SECURE_NO_WARNINGS
#define MAXNAMESIZE 25

# include <stdio.h>
# include <string.h>

void readUserFile() {
	//open file
	FILE* fp = fopen("text.txt", "r");
	int size = 1;
	char ch; //buffer
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n') {
			size++;
		}
	}
	size = size / 4;
	//find size of file
	printf("%d", size);
	//malloc space

	//read data to arrays

	//close file
	fclose(fp);
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
