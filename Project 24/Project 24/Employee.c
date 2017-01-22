#include "database.h"
#include "Employee.h"
/*function to employer login*/
void LogIn_Employee()
{
	char TEMP_id[10];
	char TEMP_pass[10];
	Employee Employer;

	// get user idintification
	printf("**** hello worker! ****\n ");
	printf("please enter your ID: ");
	scanf("%s", TEMP_id);
	fflush(stdin);
	printf(" enter password: ");
	fflush(stdin);
	scanf("%s", TEMP_pass);

	Employer = DBreadEmployee(EMPLOYEES_DB, "ID", TEMP_id);
	if (!strcmp(Employer.name,"None"))
	{
		printf(" worker not found in database \n");
		return;
	}
	else if (!strcmp(Employer.status, "not-active"))
	{
		printf(" your status is 'not active', please go to Manager \n");
		return;
	}
	else if (strcmp(Employer.ID, TEMP_pass))
	{
		system("cls");
		printf("The password is incorrect.\n");
		printf("--------------------------\n");
		return;
	}

}
/*function to write entry date and time to WorkingHours.txt, function search ID in database and write 
date and time*/
void EntryTime(char *ID) 
{

	time_t now;
	time(&now);
	struct tm *mytime = localtime(&now);
	FILE *myFile;
	char buffer[255];
	ID_H *HoursArray, aa;
	int size = 0, size1;
	myFile = fopen(HOURS_DB, "r");
	fgets(buffer, sizeof buffer, myFile);
	while (buffer != NULL)
	{
		if (!strcmp(buffer, "ID\n"))
		{
			fgets(buffer, sizeof buffer, myFile);
			size++;
			if (size == 1)
				HoursArray = (ID_H*)malloc(size * sizeof(ID_H));
			else HoursArray = (ID_H*)realloc(HoursArray, size * sizeof(ID_H));
			strcpy(HoursArray[size - 1].id, buffer);
			size1 = 1;
		}
		if (size1 == 1)
		{
			HoursArray[size - 1].hours[27] = (char*)malloc(size1 * sizeof(char));
			fgets(buffer, sizeof buffer, myFile);
		}
		else
			HoursArray[size - 1].hours[27] = (char*)realloc(HoursArray[size - 1].hours[27], size1 * sizeof(char));
		if (strcmp(buffer, "ID\n"))
		{
			strcpy(HoursArray[size - 1].hours[27][size1-1], buffer);
			size1++;
		}

		//HoursArray[size - 1].tm_h[size1 - 1].d = (buffer[0]-48)*10 + buffer[1] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].m = (buffer[3]-48)*10 + buffer[4] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].y = (buffer[6]-48)*1000 + (buffer[7]-48)*100 + (buffer[8]-48)*10 + buffer[9] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].s_h = (buffer[13]-48)*10 + buffer[14] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].s_m = (buffer[16] - 48) * 10 + buffer[17] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].e_h = (buffer[21] - 48) * 10 + buffer[22] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].e_m = (buffer[24] - 48) * 10 + buffer[25] - 48;
		
	}
	fclose(myFile);


	printf("Date is: %d.%d.%d\n", mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900);
	printf("The time of entry is: %d:%d\n\n", mytime->tm_hour, mytime->tm_min);
}