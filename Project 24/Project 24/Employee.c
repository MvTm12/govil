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
	EntryTime(TEMP_id);
	scanf("%s", TEMP_pass);
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
void WorkerMenu(char *ID)
{

}