#pragma once
#include <stdio.h>
typedef struct Employee {
	char ID[10];
	char name[12];
	char lastName[12];
	char status[10];
} Employee;
/*login for employee*/
void LogIn_Employee();