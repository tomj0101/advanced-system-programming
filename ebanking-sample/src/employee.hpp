#ifndef emp_h
#define emp_h
#include<iostream>
#include<string>
#include<occi.h>
using namespace oracle::occi;
using namespace std;

class Employee
{

    public:
	Environment *env;
	Connection *conn;
	Statement *stmt;
	ResultSet *rs,*rs1,*rs2;
	double salary;
	int employeeId,workingBankId,reportingHeadId,rank; 
	string employeeFirstName,employeeLastName,address,designation,dateOfJoining,password,password1,newPassword,newPassword1,region;
	Employee(int);
	Employee();
	~Employee();
};
#endif
