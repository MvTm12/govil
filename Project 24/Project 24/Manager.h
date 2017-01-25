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