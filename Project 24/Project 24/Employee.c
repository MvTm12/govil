#include "database.h"
#include "Employee.h"
/*function to employer login*/
void LogIn_Employee()
{
	char TEMP_id[10];
	char TEMP_pass[10];
	int numberOfFiltered = 0;
	Person* resultArr = NULL;

	// get user idintification
	printf("**** hello worker! ****\n ");
	printf("please enter your ID: ");
	scanf("%s", TEMP_id);
	fflush(stdin);
	printf(" enter password: ");
	fflush(stdin);
	scanf("%s", TEMP_pass);

	resultArr = DBreadPeople(PEOPLE_DB, "ID", TEMP_id, &numberOfFiltered);
	if (resultArr == NULL)
	{
		printf(" user not found \n");
		return;
	}
	if (strcmp(TEMP_id, TEMP_pass))
	{
		system("cls");
		printf("The password is incorrect.\n");
		printf("--------------------------\n");
		return;
	}
	//printf("ID          Name          LastName      Telephone    Age   Gender   City\n");
	//for (int i = 0; i < numberOfFiltered; i++)
	//printf("%-11s %-13s %-13s %-12s %-5d %-8s %-25s \n", resultArr[i].ID, resultArr[i].name, resultArr[i].lastName, resultArr[i].telephone,  resultArr[i].age, resultArr[i].gender, resultArr[i].city );

	// in this point the autorization approved and we continue

	// citizen main func


	if (resultArr != NULL)
		free(resultArr);
}