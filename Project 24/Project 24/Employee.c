#include "database.h"
#include "Employee.h"
#include "UnitTest_Worker.h"
#include "MinUnit.h"

/*function to employer login*/
void LogIn_Employee()
{
	char TEMP_id[10];
	char TEMP_pass[10];
	Employee Employer;
	while (getchar() != '\n');
	int i = 0;
	// get user idintification
	system("cls");
	printf("******************************************************************************************\n");
	printf("*-----------------------------------hello worker!----------------------------------------*\n");
	printf("******************************************************************************************\n");
	printf("please enter your ID(enter '0' to back to main login menu): ");
	scanf("%s", TEMP_id);
	if (TEMP_id[0] == '0')
	{
		system("cls");
		return;
	}
	fflush(stdin);
	printf(" enter password(enter '0' to back to main login menu): ");
	while (i <= 10) {
		if (i == 9)
			break;
		TEMP_pass[i] = getch();
		printf("*");
		i++;
	}
	TEMP_pass[i] = '\0';
	//scanf("%s", TEMP_pass);
	if (TEMP_pass[0] == '0')
	{
		system("cls");
		return;
	}

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
	else if (!strcmp(Employer.status, "active"))
		WorkerMenu(Employer);

	
}
/*function to write entry date and time to WorkingHours.txt, function search ID in database and write 
date and time*/
void EntryTime(char *ID) 
{

	time_t now;
	time(&now);
	struct tm *mytime = localtime(&now);
	empl_hours *this_timeArray=NULL, this_time;
	int cnt = 0,cnt1=1,i;
	char line[255];
	char name[20];
	FILE *myFile;
	sprintf(name, "%s.txt", ID);
	myFile = fopen(name, "r+");
	if (myFile == NULL) 
	{
		myFile = fopen(name, "w");
		fprintf(myFile,"%02d.%02d.%d ", mytime->tm_mday, mytime->tm_mon + 1, mytime->tm_year + 1900);
		fprintf(myFile,"%02d:%02d ", mytime->tm_hour, mytime->tm_min);
		fprintf(myFile,"%02d:%02d\n", -1, -1);
		fclose(myFile);
		return ;
	}
	//conting lines
	while (fgets(line, sizeof line, myFile) != NULL)
		cnt++;
	rewind(myFile);
	//this_timeArray = (empl_hours*)malloc(cnt * sizeof(empl_hours));
	//for (i = 0; i < cnt; i++)
	//	fscanf(myFile, "%d.%d.%d %d:%d %d:%d", &this_timeArray[i].d, &this_timeArray[i].m, &this_timeArray[i].y, &this_timeArray[i].h_s, &this_timeArray[i].m_s, &this_timeArray[i].h_e, &this_timeArray[i].m_e);
	//go to end line
	while (cnt1 != cnt)
	{
		fgets(line, sizeof line, myFile) != NULL;
		cnt1++;
	}
	fscanf(myFile, "%d.%d.%d %d:%d %d:%d", &this_time.d, &this_time.m, &this_time.y, &this_time.h_s, &this_time.m_s, &this_time.h_e, &this_time.m_e);
	if (this_time.d == mytime->tm_mday && this_time.m == mytime->tm_mon + 1 && this_time.y == mytime->tm_year + 1900)
	{
		if (this_time.h_e != -1)
		{
			fseek(myFile, 0, SEEK_CUR);
			fprintf(myFile, "\n%02d.%02d.%d ", this_time.d, this_time.m, this_time.y);
			fprintf(myFile, "%02d:%02d ", mytime->tm_hour, mytime->tm_min);
			fprintf(myFile, "%02d:%02d\n", -1, -1);
			fclose(myFile);
		}
		return;
	}
	fseek(myFile, 0, SEEK_CUR);
	fprintf(myFile, "\n%02d.%02d.%d ", mytime->tm_mday, mytime->tm_mon + 1, mytime->tm_year + 1900);
	fprintf(myFile, "%02d:%02d ", mytime->tm_hour, mytime->tm_min);
	fprintf(myFile, "%02d:%02d\n", -1, -1);
	/*
	if (this_timeArray)
		free(this_timeArray);
		*/
	fclose(myFile);
	

		//HoursArray[size - 1].tm_h[size1 - 1].d = (buffer[0]-48)*10 + buffer[1] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].m = (buffer[3]-48)*10 + buffer[4] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].y = (buffer[6]-48)*1000 + (buffer[7]-48)*100 + (buffer[8]-48)*10 + buffer[9] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].s_h = (buffer[13]-48)*10 + buffer[14] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].s_m = (buffer[16] - 48) * 10 + buffer[17] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].e_h = (buffer[21] - 48) * 10 + buffer[22] - 48;
		//HoursArray[size - 1].tm_h[size1 - 1].e_m = (buffer[24] - 48) * 10 + buffer[25] - 48;


	printf("Date is: %d.%d.%d\n", mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900);
	printf("The time of entry is: %d:%d\n\n", mytime->tm_hour, mytime->tm_min);
}
/*function to add exit time*/
void ExitTime(char *ID)
{
	time_t now;
	time(&now);
	struct tm *mytime = localtime(&now);
	empl_hours this_time;
	int cnt = 0, cnt1 = 1, i;
	char line[255];
	char name[20];
	FILE *myFile;
	sprintf(name, "%s.txt", ID);
	myFile = fopen(name, "r+");
	if (myFile == NULL) {
		printf("File could not be opened\n");
		return;
	}
	while (fgets(line, sizeof(line), myFile) != NULL)
		cnt++;
	rewind(myFile);
	while (cnt != cnt1)
	{
		fgets(line, sizeof(line), myFile);
		cnt1++;
	}
	fscanf(myFile, "%d.%d.%d %d:%d %d:%d", &this_time.d, &this_time.m, &this_time.y, &this_time.h_s, &this_time.m_s, &this_time.h_e, &this_time.m_e);
	if (this_time.h_e == -1)
	{
		fseek(myFile, -22, SEEK_CUR);
		fprintf(myFile, "%02d.%02d.%d ", mytime->tm_mday, mytime->tm_mon + 1, mytime->tm_year + 1900);
		fprintf(myFile, "%02d:%02d ", this_time.h_s, this_time.m_s);
		fprintf(myFile, "%02d:%02d\n", mytime->tm_hour, mytime->tm_min);
	}
	fclose(myFile);
}
/*options for regular worker*/
void WorkerMenu(Employee Employer)
{
	EntryTime(Employer.ID);
	char choose=-1;
	while (getchar() != '\n');
	system("cls");
	while (choose != '0')
	{
		printf("Hello %s %s.\n", Employer.name, Employer.lastName);
		printf("-------======This is a menu for your permissions!======--------.\n");
		printf("[1] - To Tasks Manager.\n");
		printf("[2] - To list of citizen requests in status open.\n");
		printf("[9] - To exit ,           press '0'.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':
			TasksManager(Employer);
			break;
		case '2':
			ListRequests(Employer);
			break;
		case '3':
			runtests();
			break;
		case '4':

			break;
		case '0':
			ExitTime(Employer.ID);
			LogIn_Employee();
			break;
		default:
			printf("Wrong enter, please try again...\n");
			break;
		}
		while (getchar() != '\n');

	}

}
/*function to take all tasks from database to array and print to worker*/
void TasksManager(Employee Employer)
{
	int fieldIndex;		//Index of value column
	int numberOfFiltered = 0;
	FILE *myFile;
	char buffer[255];	//Current row content
	char temp[10], c[4];		//Column data to compare with sent value 
	Tasks *filteredResults = NULL;
	int resultArrSize=0,i,j;
	myFile = fopen(TASKS_MANAGER_DB, "r");
	//Check file
	if (myFile == NULL) {
		printf("File could not be opened\n");
		return 0;
	}

	//Search for proper column
	fieldIndex = findFieldIndex(myFile, "id");
	if (fieldIndex == -1) {
		printf("Can't find field you specified");
		return 0;
	}

	//Go to records
	fgets(buffer, sizeof buffer, myFile);

	//Get records till EOF
	while (fgets(buffer, sizeof buffer, myFile) != NULL) {

		//Copy data from proper column to temp
		strcpy(temp, getfieldValue(buffer, fieldIndex));

		//Append filtered record if value == temp
		if (!strcmp(Employer.ID, temp)) {

			if (numberOfFiltered == 0) 	filteredResults = (Tasks*)malloc(sizeof(Tasks));
			else filteredResults = (Tasks*)realloc(filteredResults, (numberOfFiltered + 1) * sizeof(Tasks));
			sscanf(buffer, "%[^;]", filteredResults[numberOfFiltered].number);
			sscanf(buffer + 17, "%[^;]", filteredResults[numberOfFiltered].task);
			sscanf(buffer+89, "%s", filteredResults[numberOfFiltered].status);
			numberOfFiltered++;
		}
	}
	fclose(myFile);
	system("cls");
	if (filteredResults)
	{
		printf("Your task manager is:\n");
		printf("N   task                                                                      status\n");
		for (i = 0; i < numberOfFiltered; i++)
			printf("%s ; %s ; %s\n", filteredResults[i].number, filteredResults[i].task, filteredResults[i].status);
		while (getchar() != '\n');
		
		printf("For update status of task enter a number of task?(press '0' to back):");
		scanf("%s", &c);
		if (c[0] == '0')
			system("cls");
		else
		{
			system("cls");
			if (ChangeStatusInTasks(TASKS_MANAGER_DB, c) == 1)
				printf("The task is updated.\n");
			else
				printf("The task is not updated.\n");
		}
	}

	else
	{
		printf("You not have tasks from manager...");
		printf("\n\n");
	}
	if (filteredResults)
		free(filteredResults);

}
/*function to change status of task manager in database*/
int ChangeStatusInTasks(char *filename, char *number)
{
	FILE *myFile;
	char buffer[255];	//Current row content
	char temp[4], status[14];
	myFile = fopen(filename, "r+");
	//Check file
	if (myFile == NULL) {
		printf("File could not be opened\n");
		return 0;
	}
	while (fgets(buffer, sizeof buffer, myFile) != NULL)
	{
		sscanf(buffer, "%[^ ]",temp);
		sscanf(buffer + 89, "%s", status);
		if (!strcmp(temp, number))
		{
			if (!strcmp(status, "open"))
			{
				fseek(myFile, -8, SEEK_CUR);
				fprintf(myFile, "closed\n");
				fclose(myFile);
				return 1;
			}
			return 0;
		}
	}
}
/*function to list all citizen requests*/
void ListRequests(Employee Employer)
{
	Requests *ReqList=NULL,temp;
	int sizeOfList = 0,i,flag=0;
	char number[4];
	ReqList = CreateRequestList(&sizeOfList);
	printf("  N    citizen_ID Empl_ID    N_Car      Request         Sub_date    Status    Comment\n");
	for (i = 0; i < sizeOfList; i++)
		if (!strcmp(ReqList[i].Status, "open    "))
		{
			flag = 1;
			printf("[%s]; %9s; %9s; %s; %14s; %02d.%02d.%d; %7s; %s\n", ReqList[i].num, ReqList[i].Citizen_ID, ReqList[i].Empl_ID, ReqList[i].N_car, ReqList[i].Request, ReqList[i].d, ReqList[i].m, ReqList[i].y, ReqList[i].Status, ReqList[i].Comment);
		}
	if (flag)
	{
		printf("For update status of request enter a number of request(press '0' to back):");
		scanf("%s",number);
	}
	else
		printf("You not have any requests to update.");
	if (ReqList)
		free(ReqList);
	
}
/*create requests list by filed and text in field*/
Requests *CreateRequestList(int *sizeOfList)
{
	Requests *ReqList = NULL, temp;
	FILE *myFile;
	char buffer[255];	//Current row content
	myFile = fopen(REQUESTS_DB, "r");
	//Check file
	if (myFile == NULL) {
		printf("File not found.\n");
		return;
	}
	fgets(buffer, sizeof buffer, myFile);
	while (fgets(buffer, sizeof buffer, myFile) != NULL)
	{
		sscanf(buffer, "%[^;]; %[^;]; %[^;]; %[^;]; %[^;]", temp.num, temp.Citizen_ID, temp.Empl_ID, temp.N_car, temp.Request);
		sscanf(buffer + 55, "%d.%d.%d", &temp.d, &temp.m, &temp.y);
		sscanf(buffer + 67, "%[^;]; %s", temp.Status, temp.Comment);
		
		if (*sizeOfList == 0) 	ReqList = (Requests*)malloc(sizeof(Requests));
		else ReqList = (Requests*)realloc(ReqList, (*sizeOfList + 1) * sizeof(Requests));
		ReqList[*sizeOfList] = temp;
		(*sizeOfList)++;
	}
	fclose(myFile);
	return ReqList;
}
/*function to change status of request in database*/
int ChangeStatusOfRequest(char *filename, char *number)
{

}