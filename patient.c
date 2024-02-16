

#include "string.h"
#include "stdio.h"
#include "patient.h"

// ADD DOCUMENTATION

//Purpose is to print a given patients information in a formatted table.
//Input: patient(person) to be printed.
/********************************************************************/
void printPatient(PersonRec *person)

{

  char name[30];
  float totalCost = (person->patient.numDaysInHospital)*(person->patient.dailyCost);
  sprintf(name, "%s %s", person->firstName, person->familyName);
  
  printf("\n%-33s dept: %d days in hospital:%3d severity: %d daily-cost: %5.2f total-cost: %0.2f", name, person->patient.department,person->patient.numDaysInHospital, person->patient.severity, person->patient.dailyCost, totalCost );

}

//Purpose is to take an array of persons and print all of the patients.
//Calls the helper function printPatient to iteratively print.
//Input: person - the array of people containing patients to be printed.
//numRecords - number of records printed (i.e size of person array).
/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{
  for (int x=0; x<numRecords; x++) {
    if(person->emplyeeOrPatient==1) {
    printPatient(person);
    }
    person++;
  }
  person=NULL;
}


//Purpose is to print the patients by department.
//Input: person - the array of people containing patients to be printed.
//numRecords - number of records printed (i.e size of person array).
/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{
  float total[3] = {0.0,0.0,0.0};
  float dep[6][4] = {{0.0,0.0,0.0,0.0}, {0.0,0.0,0.0,0.0}, {0.0,0.0,0.0,0.0}, {0.0,0.0,0.0,0.0}, {0.0,0.0,0.0,0.0}, {0.0,0.0,0.0,0.0}};
  for (int x=0; x<numRecords; x++) {
    if(person->emplyeeOrPatient==1) {
      total[0]+=1;
      total[1]+=person->patient.dailyCost;
      switch (person->patient.department) {
      case(1):
	dep[0][0]+=1;
	dep[0][1]=person->patient.dailyCost;
	dep[0][2]+=person->patient.dailyCost;
	break;
      case(2):
	dep[1][0]+=1;
	dep[1][1]=person->patient.dailyCost;
	dep[1][2]+=person->patient.dailyCost;
	break;
      case(3):
	dep[2][0]+=1;
	dep[2][1]=person->patient.dailyCost;
	dep[2][2]+=person->patient.dailyCost;
	break;
      case(4):
	dep[3][0]+=1;
	dep[3][1]=person->patient.dailyCost;
	dep[3][2]+=person->patient.dailyCost;
	break;
      case(5):
	dep[4][0]+=1;
	dep[4][1]=person->patient.dailyCost;
	dep[4][2]+=person->patient.dailyCost;
	break;
      case(6):
	dep[5][0]+=1;
	dep[5][1]=person->patient.dailyCost;
	dep[5][2]+=person->patient.dailyCost;
	break;
      default:
	break;
      }
    }
    person++;
  }
   total[2]=total[1]/total[0];
   dep[0][3]=dep[0][2]/dep[0][0];
   dep[1][3]=dep[1][2]/dep[1][0];
   dep[2][3]=dep[2][2]/dep[2][0];
   dep[3][3]=dep[3][2]/dep[3][0];
   dep[4][3]=dep[4][2]/dep[4][0];
   dep[5][3]=dep[5][2]/dep[5][0];
   
  printf("\nPatient Summary \nTotal number of patients:%0.0f total-cost-to-date%5.2f  average daily cost per patient:%0.2f", total[0], total[1], total[2]);
  printf("\nSummary by Department \nDepartment[1] - patients:%0.0f cost-to-date:%5.2f daily cost:%6.2f average daily cost per patient:%0.2f", dep[0][0], dep[0][1], dep[0][2], dep[0][3]);
  printf("\nDepartment[2] - patients:%0.0f cost-to-date:%5.2f daily cost:%6.2f average daily cost per patient:%0.2f", dep[1][0], dep[1][1], dep[1][2], dep[1][3]);
  printf("\nDepartment[3] - patients:%0.0f cost-to-date:%5.2f daily cost:%6.2f average daily cost per patient:%0.2f", dep[2][0], dep[2][1], dep[2][2], dep[2][3]);
  printf("\nDepartment[4] - patients:%0.0f cost-to-date:%5.2f daily cost:%6.2f average daily cost per patient:%0.2f", dep[3][0], dep[3][1], dep[3][2], dep[3][3]);
  printf("\nDepartment[5] - patients:%0.0f cost-to-date:%5.2f daily cost:%6.2f average daily cost per patient:%0.2f", dep[4][0], dep[4][1], dep[4][2], dep[4][3]);
  printf("\nDepartment[6] - patients:%0.0f cost-to-date:%5.2f daily cost:%6.2f average daily cost per patient:%0.2f", dep[5][0], dep[5][1], dep[5][2], dep[5][3]);
  person=NULL;


}

//Purpose is to search through the array of person for a given familyName and print the person(s)
//Input: person - the array of people containing patients to be printed.
//numRecords - number of records printed (i.e size of person array).
//familyName - last name to look for in the array and print patients containing it.
/********************************************************************/
void searchPatients(PersonRec *person, int numRecords, char familyName[])

{
  char found = 0;
  for (int x=0; x<numRecords; x++) {
    if(person->emplyeeOrPatient==1 && strcmp(person->familyName, familyName)==0) {
    printPatient(person);
    found=1;
    }
    person++;
  }
  if(found==0) {
    printf("We don't have that patient in our system, try again");
  }
  person=NULL;
}
