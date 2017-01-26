#include "Manager.h"
void ManagerMenu(Employee Employer)
{
	char choose = '#';
	int tempYear;
	while (getchar() != '\n');

	while (choose != '0')
	{
		if (choose != '#')
		{
			printf("Press any key to continue...\n");
			getchar();
		}
		system("cls");
		printf("Hello %s %s.\n", Employer.name, Employer.lastName);
		printf("-------======This is a menu for your permissions!======--------.\n");
		printf("[1] - Create 'Recall' message and save in Task Manager.\n");
		printf("[2] - To list of citizen requests in status open.\n");
		//printf("[3] - Check for disabled parking badge eligibility.\n");
		//printf("[4] - Get city by citizen ID.\n");
		//printf("[5] - Check if City exist in Ministry of Defence database.\n");
		printf("[6] - Add New Worker.\n");
		printf("[7] -cange worker status.\n");
		//printf("[8] - Print and save recall list.\n");
		//printf("[9] - Get and save working hours for this month.\n");
		printf("[0] - To exit.\n");
		printf("--------------------------------------------------\n");
		printf("Your choose: ");
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':
			CreateRecallMessage();
			break;
		case '2':
			GetOpReq();
			break;
		case '3':
			
			break;
		case '4':
			
			break;
		case '5':
		
			break;
		case '6':
			AddEmployee();
			break;
		case '7':
			changeStatus(Employer);
			break;
		case'8':
			
			break;
		case '9':
			
			break;
		case '0':
			
			return;
		default:
			system("cls");
			printf("Wrong enter, please try again...\n");
			break;
		}

	}

}
/*function to create recall message*/
void CreateRecallMessage()
{
	char model[13], choose,tempID[10], buffer[255];
	int year, sizeOfArray=0, i, flag=0,j;
	Employee *EmployeeArray=NULL;
	FILE *myFile;
	while (getchar() != '\n');
	printf("Enter a model of car: ");
	scanf("%s",model);
	printf("Enter a year of car: ");
	scanf("%d", &year);
	printf("Please choose employee to do the this task.\n");
	EmployeeArray = GetEmployesList(&sizeOfArray);
	printf("ID         LastName     Name\n");
	for (i = 0; i < sizeOfArray; i++)
		if (!strcmp(EmployeeArray[i].status, "active    "))
			printf("%-9s; %-11s; %-11s;\n", EmployeeArray[i].ID, EmployeeArray[i].lastName, EmployeeArray[i].name);
	printf("Please enter ID of employee that you want to give him a task\nID: ");
	i = 0;
	scanf("%s",buffer);
	while (i < 9)
		tempID[i]= buffer[i++];
	tempID[9] = '\0';
	for (i = 0; i < sizeOfArray; i++)
		if (!strcmp(EmployeeArray[i].ID, tempID))
		{
			flag = 1;
			break;
		}
	if (flag)
	{
		myFile = fopen(TASKS_MANAGER_DB, "r+");
		j = 0;
		while (fgets(buffer, sizeof buffer, myFile) != NULL)
			j++;
		sprintf(buffer, "export recall report by %s model that manufactured at %d", model, year);
		fprintf(myFile, "%2d; %-9s; %-70s; open  \n", j, EmployeeArray[i].ID, buffer);
		fclose(myFile);
	}
	else
		printf("Wrong enter...\n");
	if (EmployeeArray)
		free(EmployeeArray);
}
/*function to get array of employes*/
Employee *GetEmployesList(int *sizeOfArray)
{
	Employee *EmployeeArray = NULL,temp;
	FILE *myFile;
	char buffer[255];
	myFile = fopen(EMPLOYEES_DB, "r");
	fgets(buffer, sizeof buffer, myFile);
	while (fgets(buffer, sizeof buffer, myFile)!=NULL)
	{
		sscanf(buffer, "%[^;]; %[^;]; %[^;]; %[^;]", temp.ID, temp.name, temp.lastName, temp.status);
		if (strcmp(temp.status, "manager   "))
		{
			if (*sizeOfArray == 0)
				EmployeeArray = (Employee*)malloc(sizeof(Employee));
			EmployeeArray = (Employee*)realloc(EmployeeArray, (*sizeOfArray+1) *sizeof(Employee));
			EmployeeArray[*sizeOfArray] = temp;
			(*sizeOfArray)++;
		}
	}
	return EmployeeArray;
}
/*function to get requests that opened more than 5 days and set a task for employee*/
void GetOpReq()
{
	Requests *ReqList = NULL;
	int sizeOfList = 0, i, flag = 0,j;
	FILE *myFile;
	time_t now;
	time(&now);
	struct tm *mytime = localtime(&now);
	empl_hours this_time, today_date;
	char c, buffer[255],tempID[10];
	int sizeOfArray = 0;
	Employee *EmployeeArray = NULL;
	ReqList = CreateRequestList(&sizeOfList);

	today_date.d = mytime->tm_mday;
	today_date.m = mytime->tm_mon + 1;
	today_date.y = mytime->tm_year + 1900;
	system("cls");
	printf("  N    citizen_ID N_Car      Request         Sub_date\n");
	for (i = 0; i < sizeOfList; i++)
		if (!strcmp(ReqList[i].Status, "open    ") && ((today_date.d + ((today_date.m - 1) * 31) + ((today_date.y - 1) * 365)) - (ReqList[i].d + ((ReqList[i].m - 1) * 31) + ((ReqList[i].y - 1) * 365)) > 5))
		{
			flag = 1;
			printf("[%s]; %9s; %s; %14s; %02d.%02d.%d;\n", ReqList[i].num, ReqList[i].Citizen_ID, ReqList[i].N_car, ReqList[i].Request, ReqList[i].d, ReqList[i].m, ReqList[i].y);
		}
	if (!flag)
		printf("Not exist requests that open more then 5 days.");
	flag = 0;
	printf("[0] - Back to menu\n[1] - Create task with this report\n");
	while (getchar()!='\n');
	scanf("%c", &c);
	if (c == '0')
	{
		if (ReqList)
			free(ReqList);
		return;
	}
	else if (c == '1')
	{
		system("cls");
		EmployeeArray = GetEmployesList(&sizeOfArray);
		printf("ID         LastName     Name\n");
		for (i = 0; i < sizeOfArray; i++)
			if (!strcmp(EmployeeArray[i].status, "active    "))
				printf("%-9s; %-11s; %-11s;\n", EmployeeArray[i].ID, EmployeeArray[i].lastName, EmployeeArray[i].name);
		printf("Please enter ID of employee that you want to give him a task\nID: ");
		i = 0;
		scanf("%s", buffer);
		while (i < 9)
			tempID[i] = buffer[i++];
		tempID[9] = '\0';
		for (i = 0; i < sizeOfArray; i++)
			if (!strcmp(EmployeeArray[i].ID, tempID))
			{
				flag = 1;
				break;
			}
		if (flag)
		{
			myFile = fopen(TASKS_MANAGER_DB, "r+");
			j = 0;
			while (fgets(buffer, sizeof buffer, myFile) != NULL)
				j++;
			sprintf(buffer, "Update the requests that opened more than 5 days");
			fprintf(myFile, "%2d; %-9s; %-70s; open  \n", j, EmployeeArray[i].ID, buffer);
			fclose(myFile);
			printf("Task is added.\n");
		}
	}
	if (!flag)
		printf("Id is wrong.\n");
	if (EmployeeArray)
		free(EmployeeArray);
	if (ReqList)
		free(ReqList);
}
/* function that add new worker to Employee file
return 1 for success and 0 for failuar*/
int AddEmployee()
{
	int flag = 0;
	int i = 0;
	system("cls");
	char ID[10];
	char name[12];
	char lastName[12];
	char status[11];
	FILE *myFile;
	myFile = fopen(EMPLOYEES_DB, "a+");
	if (myFile == NULL)
	{
		printf("File could not be opened\n");
		return 0;
	}
	Employee *employeelist = NULL;
	int size = 0;
	employeelist = GetEmployesList(&size);
	printf("add new employee.\n");
	printf("------------------\n");
	printf(" Enter ID of new employee: (press 0 to go back) ");
	scanf("%s", ID);
	if (ID[0] == '0')
	{
		fclose(myFile);
		system("cls");
		return 0;
	}
	printf(" Enter first name of new employee:(press 0 to go back) ");
	scanf("%s", name);
	if (name[0] == '0')
	{
		fclose(myFile);
		system("cls");
		return 0;
	}
	printf(" Enter  last name of new employee:(press 0 to go back) ");
	scanf("%s", lastName);
	if (lastName[0] == '0')
	{
		fclose(myFile);
		system("cls");
		return 0;
	}
	printf(" Enter  status of new employee -active/manager/not-active:(press 0 to go back) ");
	scanf("%s", status);
	if (status[0] == '0')
	{
		fclose(myFile);
		system("cls");
		return 0;
	}
	for (i = 0; i < size; i++)
	{
		if (strcmp(employeelist[i].ID, ID) == 0)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("the employee already exsist.\n");
		fclose(myFile);
		return 0;
	}
	else
	{
		fprintf(myFile, "%-9s; %-11s; %-11s; %-10s;\n", ID, name, lastName, status);
		printf("successfully added!\n");
		fclose(myFile);
		return 1;
	}
}

int changeStatus(Employee manager)
{
	int flag = 0;
	char ID[10];
	char status[11];
	FILE *myFile;
	Employee *employeelist = NULL;
	int size = 0;
	employeelist = GetEmployesList(&size);
	int i,j;
	
	printf("Enter ID of new employee: (press 0 to go back) ");
	scanf("%s", ID);
	if (ID[0] == '0')
	{
		return 0;
	}
	printf("Enter  status of new employee -active/manager/not-active:(press 0 to go back) ");
	scanf("%s", status);
	if (status[0] == '0')
	{
		return 0;
	}
	for (i = 0; i < size; i++)
	{
		if(strcmp(employeelist[i].ID, ID) == 0)
			flag = 1;
	}
	if (flag == 0)
	{
		printf("Employee not exsist.\n");
		getchar();
		return 0;
	}
	myFile = fopen(EMPLOYEES_DB, "w");
	if (myFile == NULL)
	{
		printf("File could not be opened\n");
		getchar();
		return 0;
	}
	fprintf(myFile, "ID         Name         LastName     Status\n");
	employeelist=(Employee*)realloc(employeelist, (size+1) *sizeof(Employee));
	fprintf(myFile, "%-9s; %-11s; %-11s; %-10s;\n", manager.ID, manager.name, manager.lastName, manager.status);
	for (i = 0,j=1; j < size+1; i++,j++)
	{
		if (strcmp(employeelist[i].ID, ID) == 0)
		{
			strcpy(employeelist[i].status, status);
		}
		fprintf(myFile, "%-9s; %-11s; %-11s; %-10s;\n", employeelist[i].ID, employeelist[i].name, employeelist[i].lastName, employeelist[i].status);
	}
	printf("employee status changed successfully!\n");
	getchar();
	if (employeelist)
		free(employeelist);
	fclose(myFile);
	return 1;
}

int Hperemployee(char* emp_id, int month, int year)
{
	time_t now;
	time(&now);
	struct tm *mytime = localtime(&now);
	char line[255];
	char name[40];
	FILE *myFile;
	Employee *employeelist = NULL;
	empl_hours temp;
	int size = 0;
//	employeelist = GetEmployesList(&size);
	sprintf(name, "./Working_Hours/%s.txt", emp_id);
	myFile = fopen(name, "r+");
	if (myFile == NULL)
	{
		printf("File could not be opened\n");
		getchar();
		return 0;
	}
	int count = 0;
	
	while (fgets(line, sizeof(line), myFile) != NULL)
	{
		sscanf(line, "%d.%d.%d %d:%d %d:%d", &temp.d, &temp.m, &temp.y, &temp.h_s, &temp.m_s, &temp.h_e, &temp.m_e);
		if (temp.y == year && temp.m == month)
		{
			count += temp.h_e * 60 + temp.m_e - temp.h_s * 60 - temp.m_s;
		}
	}
	fclose(myFile);
	return count;
}