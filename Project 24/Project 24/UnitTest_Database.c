#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//#include <vld.h>
#include "MinUnit.h"
#include "database.h"

MU_TEST(test_getfieldValue) {
	//Arrange
	char* buffer = "Zero ; First ; Second; Third; Fourth ; Fifth ; Sixth ; Seventh ; Eighth ; Ninth ; Tenth ;";
	int column = 2;

	//Act
	char* result = getfieldValue(buffer, column);

	//Assert
	mu_check(strcmp(result, "Second") == 0); 
}

MU_TEST(test_findFieldIndex) {
	//Arrange
	FILE *myFile = fopen("Citizen.txt", "r");
	char* field = "Gender";

	//Act
	int result = findFieldIndex(myFile, field);
	fclose(myFile);

	//Assert
	mu_check(result == 5); 
}

MU_TEST(test_getNextWord) {
	//Arrange
	FILE *myFile = fopen("Citizen.txt", "r");

	//Act
	char* result = getNextWord(myFile);

	//Assert
	mu_check(strcmp(result, "ID") == 0);
}

MU_TEST(test_DBreadPeople) {
	//Arrange
	char* field = "ID";
	char* value = "205774094";
	int resultArrSize = 0;

	//Act
	Person* person = DBreadPeople(PEOPLE_DB, field, value, &resultArrSize);

	//Assert
	mu_check(strcmp(person[0].name, "Nofar") == 0);
}

MU_TEST(test_DBreadEmployee) {
	//Arrange
	char* field = "ID";
	char* value = "326952298";

	//Act
	Employee employee = DBreadEmployee(EMPLOYEES_DB, field, value);

	//Assert
	mu_check(strcmp(employee.status, "manager   ") == 0);
}

MU_TEST(test_GetCarsByField) {
	//Arrange
	char* field = "N_car";
	char* value = "11-111-18";
	int resultArrSize = 0;

	//Act
	Cars* cars = GetCarsByField(field, value, &resultArrSize);

	//Assert
	mu_check(strcmp(cars->Model, "porsh       ") == 0);
}


MU_TEST(test_GetPersonList) {
	//Arrange
	int sizeOfList = 0;

	//Act
	Person* person = GetPersonList(&sizeOfList);

	//Assert
	mu_check(strcmp(person[5].name, "Tom") == 0);
}



MU_TEST_SUITE(test_suite_database) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	MU_RUN_TEST(test_findFieldIndex);
	MU_RUN_TEST(test_getfieldValue);
	MU_RUN_TEST(test_getNextWord);
	MU_RUN_TEST(test_DBreadEmployee);
	MU_RUN_TEST(test_GetCarsByField);
	MU_RUN_TEST(test_GetPersonList);

	MU_REPORT_SUITE();
}

void runtests_Database() {
	MU_RUN_SUITE(test_suite_database);

	MU_REPORT();
}
