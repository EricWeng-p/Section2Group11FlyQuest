#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define CH_LIMIT 50

//ticket structure
typedef struct TICKET {
	char first_name[CH_LIMIT];
	char last_name[CH_LIMIT];
	char flight_destination[CH_LIMIT];
	char flight_time[CH_LIMIT]; //11:15, 12:30, 18:00 format
	char ticket_ID[CH_LIMIT]; //#FFFFFF hexadec format
	int gate_number;
}TICKET;

//struct TICKET TicketGenerator(USER u, FLIGHT f); //requires user struct and flight struct
TICKET tempTicketGenerator();
char getHex();
char getTime();
void getTicket(TICKET t);
void ticketPrinter(TICKET t);