#include "employee.h"
#include "stdio.h"


// Purpose is to print a given employees information in a formatted table.
//Input: employee(person) to be printed.
void printEmployee(PersonRec *person)

{
  char name[30];
  float salaryToDate = (person->emp.salary)*(person->emp.yearsService);
  sprintf(name, "%s %s", person->firstName, person->familyName);
  
  printf("\n%-33s dept: %d  salary: %9.2f position: %d  years-of-service:%3d salary-to-date: %0.2f", name, person->emp.department, person->emp.salary, person->emp.position, person->emp.yearsService, salaryToDate);
}

//Purpose is to take an array of persons and print all of the employees.
//Calls the helper function printemployee to iteratively print.
//Input: person- the array of people containing employees to be printed.
//numRecords - number of records printed (i.e size of person array).
void printEmployees(PersonRec *person, int numRecords)
{
  for (int x=0; x<numRecords; x++) {
    if(person->emplyeeOrPatient==0) {
    printEmployee(person);
    }
    person++;
  }
  person=NULL;
}

//Purpose is to print the employees by position
//Input: person- the array of people containing employees to be printed.
//numRecords - number of records printed (i.e size of person array).
void printEmployeesSummary(PersonRec *person, int numRecords)
{

  float total[] = {0.0,0.0,0.0};
  float pos[4][3] = {{0.0,0.0,0.0}, {0.0,0.0,0.0}, {0.0,0.0,0.0}, {0.0,0.0,0.0}};
  for (int x=0; x<numRecords; x++) {
    if(person->emplyeeOrPatient==0) {
      total[0]+=1;
      total[1]+=person->emp.salary;
      switch (person->emp.position) {
      case(0):
	pos[0][0]+=1;
	pos[0][1]+=person->emp.salary;
	break;
      case(1):
	pos[1][0]+=1;
	pos[1][1]+=person->emp.salary;
	break;
      case(2):
	pos[2][0]+=1;
	pos[2][1]+=person->emp.salary;
	break;
      case(3):
	pos[3][0]+=1;
	pos[3][1]+=person->emp.salary;
	break;
      default:
	break;
      }
    }
    person++;
  }
   total[2] = total[1]/total[0];
   pos[0][2]=pos[0][1]/pos[0][0];
   pos[1][2]=pos[1][1]/pos[1][0];
   pos[2][2]=pos[2][1]/pos[2][0];
   pos[3][2]=pos[3][1]/pos[3][0];
   
   printf("\nEmployee Summary \nTotal number of employees:%0.0f Total Salary:%11.2f Average Salary:%0.2f", total[0], total[1], total[2]);
   printf("\n\nSummary by position \nPosition[0] - employees:%0.0f Total Salary:%11.2f Average Salary:%0.2f", pos[0][0], pos[0][1], pos[0][2]);
   printf("\nPosition[1] - employees:%0.0f Total Salary:%11.2f Average Salary:%0.2f", pos[1][0], pos[1][1], pos[1][2]);
   printf("\nPosition[2] - employees:%0.0f Total Salary:%11.2f Average Salary:%0.2f", pos[2][0], pos[2][1], pos[2][2]);
   printf("\nPosition[3] - employees:%0.0f Total Salary:%11.2f Average Salary:%0.2f", pos[3][0], pos[3][1], pos[3][2]);
   person=NULL;
}
