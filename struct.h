// file is struct.h
#ifndef STRUCT_HEADER
#define STRUCT_HEADER


/* The file contains the structure declarations required by the program 
*/

/***************************************************************/

//DEFINES

#define NAME_SIZE     15	// size of array for patient/employee name (maximum name length is NAME_SIZE - 1)

//Patient related defines
#define PATIENT_TYPE 1      // determine that the record is a patient record
#define NUM_SEVERITIES 4  // number of different states of a patient
#define LIGHT 0
#define STABLE 1
#define ACCUTE 2
#define IMMEDIATE_SURGERY 3

//Employee related defines
#define EMPLOYEE_TYPE 0     // determines that the record is an employee record
#define MAX_POSITIONS 4     // number of different positions
#define DOCTOR 0
#define NURSE 1
#define SURGEON  2
#define ADMIN 3

// Department defines
#define MAX_DEPARTMENTS 6


/*****************************************************************/

// structure contains patient information 
//number of days in hospital,max days is defined as 30, and unsigned as cant be negative.
//severity of illness
//department in hospital      
// cost of hospitalization per day, changed to float as payment includes cents, can't make it any smaller though.
typedef struct patient {
  float dailyCost;
  unsigned char numDaysInHospital:5;
  unsigned char severity:2;
  char unused:1;
  unsigned char department:3;
} PatientRec;

/*
typedef struct patient {
  
}PatientRec;
*/

/*****************************************************************/



// structure contains employee information
//department in hospital
//years of service (7 bits as logically cant be more than 7 bits represented > 127 years of service, due to lifepsan
//annual salary, not enough information to modify (as salaries arent exact)
//position of employee in hospital

typedef struct employee {
  float salary;
  unsigned char yearsService:7;
  char unused:1;
  unsigned char department:3;
  unsigned char position:2;
} EmployeeRec;
/*****************************************************************/




// structure contains person information
typedef struct person {
  	char firstName[NAME_SIZE];
        unsigned char emplyeeOrPatient:1;
  	char familyName[NAME_SIZE];
        char unused:1;
	union {
		EmployeeRec emp;
		PatientRec patient;
	};
} PersonRec;

#endif
