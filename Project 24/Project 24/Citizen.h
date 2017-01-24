#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define PEOPLE_DB "Citizen.txt"
#define SUSPEND_CAR_FORM "suspen_car_request_form_template.txt"
#define DISABLED_BADGE_FORM "disabled_badge_request_form_template.txt"
#define ARMORED_VEHICAL_FORM "armored vehical request_form_template.txt"

typedef struct Person {
	char ID[10];
	char name[12];
	char lastName[12];
	char telephone[11];
	int age;
	char gender[2];
	char city[20];
} Person;

// login function citizen
void LogIn_Citizen();

// citizen main
void citizen_manu(Person person);

int SaveFile(Person person, char* File, char* filename);

void FillFOrm(Person person);

void SaveForm(Person person);
