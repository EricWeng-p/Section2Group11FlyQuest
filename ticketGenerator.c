int minutes = 15 * (rand() % 4);  //0-3*15 = 00, 15, 30, 45
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


//save ticket image to file