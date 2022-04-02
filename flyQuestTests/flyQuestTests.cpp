#include "pch.h"
#include "CppUnitTest.h"
extern"C" {
#include"dataProcessing.h"
#include"saveLoad.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace flyQuestTests
{
	TEST_CLASS(SaveFileModuleTests)
	{
	public:
		/* Can't test save to file in unit test suite?
		TEST_METHOD(saveUserListToFile)
		{
			USER userlist[2];
			userlist[0] = generateUser("John", "Doe", 12345678, 321);
			userlist[1] = generateUser("Jane", "Doe", 87654321, 123);

			saveUserListToFile(userlist);
			printUserList(userlist);

		}

		TEST_METHOD(saveFlightListToFile)
		{
			FLIGHT *flightlist[2];
			flightlist[0] = generateFlight("London", true);
			flightlist[1] = generateFlight("Paris", false);

			saveFlightListToFile(flightlist);
			printFlightList(flightlist);
		}
		
		*/
		TEST_METHOD(loadUserListFromFile)
		{
			loadUserListFromFile();
		}
	
		TEST_METHOD(loadFlightListFromFile)
		{
			loadFlightListFromFile();
		}

		/*TEST_METHOD(saveTicketListToFile)
		{

		}

		TEST_METHOD(loadTicketListFromFile)
		{

		}
		*/
		
	};
}
