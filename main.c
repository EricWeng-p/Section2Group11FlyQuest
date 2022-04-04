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



	USER* userList = loadUserListFromFile(); //working
	FLIGHT* flightList = loadFlightListFromFile(); //working

	//printUserList(userList); //working
	//printFlightList(flightList); //working

//	FLIGHT f = { "New Brunswick\n", 1, generateFlightSeating() };
//	flightList = addToFlightList(f, flightList); //working
	//printFlightList(flightList);

	//saveFlightListToFile(flightList); //working

	//USER u = {"Eric\n", "Weng\n", 334551231, 586};
	//userList = addToUserList(u, userList); //userListsize is changing here
	//saveUserListToFile(userList);

	if (userList != NULL) {
		free(userList);
	}
	if (flightList != NULL) {
		free(flightList);
	}
	

}
