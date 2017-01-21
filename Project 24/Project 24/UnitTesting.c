#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <vld.h>
#include "MinUnit.h"
#include "database.h"

MU_TEST(test_getfieldValue) {
	//Arrange
	char* buffer = "First ; Second; Third; Fourth ; Fifth ; Sixth ; Seventh ; Eighth ; Ninth ; Tenth ;";
	int column = 2;

	//Act
	char* result = getfieldValue(buffer, column);

	//Assert
	mu_check(strcmp(result, "Gender") == 0); 
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
	char* field = "Gender";

	//Act
	char* result = getNextWord(myFile);
	fclose(myFile);

	//Assert
	mu_check(strcmp(result, "Name") == 0);
}


MU_TEST_SUITE(test_suite_database) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	MU_RUN_TEST(test_getfieldValue);
	MU_RUN_TEST(test_findFieldIndex);
	MU_RUN_TEST(test_getNextWord);


	MU_REPORT_SUITE();
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite_database);

	MU_REPORT();
	return 0;
}
