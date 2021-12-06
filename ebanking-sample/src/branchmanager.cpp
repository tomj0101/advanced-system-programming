#include<iomanip>
#include<iostream>
#include<string.h>
#include<cstdlib>
#include "branchmanager.hpp"
#define BLUE "\x1b[34;3m\t\t\t\t\t"
#define BLACK "\x1b[30;3m\t\t\t\t\t"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32;3m"
#define RED "\x1b[31;3m\t\t\t\t\t"
using namespace std;
BranchManager::BranchManager()
{
    env=Environment::createEnvironment();
    con=env->createConnection("e838243","Er.anshu04","ILPChnUnix");

}

BranchManager::BranchManager(int empId) : Manager(empId)
{
    env=Environment::createEnvironment();
    con=env->createConnection("e838243","Er.anshu04","ILPChnUnix");

}

void BranchManager::startupBranchManager(int rank,int eid)
{
    int Choice;
    char ch,option,op1;
    int ch1,ch2;
    do
    {
	system("clear");
	header();
	cout<<"                   ********** Welcome to Branch Manager Startup Page **********"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;

	cout<<endl;
	cout<<BLUE<<"1.Bank Management"<<RESET<<endl<<endl;
	cout<<BLUE<<"2.Bank Account Management"<<RESET<<endl<<endl;
	cout<<BLUE<<"3.Employee Management"<<RESET<<endl<<endl;
	cout<<BLUE<<"4.Logout"<<RESET<<endl<<endl;
	cout<<BLUE<<"5.Exit Application"<<RESET<<endl<<endl;
	cout<<endl<<BLACK<<"Enter your choice"<<RESET<<"\033[3;31m[1-5]  : "<<RESET;

	ch1=val.getIntegerValue();
	switch(ch1)
	{
	    case 1:
		bankManagement(rank,eid);
		break;
	    case 2:
		bankAccountManagement();
		break;
	    case 3:
		employeeManagement(rank,eid);
		break;
	    case 4:
		return;
	    case 5:
		exit(1);
		break;
	    default:
		system("read -n1 -r -p \"\033[3;31m\n\n                                            Invalid     Input\n\n\n                              Press any key to continue with Branch Manager Functions.\033[0m\"  key");
	}
    }while(1);



}

void BranchManager::bankManagement(int rank,int eid)
{
    int Choice;
    char option,ch;
    int ch2;
    do
    {
	header();
	cout<<"\033[3;30m                    ******************** Welcome to Bank Management ********************\033[0m"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl<<endl;

	cout<<BLUE<<"1.Add Bank"<<RESET<<endl<<endl;
	cout<<BLUE<<"2.Update Bank"<<RESET<<endl<<endl;
	cout<<BLUE<<"3.View All Bank"<<RESET<<endl<<endl;
	cout<<BLUE<<"4.View Single Bank"<<RESET<<endl<<endl;
	cout<<BLUE<<"5.Close Bank"<<RESET<<endl<<endl;
	cout<<BLUE<<"6.Go back to Previous Menu "<<RESET<<endl<<endl;
	cout<<BLACK<<"Enter your choice"<<RESET<<"\033[3;31m[1-6]  :  \033[0m";


	ch2=val.getIntegerValue();
	switch(ch2)
	{
	    case 1:
		addBank(rank,eid);
		break;
	    case 2:	
		updateBank(rank,eid);
		break;
	    case 3:
		viewBank();
		break;
	    case 4:
		viewSingleBank();
		break;
	    case 5:
		closeBank(rank,eid);
		break;
	    case 6:
		return;
	    default:
		cout<<endl<<RED<<"Invalid choice selected"<<RESET<<endl;
	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue Bank Management?(y/n)  : "<<RESET;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;
}

void BranchManager::bankAccountManagement()
{
    int option;
    char ch;
    do
    {
	header();
	cout<<"                 ********************** Welcome to Bank Account Management **********************"<<endl;
	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;


	//cout<<BLUE<<"1.View Messages\n\n"<<RESET;
	cout<<BLUE<<"1.Revert Funds\n\n"<<RESET;
	cout<<BLUE<<"2.Request Regional Bank for Money\n\n"<<RESET;
	cout<<BLUE<<"3.Go Back to Previous Menu\n\n"<<RESET;
	cout<<endl<<"\t\t\t\t\tEnter your choice"<<"\x1b[31;3m [1-3]   : "<<RESET;


	option=val.getIntegerValue();
	switch(option)
	{

	    case 1:
		revertFunds();
		break;
	    case 2:
		requestRegionalBank();
		break;
	    case 3:
		return;
	    default:
		cout<<endl<<RED<<"Invalid choice selected"<<endl; 
	}
	cout<<endl<<"\033[3;31m\t\t\tDo you want to continue Bank Account Management?(y/n)  : "<<RESET;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;
}

void BranchManager::employeeManagement(int rank,int eid)
{
    int Choice;
    char option,op1,ch;
    int ch1,ch2;
    do
    {
	header();

	cout<<"                     ********** Welcome to Employee Management **********"<<endl;
	cout<<"\033[3;36m_____________________________________________________________________________________________________\033[0m"<<endl<<endl;

	cout<<BLUE<<"  1.Add Employee"<<RESET<<endl;
	cout<<endl<<BLUE<<"  2.Update Employee"<<RESET<<endl;
	cout<<endl<<BLUE<<"  3.Remove Employee"<<RESET<<endl;
	cout<<endl<<BLUE<<"  4.Display All Employees"<<RESET<<endl;
	cout<<endl<<BLUE<<"  5.Display Single Employee"<<RESET<<endl;
	cout<<endl<<BLUE<<"  6.Go Back to Previous Menu"<<RESET<<endl;      
	cout<<endl<<BLACK<<"Enter Your Choice"<<RESET<<"\033[3;31m[1-6] : "<<RESET;
	ch2=val.getIntegerValue();
	switch(ch2)
	{
	    case 1:
		addEmployee(rank,eid);
		break;
	    case 2:
		updateEmployee(rank,eid);
		break;
	    case 3:
		removeEmployee(rank,eid);
		break;
	    case 4:
		displayAllEmployee();
		break;
	    case 5:
		displayEmployee();
		break;
	    case 6:
		return;
	    default:
		cout<<endl<<RED<<"Invalid Choice selected"<<RESET<<endl;

	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue Employee Management?(y/n)  : "<<RESET;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;


}


void BranchManager::requestRegionalBank()
{
    header();
    cout<<"                   *************************** Fund Request ***************************"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
    BankAccount b;
    Employee e;
    int toEmployeeId;
    string message;

    cout<<endl;
    cout<<BLUE<<"Requester Bank ID        : "<<RESET<<workingBankId;
    cout<<endl<<endl;

    Statement *st1=con->createStatement();

    string query="select report_bid from bank where bank_id=:1";

    st1->setSQL(query);
    st1->setInt(1, workingBankId);
    rs=st1->executeQuery();
    rs->next();
    b.toBankId=rs->getInt(1);



    cout<<BLUE<<"Bank Id to be requested  : "<<RESET<<b.toBankId;

    cout<<endl<<endl;
    cout<<BLUE<<"Message                  : "<<RESET;
    getline(cin>>ws, message);

    cout<<endl;
    st=con->createStatement();
    query="Insert into report values(0, :1, :2, :3, message_seq.NEXTVAL)";
    st->setSQL(query);
    st->setInt(1, workingBankId);
    st->setInt(2, b.toBankId);

    st->setString(3, message);
    st->executeUpdate();
    con->commit();
    cout<<endl<<GREEN<<"                                        Message sent successfully"<<RESET;
    cout<<endl<<endl;
}

BranchManager::~BranchManager()
{
    env->terminateConnection(con);
    Environment::terminateEnvironment(env); 
}

