#pragma once
#define CARDNUMSIZE 9
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

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
