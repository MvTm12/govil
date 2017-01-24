#include "Citizen.h"
#include "database.h"
void LogIn_Citizen()
{
	char TEMP_id[10];
	char TEMP_pass[10];
	int numberOfFiltered = 0;
	Person* resultArr = NULL;
	while (getchar() != '\n');

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

// citizen menu
void citizen_manu(Person person)
{
	char choose;
	do
	{
		while (getchar() != '\n');
		printf("Welcome %s %s,\n\n", person.name, person.lastName);
		printf("-------======This is the citizen menu !======--------.\n");
		printf("[1] save form.\n");
		printf("[2] fill form.\n");
		printf("[3] request status report.\n");
		printf("[4] fee Payment.\n");
		printf("[5] fee payments report.\n");
		printf("[6] fee payments by car.\n");
		printf("[0] To exit.\n");
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
		while (getchar() != '\n');
	} while (choose != '0');
}

// menu for save form
void SaveForm(Person person)
{
	system("cls");
	char choose;
	do
	{
		while (getchar() != '\n');
		printf("Welcome %s %s,\n", person.name, person.lastName);
		printf("-------======This is the save form menu !======--------.\n");
		printf("[1] save form - suspen car request.\n");
		printf("[2] save form - disabled badge form.\n");
		printf("[3] save form - armored vehical roem.\n");
		printf("[4] To go back.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		int i;
		switch (choose)
		{
		case '1':
			i= SaveFile(person, SUSPEND_CAR_FORM, "suspend_car_form");
			if (i == 1)
			{
				printf("success");
			}
			else
			{
				printf("fail");
			}

			break;
		case '2':
			i=SaveFile(person, DISABLED_BADGE_FORM,"disabeled_badge_form");
			if (i == 1)
			{
				printf("success");
			}
			else
			{
				printf("fail");
			}
			break;
		case '3':
			i=SaveFile(person, ARMORED_VEHICAL_FORM,"armored_vehical_form");
			if (i == 1)
			{
				printf("success");
			}
			else
			{
				printf("fail");
			}
			break;
		case '0':
			printf(" Bye-Bye!");
			return;
			break;
		default:
			printf("Wrong choose, please try again...\n");
			break;
		}
		while (getchar() != '\n');
	} while (choose != '0');

}
// function that get the requested fie template and save it for the user
// function that saves rquested form by name and user id 
int SaveFile(Person person, char* File,char* filename)
{
	FILE *myFile, *myFile_new;
	char buffer[255];	//Current row content
	myFile = fopen(File, "r");
	//Check file
	if (myFile == NULL) {
		printf("File could not be opened\n");
		return 0;
	}
	char name[50];
	sprintf(name, "%s_%s.txt", filename,person.ID);
	myFile_new = fopen(name, "w");
	while (fgets(buffer, sizeof buffer, myFile) != NULL)
	{
		fputs(buffer, myFile_new);
	}
	fclose(myFile_new);
	fclose(myFile);
	return 1;
}


void FillFOrm(Person person)
{
	char choose;
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
			///
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

int FillForm_suspen_car_request()
{

}