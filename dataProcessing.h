#pragma once
#define CARDNUMSIZE 9
#include<stdbool.h>

typedef struct USER {
	char* firstName;
	char* lastName;
	double cardNumber;
	int cvv;
}USER;

typedef struct FLIGHT {
	char* flightDestination;
	bool oneWay;
}FLIGHT;

int encryptionKey[CARDNUMSIZE] = { 14, 23, 44, 2, 4, 13, 41, 7, 11 };
double* encryptCardNumber(double d);
double decryptCardNumber(double* d);
double setCardNumber(USER u, double d);
double getCardNumber(USER u);


char* setFirstName(USER u, char* name);
char* setLastName(USER u, char* name);
char* getFirstName(USER u);
char* getLastName(USER u);

void setCvv(USER u, int cvv);
int getCvv(USER u);

char* getDestination(FLIGHT f);
char* setDestination(FLIGHT f, char* destination);
bool getFlightDirection(FLIGHT f);
bool setFlightDirection(FLIGHT f, bool b);

FLIGHT* generateFlight();
FLIGHT* generateRandomFlight();
FLIGHT* removeFlight(FLIGHT f);

USER generateRandomUser();
USER generateUser(char* firstName, char* lastName, double cardNumber, int cvv);




