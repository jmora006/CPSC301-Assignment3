#include "person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person()
{
	firstName = "N/A";
	lastName = "N/A";
	employeeID = 0;
	companyName = "N/A";
	hoursWorked = 0.0;
	payRate = 0.00;
}

void Person::setFirstName(string fName)
{firstName = fName;}

string Person::getFirstName()
{return firstName;}

void Person::setLastName(string lName)
{lastName = lName;}

string Person::getLastName()
{return lastName;}

void Person::setEmployeeId(int id)
{employeeID = id;}

int Person::getEmployeeId()
{return employeeID;}

void Person::setCompanyName(string coName)
{companyName = coName;}

string Person::getCompanyName()
{return companyName;}

void Person::setPayRate(float rate)
{payRate = rate;}

float Person::getPayRate()
{return payRate;}

void Person::setHoursWorked(float hours)
{hoursWorked = hours;}

float Person::getHoursWorked()
{return hoursWorked;}

float Person::totalPay()
{return getPayRate() * getHoursWorked();}

string Person::fullName()
{return firstName + " " + lastName;}
