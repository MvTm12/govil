#include "UnitTest_Worker.h"
#include "database.h"
#include "MinUnit.h"
#include "Employee.h"

//change task status in db
MU_TEST(test_CheckIdInDB)
{
	//Arrange
	char *ID = "326952298";


	//Act
	mu_check(CheckIdInDB(ID));
	//Assert

}
//change task status in db
MU_TEST(test_ChangeStatusInTasks)
{
	//Arrange
	char *filename = "Tasks_ManagerUniTest.txt";
	char *numberOfTask = "4";


	//Act
	mu_check(ChangeStatusInTasks(filename,numberOfTask));
	//Assert
	
}
//DBreadEmployee(EMPLOYEES_DB, "ID", TEMP_id)
MU_TEST(test_getfieldValue)
{
	//Arrange
	char *buffer = "first; last; second";
	int field = 2;

	//Act
	char *result = getfieldValue(buffer, field);
	//Assert
	mu_check(strcmp(result, "second") == 0);
}
MU_TEST(test_DBreadEmployee)
{
	//Arrange
	char *ID = "326952298";

	//Act
	Employee result = DBreadEmployee(EMPLOYEES_DB, "ID", ID);

	//Assert
	mu_check(strcmp(result.name, "Andrey") == 0);
}
MU_TEST_SUITE(test_suite_worker) 
{
	MU_SUITE_CONFIGURE(NULL, NULL);
	MU_RUN_TEST(test_DBreadEmployee);
	MU_RUN_TEST(test_getfieldValue);
	MU_RUN_TEST(test_ChangeStatusInTasks);
	MU_RUN_TEST(test_CheckIdInDB);
	MU_REPORT_SUITE();
}
int runtests()
{

	MU_RUN_SUITE(test_suite_worker);

	MU_REPORT();
	return 0;
}