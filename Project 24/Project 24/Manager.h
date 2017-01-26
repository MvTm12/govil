#pragma once
#include "Citizen.h"
#include "database.h"
#include "Employee.h"
#include "MinUnit.h"
#include "UnitTest_Worker.h"
/*menu for manager*/
void ManagerMenu(Employee Employer);
/*function to create recall message*/
void CreateRecallMessage();
/*function to get array of employes*/
Employee *GetEmployesList(int *sizeOfArray);
/*function to get requests that opened more than 5 days and set a task for employee*/
void GetOpReq();
// function that add new worker to Employee file
int AddEmployee();
/*function to print all employees that updated requests today with counter of updates*/
void PrintEmplAndReq();