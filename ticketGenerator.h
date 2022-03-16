
#include <stdio.h>
#define CH_LIMIT 50

//ticket structure
struct TICKET {
	char first_name[CH_LIMIT];
	char last_name[CH_LIMIT];
	char flight_destination[CH_LIMIT];
	char flight_time[CH_LIMIT]; //11:15, 12:30, 18:00 format
	char ticket_ID[CH_LIMIT]; //#FFFFFF hexadec format
	int gate_number;
};

struct TICKET TicketGenerator(USER u, FLIGHT f);
char getHex();
char getTime();
void TicketPrinter(struct TICKET t);