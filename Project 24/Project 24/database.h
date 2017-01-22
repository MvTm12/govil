#pragma once
#include "Citizen.h"
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct ID_H {
	char id[10];
	char *(hours[27]);
}ID_H;

//Add new entry to data base
int DBaddPerson(char *fileName, Person newPerson);
Person *DBreadPeople(char* fileName, char* field, char* value, int* resultArrSize);
Employee DBreadEmployee(char* fileName, char* field, char* value);
int findFieldIndex(FILE *myFile, char *field);
char* getNextWord(FILE* myFile);
char* getfieldValue(char* buffer, int column);

