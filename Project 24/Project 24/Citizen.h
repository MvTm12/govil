#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
//#include "vld.h"
#define PEOPLE_DB "Citizen.txt"

typedef struct Person {
	char ID[10];
	char name[12];
	char lastName[12];
	char telephone[11];
	int age;
	char gender[2];
	char city[20];
} Person;


void LogIn_Citizen();
