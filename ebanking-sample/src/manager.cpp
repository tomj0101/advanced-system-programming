#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<limits>
#include<unistd.h>
#include<occi.h>
#include<iomanip>
#include"manager.hpp"
#include"bank.hpp"
#define BLUE "\x1b[34;3m"
#define RESET "\x1b[0m"
#define RED "\x1b[31;3m" 
#define GREEN "\x1b[32;3m"
#define MAG "\x1b[22;35m"
#define BLACK "\033[3;30m"
using namespace std;


/*----------------------------------------------------------
  Function adds header to the top of every page whenever called
  from any function
  ------------------------------------------------------------*/
void Manager:: header()
{
    system("clear");
    cout<<"\x1b[41m                                                                                                       \x1b[0m"<<endl;
    cout<<"\033[3;30m                         *************Welcome to SAHARA BANKING**************\033[0m"<<endl;
    cout<<endl<<"\033[3;30m                           ********CORE BANKING MANAGEMENT SYSTEM*********\033[0m"<<endl;
    cout<<endl<<"\033[3;30m                               ****************************************\033[0m"<<endl;
    cout<<"\x1b[42m                                                                                                       \x1b[0m"<<endl<<endl;
    cout<<"\033[3;34m Logged In As :\033[0m\033[31m"<<employeeFirstName<<" "<<employeeLastName<<"\033[0m";
    cout<<"\033[3;34m          Designation  :\033[0m\033[31m"<<designation<<"\033[0m";
    cout<<"\033[3;34m          Employee ID :\033[0m\033[31m"<<employeeId<<"\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;


}

Manager::Manager(int empId) :Employee(empId)
{
    env=Environment::createEnvironment();
    con=env->createConnection("e838243","Er.anshu04","ILPChnUnix");
}
Manager::Manager()
{
}

/*The addBank() function is used to open a new bank by the different manage     rs under their authorised regions.
  Eg. of a Constraint - a North Manager can add banks only in north region an     d create lockers if wanted*/

void Manager::addBank(int rank,int eid)
{  
    Validations val;    
    int option;
    header();
    Bank b;
    Employee e;
    int count,Choice,rk;
    string reg;
    int count2,count3,count4;
    char Option;
    char ch;
    rk=rank;
    string sqlst="select region from employeedetails where rank=:1 AND emp_id=:2";
    st2=con->createStatement();
    st2->setSQL(sqlst);
    st2->setInt(1,rank);
    st2->setInt(2,eid);
    rs=st2->executeQuery();
    while(rs->next())
    {
	reg=rs->getString(1);
    }
    st2->closeResultSet(rs);
    con->terminateStatement(st2);

    do
    {   
        system("clear");
	header();
	cout<<"                   *************************** Add Bank ***************************"<<            endl;
	cout<<"\033[3;36m_____________________________________________________________________________________________________\033[0m"<<endl<<endl;

	if(rk==1)
	{   
	    cout<<endl<<"\033[4;31m\t\t\t\t\tSelect a Region"<<RESET<<endl;
	    cout<<endl<<BLUE<<"\t\t\t\t\t1.North"<<endl<<"\t\t\t\t\t2.South"<<endl<<"\t\t\t\t\t3.East"<<endl<<"\t\t\t\t\t4.West"<<endl<<"\t\t\t\t\t5.Central"<<endl<<RESET;
	    cout<<endl<<"\033[3;30m\t\t\t\t\tEnter Your Choice"<<RESET<<"\033[3;31m[1-5]  :  "<<RESET;
	    option=val.getIntegerValue();
	    switch(option)
	    {
		case 1:
		    b.region="North";
		    b.reportingBId=1001;
		    again(b.region,b.reportingBId);
		    break;
		case 2:
		    b.region="South";
		    b.reportingBId=1002;
		    again(b.region,b.reportingBId);
		    break;

		case 3:
		    b.region="East";
		    b.reportingBId=1003;
		    again(b.region,b.reportingBId);
		    break;

		case 4:
		    b.region="West";
		    b.reportingBId=1004;
		    again(b.region,b.reportingBId);
		    break;

		case 5:
		    b.region="Central";
		    b.reportingBId=1000;
		    again(b.region,b.reportingBId);
		    break;
		default:cout<<"\n"<<RED<<"\t\t\t\t\tInvalid Choice";
			return;
	    } 
	    break;

	}
	else  if((rk==2) && (strcmp(reg.c_str(),"North")==0))
	    Choice=1;
	else if((rk==2) && (strcmp(reg.c_str(),"South")==0))
	    Choice=2;
	else if((rk==2) && (strcmp(reg.c_str(),"East")==0))
	    Choice=3;
	else if((rk==2)&& (strcmp(reg.c_str(),"West")==0))
	    Choice=4;
	else if((rk==3) && (strcmp(reg.c_str(),"North")==0))
	    Choice=6;
	else if((rk==3) && (strcmp(reg.c_str(),"South")==0))
	    Choice=7;
	else if((rk==3) && (strcmp(reg.c_str(),"East")==0))
	    Choice=8;
	else if((rk==3)&& (strcmp(reg.c_str(),"West")==0))
	    Choice=9;



	switch(Choice)
	{
	    case 1: 
		b.region="North";
		b.reportingBId=1001;
		again(b.region,b.reportingBId);
		break;
	    case 2: 
		b.region="South";
		b.reportingBId=1002;
		again(b.region,b.reportingBId);
		break;

	    case 3: 
		b.region="East";
		b.reportingBId=1003;
		again(b.region,b.reportingBId);
		break;

	    case 4: 
		b.region="West";
		b.reportingBId=1004;
		again(b.region,b.reportingBId);
		break;

	    case 5: 
		b.region="Central";
		b.reportingBId=1000;
		again(b.region,b.reportingBId);
		break;
	    case 6:
		b.region="North";
		b.reportingBId=workingBankId;
		again(b.region,b.reportingBId);
		break;
	    case 7:
		b.region="South";
		b.reportingBId=workingBankId;
		again(b.region,b.reportingBId);
		break;

	    case 8:
		b.region="East";
		b.reportingBId=workingBankId;
		again(b.region,b.reportingBId);
		break;

	    case 9:
		b.region="West";
		b.reportingBId=workingBankId;
		again(b.region,b.reportingBId);
		break;

	    default:
		cout<<"\n"<<RED<<"\t\t\t\t\tInvalid Choice"<<RESET<<endl;
		return;

	}
	cout<<endl<<RED<<"\t\t\t\tDo you want to add more Banks? (y/n)    :  "<<RESET;
	Option=val.getCharacter();

    }while(Option=='y'||Option=='Y');


}
void Manager::again(string reg,int rid)
{
    Validations val;

    Bank b;
    int count,bid;
    char ch;
    cout<<endl<<"\t\t\t\t\t\033[4;30mEnter the following Bank details"<<RESET<<endl;
    cout<<endl<<BLUE<<"\t\t\t\tEnter the Balance                            :  "<<RESET;
    b.balance=val.getDouble();
    cout<<endl<<BLUE<<"\t\t\t\tEnter Contact Details for bank               :  "<<RESET;
    getline(cin>>ws,b.contact);
    st=con->createStatement();     
    string sqlst="insert into Bank values(bseq.nextVal,:1,:2,:3,:4,:5)";
    st->setSQL(sqlst);
    st->setString(1,reg);
    st->setInt(2,rid);
    st->setDouble(3,b.balance);
    st->setInt(4,3);
    st->setString(5,b.contact);
    count=st->executeUpdate();
    if(count==1)
    {  
	st2=con->createStatement(); 
	cout<<endl<<GREEN<<"\t\t\t\t\tBank Opened/Added Successfully\n"<<RESET;
	string sqlst="select bseq.CurrVal from dual";
	st2->setSQL(sqlst);
	rs=st2->executeQuery();            
	if(rs->next())
	    bid=rs->getInt(1);

	cout<<"\n"<<GREEN<<"\t\t\t\t\tBank ID           : "<<bid<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tRegion            : "<<reg<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tReporting Bank ID : "<<rid<<RESET;
	cout.precision(20);
	cout<<"\n"<<GREEN<<"\t\t\t\t\tBalance           : "<<b.balance<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tBank Level        : 3"<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tContact Details   : "<<b.contact<<RESET;      
	cout<<endl;

	st2->closeResultSet(rs);
	con->commit();
	con->terminateStatement(st2);
	cout<<endl<<RED<<"\t\t\tDo you want to add Lockers for this Bank? (y/n) :  "<<RESET;

	ch=val.getCharacter(); 
	if(ch=='Y'||ch=='y')
	    lockers();

    }
    else
    {
	cout<<endl<<RED<<"\t\t\t\t\tNot able to add Bank"<<RESET<<endl;
    }

    con->commit();
    con->terminateStatement(st);
}

void Manager::lockers()
{
    Validations val;

    int count2,count3,count4;
    int bid;
    st2=con->createStatement();
    st3=con->createStatement();
    st4=con->createStatement();
    string sqlst2="insert into bidding_info values(bseq.currVal,'A',5000,500,500)";
    string sqlst3="insert into bidding_info values(bseq.currVal,'B',3000,300,300)";
    string sqlst4="insert into bidding_info values(bseq.currVal,'C',2000,200,200)";
    st2->setSQL(sqlst2);
    st3->setSQL(sqlst3);
    st4->setSQL(sqlst4);
    count2=st2->executeUpdate();
    count3=st3->executeUpdate();
    count4=st4->executeUpdate();

    if(count2==1 && count3==1 && count4==1)
    {
	cout<<endl<<GREEN<<"\t\t\t\t\tLocker added successfully"<<RESET<<endl;
	string sqlst="select bseq.CurrVal from dual";
	st2->setSQL(sqlst);
	rs=st2->executeQuery();
	if(rs->next())
	    bid=rs->getInt(1);

	cout<<"\n"<<GREEN<<"\t\t\t\t\tBank ID                  : "<<bid<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tLocker Type              : A\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tMinimum Amount           : 5000\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tAvailability             : 500\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tTotal number of Lockers  : 500\n"<<RESET;

	cout<<"\n"<<GREEN<<"\t\t\t\t\tLocker Type              : B\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tMinimum Amount           : 3000\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tAvailability             : 300\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tTotal number of Lockers  : 300\n"<<RESET;

	cout<<"\n"<<GREEN<<"\t\t\t\t\tLocker Type              : C\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tMinimum Amount           : 2000\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tAvailability             : 200\n"<<RESET;
	cout<<GREEN<<"\t\t\t\t\tTotal number of Lockers  : 200\n\n"<<RESET;



    }
    else
    {
	cout<<endl<<RED<<"\t\t\t\t\tNot able to add lockers\n"<<RESET<<endl;
    }

    con->commit();
    con->terminateStatement(st2);
    con->terminateStatement(st3);
    con->terminateStatement(st4);

}


void Manager::updateBank(int rank,int eid)
{
    Validations val;

    system("clear");
    header();
    cout<<"                   *************************** Update Bank ***************************"<<            endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    Bank b;
    int Choice,Count;
    char Option;
    int rk,rid;
    Employee e;    
    string reg1,reg2;
    rk=rank;
    int flag=1;
    while(flag)
    {
	st2=con->createStatement();
	string sqlst="select region from employeedetails where rank=:1 AND emp_id=:2";
	st2->setSQL(sqlst);
	st2->setInt(1,rank);
	st2->setInt(2,eid);
	rs=st2->executeQuery();
	while(rs->next())
	{
	    reg1=rs->getString(1);
	}
	st2->closeResultSet(rs);

	con->terminateStatement(st2);

	st3=con->createStatement();
	int count;
	cout<<endl<<BLUE<<"\t\t\t\t\tEnter the Bank Id to update   :  "<<RESET;
	b.bankId=val.getIntegerValue();
	string sqlst3="select region,report_bid from bank where bank_id=:1";
	st3->setSQL(sqlst3);
	st3->setInt(1,b.bankId);
	rs=st3->executeQuery();
	if(rs->next())
	{flag=0;
	    reg2=rs->getString(1);
	    rid = rs->getInt(2);
	    st3->closeResultSet(rs);
	    con->terminateStatement(st3);

	    if(rk==1)
	    {
		up(b.bankId,reg2);
	    }
	    else if( (rk==2) && (strcmp(reg1.c_str(),reg2.c_str()) == 0 ) )
	    {
		up(b.bankId,reg2);
	    }
	    else if (rk==3 && (strcmp(reg1.c_str(),reg2.c_str()) == 0 ) && rid==workingBankId)
	    {
		up(b.bankId,reg2);
	    }
	    else
	    {
		cout<<endl<<"\t\t\t"<<RED<< reg1 <<" Manager has no authority to update the bank of "<< reg2 <<" region\n"<<RESET;

	    }
	}
	else
	{ 
	    cout<<"\n"<<RED<<"\t\t\t\t\tBank Id not present int the database\n"<<RESET;
	    continue;
	}
    }
}

void Manager::up(int bid,string region)
{
    Validations val;

    system("clear");
    Bank b;
    int Choice,Count;
    char Option;
    string sqlst,cdetail;
    do
    {
	header();
	cout<<"                   *************************** Update Bank ***************************"<<            endl;
	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;

	cout<<endl<<"\t\t\t\t\t\033[4;31mSelect for updation"<<RESET<<endl;
	cout<<endl<<BLUE<<"\t\t\t\t\t1.Contact Details"<<endl<<"\t\t\t\t\t2.Reporting Bank Id"<<endl<<"\t\t\t\t\t3.Go Back to Previous Page"<<endl<<RESET;
	cout<<endl<<"\t\t\t\t\tEnter your Choice"<<RESET<<"\033[3;31m[1-3] : "<<RESET;
	Choice=val.getIntegerValue();;
	switch(Choice)
	{
	    case 1:
		st=con->createStatement();
		cout<<"\n"<<BLUE<<"\t\t\t\tEnter new Contact Details               : "<<RESET;	
		getline(cin>>ws,b.contact);
		//cout<<b.contact;
		sqlst="update bank set contact=:1 where bank_id=:2";
		st->setSQL(sqlst);
		st->setString(1,b.contact);
		st->setInt(2,bid);
		Count=st->executeUpdate();
		con->commit();
		con->terminateStatement(st);	
		if(Count==1)
		{
		    cout<<"\n"<<GREEN<<"\t\t\t\tBank Contact Details Updated Successfuly\n"<<RESET;
		    cout<<"\n"<<GREEN<<"\t\t\t\tBank ID                 : "<<bid<<RESET;
		    cout<<"\n"<<GREEN<<"\t\t\t\tNew Contact Details     : "<<b.contact<<RESET<<endl;
		}
		else
		{
		    cout<<"\n"<<RED<<"\t\t\tNot able to update Bank Contact Details\n"<<RESET;
		}

		break;
	    case 2:
		if(bid==1000||bid==1001||bid==1002||bid==1003||bid==1004)
		{
		    cout<<"\n"<<RED<<"\t\t\tYou cannot Update the Reporting Bank IDs of Regional or Central Bank.\n"<<RESET;
		}
		else
		{
		    st=con->createStatement();
		    sqlst="select bank_id from bank where region=:1 and bank_id != :2";
		    st->setSQL(sqlst);
		    st->setString(1,region);
		    st->setInt(2,bid);	
		    rs=st->executeQuery();
		    cout<<"\n"<<"\t\t\t\t\t\033[4;30mPossible Reporting Bank Ids"<<RESET<<endl<<endl;
		    while(rs->next())
		    {
			cout<<BLUE<<"\t\t\t\t\t\t"<<rs->getInt(1)<<"   "<<RESET<<endl;
		    }
		    cout<<"\n"<<BLUE<<"\t\t\tChoose the new Reporting Bank Id value : "<<RESET;
		    b.reportingBId=val.getIntegerValue();
		    sqlst="update bank set report_bid=:1 where region=(select region from bank where bank_id=:2) and bank_id=:3";
		    st->setSQL(sqlst);
		    st->setInt(1,b.reportingBId);
		    st->setInt(2,b.reportingBId);
		    st->setInt(3,bid);
		    Count=st->executeUpdate();
		    con->commit();
		    con->terminateStatement(st);
		    if(Count==1)
		    {

			cout<<"\n"<<GREEN<<"\t\t\t\t\tBank Updated Successfuly\n"<<RESET;
			cout<<"\n"<<GREEN<<"\t\t\t\t\tBank ID                   : "<<bid<<RESET;
			cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Reporting Bank ID     : "<<b.reportingBId<<RESET;

		    }
		    else
		    {    
			cout<<"\n"<<RED<<"\t\t\t\tInvalid choice";
			cout<<"\n"<<RED<<"\t\t\t\tNot able to update Bank Reporting Id"<<RESET;
			cout<<"\n"<<RED<<"\t\t\t\tSelect from the list of possible bank ID's\n"<<RESET;
		    }
		}

		break;
	    case 3:
		return;
	    default:
		cout<<endl<<RED<<"\t\t\t\t\tInvalid Option"<<RESET<<endl;
	}
	cout<<"\n"<<"\t\t\t\t"<<RED<<"Do you want to continue updation? (y/n)  :         "<<RESET;
	Option=val.getCharacter();
    }while(Option=='y'||Option=='Y');

}


void Manager::viewBank()
{
    Validations val;

    system("clear");
    header(); 
    cout<<"                   *************************** View All Bank ***************************"<<            endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl<<endl;

    int Bankid,Level,Balance,Reportid;
    string Region,Contact;
    st=con->createStatement();
    string sqlst="select * from bank order by bank_id";
    st->setSQL(sqlst);
    rs=st->executeQuery();
    cout<<"\n  ||---BANK ID---||---REGION---||---REPORTING ID---||---BALANCE---||---LEVEL---||---CONTACT---||\n";
    while(rs->next())
    {
	Bankid=rs->getInt(1);
	Region=rs->getString(2);
	Reportid=rs->getInt(3);
	Balance=rs->getDouble(4);
	Level=rs->getInt(5);    
	Contact = rs->getString(6);
	cout<<"\n\t"<<Bankid<<"\t      "<<Region<<"\t\t"<<Reportid<<"\t\t"<<Balance<<"\t\t "<<Level<<"\t    "<<Contact<<"\n";

    }
    cout<<"\n"<<GREEN<<"\t\t\t\t\tBank Viewed successfuly\n"<<RESET;
    st->closeResultSet(rs);
    con->commit();
    con->terminateStatement(st);

}

void Manager::viewSingleBank()
{
    Validations val;

    system("clear");
    header();
    cout<<"                   *************************** View Single Bank ***************************"<<            endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    Bank b;
    int Bankid,Level,Balance,Reportid;
    string Region,Contact;
    st=con->createStatement();
    cout<<"\n"<<BLUE<<"\t\t\t\tEnter the Bank Id to view Bank  :  "<<RESET;
    b.bankId=val.getIntegerValue();
    string sqlst="select * from bank where bank_id= :1";
    st->setSQL(sqlst);
    st->setInt(1,b.bankId);
    rs=st->executeQuery();
    if(rs->next())
    {
	Bankid=rs->getInt(1);
	Region=rs->getString(2);
	Reportid=rs->getInt(3);
	Balance=rs->getDouble(4);
	Level=rs->getInt(5);    
	Contact=rs->getString(6);

	//cout<<"\n  ||---BANK ID---||---REGION---||---REPORTING ID---||---BALANCE---||---LEVEL---||---CONTACT---||\n";

	//cout<<"\n\t"<<Bankid<<"\t     "<<Region<<"\t\t"<<Reportid<<"\t\t"<<Balance<<"\t\t "<<Level<<"\t     "<<Contact<<"\n"; 
	cout<<"\n"<<GREEN<<"\t\t\t\t\tBank ID           : "<<Bankid<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tRegion            : "<<Region<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tReporting Bank ID : "<<Reportid<<RESET;
	cout.precision(20);
	cout<<"\n"<<GREEN<<"\t\t\t\t\tBalance           : "<<Balance<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tBank Level        : "<<Level<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tContact Details   : "<<Contact<<RESET;
	cout<<endl;

	cout<<"\n"<<GREEN<<"\t\t\t\t\tBank viewed Successfuly\n"<<RESET;
	st->closeResultSet(rs);
	con->commit();
	con->terminateStatement(st);
    } 
    else
    {
	cout<<"\n"<<RED<<"\t\t\t\tBank Id not present in the database\n"<<RESET;
    }

}


void Manager::closeBank(int rank,int eid)
{
    Validations val;

    system("clear"); 
    header();
    cout<<"                   *************************** Close Bank ***************************"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;

    Bank b;
    Employee e;
    string reg1,reg2;
    int rk=rank,rid;
    string sqlst2="select region from employeedetails where rank=:1 AND emp_id=:2";
    st2=con->createStatement();
    st2->setSQL(sqlst2);
    st2->setInt(1,rank);
    st2->setInt(2,eid);
    rs=st2->executeQuery();
    while(rs->next())
    {
	reg1=rs->getString(1);
    }
    st2->closeResultSet(rs);
    con->terminateStatement(st2);

    st3=con->createStatement();
    int count;
    cout<<BLUE<<"\t\t\t\tEnter the Bank Id       :  "<<RESET;
    b.bankId=val.getIntegerValue();
    string sqlst3="select region,report_bid from bank where bank_id=:1";

    st3->setSQL(sqlst3);
    st3->setInt(1,b.bankId);
    rs=st3->executeQuery();
    if(rs->next())
    {
	//while(rs->next())
	//{
	reg2=rs->getString(1);
	rid=rs->getInt(2);
	//}
	st3->closeResultSet(rs);
	con->terminateStatement(st3);      
	if(rk==1)
	{ 
	    //	cout<<"central";
	    del(b.bankId);
	}
	else if( (rk==2) && (strcmp(reg1.c_str(),reg2.c_str()) == 0 ) )
	{
	    del(b.bankId);
	}
	else if (rk==3 && (strcmp(reg1.c_str(),reg2.c_str()) == 0 ) && rid==workingBankId)
	{
	    del(b.bankId);
	}
	else
	{
	    cout<<"\n\t\t\t"<<RED<< reg1 <<"Manager has no authority to close the bank of"<<reg2<<" region\n"<<RESET;
	}
    }
    else
    {
	cout<<"\n"<<RED<<"\t\t\t\tBank Id not present in the database\n"<<RESET;
    }

}
void Manager::del(int bank_id)
{
    Validations val;

    int count;
    st2=con->createStatement();
    string sqlst1="update bank set report_bid=(select report_bid from bank where bank_id=:1) where report_bid=:2";
    st2->setSQL(sqlst1);
    st2->setInt(1,bank_id);
    st2->setInt(2,bank_id);
    st2->executeUpdate();
    con->commit();
    con->terminateStatement(st2);
    st2=con->createStatement();
    sqlst1="update employeedetails set work_bid=(select report_bid from bank where bank_id=:1) where work_bid=:2";
    st2->setSQL(sqlst1);
    st2->setInt(1,bank_id);
    st2->setInt(2,bank_id);
    st2->executeUpdate();
    con->commit();
    con->terminateStatement(st2);

    st=con->createStatement();
    string sqlst="delete from bank where bank_id=:1";
    st->setSQL(sqlst);
    st->setInt(1,bank_id);
    count=st->executeUpdate();
    con->commit();
    con->terminateStatement(st); 
    if(count==1)
    {
	//cout<<"\n"<<GREEN<<"\t\t\t\t\tBank Closed successfuly\n"<<RESET;
	system("read -n1 -r -p \"\033[3;32m\n\n                                            Bank Closed Successfully\n\n\n                                   Press any key to view the bank database      \033[0m\"  key");
	viewBank();
    }
    else
    {
	cout<<"\n"<<RED<<"\t\t\t\t\tNot able to delete the bank\n"<<RESET;
    }
}        





/*--------------------------------------------------------------------
  Function allows the manager to respond to any fund request message 
  received from immediate lower order banks by transferring funds to it
  ----------------------------------------------------------------------*/
void Manager::respondBranches(int fundSenderId, int fundReceiverId)
{
    BankAccount bk;
    cout<<endl;
    system("clear");
    header();
    cout<<"                 *************************** Fund Transfer Details ***************************"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
    string query="select * from bank where bank_id=:1";

    st=con->createStatement();   
    st->setSQL(query);
    st->setInt(1, fundSenderId);
    rs=st->executeQuery();

    string query1="select * from bank where bank_id=:1";
    Statement *st1=con->createStatement();
    st1->setSQL(query1);
    st1->setInt(1, fundReceiverId);
    ResultSet *rs1=st1->executeQuery();
    rs->next();
    rs1->next();

    double distributeBalance=rs->getDouble(4);
    double receiveBalance=rs1->getDouble(4);

    cout<<"\n"<<BLUE<<"\t\t\tDistributer Bank ID           : "<<RESET<<fundSenderId;

    cout<<endl;
    cout.precision(20);
    cout<<"\n"<<BLUE<<"\t\t\tDistributer Bank's Balance    : "<<RESET<<distributeBalance;

    cout<<endl;
    cout<<"\n"<<BLUE<<"\t\t\tReceiver Bank ID              : "<<RESET<<fundReceiverId;

    cout<<endl;
    cout.precision(20);
    cout<<"\n"<<BLUE<<"\t\t\tReceiver Bank's Balance       : "<<RESET<<receiveBalance;

    cout<<endl;
    cout.precision(20);
    cout<<"\n"<<BLUE<<"\t\t\tAmount to be transferred      : "<<RESET;
    bk.amount=val.getDouble();
    cout<<endl<<endl;
    query="select balance from bank where bank_id=:1";
    st->setSQL(query);
    st->setInt(1, fundSenderId);
    rs=st->executeQuery();
    rs->next();
    double bankBalance=rs->getDouble(1);

    /*checks if the amount entered is less than the balance of the
      bank*/
    if((bankBalance<=bk.amount)||(bankBalance<=0))
    {
	cout<<"\n"<<RED<<"\t\t\tFund transfer not possible"<<RESET<<endl;
	cout<<"\n"<<RED<<"\t\t\tSufficient amount not present in your Bank Account"<<RESET<<endl;
    }
    else
    {
	double newBankBalance=bankBalance-bk.amount;
	query="update bank set balance=:1 where bank_id=:2";
	st->setSQL(query);
	st->setDouble(1, newBankBalance);
	st->setInt(2, fundSenderId);
	st->executeUpdate();
	con->commit();

	query="select balance from bank where bank_id=:1";
	st->setSQL(query);
	st->setInt(1, fundReceiverId);
	rs=st->executeQuery();
	rs->next();
	bankBalance=rs->getDouble(1);

	double newBankBalance1=bankBalance+bk.amount;
	query="update bank set balance=:1 where bank_id=:2";
	st->setSQL(query);
	st->setInt(1, newBankBalance1);
	st->setInt(2, fundReceiverId);
	st->executeUpdate();
	con->commit();


	query="Insert into fund_transfer values(:2, sysdate, :3, :1)";
	st->setSQL(query);
	st->setInt(1, fundSenderId);
	st->setInt(2, fundReceiverId);
	st->setDouble(3, bk.amount);
	int check= st->executeUpdate();
	con->commit();
	if(check==1)
	{
	    cout<<"\n"<<GREEN<<"\t\t\tFund transfer successful"<<RESET<<endl;

	    cout<<"\n"<<GREEN<<"\t\t\tBalance after fund transfer is as follows "<<RESET<<endl;
	    cout.precision(20);
	    cout<<"\n"<<GREEN<<"\t\t\tDistributor Bank's Balance    : "<<RESET<<newBankBalance<<endl;
	    cout.precision(20);
	    cout<<"\n"<<GREEN<<"\t\t\tSenders Bank's Balance        : "<<RESET<<newBankBalance1<<endl;

	    cout<<endl<<endl;
	    system("read -n1 -r -p \"\033[3;31m                        Press any key to continue \033[0m\"  key");   
	    return;
	}
    }
}




/*-------------------------------------------------------- 
  Function allows the manager to view fund transfer request 
  messages sent to it by lower orderbanks
  ----------------------------------------------------------*/
void Manager::viewMessages()
{
    system("clear");
    Bank b;
    BankAccount bk;
    char decision;
    int messageNo,flag=1;

    header();
    ResultSet *rs1;

    st=con->createStatement();
    string query="select * from report where receiver_bid=:1";
    st->setSQL(query);
    st->setInt(1, workingBankId);
    rs=st->executeQuery();
    rs1=rs;

    //checks if any message is present for the bank in the database
    if(rs1->next())
    {
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\t"<<setw(6)<<left<<"Read"<<setw(16)<<left<<"Sender Bank ID"<<setw(20)<<left<<"Receiver Bank ID"<<setw(23)<<left<<"Message"<<setw(23)<<left<<"Message Number"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;


	//loop iterates to display all the messages present in the database
	while(rs->next())
	{
	    int read=rs->getInt(1);
	    if(read)
	    {
		cout<<RED<<"\t"<<setw(6)<<left<<read<<RESET;
		cout<<RED<<setw(16)<<left<<rs->getInt(2)<<RESET;
		cout<<RED<<setw(20)<<left<<rs->getInt(3)<<RESET;
		cout<<RED<<setw(23)<<left<<rs->getString(4)<<RESET;
		cout<<RED<<setw(23)<<left<<rs->getString(5)<<RESET;
		cout<<endl<<endl;
	    }

	    else
	    {
		cout<<GREEN<<"\t"<<setw(6)<<left<<read<<RESET;
		cout<<GREEN<<setw(16)<<left<<rs->getInt(2)<<RESET;
		cout<<GREEN<<setw(20)<<left<<rs->getInt(3)<<RESET;
		cout<<GREEN<<setw(23)<<left<<rs->getString(4)<<RESET;
		cout<<GREEN<<setw(23)<<left<<rs->getString(5)<<RESET;
		cout<<endl<<endl;
	    }
	}


	string query1="select balance from bank where bank_id=:1";
	st->setSQL(query1);
	st->setInt(1, workingBankId);
	rs=st->executeQuery();
	rs->next();  
	double bal=rs->getDouble(1);

	if(bal<=0)
	{
	    cout<<RED<<"Sorry, you do not have sufficient balance to respond to any message"<<endl<<endl;
	    cout<<RED<<"Press enter to return..."<<endl;
	    cin.ignore();
	    int ent=cin.get();
	    return ;
	}


	cout<<"\n"<<RED<<"\t\t\tDo you want to respond to any message? \n\t\t\tPress 'Y'/'y' for yes or 'N'/'n' for no : "<<RESET;


	//loop iterates & displays message to enter valid character input
	while(flag)
	{
	    decision=val.getCharacter();


	    //checks if the entered character is Y or y
	    if((decision=='Y')||(decision=='y'))
	    {

		cout<<"\n"<<BLUE<<"\t\t\tEnter the Message Number to be marked as read   : "<<RESET;
		messageNo=val.getIntegerValue();
		// system("clear");
		// header();

		query="select read from report where message_no=:1";
		st->setSQL(query);
		st->setInt(1, messageNo);
		rs=st->executeQuery();

		if(rs->next())
		{
		    //checks if the request has already been responded by checking if read=1
		    if(rs->getInt(1))
		    {
			// cout<<"Inside Read"<<endl;
			cout<<"\n"<<RED<<"\t\t\tRequest has already been responded"<<RESET<<endl;
			cout<<"\n"<<RED<<"\t\t\tPress (Y/y) to respond again or (N/n) to return : "<<RESET;
			decision=val.getCharacter();
			if((decision=='Y')||(decision=='y'))
			    viewMessages();
			return ;
			if((decision=='N')||(decision=='n'))
			    return ; 
		    }
		    else
		    {
			string query="Update report set read=1 where message_no=:1";
			st->setSQL(query);
			st->setInt(1, messageNo);
			st->executeUpdate();
			con->commit();
			string query1="select receiver_bid, sender_bid from report where message_no=:1";
			st->setSQL(query1);
			st->setInt(1, messageNo);
			rs=st->executeQuery();
			rs->next();
			bk.fromBankId=rs->getInt(1);
			bk.toBankId=rs->getInt(2);
			cout<<"\n"<<GREEN<<"\t\t\tRead has been marked as 1 for the message specified"<<RESET<<endl;
			cout<<GREEN<<"\n"<<"\t\t\tPress enter to move to fund transfer page..."<<endl<<endl;
			cin.ignore();
			int ent=cin.get();
			cout<<"\t\t\t**********Moving to Fund Transfer Page**********";
			cout<<endl<<endl;
			respondBranches(bk.fromBankId, bk.toBankId);
			flag=0;
			return ;
		    }
		}
		else
		{
		    cout<<RED<<"\n"<<"\t\t\tEntered Message Number not present in the database"<<RESET<<endl;
		    cout<<RED<<"\n"<<"\t\t\tPress (Y/y) to respond again or (N/n) to return : "<<RESET;
		    decision=val.getCharacter();
		    if((decision=='Y')||(decision=='y'))
			viewMessages();
		    return ;
		    if((decision=='N')||(decision=='n'))
			return ;
		}
	    }

	    //checks if the entered character is N or n
	    if((decision=='N')||(decision=='n'))
	    {
		cout<<"\n"<<GREEN<<"\t\t\tNo Message Read"<<RESET<<endl<<endl;
		return ;
	    }

	}
    }
    else
    {
	cout<<"\n"<<RED<<"\t\t\tNo message present in the database for you"<<RESET<<endl<<endl;
	cout<<"\n"<<RED<<"\t\t\tPress enter to return..."<<RESET;
	cin.ignore();
	int ent=cin.get();
	return ;
    }
}




/*-----------------------------------------------------------------
  Function allows the manager to distribute funds to lower order banks
  -------------------------------------------------------------------*/
void Manager::distributeFunds()
{
    BankAccount bk;
    system("clear");
    header();
    cout<<"                   *************************** Fund Transfer Details ***************************"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
    cout<<"\n"<<BLUE<<"\t\t\tDistributer Bank ID                   : "<<RESET<<workingBankId;

    st=con->createStatement();
    string query="select * from bank where bank_id=:1";
    st->setSQL(query);
    st->setInt(1, workingBankId);
    rs=st->executeQuery();
    double distributeBalance, receiveBalance;  
    //checks if the entered bank id is present in the database
    if(rs->next())
    {
	int ids[25];
	distributeBalance=rs->getDouble(4);
	st->closeResultSet(rs);
	cout.precision(20);  
	cout<<"\n"<<BLUE<<"\t\t\tDistributer Bank's Balance            : "<<RESET<<distributeBalance<<endl<<endl;
	query="select * from bank where report_bid=:1";
	st->setSQL(query);
	st->setInt(1, workingBankId);
	rs=st->executeQuery();
	int index=0;
	//cout<<"\n"<<BLUE<<"\t\t\tReceiver Bank ID         : "<<RESET;

	//iterates to output the id's of all the banks present under the user's bank
	while(rs->next())
	{
	    ids[index]=rs->getInt(1);
	    cout<<"\n"<<BLUE<<"\t\t\tReceiver Bank ID                      : "<<RESET<<ids[index]<<endl;
	    receiveBalance=rs->getDouble(4);
	    cout.precision(20);
	    cout<<BLUE<<"\t\t\tBank's Balance                        : "<<RESET<<receiveBalance<<endl<<endl;
	    index++;
	}
	st->closeResultSet(rs);
	cout<<endl<<endl;
	cout.precision(20);
	cout<<"\n"<<BLUE<<"\t\t\tAmount transferred                    : "<<RESET;
	bk.amount=val.getDouble();
	cout<<endl<<endl;
	int index1=0;


	//iterates to distribute money to all the lower order banks present under user's bank
	while(index1<index)
	{
	    string query="select balance from bank where bank_id=:1";
	    st->setSQL(query);
	    st->setInt(1, workingBankId);
	    rs=st->executeQuery();
	    rs->next();
	    double bankBalance=rs->getDouble(1);
	    st->closeResultSet(rs);
	    //checks if the entered amount is less than the balance of the bank
	    if((bankBalance<=bk.amount)||(bankBalance<=0))
	    {
		cout<<"\n"<<RED<<"\t\t\tFund transfer not possible"<<RESET<<endl;
		cout<<"\n"<<RED<<"\t\t\tSufficient amount not present in your Bank Account"<<RESET<<endl;
		break;
	    }
	    else
	    {
		double newBankBalance=bankBalance-bk.amount;
		query="update bank set balance=:1 where bank_id=:2";
		st->setSQL(query);
		st->setDouble(1, newBankBalance);
		st->setInt(2, workingBankId);
		st->executeUpdate();
		con->commit();

		cout.precision(20);
		cout<<"\n"<<GREEN<<"\t\t\tDistributer Bank's Balance            : "<<RESET<<newBankBalance; 
		query="select balance from bank where bank_id=:1";
		st->setSQL(query);
		st->setInt(1, ids[index1]);
		rs=st->executeQuery();
		rs->next();
		bankBalance=rs->getDouble(1);
		st->closeResultSet(rs);
		newBankBalance=bankBalance+bk.amount;
		query="update bank set balance=:1 where bank_id=:2";
		st->setSQL(query);
		st->setDouble(1, newBankBalance);
		st->setInt(2, ids[index1]);
		st->executeUpdate();
		con->commit();

		query="Insert into fund_transfer values(:1, sysdate, :2, :3)";
		st->setSQL(query);
		st->setDouble(1, bk.amount);
		st->setInt(2, workingBankId);
		st->setInt(3, ids[index1]);
		st->executeUpdate();
		cout<<endl;
		cout<<"\n"<<GREEN<<"\t\t\tAmount transfer successful to Bank Id : "<<RESET<<ids[index1];
		cout.precision(20);
		cout<<"\n"<<GREEN<<"\t\t\tBank's Balance                        : "<<RESET<<newBankBalance<<endl<<endl;
		index1++;
	    }   }
    } else
    {
	st->closeResultSet(rs);
	cout<<RED<<"\t\t\t\tFund transfer not allowed"<<RESET<<endl<<endl;
	distributeFunds();
    }
}




/*--------------------------------------------------------------
  Function reverts money to the reporting bank of the user's bank
  ----------------------------------------------------------------*/ 
void Manager::revertFunds()
{
    BankAccount bk;
    double newBankBalance;
    system("clear");
    header();
    cout<<"                   *************************** Revert Fund ***************************"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
    cout<<endl;
    cout<<"\n"<<BLUE<<"\t\t\tSender Bank ID                        : "<<RESET<<workingBankId;



    double distributeBalance, receiveBalance;
    double bankBalance;

    st=con->createStatement();

    string query="select * from bank where bank_id=:1";
    st->setSQL(query);
    st->setInt(1, workingBankId);
    rs=st->executeQuery();

    //checks if the entered bank id is present in the database
    if(rs->next())
    {

	distributeBalance=rs->getDouble(4);
	cout.precision(20);
	cout<<"\n"<<BLUE<<"\t\t\tBank's Balance                        : "<<RESET<<distributeBalance<<endl<<endl;

	query="select * from bank where bank_id=:1";

	st->setSQL(query);
	st->setInt(1, workingBankId);
	rs=st->executeQuery();
	rs->next();

	bk.toBankId=rs->getInt(3);
	cout<<"\n"<<BLUE<<"\t\t\tReceiver Bank ID                      : "<<RESET<<bk.toBankId;

	query="select * from bank where bank_id=:1";

	st->setSQL(query);
	st->setInt(1, bk.toBankId);
	rs=st->executeQuery();
	rs->next();
	receiveBalance=rs->getDouble(4);
	cout.precision(20);
	cout<<"\n"<<BLUE<<"\t\t\tBank's Balance                        : "<<RESET<<receiveBalance<<endl;



	cout<<endl<<endl;
	cout.precision(20);
	cout<<"\n"<<BLUE<<"\t\t\tAmount transferred                    : "<<RESET;
	bk.amount=val.getDouble();
	cout<<endl<<endl;


	string query="select balance from bank where bank_id=:1";
	st->setSQL(query);
	st->setInt(1, workingBankId);
	rs=st->executeQuery();
	rs->next();
	bankBalance=rs->getDouble(1);
	//cout<<"Bank Balance is : "<<bankBalance<<endl;
	//checks if the balance present in the bank is more than the amount entered
	if((bankBalance<=bk.amount)||(bankBalance<=0))
	{
	    cout<<"\n"<<RED<<"\t\t\tFund Transfer Not Possible"<<RESET<<endl;
	    cout<<"\n"<<RED<<"\t\t\tSufficient amount not present in your Bank Account"<<RESET<<endl;
	}
	else
	{
	    newBankBalance=bankBalance-bk.amount;
	    cout.precision(20);
	    cout<<"\n"<<GREEN<<"\t\t\tSender Bank's Balance                 : "<<RESET<<newBankBalance; 
	    query="update bank set balance=:1 where bank_id=:2";
	    st->setSQL(query);
	    st->setDouble(1, newBankBalance);
	    st->setInt(2, workingBankId);
	    st->executeUpdate();
	    con->commit();
	    query="select balance from bank where bank_id=:1";
	    st->setSQL(query);
	    st->setInt(1, bk.toBankId);
	    rs=st->executeQuery();
	    rs->next();
	    bankBalance=rs->getInt(1);

	    newBankBalance=bankBalance+bk.amount;
	    query="update bank set balance=:1 where bank_id=:2";
	    st->setSQL(query);
	    st->setDouble(1, newBankBalance);
	    st->setInt(2, bk.toBankId);
	    st->executeUpdate();
	    con->commit();

	    query="Insert into fund_transfer values(:1, sysdate, :2, :3)";
	    st->setSQL(query);
	    st->setDouble(1, bk.amount);
	    st->setInt(2, workingBankId);
	    st->setInt(3, bk.toBankId);
	    st->executeUpdate();


	    cout<<"\n\n"<<GREEN<<"\t\t\tAmount transfer successful"<<RESET<<endl;
	    cout.precision(20); 
	    cout<<"\n"<<GREEN<<"\t\t\tReceiver Bank's Balance               : "<<RESET<<newBankBalance<<endl<<endl;
	}
    }
    else
    {
	cout<<"\n"<<RED<<"\t\t\tFund transfer not allowed"<<RESET<<endl<<endl;
	cout<<"\n"<<RED<<"\t\t\tPress enter to continue again..."<<endl;
	revertFunds();
    }
}





/* Add employee function will inserts new employee details into the employee details database.*/
void Manager::addEmployee(int rank,int eid)
{ 
    Validations val;

    int count;
    int co;
    system("clear");
    header();
    cout<<"                 *************************** Employee Registration ***************************"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
    Employee e;
    string sqlstmt,region1;
    st3=con->createStatement();
    sqlstmt="select region from employeedetails where rank=:1 and emp_id=:2";

    st3->setSQL(sqlstmt);
    st3->setInt(1,rank);
    st3->setInt(2,eid);
    rs=st3->executeQuery();
    rs->next();
    region1=rs->getString(1);
    st3->closeResultSet(rs);
    con->terminateStatement(st3);
    st=con->createStatement();
    cout<<"\n"<<"\t\t\t\t\033[4;30mEnter the following details of employees \n"<<RESET;    
    cout<<"\n"<<BLUE<<"\t\t\t\t\tEmployee first name  : "<<RESET;
    e.employeeFirstName=val.getStringValue();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tEmployee last name   : "<<RESET;
    e.employeeLastName=val.getStringValue();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tDate of joining      : "<<RESET;
    e.dateOfJoining=val.getDate();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tAddress              : "<<RESET;
    cin>>e.address;
    cout<<"\n"<<BLUE<<"\t\t\t\t\tWorking Bank ID      : "<<RESET;
    e.workingBankId=val.getIntegerValue();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tDesignation          : "<<RESET;
    e.designation=val.getStringValue();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tRanking              : "<<RESET;
    e.rank=val.getIntegerValue();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tReporting Head ID    : "<<RESET;
    e.reportingHeadId=val.getIntegerValue();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tSalary               : "<<RESET;
    e.salary=val.getDouble();
    cout<<"\n"<<BLUE<<"\t\t\t\t\tPassword             : "<<RESET;
    cin>>e.password;
    e.region=region1;
    sqlstmt = "insert into employeedetails values (empid.nextVal,:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11)";
    st->setSQL(sqlstmt);
    st->setString(1,e.employeeFirstName);
    st->setString(2,e.employeeLastName);
    st->setString(3,e.dateOfJoining);
    st->setString(4,e.address);
    st->setInt(5,e.workingBankId);
    st->setString(6,e.designation);
    st->setInt(7,e.rank);
    st->setInt(8,e.reportingHeadId);
    st->setDouble(9,salary);
    st->setString(10,e.password);
    st->setString(11,e.region);
    count=st->executeUpdate();
    // cout<<"Inserted successfully\n Press enter to return"<<endl;
    // cin.get(); cin.get();

    con->commit();
    con->terminateStatement(st);
    if(count==1)
    {
	cout<<"\n"<<GREEN<<"\t\t\t\t\t\tInserted successfully\n"<<RESET;
	st2=con->createStatement();
	string sqlst="select empid.currVal from dual";
	st2->setSQL(sqlst);
	rs=st2->executeQuery();
	if(rs->next())
	    eid=rs->getInt(1);

	cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID          : "<<eid<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee first name  : "<<e.employeeFirstName<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee last name   : "<<e.employeeLastName<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tDate of joining      : "<<e.dateOfJoining<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tAddress              : "<<e.address<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tWorking Bank ID      : "<<e.workingBankId<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tDesignation          : "<<e.designation<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tRanking              : "<<e.rank<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tReporting Head ID    : "<<e.reportingHeadId<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tSalary               : "<<e.salary<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tPassword             : "<<e.password<<RESET;
	cout<<"\n"<<GREEN<<"\t\t\t\t\tRegion               : "<<e.region<<RESET<<endl<<endl;
	st2->closeResultSet(rs);
	con->terminateStatement(st2);

    }
    else
    {
	cout<<"\n"<<RED<<"\t\t\t\t\t\tNot able to add employee"<<RESET;
	//cout<<setw(40)<<BLUE<<" Press enter to return"<<RESET<<endl;
    }
}

/* Update employee function will modify existing employee details for the particular  employee id passed into the employee details database.*/
void Manager::updateEmployee(int rank,int eid)
{
    Validations val;

    header();
    cout<<"                   *************************** Update Employee ***************************"<<            endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    Employee e;
    char decision;
    int choice,count,flag;
    string sqlstmt,region,region1,password1,password2;
    st=con->createStatement();
    sqlstmt="select region from employeedetails where rank=:1 and emp_id=:2";
    st->setSQL(sqlstmt);
    st->setInt(1,rank);
    st->setInt(2,eid);
    rs=st->executeQuery();

    /* stores the region coresponding to the manager's employee id and rank entered above.*/
    while(rs->next())
    {
	region=rs->getString(1);
    }
    st->closeResultSet(rs);
    con->terminateStatement(st);
    st1=con->createStatement();
    cout<<"\n"<<BLUE<<"\t\t\t\tEnter the employee id for updation  : "<<RESET;
    e.employeeId=val.getIntegerValue();
    sqlstmt="select * from employeedetails where emp_id=:1";
    st1->setSQL(sqlstmt);
    st1->setInt(1,e.employeeId);
    rs=st1->executeQuery();
    /* stores the region coresponding to the employee id entered above.*/
    if(rs->next())
    {  
	region1=rs->getString(12);         
	/* checks if the manager's region and the employee's region match.*/
	if(region==region1)
	{
	    cout<<rs->getString(2);
	    st1->closeResultSet(rs);
	    con->terminateStatement(st1);

	    do
	    {

		header();
		cout<<"\t\t\t\t\t\033[4;31mChoose the detail to update "<<RESET<<endl;
		cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t1.Designation"<<RESET<<endl;
		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t2.Salary\n"<<RESET;
		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t3.Address\n"<<RESET;
		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t4.Rank\n"<<RESET;
		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t5.Reporting Head Id\n"<<RESET;
		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t6.Region\n"<<RESET;
		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t7.Change Password\n"<<RESET;
		cout<<"\n"<<BLUE<<"\t\t\t\t\t\t8.Back to Previous Menu"<<RESET;
		cout<<endl<<endl<<"\t\t\t\t\tEnter your choice"<<RESET<<"\033[3;31m[1-8] : "<<RESET;

		choice=val.getIntegerValue();
		// switch provides  with options from which we can choose the option to be updated.
		switch(choice)
		{
		    case 1:
			cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter the new designation of Employee:"<<RESET;
			e.designation=val.getStringValue();
			st=con->createStatement();
			sqlstmt="update employeedetails set designation=:1 where emp_id=:2";
			st->setSQL(sqlstmt);
			st->setString(1,e.designation);
			st->setInt(2,e.employeeId);
			count=st->executeUpdate();
			if(count==1)
			{
			    cout<<"\n"<<GREEN<<"\t\t\t\t\t\tUpdated successfully"<<endl<<endl;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID          : "<<e.employeeId<<RESET;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Designation      : "<<e.designation<<RESET;
			}
			else
			    cout<<"\n"<<RED<<"\t\t\t\tNot able to update employee designation"<<RESET;
			con->commit();
			con->terminateStatement(st);
			break;
		    case 2:
			cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter the new salary of Employee : "<<RESET;
			e.salary=val.getDouble();
			st=con->createStatement();
			sqlstmt="update employeedetails set salary=:1 where emp_id=:2";
			st->setSQL(sqlstmt);
			st->setDouble(1,e.salary);
			st->setInt(2,e.employeeId);
			count=st->executeUpdate();
			if(count==1)
			{
			    cout<<"\n"<<GREEN<<"\t\t\t\t\t\tUpdated successfully"<<RESET<<endl
				<<endl;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID          : "<<e.employeeId<<RESET;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Salary           : "<<e.salary<<RESET;
			}
			else
			{
			    cout<<"\n"<<RED<<"\t\t\t\tNot able to update employee salary"<<RESET;
			}
			con->commit();
			con->terminateStatement(st);
			break;
		    case 3:
			cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter new address of the employee : "<<RESET;
			getline(cin,e.address); getline(cin,e.address);
			st=con->createStatement();
			sqlstmt="update employeedetails set address=:1 where emp_id=:2";
			st->setSQL(sqlstmt);
			st->setString(1,e.address);
			st->setInt(2,e.employeeId);
			count=st->executeUpdate();
			if(count==1)
			{
			    cout<<"\n"<<GREEN<<"\t\t\t\t\t\tUpdated successfully"<<RESET<<endl<<endl;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID          : "<<e.employeeId<<RESET;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Address          : "<<e.address<<RESET;
			}



			con->commit();
			con->terminateStatement(st);
			break;
		    case 4:
			cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter new rank of the employee : "<<RESET;
			e.rank=val.getIntegerValue();
			st=con->createStatement();
			sqlstmt="update employeedetails set rank=:1 where emp_id=:2";
			st->setSQL(sqlstmt);
			st->setInt(1,e.rank);
			st->setInt(2,e.employeeId);
			count=st->executeUpdate();
			if(count==1)
			{
			    cout<<"\n"<<GREEN<<"\t\t\t\t\t\tUpdated successfully"<<RESET<<endl<<endl;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID          : "<<e.employeeId<<RESET;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Rank             : "<<e.rank<<RESET;
			}
			else
			{
			    cout<<"\n"<<RED<<"\t\t\t\tNot able to update employee rank"<<RESET;
			}
			con->commit();
			con->terminateStatement(st);
			break;
		    case 5:
			cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter new reporting head id of the employee : "<<RESET;
			e.reportingHeadId=val.getIntegerValue();
			st=con->createStatement();
			sqlstmt="update employeedetails set report_hid=:1 where emp_id=:2";
			st->setSQL(sqlstmt);
			st->setInt(1,e.reportingHeadId);
			st->setInt(2,e.employeeId);
			count=st->executeUpdate();
			if(count==1)
			{
			    cout<<"\n"<<GREEN<<"\t\t\t\t\t\tUpdated successfully"<<RESET<<endl<<endl;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID               : "<<e.employeeId<<RESET;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Reporting Head ID     : "<<e.reportingHeadId<<RESET;
			}
			else
			{
			    cout<<"\n"<<RED<<"\t\t\t\tNot able to update employee reporting head ID"<<RESET;
			}

			con->commit();
			con->terminateStatement(st);
			break;
		    case 6:
			cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter new region : "<<RESET;
			e.region=val.getStringValue();
			st=con->createStatement();
			sqlstmt="update employeedetails set Region=:1 where emp_id=:2";
			st->setSQL(sqlstmt);
			st->setString(1,e.region);
			st->setInt(2,e.employeeId);
			count=st->executeUpdate();
			if(count==1)
			{
			    cout<<"\n"<<GREEN<<"\t\t\t\t\t\tUpdated successfully"<<RESET<<endl<<endl;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID           : "<<e.employeeId<<RESET;
			    cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Region            : "<<e.region<<RESET;
			}
			else
			{
			    cout<<"\n"<<RED<<"\t\t\t\tNot able to update employee region"<<RESET;
			}

			con->commit();
			con->terminateStatement(st);
			break;
		    case 7:
			flag=1;
			cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter old password       : "<<RESET;
			cin>>password1;
			st=con->createStatement();
			sqlstmt="select password from employeedetails where emp_id=:1";
			st->setSQL(sqlstmt);
			st->setInt(1,e.employeeId);
			rs=st->executeQuery();
			while(rs->next())
			{
			    password2=rs->getString(1);
			}
			/* compares the old password entered above and the passord present in the employee details for the coresponding employee id match.*/
			if (password1.compare(password2)==0)
			{
			    while(flag)
			    {
				cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter the new password   : "<<RESET;
				cin>>e.newPassword;
				cout<<"\n"<<BLUE<<"\t\t\t\t\tConfirm new password     : "<<RESET;
				cin>>e.newPassword1;
				if ( e.newPassword.compare(e.newPassword1)==0)
				{   flag=0;
				    st2=con->createStatement();
				    sqlstmt="update employeedetails set password=:1 where emp_id=:2";
				    st2->setSQL(sqlstmt);
				    st2->setString(1,e.newPassword);
				    st2->setInt(2,e.employeeId);
				    count=st2->executeUpdate();
				    if(count==1)
				    {
					cout<<"\n"<<GREEN<<"\t\t\t\t\t\tUpdated successfully"<<RESET<<endl<<endl;
					cout<<"\n"<<GREEN<<"\t\t\t\t\tEmployee ID           : "<<e.employeeId<<RESET;
					cout<<"\n"<<GREEN<<"\t\t\t\t\tNew Password          : "<<e.newPassword<<RESET;
				    }
				    con->commit();
				    con->terminateStatement(st2);
				}
				else
				{
				    cout<<"\n"<<RED<<"\t\t\t\t\tPassword mismatch. Try again"<<RESET<<endl;
				    continue;
				}
			    }
			}

			else
			{
			    cout<<"\n"<<RED<<"\t\t\t\t\tIncorrect password"<<RESET<<endl;
			}
			st->closeResultSet(rs);
			con->terminateStatement(st);
			break;
		    case 8:
			return;
		    default:
			{
			    cout<<"\n\t\t\t"<<RED<<"Invalid choice.. select choice between [1-8]"<<RESET<<endl;
			}
		}
		cout<<endl<<endl<<RED<<"\t\t\tDo you want to update anything else? (y/n) : "<<RESET;
		//cin>>decision;
		decision=val.getCharacter();
	    }
	    while(decision=='y'|| decision=='Y');
	    if(decision=='n' || decision=='N')
		return;


	}
	else
	{
	    cout<<"\n\t\t\t"<<RED<<region<< " Manager has no authority to update employees of "<<region1<<" region"<<RESET<<endl;
	}

    } 
    else
    {										
	cout<<"\n"<<RED<<"\t\t\t\tInvalid Id"<<RESET<<endl;

    }

    /* Carries out the above operations until the the decision to continue is "yes".*/  

}

/* Remove employee function will delete existing employee details for the particular employee id present in the employee details database.*/
void Manager::removeEmployee(int rank,int eid)
{
    Validations val;

    system("clear");
    header();
    cout<<"                   *************************** Delete Employee **************************"<<            endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    Employee e;
    string sqlstmt,region1;
    string reg,reg1;
    st=con->createStatement();
    sqlstmt="select region from employeedetails where rank=:1 and emp_id=:2";

    st->setSQL(sqlstmt);
    st->setInt(1,rank);
    st->setInt(2,eid);
    rs=st->executeQuery();
    /* stores the region coresponding to the manager's employee id and rank entered above.*/
    while(rs->next())
    {
	reg=rs->getString(1);
    }
    st->closeResultSet(rs);
    con->terminateStatement(st);
    cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter the employee Id for deletion : "<<RESET;
    e.employeeId=val.getIntegerValue();
    sqlstmt="select * from employeedetails where emp_id=:1";
    st1=con->createStatement();
    st1->setSQL(sqlstmt);
    st1->setInt(1,e.employeeId);
    rs=st1->executeQuery();
    if (rs->next())
    {
	sqlstmt="select region from employeedetails where emp_id=:1";
	st1->setSQL(sqlstmt);
	st1->setInt(1,e.employeeId);
	rs=st1->executeQuery();
	/* stores the region coresponding to the employee id entered above.*/ 

	while(rs->next())
	{
	    reg1=rs->getString(1);
	}
	st1->closeResultSet(rs);
	con->terminateStatement(st1);

	/* checks if the manager's region and the employee's region match.*/ 
	if(reg==reg1)
	{ 
	    st2=con->createStatement();
	    sqlstmt="delete from employeedetails where emp_id=:1";
	    st2->setSQL(sqlstmt);
	    st2->setInt(1,e.employeeId);
	    st2->executeUpdate();
	    con->terminateStatement(st2);
	    cout<<"\n"<<GREEN<<"\t\t\t\t\t\tDeleted successfully"<<RESET<<endl;
	    cout<<"\n"<<RED<<"\t\t\t\t\tPress enter key to continue  "<<RESET;
	    cin.get(); cin.get();

	}
	else
	{
	    cout<<"\n\t\t\t"<<RED<<reg<<" Manager has no authority to remove employee details of "<<reg1<<" region"<<RESET<<endl;
	    //        cout<<"\n"<<RED<<"\t\t\t\t\tPress enter key to continue  "<<RESET;

	} 
    }
    else
    {  
	cout<<"\n\t\t\t\t\t"<<RED<<" Employee Id does not exist"<<RESET<<endl;
    }
}
/* Display employee function will list all the existing and newly added employees details from employee details database.*/
void Manager::displayAllEmployee()
{
    Validations val;

    system("clear");
    header();
    cout<<"              *************************** Display All Employee Details **************************     "<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    Employee e;
    string sqlstmt;
    string empName;
    try
    {
	st=con->createStatement();
	sqlstmt="select * from employeedetails order by emp_id";
	st->setSQL(sqlstmt);
	rs=st->executeQuery();
	cout<<BLACK<<setw(13)<<"EMPLOYEE ID"<<setw(20)<<"EMPLOYEE NAME"<<setw(8)<<"BANK ID"<<setw(26)<<"DESIGNATION"<<setw(6)<<"RANK"<<setw(8)<<"HEAD ID"<<setw(11)<<"SALARY"<<setw(8)<<"REGION"<<RESET<<endl;
	cout<<RED<<setw(13)<<"-----------"<<setw(20)<<"-------------"<<setw(8)<<"-------"<<setw(26)<<"-----------"<<setw(6)<<"----"<<setw(8)<<"-------"<<setw(11)<<"------"<<setw(8)<<"------"<<RESET<<"\n";
	/* Displays all the employee details one after the other till the end of the database.*/
	while(rs->next())
	{
	    e.employeeId=rs->getInt(1);
	    e.employeeFirstName=rs->getString(2);
	    e.employeeLastName=rs->getString(3);
	    e.dateOfJoining=rs->getString(4);
	    e.address=rs->getString(5);
	    e.workingBankId=rs->getInt(6);
	    e.designation=rs->getString(7);
	    e.rank=rs->getInt(8);
	    e.reportingHeadId=rs->getInt(9);
	    e.salary=rs->getDouble(10);
	    e.region=rs->getString(12);
	    empName = e.employeeFirstName+" "+e.employeeLastName;
	    cout.precision(20);
	    cout<<endl<<BLUE<<setw(13)<<e.employeeId<< setw(20)<< empName <<setw(8)<<e.workingBankId<<setw(26)<<e.designation<<setw(6)<<e.rank<<setw(8)<<e.reportingHeadId<<setw(11)<<e.salary<<setw(8)<<e.region<<RESET<<"\n";
	} 
	cout<<"\n"<<RED<<"\t\t\t\t\tPress any key to continue  "<<RESET;
	cin.get(); cin.get();
	st->closeResultSet(rs);
	con->terminateStatement(st);
    }
    catch(SQLException &y)
    {
	cout<<"\n"<<RED<<"\t\t\t\t\tInvalid Option"<<RESET<<endl;
    }
}

/* Display employee function will lists a particular employee details coresponding to the employee id passed from the employee details database.*/

void Manager::displayEmployee()
{
    Validations val;

    system("clear");
    header();
    cout<<"                *************************** Display Employee Details **************************     "<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    Employee e;
    string sqlstmt;
    string empName;

    st=con->createStatement();
    try
    {

	cout<<"\n"<<BLUE<<"\t\t\t\t\tEnter the employee id to view : "<<RESET;
	cin>>e.employeeId;
	cout<<endl;
	sqlstmt="select * from employeedetails where emp_id=:1";
	st->setSQL(sqlstmt);
	st->setInt(1,e.employeeId);
	rs=st->executeQuery();

	/* Checks if the entered employee id exists in the employee details database.*/
	if(rs->next())
	{
	    e.employeeId=rs->getInt(1);
	    e.employeeFirstName=rs->getString(2);
	    e.employeeLastName=rs->getString(3);
	    e.dateOfJoining=rs->getString(4);
	    e.address=rs->getString(5);
	    e.workingBankId=rs->getInt(6);
	    e.designation=rs->getString(7);
	    e.rank=rs->getInt(8);
	    e.reportingHeadId=rs->getInt(9);
	    e.salary=rs->getDouble(10);
	    e.region=rs->getString(12);
	    empName = e.employeeFirstName+" "+e.employeeLastName;
	    cout<<BLACK<<setw(13)<<"EMPLOYEE ID"<<setw(20)<<"EMPLOYEE NAME"<<setw(8)<<"BANK ID"<<setw(26)<<"DESIGNATION"<<setw(6)<<"RANK"<<setw(8)<<"HEAD ID"<<setw(11)<<"SALARY"<<setw(8)<<"REGION"<<RESET<<"\n";
	    cout.precision(20);
	    cout<<RED<<setw(13)<<"-----------"<<setw(20)<<"-------------"<<setw(8)<<"-------"<<setw(26)<<"-----------"<<setw(6)<<"----"<<setw(8)<<"-------"<<setw(11)<<"------"<<setw(8)<<"------"<<RESET<<"\n";
	    cout<<endl<<BLUE<<setw(13)<<e.employeeId<< setw(20)<< empName << setw(14) <<setw(8)<<e.workingBankId<<setw(26)<<e.designation<<setw(6)<<e.rank<<setw(8)<<e.reportingHeadId<<setw(11)<<e.salary<<setw(8)<<e.region<<RESET<<"\n";
	    cout<<endl<<RED<<"\t\t\t\t\tPress enter key to continue  "<<RESET;
	    cin.get(); cin.get();
	    st->closeResultSet(rs);
	    con->terminateStatement(st);
	}
	else
	{
	    cout<<"\n"<<RED<<"\t\t\t\t\tInvalid Employee Id"<<RESET<<endl;
	}

    }
    catch(SQLException &y)
    {
	cout<<"\n"<<RED<<"\t\t\t\t\tInvalid Option"<<RESET;
    }
}



Manager::~Manager()
{
    env->terminateConnection(con);
    Environment::terminateEnvironment(env);
}





