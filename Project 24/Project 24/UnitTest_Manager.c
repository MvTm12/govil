#include "Manager.h"
#include "MinUnit.h"

MU_TEST(test_GetEmployesList) {
	//Arrange
	int sizeOfArray = 0 ;
	Employee *EmployeeArray;

	//Act
	EmployeeArray = GetEmployesList(&sizeOfArray);

	//Assert
	mu_check(strcmp(EmployeeArray[0].ID, "317743425") == 0);
}

MU_TEST(test_Hperemployee) {
	//Arrange
	char *emp_id= "311268262";
	int month = 1;
	int year = 2017;
	int result;

	//Act
	result = Hperemployee(emp_id, month, year);

	//Assert
	mu_check(result = 81);
}


MU_TEST_SUITE(test_suite_manager)
{
	MU_SUITE_CONFIGURE(NULL, NULL);
	MU_RUN_TEST(test_GetEmployesList);
	MU_RUN_TEST(test_Hperemployee);

	
	MU_REPORT_SUITE();
}

void runtests_Manager()
{
	MU_RUN_SUITE(test_suite_manager);

	MU_REPORT();
}