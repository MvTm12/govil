#pragma once
#include <stdio.h>
#define EMPLOYEES_DB "Employee.txt"
#define HOURS_DB "WorkingHours.txt"
typedef struct Employee {
	char ID[10];
	char name[12];
	char lastName[12];
	char status[11];
} Employee;

/*login for employee*/
void LogIn_Employee();
/*function to write entry date and time to WorkingHours.txt, function search ID in database and write
new date and time to last line of this ID*/
void EntryTime(char *ID);