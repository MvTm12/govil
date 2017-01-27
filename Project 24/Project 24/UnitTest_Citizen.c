#include "UnitTest_Citizen.h"
#include "MinUnit.h"
#include "Citizen.h"

MU_TEST(test_CreatetListCars) {
	//Arrange
	Cars *cars;
	int sizeOfList = 0;

	//Act
	cars = CreatetListCars(&sizeOfList);

	//Assert
	mu_check(strcmp(cars[0].ID, "205774094") == 0);
}

MU_TEST(test_agra_amount) {
	//Arrange
	Cars car = { "11-121-99", 2.0, "237644654", "Porsche", 2013, 26 , 8, 2015, 26, 6, 2011, "No", "No", "No" };
	float agra;

	//Act
	agra = (int)(agra_amount(car) * 10000)/10000.0;

	//Assert
	mu_check(agra ,3220.80005);
}


MU_TEST_SUITE(test_suite_Citizen) {
	MU_SUITE_CONFIGURE(NULL, NULL);

	MU_RUN_TEST(test_CreatetListCars);
	MU_RUN_TEST(test_agra_amount);

	MU_REPORT_SUITE();
}



void runtests_Citizen() {
	MU_RUN_SUITE(test_suite_Citizen);

	MU_REPORT();
}
