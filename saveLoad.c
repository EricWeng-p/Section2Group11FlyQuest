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
void decrementFlightListSize() {
	setFlightListSize(getFlightListSize() - 1);
}
void incrementFlightListSize() {
	setFlightListSize(getFlightListSize() + 1);
}
void decrementUserListSize() {
	setUserListSize(getUserListSize() - 1);
}
void incrementUserListSize() {
	setUserListSize(getUserListSize() - 1);
}
//user list functions
USER* loadUserListFromFile() {
	//open file
	FILE* fp = fopen("userList.txt", "r");
	//find size of file
	int size = 4;
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
	USER* userArray = (USER*)malloc(sizeof(USER) * size);

	if (userArray != NULL) {
		fseek(fp, 0, SEEK_SET);
		char buffer[NAMESIZE];
		int count = 1, maxCount = 4, userCount = -1;
		while (fgets(buffer, NAMESIZE, fp)) {
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
	fclose(fp);
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
	//open file
	FILE* fp = fopen("flightList.txt", "r");
	//find size of file
	int size = 2;
	char ch; //buffer
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n') {
			size++;
		}
	}
	size = size / 2;
	setFlightListSize(size);
	//malloc space
	FLIGHT* flightArray = (FLIGHT*)malloc(sizeof(FLIGHT) * size);
	if (flightArray != NULL) {
		fseek(fp, 0, SEEK_SET);
		char buffer[NAMESIZE];
		int count = 1, flightCount = -1;
		while (fgets(buffer, NAMESIZE, fp)) {
			//printf("%s", buffer); //testing
			flightCount++;
			switch (count) {
			case 1:
				
				strncpy((flightArray + flightCount)->flightDestination, buffer, NAMESIZE);
				count++;
				break;
			case 2:
				(flightArray + flightCount)->oneWay = buffer;
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
	fclose(fp);
	return flightArray;
}

void saveFlightListToFile(FLIGHT* f) {
	FILE* fp = fopen("flightList.txt", "w");
	for (int i = 0; i < getFlightListSize(); i++) {
		fprintf(fp, "%s%d\n", (f + i)->flightDestination, (f + i)->oneWay);
	}
	fclose(fp);
}

void printFlightList(FLIGHT* f) {
	int count = 0;
	for (int i = 0; i < getFlightListSize(); i++) {
		printf("%s%c\n", (f + count)->flightDestination, (f + count)->oneWay);
		count++;
	}
}

FLIGHT* addToFlightList(FLIGHT f, FLIGHT* flightPtr) {
	if (!getFlightListSize()) { //0
		setFlightListSize(1);
	}
	else {
		incrementFlightListSize();
	}
	FLIGHT* newFlt = (FLIGHT*)realloc(flightPtr, (sizeof(FLIGHT) * getFlightListSize()));
	printf("%d", getFlightListSize());
	strncpy((newFlt + (getFlightListSize() - 1))->flightDestination, f.flightDestination, NAMESIZE);
	(newFlt + getFlightListSize() - 1)->oneWay = f.oneWay;
	
	return newFlt;
}
void addToUserList(USER u, USER* listPtr, int listSize) { //using list pointer and list size, realloc listptr to accomodate extra user then add u to list
	//need save/load functions
}
