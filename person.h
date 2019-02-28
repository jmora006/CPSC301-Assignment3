#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
	Person();
	void   setFirstName(string fName);
	string getFirstName();
	void   setLastName(string lName);
	string getLastName();
	void   setEmployeeId(int id);
	int    getEmployeeId();
	void   setCompanyName(string coName);
	string getCompanyName();
	void   setPayRate(float rate);
	float  getPayRate();
	void   setHoursWorked(float hours);
	float  getHoursWorked();
	float  totalPay();
	string fullName();

private:
	string firstName;
	string lastName;
	int    employeeID;
	string companyName;
	float  hoursWorked;
	float  payRate;
};
#endif
