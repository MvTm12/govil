#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "database.h"
#include "Employee.h"
#include "UnitTest_Worker.h"
#define PEOPLE_DB "Citizen.txt"
#define EMPLOYEES_DB "Employee.txt"

int main() {
	int numberOfFiltered = 0;
	char choose=-1;
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
			GetHoursRep("326952298");
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

}