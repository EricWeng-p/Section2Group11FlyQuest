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



	//addtoflightlist test
	FLIGHT* flightList = loadFlightListFromFile();
	FLIGHT* listReference = &flightList;
	printFlightList(flightList);
	FLIGHT f = { "arkansas county\n", 't', generateFlightSeating() };
	flightList = addToFlightList(f, flightList);
	printFlightList(flightList);
	if (flightList != NULL) {
		free(flightList);
	}
	

}
