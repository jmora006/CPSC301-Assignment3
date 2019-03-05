#include "person.cpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void readData(vector<Person> &employees)
{
	string fName, lName, coName;
	int id;
	float pay, hours;
	string line;
	Person person;
	
	ifstream file("input.txt");
	if(file.is_open())
	{
		while(file>>fName>>lName>>id>>coName>>hours>>pay)
		{
			person.setFirstName(fName);
			person.setLastName(lName);
			person.setEmployeeId(id);
			person.setCompanyName(coName);
			person.setHoursWorked(hours);
			person.setPayRate(pay);
			employees.push_back(person);
		}
	}
	
	file.close();
}

void getCompanies(vector<Person> &employees, vector<string> &compNames)
{
  string tmp;
  
  for(int i = 0; i < employees.size(); i++)
  {
  	tmp = employees.at(i).getCompanyName();
  	if(count(compNames.begin(), compNames.end(), tmp) == 0)
  	{
  		compNames.push_back(tmp);
  	}
  }
}

void printHighestPaid(vector<Person> &employees)
{
	float high, comp;
	int id, ind;
	string name, coName;
	
	for(int i = 0; i < employees.size(); i++)
	{
		comp = employees.at(i).totalPay();
		if(comp > high)
		{
			high = comp;
			ind = i;
		}
	}
	
	name = employees.at(ind).fullName();
	id = employees.at(ind).getEmployeeId();
	coName = employees.at(ind).getCompanyName();
	
	cout<<"HighestPaid: "<<name<<endl;
	cout<<"Employee ID: "<<id<<endl;
	cout<<"Employer: "<<coName<<endl;
	cout<<"Total Pay: $"<<setprecision(2)<<fixed<<employees.at(ind).totalPay()<<endl;
}

void separateAndSave(vector<Person> &employees, vector<string> &compNames)
{
  string comp, empComp, fName, lName, coName;
  int id;
  float empTotal, compTotal;
  
  for(int i = 0; i < compNames.size(); i++)
  {
  	compTotal = 0.0;
  	comp = compNames.at(i);
  	
  	ofstream file(comp + ".txt");
  	file.close();
  	file<<"-------------"<<endl;
  	
  	for(int j = 0; j < employees.size(); j++)
  	{
  		ofstream file(comp + ".txt", ofstream::out | ofstream::app);
  		empComp = employees.at(j).getCompanyName();
  		
  		if(comp == empComp)
  		{
  			if(file.is_open())
  			{
  				fName = employees.at(j).getFirstName();
  				lName = employees.at(j).getLastName();
  				id = employees.at(j).getEmployeeId();
  				coName = employees.at(j).getCompanyName();
  				empTotal = employees.at(j).getPayRate() * employees.at(j).getHoursWorked();
  				
  				file<<setprecision(2)<<fixed<<setw(10)<<left<<fName<<setw(7)<<left<<lName<<setw(4)<<right<<id<<" "<<setw(compNames[i].size())<<coName<<" $"<<empTotal<<endl;
  				compTotal += empTotal;
  			}
  		}
  		
  		if(j == (employees.size() - 1))
  		{
  			file<<setprecision(2)<<fixed<<"Total $"<<compTotal<<endl;
  		}
  	}
  	file.close();
  }
}

int main()
{
	vector<Person> employees;
	vector<string> companyNames;
	
	readData(employees);
	getCompanies(employees, companyNames);
	printHighestPaid(employees);
	separateAndSave(employees, companyNames);
	cin.get();
	return 0;
}
