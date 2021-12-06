#include<iostream>
#include<iomanip>
#include<string.h>
#include<cstdlib>
#include"generalmanager.hpp"
#define BLUE "\x1b[34;3m \t\t\t\t\t"
#define FORMAT "\x1b[0m"
#define YELLOW "\x1b[33;3m \t\t\t\t\t"
#define BLACK "\x1b[30;3m \t\t\t\t\t"
#define GREEN "\x1b[32;3m \t\t\t\t\t"
#define WHITE "\x1b[37;3m \t\t\t\t\t"
#define RED "\x1b[31;3m \t\t\t\t\t" 
#define CYAN "\033[3;36m"
using namespace std;

GeneralManager::GeneralManager(int empId) : Manager(empId)
{
}
GeneralManager::~GeneralManager()
{
}


/*--------------------------------------------------------
  Displays all the possible options for the General Manager
  to function
  ----------------------------------------------------------*/
void GeneralManager::startupGeneralManager(int rank,int eid)
{
    int Choice;
    char option;
    int flag=1;

    /*iterates the loop if the user wants to continue with 
      functionalities of the General Manager */
    do
    {
	system("clear");
	header();
	// cout<<"______________________________________________________________________________________________________"<<endl<<endl;
	cout<<"                   ********** Welcome to General Manager Startup Page **********"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;

	cout<<endl;
	cout<<BLUE<<"1.Bank Management"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"2.Bank Account Management"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"3.Employee Management"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"4.Add Interest"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"5.Update Foreign Exchange"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"6.Logout"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"7.Exit Application"<<FORMAT<<endl<<endl;
	cout<<endl<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-7]  : "<<FORMAT;

	Choice=val.getIntegerValue();

	//  chooses one of the startup options
	switch(Choice)
	{
	    case 1:
		bankManagement(rank, eid);
		break;
	    case 2:	
		bankAccountManagement();
		break;
	    case 3:
		employeeManagement(rank, eid);
		break;
	    case 5:
		updateForeignExchange();
		break;
	    case 4:
		addInterest();
		break;

	    case 6:
		return;
	    case 7:
		exit(1);
	    default:
		system("read -n1 -r -p \"\033[3;31m\n\n                                            Invalid Input\n\n\n                             Press any key to continue with General Manager Functions.\033[0m\"  key");	
	}
    }while(1);
}




/*---------------------------------------------------------
  Displays all the functions that can be carried out under 
  Bank Management like adding,deleting bank etc.
  --------------------------------------------------------*/

void GeneralManager::bankManagement(int rank, int eid)
{
    char ch;
    do
    {
	header();
	int option;
	cout<<"\033[3;30m                    ******************** Welcome to Bank Management ********************\033[0m"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl<<endl;


	cout<<BLUE<<"1.Add Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"2.Update Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"3.Close Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"4.View Single Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"5.View Bank"<<FORMAT<<endl<<endl;
	cout<<BLUE<<"6.Go back to previous page "<<FORMAT<<endl<<endl;
	cout<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-6]  :  \033[0m";

	option=val.getIntegerValue();

	//chooses one of the bank management options
	switch(option)
	{
	    case 1: addBank(rank, eid);
		    break;

	    case 2: updateBank(rank, eid);
		    break;

	    case 3: closeBank(rank, eid);
		    break;

	    case 4: viewSingleBank();
		    break;

	    case 5: viewBank();
		    break;

	    case 6: 
		    return;
		    break;
	    default:
		    cout<<endl<<RED<<"Invalid Choice Entered"<<FORMAT<<endl;
	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue Bank Management?(y/n)  : "<<FORMAT;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;
}



/*---------------------------------------------------------
  Displays all the functions that can be carried out under Bank
  Account Management like viewing fund request messages, distributing funds etc.
  --------------------------------------------------------*/

void GeneralManager::bankAccountManagement()
{
    int option;
    char ch;
    do
    {
	header();
	cout<<"                     ********** Welcome to Bank Account Management **********"<<endl;
	cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl<<endl;     


	cout<<BLUE<<"1.View Messages"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"2.Distribute Funds"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"3.Go back to previous page"<<FORMAT<<endl;
	cout<<endl<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-3]  : "<<FORMAT;
	option=val.getIntegerValue();

	//chooses one of the bank account management options
	switch(option)
	{
	    case 1: viewMessages();
		    break;

	    case 2: distributeFunds();
		    break;

	    case 3: 
		    return;
	    default:
		    cout<<endl<<RED<<"Invalid Choice entered"<<FORMAT<<endl;

	}
	cout<<endl<<"\033[3;31m\t\t\tDo you want to continue Bank Account Management?(y/n)  : "<<FORMAT;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');
    if(ch=='n' || ch =='N')
	return;

}



/*---------------------------------------------------------
  Displays all the functions that can be carried out under
  Employee Management like adding,deleting employee etc.
  --------------------------------------------------------*/

void GeneralManager::employeeManagement(int rank, int eid)
{
    int option;
    char ch;
    do
    {
	header();
	cout<<"                   ********** Welcome to General Manager Employee Management **********"<<endl;
	cout<<"\033[3;36m_____________________________________________________________________________________________________\033[0m"<<endl<<endl; 
	cout<<BLUE<<"1.Add Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"2.Update Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"3.Remove Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"4.Display Single Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"5.Display All Employee"<<FORMAT<<endl;
	cout<<endl<<BLUE<<"6.Go back to previous page"<<FORMAT<<endl;
	cout<<endl<<BLACK<<"Enter your choice"<<FORMAT<<"\033[3;31m[1-6]  : "<<FORMAT;
	option=val.getIntegerValue();

	//chooses one of the employee management options
	switch(option)
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
	    case 5:
		displayAllEmployee();
		break;
	    case 4:
		displayEmployee();
		break;
	    case 6:
		return;
	    default:
		cout<<endl<<RED<<"Invalid Choice entered"<<FORMAT<<endl;

	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue employee management?(y/n)  : "<<FORMAT;
	ch=val.getCharacter();
    }while(ch=='y'||ch=='Y');
    if(ch=='n' || ch =='N')
	return;
}

//to update values for buying and selling dollars for foreign exchange 
void GeneralManager::updateForeignExchange()
{
    char choice;
    int type,rupees,rupees1,rupees2,profit;
    header();
    cout<<"                   ********************** Update Foreign Exchange **********************"<<    endl;
    cout<<"\033[3;36m_____________________________________________________________________________________________________\033[0m"<<endl<<endl;

    stmt=con->createStatement();
    stmt->setSQL("select * from foreignex_info");
    //display the information of existing dollar's  buy and sell values
    rs=stmt->executeQuery();
    rs->next();
    cout<<"\033[3;30m\t\t\t\t      Type"<<setw(10)<<"Rupees"<<setw(10)<<"Profit"<<endl<<FORMAT;
    cout<<"\033[3;34m\t\t\t\t      "<<rs->getInt(1)<<setw(10)<<rs->getInt(2)<<setw(10)<<rs->getInt(3)<<FORMAT<<endl;
    rs->next();
    cout<<"\033[3;34m\t\t\t\t      "<<rs->getInt(1)<<setw(10)<<rs->getInt(2)<<setw(10)<<rs->getInt(3)<<FORMAT<<endl;
    stmt->closeResultSet(rs);
    con->terminateStatement(stmt);
    cout<<endl<<"\033[3;34m\t\t\t\tEnter Rupees Equivalent value for Dollar  : "<<FORMAT;
    rupees=val.getDouble();
    cout<<endl<<"\033[3;34m\t\t\t\tEnter  Dollar Sell amount : "<<FORMAT;
    rupees1=val.getDouble();
    cout<<endl<<"\033[3;34m\t\t\t\tEnter Dollar Buy amount  : "<<FORMAT;
    cin>>rupees2;
    cout<<endl;
    stmt=con->createStatement();
    profit=rupees1-rupees;
    //calculated profit and new sell value is updating in database
    stmt->setSQL("update foreignex_info set rupees=:1,profit=:2 where type=1");
    stmt->setInt(1,rupees1);
    stmt->setInt(2,profit);
    stmt->executeUpdate();
    con->commit();
    con->terminateStatement(stmt);
    profit=rupees-rupees2;
    //calculated profit and new buy value for dollar is updating in database
    stmt=con->createStatement();
    stmt->setSQL("update foreignex_info set rupees=:1,profit=:2 where type=2");
    stmt->setInt(1,rupees2);
    stmt->setInt(2,profit);
    stmt->executeUpdate();
    con->commit();
    con->terminateStatement(stmt);
    system("read -n1 -r -p \"\033[3;31m                     Press any key to continue with General Manager Functions\033[0m\"  key");
    return;


}

//Get the quarter and Add interest to Accounts of customer for that quarter
void GeneralManager::addInterest()
{
    header();
    cout<<"                   *************************** Add Interest ***************************"<<        endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl<<endl;

    int day,month,year,quarter,flag=0,q_year,bank_id,check=0;
    string issue,startdat1,endat1,startdat2,endat2,startdat3,endat3;//to assign 
    char ch;
    time_t now=time(0);
    tm *ltm=localtime(&now);
    day=ltm->tm_mday;
    month=1+ltm->tm_mon;
    year=1900+ltm->tm_year;
    cout<<BLUE<<"    Quarter : "<<FORMAT;
    quarter=val.getIntegerValue();
    cout<<endl<<BLUE<<"    Year    : "<<FORMAT;
    q_year=val.getIntegerValue();
    if(day<30)
    {
	cout<<endl<<RED<<"The date is  "<<day<<"-"<<month<<"-"<<year<<FORMAT<<endl;
	cout<<endl<<RED<<"Are you sure to proceed further?(y/n) : "<<FORMAT;
	ch=val.getCharacter();
	if(ch=='Y' || ch=='y')
	{
	}
	else
	{
	    return;
	}
    }
    if(q_year==year)
    {
	check++;
    }
    else if(quarter==4 && (q_year=year-1) && (month==12 || (month==1 && year==q_year+1)))
    {
	check++;
    }
    else
    {
	cout<<endl<<RED<<"Sorry you cannot give interest for this quarter "<<FORMAT<<endl<<endl;
	system("read -n1 -r -p \"\x1b[31;3m \t\t\t\t\t press any key to go back \033[0m \" key");
	return;
    }
    if(quarter==1)
    {
	if(month>=3)
	{
	    check++;
	}
    }
    else if(quarter==2)
    {
	if(month>=6)
	{
	    check++;
	}
    }
    else if(quarter==3)
    {
	if(month>=9)
	{
	    check++;
	}
    }
    else if(quarter==4)
    {
	if((month==12 && q_year==year) || (month==1 && (q_year=year-1)))
	{
	    check++;
	}
    }
    else
    {
	cout<<endl<<RED<<"Invalid Quarter"<<FORMAT<<endl<<endl;
	system("read -n1 -r -p \"\x1b[31;3m \t\t\t\t\t Press any key to continue \033[0m\" p");
	return;
    }
    if(check==2)
    {
	stmt=con->createStatement();
	char temp1[4];
	sprintf(temp1,"%d",q_year);
	stmt->setSQL("select quarter from interest_issue  where year=:1 and quarter=:2");
	//cout<<"checking quarter is issued or no"<<endl;
	stmt->setInt(1,q_year);
	stmt->setInt(2,quarter);
	rs=stmt->executeQuery();
	while(rs->next())//checking whether interest is already given for that quarter
	{
	    cout<<endl<<"\033[3;31m\t\t\t\tInterest is already issued for this Quarter"<<FORMAT<<endl<<endl;
	    flag=1;
	    stmt->closeResultSet(rs);
	    con->terminateStatement(stmt);
	    system("read -n1 -r -p \"\x1b[31;3m \t\t\t\t\t  Press any key to continue \033[0m \" p");
	    return;
	}
	stmt->closeResultSet(rs);
	con->terminateStatement(stmt);
	//sets start date and end date for each month of the quarter here date mentions only day and month in numerics
	if(flag==0)
	{
	    if(quarter==1)
	    {
		startdat1="1 1 ";
		endat1="31 1 ";
		startdat2="1 2 ";
		endat2="28 2 ";
		startdat3="1 3 ";
		endat3="31 3 ";
	    }
	    if(quarter==2)
	    {
		startdat1="1 4 ";
		endat1="30 4 ";
		startdat2="1 5 ";
		endat2="31 5 ";
		startdat3="1 6 ";
		endat3="30 6 ";
	    }
	    if(quarter==3)
	    {
		startdat1="1 7 ";
		endat1="31 7 ";
		startdat2="1 8 ";
		endat2="31 8 ";
		startdat3="1 9 ";
		endat3="30 9 ";
	    }
	    if(quarter==4)
	    {
		startdat1="1 10 ";
		endat1="31 10 ";
		startdat2="1 11 ";
		endat2="30 11 ";
		startdat3="1 12 ";
		endat3="31 12 ";
	    }
	    //adding year with dates
	    startdat1=startdat1 + temp1;
	    endat1=endat1 + temp1;
	    startdat2=startdat2 + temp1;
	    endat2=endat2 + temp1;
	    startdat3=startdat3 + temp1;
	    endat3=endat3 + temp1;
	    string dat[6]={startdat1,endat1,startdat2,endat2,startdat3,endat3};
	    //changing it to the format of database
	    for(int s=0;s<6;s++)
	    {
		stmt=con->createStatement();
		stmt->setSQL("select to_date(:1,'dd mm yy') from dual");
		stmt->setString(1,dat[s]);
		rs=stmt->executeQuery();
		rs->next();
		dat[s]=rs->getString(1);
		stmt->closeResultSet(rs);
		con->terminateStatement(stmt);
	    }
	    //querying account numbers and minimum balance for each account number for each month of the quarter in each iteration
	    for(int count=0;count<6;count++)
	    {
		stmt=con->createStatement();
		stmt->setSQL("select  acc_no,min(balance) from track_balance_tab where timestamp>=:1 and timestamp<=:2 group by acc_no");  
		stmt->setString(1,dat[count]);
		stmt->setString(2,dat[++count]);
		rs=stmt->executeQuery();
		//if records present
		while(rs->next())
		{
		    int acc_no;
		    double rec_balance,mini_balance,rate,balance;
		    acc_no=rs->getInt(1);
		    rec_balance=rs->getDouble(2);
		    Statement *stmt1=con->createStatement();
		    stmt1->setSQL("select mini_balance,balance,rate,bank_id from cust_account where acc_no=:1");//retrieving account properties to check  maintained minimum balance is greater than recorded minimum balance 
		    stmt1->setInt(1,acc_no);
		    ResultSet * rs1=stmt1->executeQuery();
		    rs1->next();
		    mini_balance=rs1->getDouble(1);
		    balance=rs1->getDouble(2);
		    rate=rs1->getDouble(3);
		    bank_id=rs1->getInt(4);
		    stmt1->closeResultSet(rs1);
		    con->terminateStatement(stmt1);
		    //checking recorded minimum balance is greater or equal to minimum balance of the account
		    if(mini_balance<=rec_balance)
		    {
			rec_balance=(rate*rec_balance)/100;
			balance=balance+rec_balance;
			stmt1=con->createStatement();
			stmt1->setSQL("update cust_account set balance=:1 where acc_no=:2");
			stmt1->setDouble(1,balance);
			stmt1->setInt(2,acc_no);
			stmt1->executeUpdate();
			con->commit();
			con->terminateStatement(stmt1);
			stmt1=con->createStatement();
			stmt1->setSQL("insert into cust_transaction values(trans_sequence.NextVal,'INTEREST',:1,:2,:3,sysdate)");
			stmt1->setDouble(1,rec_balance);
			stmt1->setInt(2,bank_id);
			stmt1->setInt(3,acc_no);
			stmt1->executeUpdate();
			con->commit();
			con->terminateStatement(stmt1);
		    }
		}
	    }
	    stmt->closeResultSet(rs);
	    con->terminateStatement(stmt);
	}
	//updates database about quarter and year for which interest give now.
	stmt=con->createStatement();
	stmt->setSQL("insert into interest_issue values(:1,:2)");
	stmt->setInt(1,quarter);
	stmt->setInt(2,q_year);
	stmt->executeUpdate();
	con->commit();
	con->terminateStatement(stmt);
	cout<<endl<<"\033[3;32m\t\t\t\t\tInterest Added succeflly"<<FORMAT<<endl<<endl;
    }
    else
    {
	cout<<endl<<RED<<"Sorry you cannot add interest for this quarter now"<<FORMAT<<endl<<endl;
    }
    system("read -n1 -r -p \"\033[3;31m                      Press any key to continue with General Manager Functions\033[0m\"  key");
    return;
}




