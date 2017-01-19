#pragma once
#include "Citizen.h"
#include <stdio.h>
#include <stdlib.h>

//Add new entry to data base
int DBaddPerson(char *fileName, Person newPerson);
Person* DBreadPeople(char* fileName, char* field, char* value, int* resultArrSize);

