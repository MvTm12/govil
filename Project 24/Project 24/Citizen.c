#include "Citizen.h"
#include "database.h"
void LogIn_Citizen()
{
	char TEMP_id[10];
	char TEMP_pass[10];
	int numberOfFiltered = 0;
	Person* resultArr = NULL;

	// get user idintification
	system("cls");
	printf("**** hello! ****\n ");
	printf("please enter your ID: ");
	scanf("%s", TEMP_id);
	fflush(stdin);
	printf(" enter password: ");
	fflush(stdin);
	scanf("%s", TEMP_pass);
	resultArr = DBreadPeople(PEOPLE_DB, "ID", TEMP_id, &numberOfFiltered);

	if (resultArr == NULL)
	{
		system("cls");
		printf(" user not found. \n");
		return;
	}
	if (strcmp(TEMP_id, TEMP_pass))
	{
		system("cls");
		printf(" incorrect password. \n");
		return;
	}

	//printf("ID          Name          LastName      Telephone    Age   Gender   City\n");
	//for (int i = 0; i < numberOfFiltered; i++)
	//printf("%-11s %-13s %-13s %-12s %-5d %-8s %-25s \n", resultArr[i].ID, resultArr[i].name, resultArr[i].lastName, resultArr[i].telephone,  resultArr[i].age, resultArr[i].gender, resultArr[i].city );

	// in this point the autorization approved and we continue

	// citizen main func
	citizen_manu(resultArr[0]);

	if (resultArr != NULL)
		free(resultArr);
}

void citizen_manu(Person person)
{
	int choose;
	do
	{
		printf("Welcome %s %s,\n", person.name, person.lastName);
		printf("-------======This is the citizen manue !======--------.\n");
		printf("save form				  press '1'.\n");
		printf("fill form				  press '2'.\n");
		printf("request status report	  press '3'.\n");
		printf("fee Payment				  press '4'.\n");
		printf("fee payments report		  press '5'.\n");
		printf("fee payments by car		  press '6'.\n");
		printf("To exit					  press '0'.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':
			SaveForm(person);
			break;
		case '2':
			FillFOrm(person);
			break;
		case '3':
			/////
			break;
		case '4':
			/////
			break;
		case '5':
			/////
			break;
		case '6':
			/////
			break;
		case '0':
			printf(" Bye-Bye!");
			return;
			break;
		default:
			printf("Wrong choose, please try again...\n");
			break;
		}
		while (getchar() != "\n");
	} while (choose != '0');
}
void SaveForm(Person person)
{
	int choose;
	do
	{
		printf("Welcome %s %s,\n", person.name, person.lastName);
		printf("-------======This is the save form manue !======--------.\n");
		printf("save form - suspen car request			  press '1'.\n");
		printf("save form - disabled badge form 		  press '2'.\n");
		printf("save form - armored vehical roem		  press '3'.\n");
		printf("To go back								  press '0'.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':
			/////
			break;
		case '2':
			/////
			break;
		case '3':
			/////
			break;
		case '0':
			printf(" Bye-Bye!");
			return;
			break;
		default:
			printf("Wrong choose, please try again...\n");
			break;
		}
		while (getchar() != "\n");
	} while (choose != '0');

}
void FillFOrm(Person person)
{
	int choose;
	do
	{
		printf("Welcome %s %s,\n", person.name, person.lastName);
		printf("-------======This is the Fill form manue !======--------.\n");
		printf("Fill form - suspen car request			  press '1'.\n");
		printf("Fill form - disabled badge form 		  press '2'.\n");
		printf("Fill form - armored vehical roem		  press '3'.\n");
		printf("To go back								  press '0'.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':
			/////
			break;
		case '2':
			/////
			break;
		case '3':
			/////
			break;
		case '0':
			printf(" Bye-Bye!");
			return;
			break;
		default:
			printf("Wrong choose, please try again...\n");
			break;
		}
		while (getchar() != "\n");
	} while (choose != '0');

}
