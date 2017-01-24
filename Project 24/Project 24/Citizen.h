#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define PEOPLE_DB "Citizen.txt"
#define SUSPEND_CAR_FORM "suspen_car_request_form_template.txt"
#define DISABLED_BADGE_FORM "disabled_badge_request_form_template.txt"
#define ARMORED_VEHICAL_FORM "armored vehical request_form_template.txt"
#define Cars_DB "CarsDB.txt"

typedef struct Person {
	char ID[10];
	char name[12];
	char lastName[12];
	char telephone[11];
	int age;
	char gender[2];
	char city[20];
} Person;
typedef struct Cars {
	
	char N_car[10];
	float Engine_Capacity;
	char ID[10];
	char Model[16];
	int year;
	int d_payment, m_payment, y_payment;
	int d_ownership, m_ownership, y_ownership;
	char disabled_badge[5];
	char grounded[5];
	char aremored[5];

} Cars;

// login function citizen
void LogIn_Citizen();

// citizen main
void citizen_manu(Person person);

int SaveFile(Person person, char* File, char* filename);

void FillFOrm(Person person);

void SaveForm(Person person);
