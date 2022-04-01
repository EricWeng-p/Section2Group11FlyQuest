#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define CARDNUMSIZE 9
#define FLIGHTROWS 4
#define FLIGHTCOLUMNS 15
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct USER {
	char* firstName;
	char* lastName;
	double cardNumber;
	int cvv;
}USER;

typedef struct FLIGHT {
	char* flightDestination;
	bool oneWay;
	int seatChart[FLIGHTROWS][FLIGHTCOLUMNS];
}FLIGHT;

//USER
int* encryptCardNumber(double d);
double decryptCardNumber(int* num);
char* setFirstName(USER u, char* name);
char* setLastName(USER u, char* name);
char* getFirstName(USER u);
char* getLastName(USER u);//
double setCardNumber(USER u, double d);
double getCardNumber(USER u);//
void setCvv(USER u, int cvv);
int getCvv(USER u);

USER generateUser(char* firstName, char* lastName, double cardNumber, int cvv);
USER generateRandomUser();
USER* removeUser(USER u);

//FLIGHT
char* getDestination(FLIGHT f);
char* setDestination(FLIGHT f, char* destination);
bool getFlightDirection(FLIGHT f);
bool setFlightDirection(FLIGHT f, bool b);

FLIGHT* generateFlight(char* dest, bool way);
FLIGHT* generateRandomFlight(void);
int* generateFlightSeating(void);
FLIGHT* removeFlight(FLIGHT f);
