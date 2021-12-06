#ifndef occi_h
#define occi_h
#include<iostream>
#include<occi.h>
#include<cstdlib>
#include<sstream>
#include<limits>
#include<ctype.h>
#include <stdio.h>
#include<cstring>
#include<string>
#include<iomanip>
#include"employee.hpp"
#include"customer.hpp"
#include"customerAccount.hpp"
#include"customerTransaction.hpp"
#include"validation.hpp"
#define BLACK "\033[3;30m\t\t\t\t\t"
#define BLUE "\033[3;34m\t\t\t\t\t" 
#define RED "\033[3;31m\t\t\t\t\t"
#define END "\033[0m"
#define GREEN "\033[3;32m"
#define FORMAT "\033[3;30m"
#define FORMAT1 "\033[0m"
#define FORMAT2 "\033[3;31m"
#define FORMAT3 "\033[3;34m"

using namespace std;

using namespace oracle::occi;


class Bankemployee : public Employee
{



    public:
	Validations val1;
	Bankemployee(int);
	void header();
	void startBankEmployee();
	void startCustAccMgmt();
	void startCustomerServices();
	void startCustomerMgmt();
	void respondChequeRequest();
	void respondAtmRequest();
	void lockerRequest();
	void respondLockerRequest();
	void respondForeignExchange();
	void generateAccountStatement();
	void respondTransaction();
	void generateAccountBalance();
	void addCustomerAccount();
	void closeCustomerAccount();
	void updateCustomerAccount();
	void viewCustomerAccount();
	void getCustomerDetails();
	void addCustomerDetails();
	void updateCustomerDetails();
	void viewCustomerDetails();
	void deactivateCustomer();
	void viewForeignex();
	string to_string( int number );
	void deleteCustomer();
	void activateCustomer();
	int checkInteger();
	bool activeCheck(int);
	bool activeCustId(int);
};

#endif
