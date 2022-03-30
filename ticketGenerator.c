#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "ticketGenerator.h"
//Assign relevant user and flight information, assign random variables for ticket
//!!integrate user and flight variables!!
/*
struct TICKET TicketGenerator(USER u, FLIGHT f) {
	struct TICKET t;

	strcpy(t.first_name, u.first_name);
	strcpy(t.last_name, u.last_name);
	strcpy(t.flight_destination, f.flight_destination);
	strcpy(t.ticket_ID, getHex());
	t.gate_number = (rand() % 12) + 1;
	strcpy(t.flight_time, getTime());
}
*/
TICKET tempTicketGenerator() {
	TICKET t = { "John", "Doe", "Toronto", getHex(), getGate(), getTime() };
	strcpy(t.first_name, "John");
	strcpy(t.last_name, "Doe");
	strcpy(t.flight_destination, "Toronto");
	strcpy(t.ticket_ID, getHex());
	t.gate_number = getGate();
	strcpy(t.flight_time, getTime());

	return t;
}

void getTicket(TICKET t) {
	printf("First name: %s\n", t.first_name);
	printf("Last name: %s\n", t.last_name);
	printf("Flight destination: %s\n", t.flight_destination);
	printf("Ticket ID: %s\n", t.ticket_ID);
	printf("Gate Number: %d\n", t.gate_number);
	printf("Flight time: %s\n", t.flight_time);
}

int getGate() {
	int gateNum = (rand() % 12) + 1;
	return gateNum;
}

char* getHex() {
	int h1, h2, h3;
	static char hex[CH_LIMIT];

	h1 = rand() % 255;
	h2 = rand() % 255;
	h3 = rand() % 255;
	sprintf (hex, "%x%x%x", h1, h2, h3);
	return hex;
}

char* getTime() {
	int hour = rand() % 24; //00-23
	int minutes = 15 * (rand() % 4);  //0-3*15 = 00, 15, 30, 45
	static char time[CH_LIMIT]; //12:45, 00:00, 18:30
	
	sprintf(time, "%02d:%02d", hour, minutes);
	
	return time;
}	
//Ticket Printer
/* sample
____________________________________________________________
| FlyQuest													|
| FLIGHT: A3B6C7   BOARDING TIME: 11:15    GATE: 12			|
|															|
| PASSENGER NAME: JOHN / DOE								|
| FROM: TORONTO		TO: NEW YORK							|
|															|
|___________________________________________________________|
*/
void ticketPrinter(TICKET t) { //need to align properly
	//":%-15s\n"
	printf("_________________________________________________________\n");
	printf("| FlyQuest								 |\n");
	printf(" | FLIGHT: % s", t.ticket_ID);
	printf(" BOARDING TIME : % s", t.flight_time);
	printf(" GATE: % d | ", t.gate_number);
	printf("\n | \n PASSENGER NAME : % s / % s		", t.first_name, t.last_name);
	printf("TO: %s			|", t.flight_destination);
	printf("\n| \n|_________________________________________________|\n");
}


//save ticket image to file
//call SavetoFile(ticket t);