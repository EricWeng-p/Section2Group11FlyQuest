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

	FLIGHT* flightList = loadFlightListFromFile();
	USER* userList = loadUserListFromFile();


	
	


}
