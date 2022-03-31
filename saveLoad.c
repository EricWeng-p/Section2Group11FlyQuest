#include"saveLoad.h"
//list size functions
int getUserListSize() {
	return userListSize;
}
int getFlightListSize() {
	return flightListSize;
}
void setUserListSize(int s) {
	userListSize = s;
}
void setFlightListSize(int s) {
	flightListSize = s;
}

//user list functions
USER* loadUserListFromFile() {
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
	setUserListSize(size);
	//malloc space
	if (USER* userArray = (USER*)malloc(sizeof(USER) * size) != NULL) {
		//read file line by line into tempArray
		fseek(fp, 0, SEEK_SET);
		char buffer[NAMESIZE];
		char count = 1, userCount = -1;
		while (fgets(buffer, 25, fp)) {
			//	printf("%s", buffer); //testing
			switch (count) {
			case 1:
				userCount++;
				strncpy((userArray + userCount)->firstName, buffer, NAMESIZE);
				count++;
				break;
			case 2:
				strncpy((userArray + userCount)->lastName, buffer, NAMESIZE);
				count++;
				break;
			case 3:
				(userArray + userCount)->cardNumber = atoi(buffer);
				count++;
				break;
			case 4:
				(userArray + userCount)->cvv = atoi(buffer);
				count = 1;
				break;
			default:
				count++;
				break;
			}
		}
	}
	else {
		printf("Memory allocation failed... exiting program");
		fclose(fp);
		exit(0);
	}
	
	//close file
	fclose(fp);
	//return array ptr
	return userArray;
}

void saveUserListToFile(USER* u) {
	FILE* fp = fopen("userList.txt", "w");
	for (int i = 0; i < getUserListSize(); i++) {
		fprintf(fp, "%s%s%f\n%d\n", (u + i)->firstName, (u + i)->lastName, (u + i)->cardNumber, (u + i)->cvv);
	}
	fclose(fp);
}

void printUserList(USER* u) {
	int count = 0;
	for (int i = 0; i < getUserListSize(); i++) {
		printf("%s%s%f\n%d\n", (u + count)->firstName, (u + count)->lastName, (u + count)->cardNumber, (u + count)->cvv); //%.0f causes program timeout
		count++;
	}
}

//flight list functions
FLIGHT* loadFlightListFromFile() {
	FLIGHT* f;
	return f;
}
void saveFlightListToFile(FLIGHT* f) {

}
void printFlightList(FLIGHT* f) {

}