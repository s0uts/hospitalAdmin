#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

/**Prototypes**/
void printMenu();

#define NUM_RECORDS 20

int main(int argc, char *argv[])
{ 
	struct person *person = NULL;
	int numRecords = 0;         // number of records to be created
	char rc = 0;

	// check the command line parameters for correct number of paramaters
	// if the number is wrong prompt for correct usage and quit
	//add code to get the number of records to be created
	//if number of records is not given then instruct the user what is required.
	if (argc < 2 || strcmp(argv[1], "hospital")!=0) {
	  printf("Need to enter 'hospital num', where num=number of records to be created");
	} else if (argc < 3 || atoi(argv[2]) <1) {
	  printf("Need to enter a (positive) number of records to be created");
	} else {
	  numRecords=atoi(argv[2]);
	

	// populating the array person with data of patients and employees
	person=malloc(sizeof(PersonRec)*numRecords);
	populateRecords(person, numRecords);

	// add code here for menu handling
        int choice = -1;
	printMenu();
	while(choice != 0) {
	scanf("%d", &choice);
	switch(choice) {
	case(0):
	  int temp = -1;
	  printf("\nYou're about to quit, 0 to quit or 1 to cancel\n");
	  scanf("%d", &temp);
	  if (temp == 0) {
	    choice=0;
	  } else {
	    choice=-1;
	  }
	  break;
	case(1):
	  printEmployees(person, numRecords);
	  break;
	case(2):
	  printPatients(person, numRecords);
	  break;
	case(3):
	  char name[15];
	  printf("Enter a family name to search for\n");
	  scanf("%s", name);
	  searchPatients(person, numRecords, name);
	  break;
	case(4):
	  printEmployeesSummary(person, numRecords);
	  break;
	case(5):
	  printPatientSummary(person, numRecords);
	  break;
	case(6):
	  printf("\nSize of structures \nSize of PersonRec = %ld \nSize of EmployeeRec = %ld \nSize of PatientRec = %ld", sizeof(PersonRec), sizeof(EmployeeRec), sizeof(PatientRec));
	  break;
	default:
	  printf("Please enter a valid input between 0-6");
	  break;
	}
	printMenu();
	}
	}
	free(person);
	person=NULL;
	return 0;
}

//helper function to print the menu for readability
void printMenu() {
  printf("\n\nMenu options:\n1:Print all employees \n2 Print Patient List \n3:Search for all patients by Family Name \n4:Summary of Employees Data \n5:Summary by Department\n6:Size of structures(PersonRec, PatientRec and EmployeeRec) \n0:Quit \nEnter your choice:\n");
}



