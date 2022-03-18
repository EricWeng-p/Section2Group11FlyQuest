#include"dataProcessing.h"

int encryptionKey[CARDNUMSIZE] = { 3, 2, 5, 3, 6, 5, 3, 5, 6};
//cardNumber
int* encryptCardNumber(double d) {
	//convert d into a string array
	char* arr = malloc(10); //cardnumsize + 1
	snprintf(arr, 10, "%f", d);
	int* numArr = malloc(CARDNUMSIZE);
	for (int i = 0; i < CARDNUMSIZE; i++) {
		numArr[i] = (arr[i] - '0');
		printf("%d/", numArr[i]); //test
	}
	printf("\n"); //test
	for (int i = 0; i < CARDNUMSIZE; i++) {
		numArr[i] = numArr[i] << encryptionKey[i]; //bit shift each value left based on encryption key
		printf("%d/", numArr[i]); //test
	}
	printf("\n"); //test
	free(arr);
	return numArr;
}
double decryptCardNumber(int* num) {
	int numArr[CARDNUMSIZE];
	for (int i = 0; i < CARDNUMSIZE; i++) {
		numArr[i] = *(num + i);
		printf("%d/", numArr[i]); //test
	}
	printf("\n"); //test
	for (int i = 0; i < CARDNUMSIZE; i++) {
		numArr[i] = numArr[i] >> encryptionKey[i];
		printf("%d/", numArr[i]); //test
	}
	printf("\n"); //test
	return 2;
}
double setCardNumber(USER u, double d) {
	return u.cardNumber = d;
}
double getCardNumber(USER u) {
	return u.cardNumber;
}


char* setFirstName(USER u, char* name) {
	return u.firstName = name;
}
char* setLastName(USER u, char* name) {
	return u.lastName = name;
}
char* getFirstName(USER u) {
	return u.firstName;
}
char* getLastName(USER u) {
	return u.lastName;
}
void setCvv(USER u, int cvv) {
	u.cvv = cvv;
}
int getCvv(USER u) {
	return u.cvv;
}

char* getDestination(FLIGHT f) {
	return f.flightDestination;
}
char* setDestination(FLIGHT f, char* destination) {
	return f.flightDestination = destination;
}
bool getFlightDirection(FLIGHT f) {
	return f.oneWay;
}
bool setFlightDirection(FLIGHT f, bool b) {
	return f.oneWay = b;
}

FLIGHT* generateRandomFlight() {
	//use text file data to generate a random flight
}
//may be unused but would generate flight with null values
FLIGHT* generateBlankFlight() {

}
//generate flight manually
FLIGHT* generateFlight(char* dest, bool way) {
	FLIGHT f = { dest, way };
	return &f;
}
FLIGHT* removeFlight(FLIGHT f) {
	//f.flightDestination = NULL;
	//f.oneWay = NULL;
	return &f;
}
//for testing
USER generateRandomUser() {
	//use text file to store list of names to choose from at random

}
//generate user manually
USER generateUser(char* firstName, char* lastName, double cardNumber, int cvv) {
	USER u = { firstName, lastName, cardNumber, cvv };
	return u;
}