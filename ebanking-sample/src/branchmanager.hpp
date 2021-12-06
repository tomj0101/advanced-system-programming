#include<iostream>
#include<occi.h>
#include<string.h>
#include "manager.hpp"
using namespace std;
using namespace oracle::occi;


class BranchManager :public Manager
{
    Environment *env;
    Connection *con;
    Statement *st;
    ResultSet *rs;

    public:
    BranchManager();
    BranchManager(int);
    void startupBranchManager(int,int);
    void bankManagement(int,int);
    void bankAccountManagement();
    void employeeManagement(int,int);
    void requestRegionalBank();
    ~BranchManager();
};
