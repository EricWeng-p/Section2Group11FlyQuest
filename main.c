
#include <stdio.h>
#include <string.h>
#include "ticketGenerator.h"

int main(void) {
	TICKET t;
	srand(time(NULL));
	printf("%d\n", getGate());
	printf("%s", getTime());
	printf("%s", getHex());
	t = tempTicketGenerator();
	getTicket(t);
	ticketPrinter(t);

}