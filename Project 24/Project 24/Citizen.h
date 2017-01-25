#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define PEOPLE_DB "Citizen.txt"
#define SUSPEND_CAR_FORM "suspen_car_request_form_template.txt"
#define DISABLED_BADGE_FORM "disabled_badge_request_form_template.txt"
#define ARMORED_VEHICAL_FORM "armored vehical request_form_template.txt"
#define Cars_DB "CarsDB.txt"
#define REQUESTS_DB "Requests.txt"

typedef struct Person {
	char ID[10];
	char name[12];
	char lastName[12];
	char telephone[11];
	int age;
	char gender[2];
	char city[20];
	float debt;
} Person;
typedef struct Cars {
	
	char N_car[10];
	float Engine_Capacity;
	char ID[10];
	char Model[13];
	int year;
	int d_payment, m_payment, y_payment;
	int d_ownership, m_ownership, y_ownership;
	char disabled_badge[6];
	char grounded[8];
	char aremored[4];

} Cars;

// login function citizen
void LogIn_Citizen();

// citizen main
void citizen_manu(Person person);

int SaveFile(Person person, char* File, char* filename);

void FillFOrm(Person person);

void SaveForm(Person person);

int FillForm_(Person person, char* filename);

int request_status_report(Person person);

int fee_payment(Person person);

int pay(char* car_num);

Cars *CreatetListCars(int *sizeOfList);

void fee_report(Person person);

void fee_by_car(Person person);
float agra_amount(Cars car);
