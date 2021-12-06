#include<iostream>
#include<string.h>
#include"regionalmanager.hpp"
#define BLUE "\x1b[34;3m\t\t\t\t\t"
#define RESET "\x1b[0m"
#define BLACK "\x1b[30;3m\t\t\t\t\t"
#define GREEN "\x1b[32;3m"
#define RED "\x1b[31;3m\t\t\t\t\t"
#define CYAN "\033[3;36m"
#define FORMAT "\x1b[0m"
using namespace std;

RegionalManager::RegionalManager(int empId) : Manager(empId)
{
    env=Environment::createEnvironment();
    con=env->createConnection("e838243","Er.anshu04","ILPChnUnix");

}

void RegionalManager::startupRegionalManager(int rank,int eid)
{
    char ch;
    int Choice;
    char option;
    do
    {
	header();
	cout<<"                   ********** Welcome to Regional Manager Startup Page **********"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;

	cout<<endl;
	cout<<BLUE<<"1.Bank Management"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"2.Bank Account Management"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"3.Employee Management"<<FORMAT<<endl<<endl; 
	cout<<BLUE<<"4.Logout"<<RESET<<endl<<endl;
	cout<<BLUE<<"5.Exit Application"<<RESET<<endl<<endl;
	cout<<endl<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-5]  : "<<FORMAT;

	Choice=val.getIntegerValue();
	switch(Choice)
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
	    default:
		system("read -n1 -r -p \"\033[3;31m\n\n                                            Invalid     Input\n\n\n                     Press any key to continue with Regional Manager Functions.\033[0m\"  key");
	}
    }while(1);

}

void RegionalManager::bankManagement(int rank,int eid)
{
    char ch;
    do
    {
	header();
	cout<<"\033[3;30m                    ******************** Welcome to Bank Management *******************\033[0m"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl<<endl;

	int Choice;
	cout<<BLUE<<"1.Add Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"2.Update Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"3.View Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"4.View Single Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"5.Close Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"6.Go back to previous page "<<FORMAT<<endl<<endl;
	cout<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-6]  :  \033[0m";

	Choice=val.getIntegerValue();
	switch(Choice)
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
		cout<<endl<<RED<<"Invalid Choice Entered"<<FORMAT<<endl;
	}
	cout<<endl<<"\033[3;31m\t\t\tDo you want to continue Bank Management?(y/n)  : "<<RESET;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;

}

void RegionalManager::bankAccountManagement()
{
    int Choice;
    char ch;
    do
    {
	header();
	cout<<"                     ********** Welcome to Bank Account Management **********"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl<<endl;

	cout<<BLUE<<"1.View Messages"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"2.Distribute Funds"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"3.Revert Funds"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"4.Request Central Bank for Money"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"5.Go back to previous page"<<FORMAT<<endl<<endl;
	cout<<endl<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-5]  : "<<FORMAT;

	Choice=val.getIntegerValue();
	switch(Choice)
	{
	    case 1:
		viewMessages();
		break;
	    case 2:
		distributeFunds();
		break;
	    case 3:
		revertFunds();
		break; 
	    case 4:
		requestCentralBank();
		break;
	    case 5:
		return;
	    default:
		cout<<endl<<RED<<"Invalid Choice entered"<<FORMAT<<endl;

	}
	cout<<endl<<"\033[3;31m\t\t\tDo you want to continue Bank Account Management?(y/n)  : "<<RESET;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');
    if(ch=='n' || ch =='N')
	return;

}
void RegionalManager:: employeeManagement(int rank, int eid)
{
    int choice;
    char ch;
    do
    {
	header();
	cout<<"                   ********** Welcome to Regional Manager Employee Management **********"<<    endl;
	cout<<"\033[3;36m_____________________________________________________________________________________________________\033[0m"<<endl<<endl;
	cout<<BLUE<<"1.Add Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"2.Update Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"3.Remove Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"4.Display All Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"5.Display Single Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"6.Go back to previous page"<<FORMAT<<endl<<endl;
	cout<<endl<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-6]  : "<<FORMAT;

	choice=val.getIntegerValue();
	switch(choice)
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
		cout<<endl<<RED<<"Invalid choice selected"<<FORMAT<<endl;
	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue Employee Management?(y/n)  : "<<RESET;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;

}

void RegionalManager::requestCentralBank()
{
    header();
    cout<<"                   *************************** Fund Request ***************************"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
    BankAccount b;
    Employee e;
    int toEmployeeId;
    string message;

    cout<<endl<<BLUE<<"Requester Bank Id                : "<<RESET<<workingBankId;

    cout<<endl;
    st=con->createStatement();
    string query="select report_bid from bank where bank_id=:1";
    st->setSQL(query);
    st->setInt(1, workingBankId);
    rs=st->executeQuery();
    rs->next();
    b.toBankId=rs->getInt(1);
    cout<<endl<<BLUE<<"Id of the bank to be requested   : "<<RESET<<b.toBankId;

    cout<<endl<<endl;
    cout<<endl<<BLUE<<"Message                          : "<<RESET;

    getline(cin>>ws, message);
    st=con->createStatement();
    query="Insert into report values(0, :1, :2, :3, message_seq.NEXTVAL)";
    st->setSQL(query);
    st->setInt(1, workingBankId);
    st->setInt(2, b.toBankId);

    st->setString(3, message);
    st->executeUpdate();
    st->closeResultSet(rs);
    con->terminateStatement(st);
    con->commit();

    cout<<endl<<endl<<GREEN<<"                                        Message sent successfully"<<RESET;
    cout<<endl<<endl;
}

RegionalManager::~RegionalManager()
{
}

