#define _CRT_SECURE_NO_WARNINGS
#include "database.h"
#include "Employee.h"

#include <string.h>



//Add new entry to data base
//returns 1 for success 0 for failure
int DBaddPerson(char* fileName, Person newPerson) {

	FILE *myFile = fopen(fileName, "a+");

	fprintf(myFile, "%-9s ;", newPerson.ID);
	fprintf(myFile, " %-11s ;", newPerson.name);
	fprintf(myFile, " %-11s ;", newPerson.lastName);
	fprintf(myFile, " %-10s ;", newPerson.telephone);
	fprintf(myFile, " %-3d ;", newPerson.age);
	fprintf(myFile, " %-6s ;", newPerson.gender);
	fprintf(myFile, " %-20s ;", newPerson.city);
	fprintf(myFile, "\n");

	fclose(myFile);

	return 1;
}

//Read from data base 
//returns 1 for success 0 for failure
Person* DBreadPeople(char* fileName, char* field, char* value , int* resultArrSize) {
	int fieldIndex;		//Index of value column
	int numberOfFiltered = 0;
	FILE *myFile;
	char buffer[255];	//Current row content
	char temp[25];		//Column data to compare with sent value 
	Person* filteredResults = NULL;

	myFile=fopen(fileName, "r");
	//Check file
	if (myFile == NULL) {
		printf("File could not be opened\n");
		return 0;
	}

	//Search for proper column
	fieldIndex = findFieldIndex(myFile, field);
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
		if (!strcmp(value, temp)) {
			
			if (numberOfFiltered == 0) 	filteredResults = (Person*)malloc(sizeof(Person));
			else filteredResults = (Person*)realloc(filteredResults, (numberOfFiltered + 1) * sizeof(Person));

			//Just to simplify and shorten sscanf
			char* ID = filteredResults[numberOfFiltered].ID;
			char* name = filteredResults[numberOfFiltered].name;
			char* lastName = filteredResults[numberOfFiltered].lastName;
			char* telephone = filteredResults[numberOfFiltered].telephone;
			int* age = &(filteredResults[numberOfFiltered].age);
			char* gender = filteredResults[numberOfFiltered].gender;
			char* city = filteredResults[numberOfFiltered].city;
			
			sscanf(buffer, "%s ; %s ; %s ; %s ; %d ; %s ; %s", ID, name, lastName, telephone, age, gender, city);

			numberOfFiltered++;
		}
	} 

	fclose(myFile);
	*resultArrSize = numberOfFiltered;
	return filteredResults;
}
Employee DBreadEmployee(char* fileName, char* field, char* value)
{
	int fieldIndex;		//Index of value column
	FILE *myFile;
	char buffer[255];	//Current row content
	char temp[25];		//Column data to compare with sent value 
	Employee Employer;
	int flag = 0;

	myFile = fopen(fileName, "r");
	//Check file
	if (myFile == NULL) 
	{
		printf("File could not be opened\n");
		return ;
	}

	//Search for proper column
	fieldIndex = findFieldIndex(myFile, field);
	if (fieldIndex == -1) 
	{
		printf("Can't find field you specified");
		return ;
	}

	//Go to records
	fgets(buffer, sizeof buffer, myFile);

	//Get records till EOF
	while (fgets(buffer, sizeof buffer, myFile) != NULL)
	{

		//Copy data from proper column to temp
		strcpy(temp, getfieldValue(buffer, fieldIndex));

		//Append filtered record if value == temp
		if (!strcmp(value, temp))
		{
			sscanf(buffer, "%s ; %s ; %s ; %s", Employer.ID, Employer.name, Employer.lastName, Employer.status);
			flag = 1;
		}
	}
	if (!flag)
		strcpy(Employer.name, "None");
	fclose(myFile);
	return Employer;
}
char* getfieldValue(char* buffer, int fieldIndex) {
	int currentColumn = 0, bufferIndex = 0, valueIndex = 0;
	char c = ' ';
	char fieldValue[64] ;

	//Go to correct field
	if (currentColumn != fieldIndex){
		c = buffer[bufferIndex];
		for (bufferIndex; currentColumn != fieldIndex && c != '\n'; bufferIndex++) {
			if (c == ';') currentColumn++;
			c = buffer[bufferIndex];
		}
	}

	//Ignore Spaces
	while (isspace(c)) {
		c = buffer[bufferIndex++];
	}

	//Get value from the field
	for (bufferIndex; c != ';' && !isspace(c); bufferIndex++) {
		fieldValue[valueIndex++] = c;
		c = buffer[bufferIndex];
	}

	//Finalize String
	fieldValue[valueIndex] = '\0';

	return(fieldValue);
}

//Return -1 if field not found
int findFieldIndex(FILE *myFile, char *field) {
	int columnIndex = 0;
	char* word;
	
	word = getNextWord(myFile);
	while (word != NULL){ 

		//Check if identical
		if (!strcmp(field, word)) {
			return columnIndex;
		}

		//Get new word
		columnIndex++;
		word = getNextWord(myFile);
	}
	free(word);
	return -1;
}

//Return NULL if EOF or new Line 
char* getNextWord(FILE* myFile) {
	int length = 0;
	char c;
	char temp[20];

	c = fgetc(myFile);
	if (c == '\n' || c == EOF) return NULL; //End of the row/file
	while(c == ' ') c = fgetc(myFile);	//Ignore blanks at the beginning
	while (c != ' ' && c != '\n' && c != EOF) {//End of the row/word/file
		temp[length++] = c;
		c = fgetc(myFile);
	}

	//Finalize word
	temp[length] = '\0';
	return temp;
}


