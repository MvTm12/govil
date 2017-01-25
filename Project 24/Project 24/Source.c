#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "database.h"
#include "Employee.h"
#include "UnitTest_Worker.h"
#define PEOPLE_DB "Citizen.txt"
#define EMPLOYEES_DB "Employee.txt"

int main() {
	int numberOfFiltered = 0;
	Person* resultArr=NULL;
	char choose=-1;
	//Employee Employer = DBreadEmployee(EMPLOYEES_DB, "ID", "326952298");
	
	/*Person Semion = { "317743425", "Semion" , "Faifman", "0546900184", 27, "M", "Beer-Sheva"};
	Person Andrey = { "326952298", "Andrey" , "Fiodorov", "0546579194", 29, "M", "Beer-Sheva" };
	Person Nofar = { "205774094", "Nofar" , "Hazan", "0525377581", 22, "W", "Mizpe-Ramon" };
	Person Matan = { "311268262", "Matan" , "Vaknin", "0502419553", 23, "M", "Ofakim" };
	DBaddPerson(PEOPLE_DB, Semion);
	DBaddPerson(PEOPLE_DB, Andrey);
	DBaddPerson(PEOPLE_DB, Nofar);
	DBaddPerson(PEOPLE_DB, Matan);*/
	Cars *temp = NULL;
	int size = 0;
	//resultArr = DBreadPeople(PEOPLE_DB, "ID", "205774094", &numberOfFiltered);
	/*
	printf("ID          Name          LastName      Telephone    Age   Gender   City\n");
	for (int i = 0; i < numberOfFiltered; i++)
		printf("%-11s %-13s %-13s %-12s %-5d %-8s %-25s \n", resultArr[i].ID, resultArr[i].name, resultArr[i].lastName, resultArr[i].telephone,  resultArr[i].age, resultArr[i].gender, resultArr[i].city );*/
	////test
	Person Nofar = { "205774094", "Nofar" , "Hazan", "0525377581", 22, "W", "Mizpe-Ramon" };
	while (choose != '0')
	{
		printf("Welcome to gov.il application.\n");
		printf("-------======This is a login page!======--------.\n");
		printf("[1] To citizens.\n");
		printf("[2] To employees.\n");
		printf("[3] To unitest.\n");
		printf("[4] To check function.\n");
		printf("[0] To exit.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':
			LogIn_Citizen();
			//nofar
			break;
		case '2':
			LogIn_Employee();
			break;
		case '3':
			runtests();
			break;
		case '4':
			GetCitizensDebt();
			break;
		case '0':
			/////
			break;
		default:
			system("cls");
			printf("*********************************************************************************\n");
			printf("*-------==============Wrong enter, please try again...================----------*\n");
			printf("*********************************************************************************\n");
			break;
		}
		while (getchar() != '\n');
		
	}

	if (resultArr != NULL)
		free(resultArr);

}