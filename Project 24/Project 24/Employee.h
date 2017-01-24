#pragma once
#include <stdio.h>
#define EMPLOYEES_DB "Employee.txt"
#define HOURS_DB "WorkingHours.txt"
#define TASKS_MANAGER_DB "Tasks_Manager.txt"
#define REQUESTS_DB "Requests.txt"
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
typedef struct Requests {
	char num[4];
	char Citizen_ID[10];
	char Empl_ID[10];
	char N_car[10];
	char Request[15];
	char Status[9];
	char Comment[30];
	int d, m, y;
}Requests;
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
/*function to list all citizen requests*/
void ListRequests(Employee Employer);
/*create requests list by filed and text in field*/
Requests *CreateRequestList(int *sizeOfList);
/*function to change status of request in database*/
int ChangeStatusOfRequest(char *filename, char *number);