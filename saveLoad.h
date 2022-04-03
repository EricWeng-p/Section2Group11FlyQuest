#pragma once
#include"dataProcessing.h"
//listsize
static int userListSize = 0, flightListSize = 0;
void setUserListSize(int s);
int getUserListSize();
void setFlightListSize(int s);
int getFlightListSize();
void decrementFlightListSize();
void decrementUserListSize();
void incrementFlightListSize();
void incrementUserListSize();
//user
USER* loadUserListFromFile();
void saveUserListToFile(USER* u);
void printUserList(USER* u);
USER* addToUserList(USER u, USER* listPtr);
//flight
FLIGHT* loadFlightListFromFile();
void saveFlightListToFile(FLIGHT* f);
void printFlightList(FLIGHT* f);
FLIGHT* addToFlightList(FLIGHT f, FLIGHT* flightPtr);
