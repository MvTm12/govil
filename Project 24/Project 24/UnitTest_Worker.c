#include "UnitTest_Worker.h"
#include "database.h"
#include "MinUnit.h"
#include "Employee.h"


MU_TEST(test_CheckCityInDB)
{
	//Arrange
	char *City = "Mizpe-Ramon";

	//Act
	int result = CheckCityInDB("Jerusalem");
	
	//Assert
	mu_check(result);
}

MU_TEST(test_CheckIdInDB)
{
	//Arrange
	char *ID = "326952298";
	int result;

	//Act
	result = CheckIdInDB(ID);

	//Assert
	mu_check(result);
}

MU_TEST(test_ChangeStatusInTasks)
{
	//Arrange
	char *filename = "Tasks_ManagerUniTest.txt";
	char *numberOfTask = "4";


	//Act
	mu_check(ChangeStatusInTasks(filename,numberOfTask));
	//Assert
	
}

MU_TEST(test_CreateRequestList)
{
	//Arrange
	int sizeOfList = 0;

	//Act
	Requests *requests = CreateRequestList(&sizeOfList);
	
	//Assert
	mu_check(strcmp(requests[0].Citizen_ID, "205774094") == 0);
}

MU_TEST(test_GetCity)
{
	//Arrange
	char *ID = "311268262";
	char *result;

	//Act
	result = GetCity(ID);

	//Assert
	mu_check(strcmp(result, "Ofakim") == 0);
}


MU_TEST_SUITE(test_suite_worker) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	//MU_RUN_TEST(test_ChangeStatusInTasks);
	MU_RUN_TEST(test_CheckIdInDB);
	MU_RUN_TEST(test_CheckCityInDB);
	MU_RUN_TEST(test_CreateRequestList);
	MU_RUN_TEST(test_GetCity);

	MU_REPORT_SUITE();
}

int runtests_Worker()
{
	MU_RUN_SUITE(test_suite_worker);

	MU_REPORT();
	return 0;
}