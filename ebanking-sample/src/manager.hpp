#ifndef manager_h
#define manager_h
#include<iostream>
#include<occi.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<limits>
#include<unistd.h>
#include<occi.h>
#include"validation.hpp"
#include"employee.hpp"
#include"bankaccount.hpp"
using namespace std;
using namespace oracle::occi;

class Manager :public Employee
{

    public:
	Environment *env;
	Connection *con;
	Statement *st,*st1,*st2,*st3,*st4;
	ResultSet *rs;
	Validations val;
	Manager(int);
	Manager();
	void addBank(int,int);
	void again(string,int);
	void lockers();
	void closeBank(int,int);
	void del(int);
	void viewBank();
	void viewSingleBank();
	void up(int,string);
	void updateBank(int,int);
	void respondBranches(int,int);
	void viewMessages();
	void distributeFunds();
	void revertFunds();
	void header();
	void addEmployee(int,int);
	void updateEmployee(int,int);
	void removeEmployee(int,int);
	void displayAllEmployee();
	void displayEmployee();

	~Manager();
};
#endif
