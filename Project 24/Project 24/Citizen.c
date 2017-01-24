#include "Citizen.h"
#include "database.h"
void LogIn_Citizen()
{
	char TEMP_id[10];
	char TEMP_pass[10];
	int numberOfFiltered = 0;
	Person* resultArr = NULL;
	while (getchar() != '\n');
	int i = 0;

	// get user idintification
	system("cls");
	printf("**** hello! ****\n ");
	printf("please enter your ID (enter '0' to back to main login menu): ");
	scanf("%s", TEMP_id);
	if (TEMP_id[0] == '0')
	{
		system("cls");
		return;
	}
	fflush(stdin);
	printf(" enter password: ");
	while (i <= 10) {
		if (i == 9)
			break;
		TEMP_pass[i] = getch();
		printf("*");
		i++;
	}
	TEMP_pass[i] = '\0';
	resultArr = DBreadPeople(PEOPLE_DB, "ID", TEMP_id, &numberOfFiltered);

	if (resultArr == NULL)
	{
		system("cls");
		printf(" \n user not found. \n");
		return;
	}
	if (strcmp(TEMP_id, TEMP_pass))
	{
		system("cls");
		printf(" \n incorrect password. \n");
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
	system("cls");
	char choose;
	do
	{
		while (getchar() != '\n');
		system("cls");
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
			printf(" Bye-Bye!\n");
			system("cls");
			return;
			break;
		default:
			printf("Wrong choose, please try again...\n");
			break;
		}
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
		system("cls");
		printf("Welcome %s %s,\n", person.name, person.lastName);
		printf("-------======This is the save form menu !======--------.\n");
		printf("[1] save form - suspen car request.\n");
		printf("[2] save form - disabled badge form.\n");
		printf("[3] save form - armored vehical roem.\n");
		printf("[0] To go back.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		int i;
		switch (choose)
		{
		case '1':
			i = SaveFile(person, SUSPEND_CAR_FORM, "suspend_car_form");
			getchar();
			break;
		case '2':
			i = SaveFile(person, DISABLED_BADGE_FORM, "disabeled_badge_form");
			getchar();
			break;
		case '3':
			i = SaveFile(person, ARMORED_VEHICAL_FORM, "armored_vehical_form");
			getchar();
			break;
		case '0':
			return;
			break;
		default:
			printf("Wrong choose, please try again...\n");
			break;
		}
	} while (choose != '0');

}
// function that get the requested fie template and save it for the user
// function that saves rquested form by name and user id 
int SaveFile(Person person, char* File, char* filename)
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
	sprintf(name, "%s_%s.txt", filename, person.ID);
	myFile_new = fopen(name, "w");
	while (fgets(buffer, sizeof buffer, myFile) != NULL)
	{
		fputs(buffer, myFile_new);
	}
	fclose(myFile_new);
	fclose(myFile);
	printf("success!\npress any key to continue..\n");
	return 1;
}


void FillFOrm(Person person)
{
	int i = 0;
	system("cls");
	char choose;
	do
	{
		while (getchar() != '\n');
		system("cls");
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
			i=FillForm_suspen_car_request(person, "suspend_car");
			getchar();
			break;
		case '2':
			i=FillForm_suspen_car_request(person, "disabled_badge");
			getchar();
			break;
		case '3':
			i=FillForm_suspen_car_request(person, "armord_vehicle");
			getchar();
			break;
		case '0':
			printf(" Bye-Bye!\n");
			getchar();
			return;
			break;
		default:
			printf("Wrong choose, please try again...\n");
			break;
		}
	} while (choose != '0');

}

int FillForm_suspen_car_request(Person person, char* filename)
{
	char ID[10];
	char name[12];
	char lastName[12];
	char N_car[10];
	FILE *myFile;
	char buffer[255];	//Current row content
	char temp[4], status[14];
	Cars car;
	Requests *ReqList = NULL;
	int size = 0;
	int temp_size = 0;
	int i = 2;
	time_t now;
	time(&now);
	struct tm *mytime = localtime(&now);

	system("cls");
	if (filename == "suspend_car")
	{
		printf("hello,\n");
		printf("In this form you are filling a request to suspend your car and if your request will be approved you mey not ba able to drive this car again.\n");
		printf("Please complete this form accurately to avoid disqualification Submission.\n\n");
	}
	else if (filename == "disabled_badge")
	{
		printf("hello,\n");
		printf("in this form you are filling a request for recognition as a disabled person and request  for a disabled people's benefits.\n");
		printf("Please complete this form accurately to avoid disqualification Submission.\n\n");
	}
	else
	{
		printf("hello,\n");
		printf("in this form you are filling a request for recognition as a disabled person and request  for a disabled people's benefits.\n");
		printf("Please complete this form accurately to avoid disqualification Submission.\n\n");
	}
	printf(" please enter owner ID: ");
	scanf("%s", &ID);
	printf(" please enter owner Name: ");
	scanf("%s", &name);
	printf(" please enter owner last name: ");
	scanf("%s", &lastName);
	printf(" please enter car number: ");
	scanf("%s", &N_car);

	// chaking the entered values
	if (strcmp(ID, person.ID) == 0 && strcmp(name, person.name) == 0)
	{
		// read from cars database
		myFile = fopen(Cars_DB, "r+");
		//Check file
		if (myFile == NULL)
		{
			printf("File could not be opened\n");
			return 0;
		}
		while (fgets(buffer, sizeof buffer, myFile) != NULL)
		{
			i = 2;
			sscanf(buffer, "%[^;]; ", car.N_car);
			sscanf(buffer + 11, "%f", &car.Engine_Capacity);
			sscanf(buffer + 16, "%[^;]; %[^;];", car.ID, car.Model);
			sscanf(buffer + 44, "%d;%d.%d.%d;%d.%d.%d", &car.year, &car.d_payment, &car.m_payment, &car.y_payment, &car.d_ownership, &car.m_ownership, &car.y_ownership);

			if (strcmp(car.ID, ID) == 0)
			{
				ReqList = CreateRequestList(&size);
				temp_size = size+1;
				ReqList = (Requests*)realloc(ReqList, (size + 1) * sizeof(Requests));

				//N
				ReqList[size].num[i] = (char)(temp_size % 10 + 48);
				temp_size /= 10;
				while (i>0)
				{
					i -= 1;
					if (temp_size < 0)
					{
						ReqList[size].num[i] = temp_size % 10;
						temp_size /= 10;
					}
					else
						ReqList[size].num[i] = ' ';
				}
				ReqList[size].num[3] = '\0';
				//citizen_ID
				strcpy(ReqList[size].Citizen_ID, ID);
				//Empl_ID
				strcpy(ReqList[size].Empl_ID, "None");
				//N_Car
				strcpy(ReqList[size].N_car, car.N_car);
				//Request
				strcpy(ReqList[size].Request, filename);
				//Status
				strcpy(ReqList[size].Status, "open ");
				//Comment
				strcpy(ReqList[size].Comment, "None");
				//date
				ReqList[size].d = mytime->tm_mday;
				ReqList[size].m = mytime->tm_mon + 1;
				ReqList[size].y = mytime->tm_year + 1900;

				ChangeStatusOfRequest(REQUESTS_DB, ReqList, size + 1);
			}
		}
		fclose(myFile);
		printf("\n\nYou will receive an answer within 10 business days.\nbest regarsd,\nDMV.");
	}
	else
	{
		printf("The form is not filled properly.\nSubmission Failed!\n");
		return 0;
	}
	return 1;
}