#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ticketGenerator.h"
#define CH_LIMIT 50

//Random Number Generator
srand(time(NULL));


//Assign relevant user and flight information, assign random variables for ticket
struct TICKET TicketGenerator (USER u, FLIGHT f) {
	struct TICKET t;
	//!!integrate user and flight variables!!
	strcpy(t.first_name, u.first_name);
	strcpy(t.last_name, u.last_name);
	strcpy(t.flight_destination, f.flight_destination);
	strcpy(t.ticket_ID, getHex());
	t.gate_number = (rand() % 12) + 1; 	
	strcpy(t.flight_time, getTime());
}

char getHex() {
	int h1, h2, h3;
	char hex;
	h1 = rand() % 255;
	h2 = rand() % 255;
	h3 = rand() % 255;
	hex = ("%d%d%d", h1, h2, h3);
}

char getTime() {
	int hour = rand() % 24; //00-23
	int minutes = 15 * (rand()%4);  //0-3*15 = 00, 15, 30, 45
	char time; //12:45, 00:00, 18:30

	if (hour == 0 && minutes == 0)
		time = ("00:00");

	else if (hour == 0)
		time = ("00:%d", minutes);

	else if (time == 0)
		time = ("%d:00", hour);
	else
	time = ("%d:%d\n", hour, minutes);

	return time;
}
//Ticket Printer
/*
____________________________________________________________
| FlyQuest													|
| FLIGHT: A3B6C7   BOARDING TIME: 11:15    GATE: 12			|
|															|
| PASSENGER NAME: JOHN / DOE								|
| FROM: TORONTO		TO: NEW YORK							|
|															|
|___________________________________________________________|
*/
void ticketPrinter(struct TICKET t) { //need to align properly
	printf("_________________________________________\n");
	printf("| FlyQuest\n");
	printf("| FLIGHT: %c", t.ticket_ID);
	printf("   BOARDING TIME: %c", t.flight_time);
	printf("   GATE: %d", t.gate_number);
	printf("\n \n PASSENGER NAME: %c / %c", t.first_name, t.last_name);
	printf("TO: %c", t.flight_destination);
	printf("\n \n|__________________________________________|\n");
}