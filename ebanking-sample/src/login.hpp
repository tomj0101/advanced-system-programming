#ifndef login_h
#define login_h
#include<iostream>
#include<string>
#include<occi.h>
#include<unistd.h>
#include<termios.h>

#include"bankemployee.hpp"
#include"generalmanager.hpp"
#include"regionalmanager.hpp"
#include"branchmanager.hpp"
#include"validation.hpp"
using namespace oracle::occi;
using namespace std;

class Login
{

    public:
	int empId,empRank;
	string empPassword;

	Login();
	int getch();
	string getPass(const char *prompt);
	void show(string,int);
	void head();
	void getUsernamePassword();
	void validateCredentials(int);
	void chooseDesignation();
	~Login();
};

#endif

