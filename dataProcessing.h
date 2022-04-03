#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define CARDNUMSIZE 9
#define FLIGHTROWS 4
#define FLIGHTCOLUMNS 15
#define NAMESIZE 25
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct USER {
	char firstName[NAMESIZE];
	char lastName[NAMESIZE];
	double cardNumber;
	int cvv;
}USER;

typedef struct FLIGHT {
	char flightDestination[NAMESIZE];
	char oneWay;
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
char getFlightDirection(FLIGHT f);
char setFlightDirection(FLIGHT f, char c);

FLIGHT* generateFlight(char dest[NAMESIZE], char way);
FLIGHT* generateRandomFlight(void);
int* generateFlightSeating(void);
FLIGHT* removeFlight(FLIGHT f);
