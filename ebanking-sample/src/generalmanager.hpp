#include<iostream>
#include<occi.h>
#include<string.h>
#include"manager.hpp"
using namespace std;
using namespace oracle::occi;


class GeneralManager :public Manager
{

    public:
	GeneralManager();
	GeneralManager(int);
	void bankAccountManagement();
	void bankManagement(int, int);
	void employeeManagement(int, int);
	void startupGeneralManager(int,int);
	void updateForeignExchange();
	void addInterest();
	~GeneralManager();
};

