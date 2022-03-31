#pragma once
#include"dataProcessing.h"
//listsize
static int userListSize, flightListSize;
void setUserListSize(int s);
int getUserListSize();
void setFlightListSize(int s);
int getFlightListSize();
//user
USER* loadUserListFromFile();
void saveUserListToFile(USER* u);
void printUserList(USER* u);
//flight
FLIGHT* loadFlightListFromFile();
void saveFlightListToFile(FLIGHT* f);
void printFlightList(FLIGHT* f);
