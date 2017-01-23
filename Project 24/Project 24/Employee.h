#pragma once
#include <stdio.h>
#define EMPLOYEES_DB "Employee.txt"
#define HOURS_DB "WorkingHours.txt"
#define Tasks_Manager_DB "Tasks_Manager.txt"
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
typedef struct Tasks {
	char number[4];
	char task[71];
	char status[14];
} Tasks;

/*login for employee*/
void LogIn_Employee();
/*function to write entry date and time to ID.txt*/
void EntryTime(char *ID);
/*function to add exit time*/
void ExitTime(char *ID);
/*options for regular worker*/
void WorkerMenu(Employee Employer);
/*function to take all tasks from database to array and print to worker*/
void TasksManager(Employee Employer);
/*function to change status of task manager in database*/
int ChangeStatusInTasks(char *filename, char *number);