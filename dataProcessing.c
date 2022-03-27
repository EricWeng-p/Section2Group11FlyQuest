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

//USER set/get
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

//FLIGHT set/get
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
int* getFlightSeating(FLIGHT f) {
	return f.seatChart;
}
//defining this function but our program should never need it
void setFlightSeating(FLIGHT f, int* seatChart) {

}

//generate FLIGHT datatype
//generate array for seating //must be done first
int* generateFlightSeating() {
	//set rand seed
	time_t = t;
	int seating[FLIGHTROWS][FLIGHTCOLUMNS];
	int* seatingPtr = (int)malloc(sizeof(seating)); //should be free'd later in program
	for (int i = FLIGHTROWS; i < FLIGHTROWS; i++) {
		for (int p = FLIGHTCOLUMNS; i < FLIGHTCOLUMNS; p++) {
			srand(time(&t));
			if ((rand() % 1) == 0) {
				seating[i][p] = 0;
			}
			else {
				seating[i][p] = 1;
			}
		}
	}
	return seatingPtr;
}
//print seating chart to screen
void printSeating(int* seating) {
	printf("Empty seats: 0\nTaken seats: 1");
	for (int i = 0; i < FLIGHTROWS; i++) {
		printf("\n")
			for (int p = 0; p < FLIGHTCOLUMNS; p++) {
				printf(" %d ", seating[i][p]);
			}
	}
}

//generate manually
FLIGHT* generateFlight(char* dest, bool way) {
	int* seatChart = generateFlightSeating();
	FLIGHT f = { dest, way, seatChart };
	return &f;
}
FLIGHT* generateRandomFlight() {
	//use text file data to generate a random flight
}
//may be unused but would generate flight with null values
FLIGHT* generateBlankFlight() {

}

FLIGHT* removeFlight(FLIGHT f) { //need save/load functions
	f.flightDestination = NULL;
	f.oneWay = NULL;
	free(f.seatChart);

	//remove from flight list (need save/load)
	//decrement flight list size
	return &f;
}

//generate user functions
//generate user manually
USER generateUser(char* firstName, char* lastName, double cardNumber, int cvv) {
	USER u = { firstName, lastName, cardNumber, cvv };
	return u;
}
//for testing
USER generateRandomUser() {
	//use text file to store list of names to choose from at random

}
void addToUserList(USER u, USER listPtr, int listSize){ //using list pointer and list size, realloc listptr to accomodate extra user then add u to list
	//need save/load functions
}
USER* removeUser(USER u) { //realloc list ptr to be 1 user smaller
	u.firstName = NULL;
	u.lastName = NULL;
	u.cardNumber = NULL;
	u.cvv = NULL;
	//remove from user list(save/load)
	return &u;
}
