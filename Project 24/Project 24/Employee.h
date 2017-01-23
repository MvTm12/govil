#pragma once
#include <stdio.h>
#define EMPLOYEES_DB "Employee.txt"
#define HOURS_DB "WorkingHours.txt"
#include <time.h>
typedef struct empl_hours {
	int d,m,y,h_s,m_s,h_e,m_e;
	
}empl_hours;
typedef struct Employee {
	char ID[10];
	char name[12];
	char lastName[12];
	char status[11];
} Employee;

/*login for employee*/
void LogIn_Employee();
/*function to write entry date and time to ID.txt*/
void EntryTime(char *ID);
/*function to add exit time*/
void ExitTime(char *ID);
/*options for regular worker*/
void WorkerMenu(char *ID);