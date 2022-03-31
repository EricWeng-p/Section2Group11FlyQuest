#include"saveLoad.h"

USER* readUserFile() {
	//open file
	FILE* fp = fopen("text.txt", "r");
	//find size of file
	int size = 1;
	char ch; //buffer
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n') {
			size++;
		}
	}
	size = size / 4;
	printf("%d", size);
	//malloc space
	USER* userArray = (USER*)malloc(sizeof(USER) * size);
	//read file line by line into userArray


	//close file
	fclose(fp);
}
