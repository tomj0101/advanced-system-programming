#include<iostream>
#include<occi.h>
#include<string.h>
#include<iomanip>
#include"manager.hpp"
using namespace std;
using namespace oracle::occi;

class RegionalManager :public Manager
{
    Environment *env;
    Connection *con;
    Statement *st;
    ResultSet *rs;

    public:
    RegionalManager(int);
    void startupRegionalManager(int,int);
    void requestCentralBank();
    void bankManagement(int, int);
    void bankAccountManagement();
    void employeeManagement(int, int);
    ~RegionalManager();
};

