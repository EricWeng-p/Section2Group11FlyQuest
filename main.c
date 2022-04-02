#include"dataProcessing.h"
#include"saveLoad.h"
int main(int argc, char* argv[])
{
	if (argc == 2)
		printf("argument given: \n");
	else if (argc > 2)
		printf("too many arguments supplied\n");
	else
		printf("no argument given\n");


	FLIGHT* flightlist[2];
	flightlist[0] = generateFlight("London", true);
	flightlist[1] = generateFlight("Paris", false);

	saveFlightListToFile(flightlist);
	printFlightList(flightlist);
	loadFlightListFromFile();

	USER userlist[2];
	userlist[0] = generateUser("John", "Doe", 12345678, 321);
	userlist[1] = generateUser("Jane", "Doe", 87654321, 123);

	saveUserListToFile(userlist);
	printUserList(userlist);
	loadUserListFromFile();
}
