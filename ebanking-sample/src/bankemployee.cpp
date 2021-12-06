#include<stdlib.h>
#include<locale>
#include"bankemployee.hpp"
#include"login.hpp"
Bankemployee::Bankemployee(int empId) : Employee(empId)
{
    env = Environment::createEnvironment();
    conn = env->createConnection("e838243","Er.anshu04","ILPChnUnix");

}

void Bankemployee :: header()
{
    system("clear");
    cout<<"\x1b[41m                                                                                                       \x1b[0m"<<endl;
    cout<<"\033[3;30m                         *************Welcome to SAHARA BANKING**************\033[0m"<<endl;
    cout<<endl<<"\033[3;30m                           ********CORE BANKING MANAGEMENT SYSTEM*********\033[0m"<<endl;
    cout<<endl<<"\033[3;30m                               *****************************************\033[0m"<<endl;
    cout<<"\x1b[42m                                                                                                       \x1b[0m"<<endl<<endl;
    cout<<"\033[3;34m  Logged In As :\033[0m\033[31m"<<employeeFirstName<<" "<<employeeLastName<<"\033[0m";
    cout<<"\033[3;34m             Designation  :\033[0m\033[31m"<<designation<<"\033[0m";
    cout<<"\033[3;34m             Employee ID :\033[0m\033[31m"<<employeeId<<"\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;

}

void Bankemployee :: startBankEmployee()
{
    int choice;
    char ch;
    do
    {
	header();
	cout<<"                     *************** Welcome to Employee Startup Page ***************"<<endl;
	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
	cout<<BLUE<<"1. Customer Management"<<END<<endl;
	cout<<endl<<BLUE<<"2. Customer Account Management"<<END<<endl;
	cout<<endl<<BLUE<<"3. Customer Services"<<END<<endl;
	cout<<endl<<BLUE<<"4. Logout"<<END<<endl;
	cout<<endl<<BLUE<<"5. Exit Application"<<END<<endl;

	cout<<endl<<"\033[3;30m\t\t\t\t\tEnter your Choice"<<END<<"\033[3;31m[1-5] : "<<END;  
	choice=val1.getIntegerValue();

	Login lg;
	switch(choice)
	{
	    case 1:
		startCustomerMgmt();
		break;
	    case 2:
		startCustAccMgmt();
		break;
	    case 3:
		startCustomerServices();
		break;
	    case 4:
		return;
	    case 5:
		exit(1);
		break;
	    default:
		system("read -n1 -r -p \"\033[3;31m\n\n                                            Invalid   Input\n\n\n                             Press any key to continue with Employee Functions.\033[0m\"  key");   
	}
    }while(1);
}

void Bankemployee :: startCustomerMgmt()
{

    int choice;
    char ch;
    do
    {
	header();
	cout<<"\033[3;30m                         ************** Customer Management **************\033[0m"<<endl;
	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;
	cout<<endl<<BLUE<<"1. Add Customer Details"<<END<<endl;
	cout<<endl<<BLUE<<"2. Update Customer Details"<<END<<endl;
	cout<<endl<<BLUE<<"3. View Customer Details"<<END<<endl;
	cout<<endl<<BLUE<<"4. Deactivate Customer"<<END<<endl;
	cout<<endl<<BLUE<<"5. Activate Customer"<<END<<endl;
	cout<<endl<<BLUE<<"6. Delete Customer"<<END<<endl;
	cout<<endl<<BLUE<<"7. Go Back to Previous Page"<<END<<endl;

	cout<<endl<<"\033[3;30m\t\t\t\t\tEnter your Choice"<<END<<"\033[3;31m[1-7] : "<<END;    
	choice=val1.getIntegerValue();
	cout<<endl<<endl;
	switch(choice)
	{
	    case 1:
		addCustomerDetails();
		break;
	    case 2:
		updateCustomerDetails();
		break;
	    case 3:
		viewCustomerDetails();
		break;
	    case 4:
		deactivateCustomer();
		break;
	    case 5:
		activateCustomer();
		break;
	    case 6:
		deleteCustomer();
		break;
	    case 7:
		return;
	    default:
		cout<<RED<<"Invalid Input"<<END<<endl;
	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue Customer Management?(y/n)  : "<<END;
	ch=val1.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;

}

void Bankemployee :: startCustAccMgmt()
{
    int choice;
    char ch;
    do
    {
	header();
	cout<<"\033[3;30m                             ************* Customer Account Management **************\033[0m"     <<endl;
	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
	cout<<BLUE<<"1. Add Customer Account"<<END<<endl;
	cout<<endl<<BLUE<<"2. Update Customer Account"<<END<<endl;
	cout<<endl<<BLUE<<"3. View Customer Account"<<END<<endl;
	cout<<endl<<BLUE<<"4. Close Customer Account"<<END<<endl;
	cout<<endl<<BLUE<<"5. Go Back to Previous Page"<<END<<endl;

	cout<<endl<<"\033[3;30m\t\t\t\t\tEnter your Choice"<<END<<"\033[3;31m[1-5] : "<<END;       
	choice=val1.getIntegerValue();
	switch(choice)
	{
	    case 1:
		addCustomerAccount();
		break;
	    case 2:
		updateCustomerAccount();
		break;
	    case 3:
		viewCustomerAccount();
		break;
	    case 4:
		closeCustomerAccount();
		break;
	    case 5:
		return;
	    default:
		cout<<RED<<"Invalid Input"<<END<<endl;
	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue Customer Account Management?(y/n)  : "<<END;         
	ch=val1.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;

}

void Bankemployee :: startCustomerServices()
{
    int choice;
    char ch;
    do
    {
	header();

	cout<<"\033[3;30m                               *************** Customer Services ***************\033[0m"<<endl;
	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
	cout<<BLUE<<"1. Transactions "<<END<<endl;
	cout<<endl<<BLUE<<"2. Generate Account Balance of Customer's Acccount "<<END<<endl;
	cout<<endl<<BLUE<<"3. Generate Account Statement of Customer's Account"<<END<<endl;
	cout<<endl<<BLUE<<"4. Locker Request "<<END<<endl;
	cout<<endl<<BLUE<<"5. Respond Locker Request"<<END<<endl;
	cout<<endl<<BLUE<<"6. Respond ChequeBook Request"<<END<<endl;
	cout<<endl<<BLUE<<"7. Respond Foreign Exchange Request"<<END<<endl;
	cout<<endl<<BLUE<<"8. Respond ATM Request"<<END<<endl;
	cout<<endl<<BLUE<<"9. View Foreign Exchange Rates"<<END<<endl;
	cout<<endl<<BLUE<<"10.Go Back to Previous Page"<<END<<endl; 
	cout<<endl<<"\033[3;30m\t\t\t\t\tEnter your Choice"<<END<<"\033[3;31m[1-10] : "<<END;  
	choice=val1.getIntegerValue();
	cout<<endl<<endl; 
	switch(choice)
	{
	    case 6:
		respondChequeRequest();
		break;
	    case 8:
		respondAtmRequest();
		break;
	    case 5:
		respondLockerRequest();
		break;
	    case 7:
		respondForeignExchange();
		break;
	    case 3:
		generateAccountStatement();
		break;
	    case 2:
		generateAccountBalance();
		break;
	    case 1:
		respondTransaction();
		break;
	    case 4:
		lockerRequest();
		break;
	    case 9:
		viewForeignex();
		break;
	    case 10:
		return;
	    default:
		cout<<RED<<"Invalid Input"<<END<<endl;
	}
	cout<<endl<<"\033[3;31m\t\t\t\tDo you want to continue Customer Services?(y/n)  : "<<FORMAT;
	ch=val1.getCharacter();
    }while(ch=='y'||ch=='Y');

    if(ch=='n' || ch =='N')
	return;

}

bool Bankemployee :: activeCheck(int accNumber)
{
    string sqlstmt1;
    stmt = conn->createStatement();
    sqlstmt1="select count(*) from cust_account where acc_no=:1";
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,accNumber);
    rs= stmt->executeQuery();
    rs->next();
    if(rs->getInt(1)==0)
    {
	stmt->closeResultSet(rs);
	cout<<endl<<RED<<"Invalid Account Number of Customer"<<END<<endl;
	conn->terminateStatement(stmt);
	system("read -n1 -r -p \"\033[3;31m\n\n                                  Press any key to return\033[0m\"  key");
	return 0;
    }
    else

    {
	stmt->closeResultSet(rs);
	conn->terminateStatement(stmt);
	stmt = conn->createStatement();
	sqlstmt1="select state from customer where cust_id=(select cust_id from cust_account where acc_no=:1)";
	stmt->setSQL(sqlstmt1);
	stmt->setInt(1,accNumber);
	rs= stmt->executeQuery();
	rs->next();
	if(rs->getInt(1)==0)
	{
	    stmt->closeResultSet(rs);
	    cout<<endl<<RED<<"Customer is Deactived.No Operations allowed"<<END<<endl;
	    system("read -n1 -r -p \"\033[3;31m\n\n                                Press any key to return\033[0m\"  key");
	    conn->terminateStatement(stmt);
	    return 0;

	}
	else
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    return 1;
	}
    }
}

bool Bankemployee::activeCustId(int custId)
{
    string sqlstmt1;
    stmt = conn->createStatement();
    sqlstmt1="select count(*) from customer where cust_id=:1";
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,custId);
    rs= stmt->executeQuery();
    rs->next();
    if(rs->getInt(1)==0)
    {
	stmt->closeResultSet(rs);
	cout<<endl<<RED<<"Invalid  Customer Id"<<END<<endl;
	conn->terminateStatement(stmt);
	system("read -n1 -r -p \"\033[3;31m\n\n                                Press any key to return\033[0m\"  key");
	return 0;
    }
    else

    {
	stmt->closeResultSet(rs);
	conn->terminateStatement(stmt);
	stmt = conn->createStatement();
	sqlstmt1="select state from customer where cust_id=:1";
	stmt->setSQL(sqlstmt1);
	stmt->setInt(1,custId);
	rs= stmt->executeQuery();
	rs->next();
	if(rs->getInt(1)==0)	
	{
	    stmt->closeResultSet(rs);
	    cout<<endl<<RED<<"Customer is Deactived.No Operations allowed"<<END<<endl;
	    system("read -n1 -r -p \"\033[3;31m\n\n                                Press any key to return\033[0m\"  key");
	    conn->terminateStatement(stmt);
	    return 0;

	}
	else
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    return 1;
	}
    }

}

//responds for request of cash withdrawl,deposit and fund transfer
void Bankemployee :: respondTransaction()
{
    header();
    CustomerTransaction custTrans;

    cout<<"\033[3;30m                       ******************** Transactions ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;
    int flag=1,accNumber,choice,count,count1,receiverAccNumber;
    double money,charge;
    string sqlstmt1,sqlstmt2,sqlstmt3,sqlstmt4;
    cout<<endl<<"\033[4;31m\t\t\t\t\tSelect the type of transaction"<<END<<endl<<endl<<"\033[3;34m\t\t\t\t\t\t 1. Deposit \n\t\t\t\t\t\t 2. Withdrawal \n\t\t\t\t\t\t 3. Fund Transfer "<<END<<endl;
    cout<<endl<<"\033[3;30m\t\t\t\t\tEnter your choice"<<END<<FORMAT2<<"[1-3] : "<<END;
    choice=val1.getIntegerValue();
    if(choice==1)
    {
	//checks whether the account is existing or not
	cout <<endl<<FORMAT3<<"\t\t\t\tEnter the Account Number to which Cash is deposited : "<<END;
	custTrans.receiverAccNumber=val1.getIntegerValue();

	if(!activeCheck(custTrans.receiverAccNumber))
	{
	    return;
	}	
	else
	{
	    cout<<endl<<FORMAT3<<"\t\t\t\tEnter the money to be deposited  : "<<END;
	    custTrans.amount=val1.getDouble();
	    sqlstmt1 = "update cust_account set balance=balance + :1 where acc_no = :2";
	    stmt=conn->createStatement();
	    stmt->setSQL(sqlstmt1);
	    stmt->setDouble(1,custTrans.amount);
	    stmt->setInt(2,custTrans.receiverAccNumber);
	    count = stmt->executeUpdate();
	    conn->commit();

	    if(count==1)
	    { cout<<endl<<GREEN<<"\t\t\t\tMoney deposited in customer's account successfully "<<END<<endl;
		sqlstmt1 = "select balance from cust_account where acc_no=:1";
		stmt->setSQL(sqlstmt1);
		stmt->setInt(1,custTrans.receiverAccNumber);
		rs=stmt->executeQuery();
		rs->next();
		cout<<endl<<BLUE<<"The present account balance is :"<<END<<rs->getDouble(1)<<endl;
		stmt->closeResultSet(rs);
	    }

	    sqlstmt2 = "update Bank set balance=balance + :1 where bank_id = (select bank_id from cust_account where acc_no = :2)";  //sets balance of bank
	    stmt->setSQL(sqlstmt2);
	    stmt->setDouble(1,custTrans.amount);
	    stmt->setInt(2,custTrans.receiverAccNumber);
	    stmt->executeUpdate();
	    conn->commit();
	    conn->terminateStatement(stmt);
	    stmt = conn->createStatement();
	    sqlstmt3 = "insert into cust_transaction values(trans_sequence.NextVal,'Deposit',:1,null,:2,sysdate)";                
	    stmt->setSQL(sqlstmt3);
	    stmt->setDouble(1,custTrans.amount);
	    stmt->setInt(2,custTrans.receiverAccNumber);
	    stmt->executeUpdate();
	    cout<<endl<<GREEN<<"\t\t\t\t\tTransaction Successful"<<END<<endl;
	    conn->commit();
	    conn->terminateStatement(stmt);

	} 
    }

    else if(choice==2)
    {
	//checks whether the account is existing or not
	cout<<FORMAT3<<endl<<"\t\t\tEnter the Account Number from which Cash is to be Withdrawn: "<<END;
	custTrans.senderAccNumber=val1.getIntegerValue();
	if(!activeCheck(custTrans.senderAccNumber))
	{
	    return;
	}
	else
	{

	    cout<<endl<<FORMAT3<<"\t\t\tEnter the money to be withdrawn : "<<END;
	    custTrans.amount=val1.getDouble();
	    charge = custTrans.amount;

	    stmt = conn->createStatement();
	    sqlstmt1="select count(c.sender_acc) from cust_transaction c,cust_account e where      e.acc_type='CA' and e.acc_no=c.sender_acc and c.sender_acc= :1 and extract(month from sysdate)=extract(month from c.timestamp) and extract(year from sysdate)=extract(year from c.timestamp)";
	    stmt->setSQL(sqlstmt1);
	    stmt->setInt(1,custTrans.senderAccNumber);
	    rs1 = stmt->executeQuery();
	    rs1->next();
	    if(rs1->getInt(1)>200)
		charge=charge+1.5;
	    stmt->closeResultSet(rs1);
	    sqlstmt1 = "select balance from cust_account where acc_no = :1";
	    stmt->setSQL(sqlstmt1);
	    stmt->setInt(1,custTrans.senderAccNumber);
	    rs= stmt->executeQuery();
	    rs->next();
	    if(rs->getDouble(1)<charge)   /*checks whether the balance is enough  */                
	    {
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);
		cout<<endl<<RED<<"Not enough balance in your Account"<<END<<endl;
		system("read -n1 -r -p \"\033[3;31m\n\n                                              Press any key to return\033[0m\"  key");
		return; 
	    }
	    else
	    {

		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);
		stmt = conn->createStatement();
		sqlstmt2 = "update cust_account set balance=balance - :1 where acc_no = :2";
		stmt->setSQL(sqlstmt2);
		stmt->setDouble(1,charge);
		stmt->setInt(2,custTrans.senderAccNumber);
		stmt->executeUpdate();
		conn->commit();
		cout<<endl<<GREEN<<"\t\t\t\tMoney debited from customer account successfully"<<END<<endl;

		sqlstmt1 = "select balance from cust_account where acc_no=:1";
		stmt->setSQL(sqlstmt1);
		stmt->setInt(1,custTrans.senderAccNumber);
		rs=stmt->executeQuery();
		rs->next();
		cout<<endl<<FORMAT3<<"\t\t\t\tThe present account balance is :"<<END<<rs->getDouble(1)<<endl;
		stmt->closeResultSet(rs);
		stmt = conn->createStatement();
		sqlstmt3 = "update Bank set balance=balance - :1 where bank_id = (select bank_id from cust_account where acc_no = :2)";//sets balance of bank

		stmt->setSQL(sqlstmt3);
		stmt->setDouble(1,charge);
		stmt->setInt(2,custTrans.senderAccNumber);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);
		stmt = conn->createStatement();
		sqlstmt4 = "insert into cust_transaction values(trans_sequence.NextVal,'Withdraw',:1,:2,null,sysdate)";
		stmt->setSQL(sqlstmt4);
		stmt->setDouble(1,charge);
		stmt->setInt(2,custTrans.senderAccNumber);
		stmt->executeUpdate();
		cout<<endl<<GREEN<<"\t\t\t\t\tTransaction Successful"<<END<<endl;
		conn->commit();
		conn->terminateStatement(stmt);
	    }}                 

    }

    else if(choice==3)
    {
	//checks whether the account is existing or not
	cout<<endl<<FORMAT3<<"\t\t\tEnter the Account Number from which Cash is transferred : "<<END;
	custTrans.senderAccNumber=val1.getIntegerValue();
	if(!activeCheck(custTrans.senderAccNumber))
	    return;
	cout<<endl<<FORMAT3<<"\t\t\tEnter the money to transfer :  "<<END;
	custTrans.amount=val1.getDouble();
	cout<<endl<<FORMAT3<<"\t\t\tEnter the Account Number to which Cash is transferred : "<<END;
	custTrans.receiverAccNumber=val1.getIntegerValue();
	if(!activeCheck(custTrans.receiverAccNumber))
	    return;
	if(custTrans.senderAccNumber==custTrans.receiverAccNumber)
	{
	    cout<<endl<<RED<<"Both Account Numbers cannot be same"<<END<<endl;
	    system("read -n1 -r -p \"\033[3;31m\n\n                                        Press any key to return \033[0m\"  key");
	    return;
	}
	stmt = conn->createStatement();
	sqlstmt1 = "select balance from cust_account where acc_no = :1";
	stmt->setSQL(sqlstmt1);
	stmt->setInt(1,custTrans.senderAccNumber);
	rs= stmt->executeQuery();
	rs->next();                
	if(rs->getDouble(1)<custTrans.amount)  //checks whether the balance is enough
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    cout<<endl<<RED<<"Not enough balance in Sender's Account"<<END<<endl;
	    system("read -n1 -r -p \"\033[3;31m\n\n                                        Press anykey to return \033[0m\"  key");
	    return;
	}
	else
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    stmt = conn->createStatement();
	    sqlstmt2 = "update cust_account set balance=balance - :1 where acc_no = :2";
	    stmt->setSQL(sqlstmt2);
	    stmt->setDouble(1,custTrans.amount);
	    stmt->setInt(2,custTrans.senderAccNumber);
	    count1= stmt->executeUpdate();
	    conn->commit();
	    sqlstmt3 = "update cust_account set balance=balance + :1 where acc_no = :2";
	    stmt->setSQL(sqlstmt3);
	    stmt->setDouble(1,custTrans.amount);
	    stmt->setInt(2,custTrans.receiverAccNumber);
	    count = stmt->executeUpdate();
	    conn->commit();
	    if(count==1 && count1==1)
	    {
		cout<<endl<<GREEN<<"\t\t\tMoney credited to receiver account and debited from sender account"<<END<<endl;

		sqlstmt1 = "select balance from cust_account where acc_no=:1";
		stmt->setSQL(sqlstmt1);
		stmt->setInt(1,custTrans.senderAccNumber);
		rs=stmt->executeQuery();
		rs->next();
		cout<<endl<<FORMAT3<<"\t\t\t\tThe present account balance is :"<<END<<rs->getDouble(1)<<endl;
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);
	    }
	    stmt = conn->createStatement();
	    sqlstmt4 = "insert into cust_transaction values(trans_sequence.NextVal,'FTransfer',:1,:2,:3,sysdate)";
	    stmt->setSQL(sqlstmt4);
	    stmt->setDouble(1,custTrans.amount);
	    stmt->setInt(2,custTrans.senderAccNumber);
	    stmt->setInt(3,custTrans.receiverAccNumber);
	    stmt->executeUpdate();
	    cout<<endl<<GREEN<<"\t\t\t\t\tTransaction Successful"<<END<<endl;
	    conn->commit();
	    conn->terminateStatement(stmt);



	}}
    else
    {
	cout<<endl<<RED<<"Invalid Choice"<<END<<endl;
    }
}               //end of function
void Bankemployee :: generateAccountBalance() //generates account balance of customer
{
    header();
    cout<<"\033[3;30m                       ******************** Account Balance ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    int accNumber,flag=1;
    string sqlstmt1;
    cout <<endl<<FORMAT3<<"\t\t\tEnter the Account Number to check the account balance: "<<END;
    accNumber=val1.getIntegerValue();
    if(!activeCheck(accNumber))
	return;
    sqlstmt1 = "select balance from cust_account where acc_no = :1"; //queries account balance 
    stmt = conn->createStatement(); 
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,accNumber);
    rs= stmt->executeQuery();

    rs->next();
    cout<<endl<<GREEN<<"\t\t\t\t\tThe balance is   :"<<END<<rs->getDouble(1)<<endl;


    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
}              //end of function


void Bankemployee :: generateAccountStatement() //generates account statement of customer
{
    header();
    cout<<"\033[3;30m                       ******************** Account Statement ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    int accNumber,flag=1;
    string sqlstmt1;
    //checks whether the account is existing or not
    cout<<endl<<FORMAT3<<"\t\t\tEnter the Account Number to generate the account statement :  "<<END;
    accNumber=val1.getIntegerValue();
    if(!activeCheck(accNumber))
	return;
    stmt = conn->createStatement();		
    sqlstmt1 = "select * from cust_transaction where sender_acc = :1 or receiver_acc = :1";                            //queries account statement of account number
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,accNumber);
    rs= stmt->executeQuery();

    cout<<endl;
    if(rs->next())
    {
	cout<<setw(15)<<"ID"<<setw(15)<<"Type"<<setw(15)<<"Credit/Debit"<<setw(10)<<"Sender"<<setw(10)<<"Receiver"<<setw(10)<<"Amount"<<setw(15)<<"Date"<<endl<<endl;

	do
	{

	    if(rs->getInt(5)==accNumber)
	    {
		cout<<FORMAT3;
		cout<<setw(15)<<rs->getInt(1)<<setw(15)<<rs->getString(2)<<setw(15)<<"Credit"<<setw(10)<<rs->getInt(4)<<setw(10)<<"----"<<setw(10)<<rs->getDouble(3)<<setw(15)<<rs->getString(6)<<endl;
	    }
	    else
		cout<<setw(15)<<rs->getInt(1)<<setw(15)<<rs->getString(2)<<setw(15)<<"Debit"<<setw(10)<<"----"<<setw(10)<<rs->getInt(5)<<setw(10)<<rs->getDouble(3)<<setw(15)<<rs->getString(6)<<endl;
	}while(rs->next());
    }
    else
    {
	cout<<endl<<RED<<"No Transaction done by given Account Number."<<END;

    }
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
}              //end of function


void Bankemployee :: respondChequeRequest()  //responds to the chequebook request
{
    header();
    cout<<"\033[3;30m                       ******************** Cheque Request ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;
    int accNumber,flag=1;
    string sqlstmt1,sqlstmt2,sqlstmt3,sqlstmt4;
    char chequeFees;
    //checks whether the account is existing or not
    cout<<endl<<"\033[3;30m\tThe Cheque Book Facility is Only for Salaried Savings and Salaried Non Savings Account"<<END;
    cout<<endl<<"\033[3;30m\t\t\t\tThe minimum balance of Cheque Book for SNS should be 5000"<<END;
    cout<<endl<<"\033[3;30m\t\t\t\t\tCheque Books are free for SS Account!"<<endl<<END;
    cout <<endl<<endl<<FORMAT3<<"\t\t\tEnter the Account Number for which Cheque Book is required : "<<END;
    accNumber=val1.getIntegerValue();
    if(!activeCheck(accNumber))
	return;
    stmt = conn->createStatement();

    sqlstmt1 = "select mini_balance,acc_type from cust_account where acc_no=:1";
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,accNumber);

    rs= stmt->executeQuery();
    if(rs->next())
    {
	flag=0;
	if(rs->getString(2)=="SS")
	{
	    cout<<endl<<GREEN<<"\t\t\t\t\tIssue Cheque Book without extra charge."<<END<<endl;
	    sqlstmt3="insert into chequebook values(:1,cheque_sequence.nextVal,sysdate)";
	    stmt->setSQL(sqlstmt3);
	    stmt->setInt(1,accNumber);
	    stmt->executeUpdate();
	    conn->commit();
	}
	else  if((rs->getString(2)=="SNS")&&(rs->getDouble(1)>=5000 && rs->getDouble(1)<=10000))  //checks if min balance is 5000 
	{
	    cout<<endl<<RED<<"Account User needs to pay Rs.100 in cash."<<endl<<"\t\t\t\t\t Paid?(y/n) : "<<END;
	    chequeFees=val1.getCharacter();
	    if(chequeFees=='y'||chequeFees=='Y')
	    {
		sqlstmt2="delete from chequebook where acc_no=:1";
		stmt->setSQL(sqlstmt2);
		stmt->setInt(1,accNumber);
		stmt->executeUpdate();
		cout<<endl<<GREEN<<"\t\t\t\t\tCheque Book is issued."<<END<<endl;
		sqlstmt3="insert into chequebook values(:1,cheque_sequence.nextVal,sysdate)";
		stmt->setSQL(sqlstmt3);
		stmt->setInt(1,accNumber);
		stmt->executeUpdate();
		conn->commit();


	    }
	    else if(chequeFees=='n' || chequeFees =='N')
		cout<<endl<<RED<<"\tCannot issue Cheque Book"<<END<<endl;

	}
	else if ((rs->getString(2)=="SNS")&&(rs->getDouble(1)>=10000))  //checks if min balance is 10000
	{

	    sqlstmt2= "select months_between(sysdate,timestamp) from chequebook where acc_no = :1";
	    stmt->setSQL(sqlstmt2);
	    stmt->setInt(1,accNumber);
	    rs1= stmt->executeQuery();
	    rs1->next();
	    if(rs1->getInt(1)<4)
	    {
		cout<<endl<<RED<<"Account User needs to pay Rs.100 in cash"<<endl<<"\t\t\t\t\tPaid?(y/n) : "<<END;
		chequeFees=val1.getCharacter();
		if(chequeFees=='y'||chequeFees=='Y')
		{
		    sqlstmt3="delete from chequebook where acc_no=:1";
		    stmt->setSQL(sqlstmt3);
		    stmt->setInt(1,accNumber);
		    stmt->executeUpdate();
		    cout<<endl<<GREEN<<"\t\t\t\t\tCheque Book is issued."<<END<<endl;
		    sqlstmt4="insert into chequebook values(:1,cheque_sequence.nextVal,sysdate)";
		    stmt->setSQL(sqlstmt4);
		    stmt->setInt(1,accNumber);
		    stmt->executeUpdate();
		    conn->commit();

		}
		else if(chequeFees=='n' || chequeFees =='N')
		    cout<<endl<<RED<<"\tCannot issue Cheque Book"<<END<<endl;
	    }
	    else
	    {
		sqlstmt3="delete from chequebook where acc_no=:1";
		stmt->setSQL(sqlstmt3);
		stmt->setInt(1,accNumber);
		stmt->executeUpdate();
		cout<<endl<<GREEN<<"\t\t\t\tCheque Book is issued without charging extra fee."<<END<<endl;
		sqlstmt4="insert into chequebook values(:1,cheque_sequence.nextVal,sysdate)";
		stmt->setSQL(sqlstmt4);
		stmt->setInt(1,accNumber);
		stmt->executeUpdate();
		conn->commit();


	    }
	    stmt->closeResultSet(rs1);

	}
	else if((rs->getString(2)=="SNS")&&(rs->getDouble(1)<5000)) //checks if min balance is less than 5000
	{
	    cout<<endl<<"\033[3;31m\t\t\t\tMinimum Balance Is Not Enough."<<endl<<"Cannot Issue Cheque Book"<<END<<endl;
	}
	else
	{
	    cout<<endl<<"\033[3;31m\t\t\tCheque Book facility is not available for your Account."<<END<<endl;
	}
	stmt->closeResultSet(rs);
    }
    conn->terminateStatement(stmt);


}            //end of function

void Bankemployee :: lockerRequest()  //adds locker request of customer
{

    header();
    cout<<"\033[3;30m                       ******************** Locker Request ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;
    double bidAmount;
    int custid,bankid,flag=1;
    string sqlstmt1,sqlstmt2,sqlstmt3,sqlstmt4,type;
    //checks whether the customer id  is existing or not
    cout <<endl<<BLUE<<"Enter the Customer Id : "<<END;
    custid=val1.getIntegerValue();
    if(!activeCustId(custid))
	return;
    stmt = conn->createStatement();
    sqlstmt1 = "select unique bank_id from cust_account where cust_id = :1 and bank_id =:2";
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,custid);
    stmt->setInt(2,workingBankId); 
    rs2= stmt->executeQuery();
    if(!rs2->next())
    {
	stmt->closeResultSet(rs2);
	cout<<endl<<"\033[3;31m\t\t\t\tCustomer does not have account in this Bank."<<END<<endl<<"\033[3;31m\t\t\t\t\tCan not bid for Locker."<<endl;
    }
    else
    {
	stmt->closeResultSet(rs2);
	cout<<endl<<RED<<"Minimum bidding amount for locker A is 5000"<<endl;
	cout<<RED<<"Minimum bidding amount for locker B is 3000"<<endl;
	cout<<RED<<"Minimum bidding amount for locker C is 2000"<<endl;
	cout <<endl<<BLUE<<"Enter the type of locker(A/B/C) : "<<END;
	cin>>type;
	while(!(type=="A"||type=="B"||type=="C"))
	{
	    cout <<endl<<RED<<"Enter valid type of Locker : "<<END;
	    cin>>type;

	}

	sqlstmt2 = "select bank_id,min_amt from bidding_info where bank_id=(select unique bank_id from cust_account where cust_id = :1 and bank_id =:2) and locker_type=:3";
	stmt->setSQL(sqlstmt2);
	stmt->setInt(1,custid);
	stmt->setInt(2,workingBankId);
	stmt->setString(3,type);
	rs1= stmt->executeQuery();
	if(rs1->next())  //checks if locker exists for the bank
	{
	    cout <<endl<<BLUE<<"Enter the bidding amount for locker: "<<END;
	    bidAmount=val1.getDouble();
	    while(bidAmount < rs1->getDouble(2))
	    {
		cout <<endl<<RED<<"Bidding Amount should be more than minimum bidding amount"<<END;
		cout <<endl<<BLUE<<"Enter the bidding amount for locker: "<<END;
		bidAmount=val1.getDouble();
	    }
	    bankid = rs1->getInt(1);
	    stmt->closeResultSet(rs1);
	    sqlstmt3 = "insert into bidding values(:1,:2,:3,:4)";
	    stmt->setSQL(sqlstmt3);
	    stmt->setInt(1,custid);

	    stmt->setDouble(2,bidAmount);
	    stmt->setString(3,type);
	    stmt->setInt(4,bankid);
	    stmt->executeUpdate();
	    conn->commit();
	    cout<<endl<<GREEN<<"\t\t\t\t\t\tBidded for the locker"<<END<<endl; //successfully added locker
	}
	else
	{
	    stmt->closeResultSet(rs1);
	    cout<<RED<<"\tLocker is Not Available in Bank"<<END;
	} 
    }


    conn->terminateStatement(stmt);

}            //end of function


void Bankemployee ::respondLockerRequest()  //responds to locker request made by customer
{

    header();
    cout<<"\033[3;30m                       ******************** Respond Locker Request ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    Statement *stmt1;
    ResultSet *rs1;
    int count,bankid,cust_id,flag=1;
    double bidAmount;
    string sqlstmt1,sqlstmt2,sqlstmt3,sqlstmt4,sqlstmt5,type;
    stmt = conn->createStatement();
    sqlstmt1 = "select cust_id,bidding_amount,locker_type,bank_id, row_number() over(partition by bank_id order by bidding_amount desc)rno from bidding";
    stmt->setSQL(sqlstmt1);
    rs= stmt->executeQuery();

    while(rs->next())  //checks for all locker request
    {
	flag=0;
	stmt1 = conn->createStatement();
	cust_id = rs->getInt(1);
	bidAmount = rs->getDouble(2);
	type = rs->getString(3);
	bankid=rs->getInt(4);
	sqlstmt2="select availability from bidding_info where bank_id=:1 and locker_type=:2";

	stmt1->setSQL(sqlstmt2);
	stmt1->setInt(1,bankid);
	stmt1->setString(2,type);

	rs1= stmt1->executeQuery();

	rs1->next();
	if(rs1->getInt(1)>0)  //if locker is available its alloted
	{
	    stmt1->closeResultSet(rs1);
	    sqlstmt3= "insert into locker_info values(lock_sequence.nextVal,:1,:2,:3,:4)";
	    stmt1->setSQL(sqlstmt3);
	    stmt1->setInt(1,bankid);
	    stmt1->setString(2,type);
	    stmt1->setDouble(3,bidAmount);
	    stmt1->setInt(4,cust_id);
	    stmt1->executeUpdate();
	    conn->commit();
	    sqlstmt4 = "delete from bidding where cust_id=:1 and bank_id=:2 and locker_type=:3";
	    stmt1->setSQL(sqlstmt4);
	    stmt1->setInt(1,cust_id);
	    stmt1->setInt(2,bankid);
	    stmt1->setString(3,type);
	    stmt1->executeUpdate();
	    sqlstmt5 = "update bidding_info set availability=availability-1 where bank_id=:1 and locker_type=:2";
	    stmt1->setSQL(sqlstmt5);
	    stmt1->setInt(1,bankid);
	    stmt1->setString(2,type);
	    stmt1->executeUpdate();
	    conn->commit();
	    cout<<endl<<FORMAT3<<"\t\t\tLocker type "<<type<<" alloted to customer with id :"<<cust_id<<END<<endl<<endl;		
	}
	else
	{
	    cout<<endl<<"\033[3;31m\t\t\tLockers are not available for customer of bank with id :"<<bankid<<END<<endl<<endl;
	}
    }
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
    if(flag==1)
    {
	cout<<endl<<RED<<"No pending Request for Lockers."<<END<<endl;
    }

}  //end of function
//To exchange dollars and rupees as a service to customer 
//Get Type i.e. Type 1 is conversion of rupees to dollars Type 2 is conversion of Dollar to rupees		
void Bankemployee::respondForeignExchange()
{
    header();
    cout<<"\033[3;30m                       ******************** Respond Foreign Exchnage Request ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;


    double unitamount,customerunit,cust_id,bank_id,type,gain,temp,rupees,balance;
    int dollar;
    while(1)
    {
	cout<<endl<<BLUE<<"Enter the Customer ID : "<<END;
	cust_id=val1.getIntegerValue();
	if(!activeCustId(cust_id))
	{
	    return;
	}

	stmt=conn->createStatement();
	stmt->setSQL("select cust_id from customer where cust_id=:1");
	stmt->setInt(1,cust_id);
	rs=stmt->executeQuery();
	if(rs->next())
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    break;
	}
	else
	{
	    cout<<endl<<RED<<"Customer Id does not Exist"<<END<<endl;
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);

	}
    }

    while(1)
    {
	cout<<endl<<BLUE<<"Bank Id  : "<<END;
	bank_id=workingBankId;
	cout<<workingBankId<<endl;
	stmt=conn->createStatement();
	stmt->setSQL("select bank_id from bank where bank_id=:1");
	stmt->setInt(1,bank_id);
	rs=stmt->executeQuery();
	if(rs->next())
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    break;
	}
	else
	{
	    cout<<endl<<RED<<"Bank Id does not Exist"<<END<<endl;
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);

	}
    }
    cout<<endl<<FORMAT2<<"\t\t\t\t\t1. Rupee to Dollar conversion"<<END<<endl<<FORMAT2<<"\t\t\t\t\t2. Dollar to Rupee conversion"<<END<<endl;
    cout<<endl<<"\033[3;30m\t\t\t\t\tEnter your choice"<<END<<FORMAT2<<"[1-2] : "<<END;
    type=val1.getIntegerValue();
    if(type==1 || type==2)
    {
	stmt=conn->createStatement();
	stmt->setSQL("select rupees,profit from foreignex_info where type=:1");//querying database to get information about foreign exchange buy and sell rates
	stmt->setInt(1,type);
	rs=stmt->executeQuery();
	rs->next();
	unitamount=rs->getInt(1);
	gain=rs->getInt(2);
	stmt->closeResultSet(rs);
	conn->terminateStatement(stmt);
    }
    //condition checks which type is selected by user
    if(type==1)
    {
	cout<<endl<<BLUE<<"Enter Rupees  : "<<END;
	do
	{
	    customerunit=val1.getDouble();
	}while(customerunit<1);
	temp=customerunit/unitamount;
	gain=gain*temp;
	dollar=temp;
	rupees=customerunit;
	cout<<endl<<BLUE<<"You will get dollar  : "<<dollar<<END<<endl;
    }
    else if(type==2)
    {
	cout<<endl<<BLUE<<"Enter Dollars  : "<<END;
	do
	{
	    customerunit=val1.getIntegerValue();
	}while(customerunit<1);
	gain=customerunit*gain;
	dollar=customerunit;
	rupees=customerunit*unitamount;
	cout<<endl<<BLUE<<"You will get rupees  : "<<rupees<<END<<endl;
    }
    //Checks whether either two of exchange happened or not and updates bank balance
    if(type==1 || type==2)
    {
	stmt=conn->createStatement();
	stmt->setSQL("insert into foreignex values(:1,:2,:3,:4,:5)");
	stmt->setInt(1,cust_id);
	stmt->setInt(2,bank_id);
	stmt->setInt(3,type);
	stmt->setDouble(4,rupees);
	stmt->setInt(5,dollar);
	stmt->executeUpdate();
	conn->commit();
	conn->terminateStatement(stmt);
	stmt=conn->createStatement();
	stmt->setSQL("select balance from bank where bank_id=:1");
	stmt->setInt(1,bank_id);
	rs=stmt->executeQuery();
	rs->next();
	balance=rs->getInt(1);
	balance+=gain;
	stmt->closeResultSet(rs);
	conn->terminateStatement(stmt);
	stmt=conn->createStatement();
	stmt->setSQL("update bank set balance=:1 where bank_id=:2");
	stmt->setDouble(1,balance);
	stmt->setInt(2,bank_id);
	stmt->executeUpdate();
	conn->commit();
	conn->terminateStatement(stmt);
    }
    //If invalid  type is selected 
    else
    {
	cout<<endl<<RED<<"Invalid Choice"<<END<<endl;
    }
}
void Bankemployee::viewForeignex()
{
    header();
    cout<<"\033[3;30m                       ******************** View Foreign Exchange ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    int type,rupees,rupees1,rupees2,profit;
    stmt=conn->createStatement();
    stmt->setSQL("select * from foreignex_info");
    rs=stmt->executeQuery();
    rs->next();
    cout<<endl<<BLACK<<"Type 1-> Rupee to Dollar Conversion"<<endl;
    cout<<BLACK<<"Type 2-> Dollar to Rupee Conversion"<<endl;
    cout<<endl<<endl<<"                                        "<<FORMAT<<setw(10)<<"Type"<<setw(10)<<"Rupees"<<setw(10)<<"Profit"<<endl<<END<<endl;
    cout<<"                                        "<<FORMAT2<<setw(10)<<rs->getInt(1)<<setw(10)<<rs->getInt(2)<<setw(10)<<rs->getInt(3)<<endl<<END;
    rs->next();
    cout<<"                                        "<<FORMAT2<<setw(10)<<rs->getInt(1)<<setw(10)<<rs->getInt(2)<<setw(10)<<rs->getInt(3)<<endl<<END;
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
}
/*This function add the new customer to the bank by getting
 * detail from the customer who wants to open his account in the
 * bank*/
void Bankemployee::addCustomerDetails()
{
    header();
    Customer customerObject;
    int flag=1;

    cout <<FORMAT<<"\t\t******************** Enter the Details Of Customer ********************"<<FORMAT1;
    cout<<endl<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;

    string sqlstmt1;

    cout<<endl<<endl;
    cout<<setw(27)<<FORMAT3<<"Customer Name"FORMAT<<FORMAT2<<"*"<<FORMAT<<FORMAT3<<"                                  :   "<<FORMAT;
    //Get the name of customer
    while((getline(cin>>ws,customerObject.customerName)))
    {

	int flag=1;
	int Len=0;

	Len = customerObject.customerName.length();
	for(unsigned int i = 0; i < Len; i++)
	{

	    if(isdigit(customerObject.customerName[i]))
		flag=0;



	}
	if(flag==0)
	{

	    cin.clear();

	    cout<<endl<<setw(27)<<FORMAT2<<"Please enter a valid name must be alphabet      :   "<<FORMAT;

	}
	else
	{
	    break;
	}
    }
    cout<<endl<<setw(27)<<FORMAT3<<"Age"<<FORMAT<<FORMAT2<<"*"<<FORMAT<<FORMAT3<<"                                            :   "<<FORMAT;
    customerObject.customerAge=val1.ageValidation();

    cout<<endl<<setw(27)<<FORMAT3<<"Customer Address"<<FORMAT<<FORMAT2<<"*"<<FORMAT<<FORMAT3<<"                               :   "<<FORMAT;
    getline(cin>>ws,customerObject.customerAddress);

    /*check whether the voter id and pan card id is
      valid or not until user enter the valid input*/


    while(flag)
    {
	cout<<endl<<setw(27)<<FORMAT3<<"Customer Voter Id                               :   "<<FORMAT;
	getline(cin,customerObject.customerVoterId);
	cout<<endl<<setw(27)<<FORMAT3<<"Customer Pan Card Id                            :   "<<FORMAT;
	getline(cin,customerObject.customerPanCardId);

	if(customerObject.customerVoterId.empty()==0 && customerObject.customerPanCardId.empty()==1)
	{
	    flag=0;
	    customerObject.customerPanCardId="null";
	    while(customerObject.customerVoterId.length()!=10)
	    {
		cout<<endl<<setw(27)<<FORMAT2<<"Length Of Voter Id Should be 10"<<FORMAT;
		cout<<setw(69)<<FORMAT3<<"Enter Customer Voter Id Again                   :   "<<FORMAT;
		getline(cin,customerObject.customerVoterId);
	    }
	}
	else if(customerObject.customerVoterId.empty()==1 && customerObject.customerPanCardId.empty()==0)
	{
	    flag=0;
	    customerObject.customerVoterId="null";
	    while(customerObject.customerPanCardId.length()!=10)
	    {

		cout<<endl<<setw(27)<<FORMAT2<<"Length of Customer Pan Card Id Should be 10"<<FORMAT<<endl;
		cout<<setw(27)<<FORMAT3<<"Enter Customer Pan Card Id Again                :   "<<FORMAT;
		getline(cin,customerObject.customerPanCardId);
	    }
	}
	else if(customerObject.customerVoterId.empty()==1 && customerObject.customerPanCardId.empty()==1)
	{
	    cout<<endl<<setw(27)<<FORMAT2<<"One Of The Id Is Mandatory.Please Enter"<<FORMAT<<endl;
	    continue;
	}
	else if(customerObject.customerVoterId.empty()==0 && customerObject.customerPanCardId.empty()==0)
	{
	    flag=0;
	    while(  customerObject.customerPanCardId.length()!=10)
	    {
		cout<<endl<<setw(27)<<FORMAT2<<"Length of Customer Pan Card Id Should be 10"<<FORMAT<<endl;
		cout<<setw(27)<<FORMAT3<<"Enter Customer Pan Card Id Again                :   "<<FORMAT;
		getline(cin,customerObject.customerPanCardId);
	    }
	    while(customerObject.customerVoterId.length()!=10)
	    {
		cout<<endl<<setw(27)<<FORMAT2<<"Length Of Voter Id Should be 10"<<FORMAT<<endl;
		cout<<setw(27)<<FORMAT3<<"Enter Customer Voter Id Again                   :   "<<FORMAT;
		getline(cin,customerObject.customerVoterId);
	    }


	}
    }

    cout<<endl<<setw(27)<<FORMAT3<<"Customer Phone Number"<<FORMAT<<FORMAT2<<"*"<<FORMAT<<FORMAT3<<"                          :   "<<FORMAT;
    //Get phone number from the user and check it whether it is valid or not
    customerObject.customerPhoneNumber=val1.isValidMobileNumber();
    string a="c9876543210";
    string n="Anshuman Shukla";
    stmt = conn->createStatement();
    sqlstmt1 = "insert into customer values(cust_sequence.nextVal,:1,1,:2,:3,:4,:5,:6)";
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,customerObject.customerAge);
    stmt->setString(2,customerObject.customerName);
    stmt->setString(3,customerObject.customerAddress);
    stmt->setString(4,customerObject.customerPhoneNumber);
    stmt->setString(5,customerObject.customerPanCardId);
    stmt->setString(6,customerObject.customerVoterId);
    stmt->executeUpdate();
    cout<<endl<<"\033[3;32m\t\t\t\t\t Details Inserted Successfully\033[0m"<<endl;
    conn->commit();
    conn->terminateStatement(stmt);
    stmt = conn->createStatement();
    int id;
    sqlstmt1 = "select cust_sequence.CurrVal from dual";
    stmt->setSQL(sqlstmt1);
    rs = stmt->executeQuery();
    if(rs->next())
    {
	id= rs->getInt(1);
    }
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
    cout<<endl<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer Id           : "<<id<<END<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer Name         : "<< customerObject.customerName <<END<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer Age          : "<<customerObject.customerAge <<END<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer State        : "<<customerObject.stateOfCustomer<<END<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer Address      : "<<customerObject.customerAddress<<END<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer Phone Number : "<<customerObject.customerPhoneNumber<<END<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer Voter Id     : "<< customerObject.customerVoterId<<END<<endl;
    cout<<GREEN<<"\t\t\t\t\tCustomer Pan Card Id  : "<< customerObject.customerPanCardId<<END<<endl;
}


//convert the integer type into string type
string  Bankemployee::to_string( int number )
{
    ostringstream oss;
    oss<< number;
    return oss.str();
}
/*This function is used to update the existing details of the
 * 		customer by entering the id of that customer 
 * 				whose details have to be updated*/

void Bankemployee::updateCustomerDetails()
{
    Validations val;
    header();
    Customer customerObject;
    char ch;
    int co,choice,count,flag=1;
    string sqlstmt1;
    cout <<FORMAT<<"\t\t\t******************** Update Customer Details ********************"<<FORMAT1<<endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;
repeatif:
    cout<<endl<<setw(34)<<FORMAT3<<"Enter The Customer Id To Update    :   "<<FORMAT1;
    customerObject.customerId=val.getIntegerValue();
    if(!activeCustId(customerObject.customerId))
    {
	return;
    }

    stmt = conn->createStatement();
    sqlstmt1 = "select count(*) from customer where cust_id=:1";
    stmt->setSQL(sqlstmt1);
    stmt->setInt(1,customerObject.customerId);
    rs = stmt->executeQuery();
    rs->next();
    co=rs->getInt(1);
    //check whether the customer id exist or not
    if(co==1)
    {
	//Display choices to update
	do
	{
	    system("clear");
	    header();

	    cout<<setw(40)<<FORMAT<<"\033[4;31mSelect the Details to be Updated\033[0m"<<FORMAT1<<endl;
	    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;

	    cout<<endl<<setw(42)<<FORMAT3<<"1. Name                    "<<FORMAT1<<endl;
	    cout<<endl<<setw(42)<<FORMAT3<<"2. Address                 "<<FORMAT1<<endl;
	    cout<<endl<<setw(42)<<FORMAT3<<"3. Age                     "<<FORMAT1<<endl;
	    cout<<endl<<setw(42)<<FORMAT3<<"4. Voter Id                    "<<FORMAT1<<endl;
	    cout<<endl<<setw(42)<<FORMAT3<<"5. Pan Card Id                    "<<FORMAT1<<endl;
	    cout<<endl<<setw(42)<<FORMAT3<<"6. Phone Number                     "<<FORMAT1<<endl;
	    cout<<endl<<setw(40)<<FORMAT<<"Enter Your Choice"<<FORMAT1<<FORMAT2<<"[1-6]  :   "<<FORMAT1;
	    choice=checkInteger();
	    switch(choice)
	    {
		case 1:

		    //check whether the bname is valid or not and continue until the valid name is enter
		    flag=1;
		    while(flag)
		    {
			cout<<endl<<setw(34)<<FORMAT3<<"Customer Name"FORMAT1<<FORMAT2<<"*"<<FORMAT1<<FORMAT3<<"                   :   "<<FORMAT1;
			cin.ignore();

			while((getline(cin,customerObject.customerName)))
			{

			    int flag=1;
			    int Len=0;
			    if(customerObject.customerName.empty())
				flag=0;
			    Len = customerObject.customerName.length();
			    for(unsigned int i = 0; i < Len; i++)
			    {

				if(isdigit(customerObject.customerName[i]))
				    flag=0;



			    }
			    if(flag==0)
			    {

				cin.clear();

				cout<<endl<<setw(34)<<FORMAT2<<"Please enter a valid name must be alphabet :   "<<FORMAT;

			    }
			    else
			    {
				break;
			    }
			}
			stmt = conn->createStatement();
			sqlstmt1 = "update customer set cust_name=:1 where cust_id= :2";
			stmt->setSQL(sqlstmt1);
			stmt->setString(1,customerObject.customerName);
			stmt->setInt(2,customerObject.customerId);
			count = stmt->executeUpdate();
			//check whether the query is executed or not
			if(count==1)
			{


			    cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Name Updated\033[0m"<<endl;
			    stmt = conn->createStatement();
			    sqlstmt1 = "select cust_id,cust_name from customer where cust_id=:1";
			    stmt->setSQL(sqlstmt1);
			    stmt->setInt(1,customerObject.customerId);
			    rs = stmt->executeQuery();
			    rs->next();
			    customerObject.customerId  = rs->getInt(1);
			    customerObject.customerName = rs->getString(2);
			    cout<<endl<<endl<<GREEN<<"\t\t\t\t\tCustomer Id   : "<<customerObject.customerId<<endl<<END;
			    cout<<GREEN<<"\t\t\t\t\tCustomer Name : "<<customerObject.customerName<<END<<endl<<endl;
			    flag=0;
			}
			else
			{
			    cout<<endl<<setw(44)<<FORMAT2<<"Customer Name Cannot Be Updated !"<<FORMAT1<<endl;

			    continue;
			}
			conn->commit();
			conn->terminateStatement(stmt);
		    }
		    break;
		case 2:		flag=1;

				while(flag)
				{
				    stmt = conn->createStatement();
				    cout<<endl<<setw(37)<<FORMAT3<<"Customer Address"<<FORMAT<<FORMAT2<<"*"<<FORMAT<<FORMAT3<<"                   :   "<<FORMAT;
				    cin.ignore();
				    getline(cin>>ws,customerObject.customerAddress);

				    sqlstmt1 = "update customer set cust_add=:1 where cust_id=:2";
				    stmt->setSQL(sqlstmt1);
				    stmt->setInt(2,customerObject.customerId);
				    stmt->setString(1,customerObject.customerAddress);
				    count=stmt->executeUpdate();
				    //check query is executed or not
				    if(count==1)
				    {
					cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Address Updated\033[0m"<<endl;

					stmt = conn->createStatement();
					sqlstmt1 = "select cust_id,cust_add from customer where cust_id=:1";
					stmt->setSQL(sqlstmt1);
					stmt->setInt(1,customerObject.customerId);
					rs = stmt->executeQuery();
					rs->next();
					customerObject.customerId  = rs->getInt(1);
					customerObject.customerAddress = rs->getString(2);
					cout<<endl<<endl<<GREEN<<"\t\t\t\t\tCustomer Id      : "<<customerObject.customerId<<endl<<END;
					cout<<GREEN<<"\t\t\t\t\tCustomer Address : "<<customerObject.customerAddress<<END<<endl<<endl;

					flag=0;
				    }


				    else
				    {
					cout<<endl<<setw(44)<<FORMAT2<<"Customer Address Cannot Be Updated !"<<FORMAT1<<endl;

					continue;
				    }
				    conn->commit();
				    conn->terminateStatement(stmt);
				}
				break;

		case 3:
				flag=1;
				//Check whether the age is valid or not and continue till the valid age is enter
				while(flag)
				{

				    stmt = conn->createStatement();
				    cout<<endl<<setw(40)<<FORMAT3<<"Age"<<FORMAT<<FORMAT2<<"*"<<FORMAT<<FORMAT3<<"                    :   "<<FORMAT;


				    customerObject.customerAge=val1.ageValidation();
				    sqlstmt1 = "update  customer set age=:1  where cust_id=:2";
				    stmt->setSQL(sqlstmt1);
				    stmt->setInt(2,customerObject.customerId);
				    stmt->setInt(1,customerObject.customerAge);

				    count=stmt->executeUpdate();
				    //Check query is executed or not
				    if(count==1)
				    {
					cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Age Updated\033[0m"<<endl;
					stmt = conn->createStatement();
					sqlstmt1 = "select cust_id,age from customer where cust_id=:1";
					stmt->setSQL(sqlstmt1);
					stmt->setInt(1,customerObject.customerId);
					rs = stmt->executeQuery();
					rs->next();
					customerObject.customerId  = rs->getInt(1);
					customerObject.customerAge = rs->getInt(2);
					cout<<endl<<endl<<GREEN<<"\t\t\t\t\tCustomer Id  : "<<customerObject.customerId<<endl<<END;
					cout<<GREEN<<"\t\t\t\t\tCustomer Age : "<<customerObject.customerAge<<END<<endl<<endl;


					flag=0;
				    }

				    else
				    {
					cout<<endl<<setw(44)<<FORMAT2<<"Customer Age Cannot Be Updated.Id Not Exist!"<<FORMAT1<<endl;

					continue;
				    }
				    conn->commit();
				    conn->terminateStatement(stmt);
				}
				break;


		case 4:flag=1;
		       //Check the voter id is correct or not and continue till the valid id is enter
		       while(flag)
		       {
			   stmt = conn->createStatement();
			   cout<<endl<<setw(40)<<FORMAT3<<"Customer Voter Id            :   "<<FORMAT;
			   cin.ignore();
			   getline(cin,customerObject.customerVoterId);

			   //Check the voter id cannot be blank
			   if(customerObject.customerVoterId.empty())
			   {
			       cout<<endl<<setw(41)<<FORMAT2<<"Customer Voter Id  Cannot Be Blank         "<<FORMAT<<endl;

			       continue;
			   }
			   else
			   {

			       while(customerObject.customerVoterId.length()!=10)
			       {
				   cout<<endl<<setw(38)<<FORMAT2<<"Length Of Voter Id Should be  10"<<FORMAT<<endl;
				   cout<<endl<<setw(38)<<FORMAT3<<"Enter Customer Voter Id Again    :   "<<FORMAT;

				   getline(cin,customerObject.customerVoterId);
			       }
			   }

			   sqlstmt1 = "update  customer set cust_voterid=:1  where cust_id=:2";
			   stmt->setSQL(sqlstmt1);
			   stmt->setInt(2,customerObject.customerId);
			   stmt->setString(1,customerObject.customerVoterId);
			   count=stmt->executeUpdate();
			   //Check query is executed or not
			   if(count==1)
			   {
			       cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Voter Id Updated\033[0m"<<endl;
			       stmt = conn->createStatement();
			       sqlstmt1 = "select cust_id,cust_voterid  from customer where cust_id=:1";
			       stmt->setSQL(sqlstmt1);
			       stmt->setInt(1,customerObject.customerId);
			       rs = stmt->executeQuery();
			       rs->next();
			       customerObject.customerId  = rs->getInt(1);
			       customerObject.customerVoterId = rs->getString(2);
			       cout<<endl<<endl<<GREEN<<"\t\t\t\t\tCustomer Id       : "<<customerObject.customerId<<endl<<END;
			       cout<<GREEN<<"\t\t\t\t\tCustomer Voter Id : "<<customerObject.customerVoterId<<END<<endl<<endl;


			       flag=0;

			   }
			   else
			   {
			       cout<<endl<<setw(43)<<FORMAT2<<"Customer Voter Id Cannot Be Updated !"<<FORMAT1<<endl;

			       continue;
			   }
			   conn->commit();
			   conn->terminateStatement(stmt);
		       }
		       break;

		case 5:
		       flag=1;
		       //Check whether pan card id is valid or not and continue till the correct id is enter
		       while(flag)
		       {
			   stmt = conn->createStatement();
			   cout<<endl<<setw(40)<<FORMAT3<<"Customer Pan Card Id        :   "<<FORMAT;
			   cin.ignore();

			   getline(cin,customerObject.customerPanCardId);
			   //Pan card id cannot be left blank
			   if(customerObject.customerPanCardId.empty()==1)
			   {
			       cout<<endl<<setw(40)<<FORMAT2<<"Customer Pan Card Id  Cannot Be Blank"<<FORMAT<<endl;

			       continue;
			   }
			   else
			   {
			       while(customerObject.customerPanCardId.length()!=10)
			       {
				   cout<<endl<<setw(38)<<FORMAT2<<"Length of Pan Card Id Should be 10"<<FORMAT<<endl;
				   cout<<endl<<setw(38)<<FORMAT3<<"Enter Customer Pan Card Id Again     :   "<<FORMAT;

				   getline(cin,customerObject.customerPanCardId);
			       }
			   }
			   sqlstmt1 = "update  customer set cust_pancardid=:1  where cust_id=:2";
			   stmt->setSQL(sqlstmt1);
			   stmt->setInt(2,customerObject.customerId);
			   stmt->setString(1,customerObject.customerPanCardId);
			   count=stmt->executeUpdate();
			   //Check query is executed or not
			   if(count==1)
			   {
			       cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Pan Card Id Updated\033[0m"<<endl;

			       stmt = conn->createStatement();
			       sqlstmt1 = "select cust_id,cust_pancardid from customer where cust_id=:1";
			       stmt->setSQL(sqlstmt1);
			       stmt->setInt(1,customerObject.customerId);
			       rs = stmt->executeQuery();
			       rs->next();
			       customerObject.customerId  = rs->getInt(1);
			       customerObject.customerPanCardId = rs->getString(2);
			       cout<<endl<<endl<<GREEN<<"\t\t\t\t\tCustomer Id          : "<<customerObject.customerId<<endl<<END;
			       cout<<GREEN<<"\t\t\t\t\tCustomer Pan Card Id : "<<customerObject.customerPanCardId<<END<<endl<<endl;

			       flag=0;
			   }
			   else
			   {
			       cout<<endl<<setw(44)<<FORMAT2<<"Customer Pan Card Id Cannot Be Updated !"<<FORMAT1<<endl;

			       continue;
			   }
			   conn->commit();
			   conn->terminateStatement(stmt);
		       }
		       break;


		case 6:
		       flag=1;
		       //Check phone number is valid or not
		       while(flag)
		       {
			   stmt = conn->createStatement();
			   cout<<endl<<setw(37)<<FORMAT3<<"Customer Phone Number"<<FORMAT<<FORMAT2<<"*"<<FORMAT<<FORMAT3<<"     :   "<<FORMAT;

			   customerObject.customerPhoneNumber=val1.isValidMobileNumber();


			   sqlstmt1 = "update  customer set cust_mobnumber=:1  where cust_id=:2";
			   stmt->setSQL(sqlstmt1);
			   stmt->setInt(2,customerObject.customerId);
			   stmt->setString(1,customerObject.customerPhoneNumber);
			   count=stmt->executeUpdate();
			   //Check query is executed or not
			   if(count==1)
			   {
			       cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Number Updated\033[0m"<<endl;
			       stmt = conn->createStatement();
			       sqlstmt1 = "select cust_id,cust_mobnumber from customer where cust_id=:1";
			       stmt->setSQL(sqlstmt1);
			       stmt->setInt(1,customerObject.customerId);
			       rs = stmt->executeQuery();
			       rs->next();
			       customerObject.customerId  = rs->getInt(1);
			       customerObject.customerPhoneNumber = rs->getString(2);
			       cout<<endl<<endl<<GREEN<<"\t\t\t\t\tCustomer Id           : "<<customerObject.customerId<<endl<<END;
			       cout<<GREEN<<"\t\t\t\t\tCustomer Phone Number : "<<customerObject.customerPhoneNumber<<END<<endl<<endl;

			       flag=0;
			   }
			   else
			   {
			       cout<<endl<<setw(41)<<FORMAT2<<"Customer Number Cannot Be Updated !"<<FORMAT1<<endl;

			       continue;
			   }
			   conn->commit();
			   conn->terminateStatement(stmt);
		       }
		       break;

		default:
		       cout<<endl<<FORMAT2<<"\t\t\t\t\tInvalid Choice"<<endl<<FORMAT1;
	    }
	    cout<<endl<<setw(34)<<FORMAT2<<"Do you want to update anything else?'y' or 'n':  "<<FORMAT1;
	    ch=val1.getCharacter();
	}while(ch=='y'||ch=='Y');
    }
    else
    {
	cout<<endl<<setw(41)<<RED<<"Id not exist"<<END;
	goto repeatif;
    }
    if(ch=='n'||ch=='N')
	cout<<endl<<setw(48)<<FORMAT3<<"Thank you for updating"<<FORMAT1<<endl;

}
/*This function is used when employee wants to view the details of the 
 * specific customer by entering the id for that customer*/

void Bankemployee::viewCustomerDetails()
{
    Validations val;	
    header();	

    Customer customerObject;
    string sqlstmt1;
    int flag=1;
    cout  <<FORMAT<<"\t\t\t******************** View Customer Details ********************"<<FORMAT1<<endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;

    //if the id does not exist then it will prompt to enter the id again
    while(flag)
    {

	cout<<endl<<setw(39)<<FORMAT3<<"Enter The Customer Id    :   "<<FORMAT1;

	customerObject.customerId=val.getIntegerValue();
	stmt = conn->createStatement();
	sqlstmt1 = "select * from customer where cust_id=:1";
	stmt->setSQL(sqlstmt1);
	stmt->setInt(1,customerObject.customerId);
	rs = stmt->executeQuery();
	if(rs->next())
	{
	    flag=0;
	    cout<<endl<<endl<<endl;
	    customerObject.customerId  = rs->getInt(1);
	    customerObject.customerAge = rs->getInt(2);
	    customerObject.stateOfCustomer  = rs->getInt(3);
	    customerObject.customerName = rs->getString(4);
	    customerObject.customerAddress=rs->getString(5);
	    customerObject.customerPhoneNumber=rs->getString(6);
	    customerObject.customerPanCardId=rs->getString(7);
	    customerObject.customerVoterId=rs->getString(8);
	    cout<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer Id           : "<<customerObject.customerId<<END<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer Name         : "<< customerObject.customerName <<END<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer Age          : "<<customerObject.customerAge <<END<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer State        : "<<customerObject.stateOfCustomer<<END<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer Address      : "<<customerObject.customerAddress<<END<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer Phone Number : "<<customerObject.customerPhoneNumber<<END<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer Voter Id     : "<< customerObject.customerVoterId<<END<<endl;
	    cout<<GREEN<<"\t\t\t\tCustomer Pan Card Id  : "<< customerObject.customerPanCardId<<END<<endl<<endl;
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	}
	else
	{
	    cout<<endl<<setw(34)<<FORMAT2<<"Customer Details Not Available.Id does not Exist!"<<FORMAT1<<endl;

	    continue;
	}

    }
}
/*This function is used to deactivate the customer when
 * ever the employee found something wrong with the customer account
 * or in any other emergency condition*/
void Bankemployee::deactivateCustomer()
{
    header();
    Customer customerObject;
    string sqlstmt1,sqlstmt2;
    int count,flag=1;
    cout <<FORMAT<<"\t\t\t******************** Deactivate Customer ********************"<<FORMAT1<<endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;
    //If customer id does not exist then it will prompt to enter the id again
    while(flag)
    {
	cout<<endl<<setw(34)<<FORMAT3<<"Enter The Customer Id To Be Dectivated    :   "<<FORMAT1;
	customerObject.customerId=checkInteger();
	stmt=conn->createStatement();
	sqlstmt2="select state from customer where cust_id=:1";
	stmt->setSQL(sqlstmt2);
	stmt->setInt(1,customerObject.customerId);
	rs=stmt->executeQuery();
	rs->next();
	if(rs->getInt(1)==0)
	{
	    cout<<endl<<"\033[3;31m\t\t\t\t\tCustomer Already Deactivated\033[0m"<<endl;
	    stmt->closeResultSet(rs);
	    flag=0;
	}
	else
	{
	    stmt->closeResultSet(rs);

	    sqlstmt1="update customer set state=0 where cust_id=:1";
	    stmt->setSQL(sqlstmt1);
	    stmt->setInt(1,customerObject.customerId);
	    count=stmt->executeUpdate();
	    //check whether the query is executed or not
	    if(count==1)
	    {
		cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Deactivated\033[0m"<<endl;
		sqlstmt1="select * from customer where cust_id=:1";
		stmt->setSQL(sqlstmt1);
		stmt->setInt(1,customerObject.customerId);
		rs = stmt->executeQuery();
		rs->next();
		customerObject.customerId  = rs->getInt(1);
		customerObject.customerAge = rs->getInt(2);
		customerObject.stateOfCustomer  = rs->getInt(3);
		customerObject.customerName = rs->getString(4);
		customerObject.customerAddress=rs->getString(5);
		customerObject.customerPhoneNumber=rs->getString(6);
		customerObject.customerPanCardId=rs->getString(7);
		customerObject.customerVoterId=rs->getString(8);
		cout<<endl<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Id           : "<<customerObject.customerId<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Name         : "<< customerObject.customerName <<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Age          : "<<customerObject.customerAge <<END<<endl;
		cout<<"\033[3;31m\t\t\t\tCustomer State        : "<<customerObject.stateOfCustomer<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Address      : "<<customerObject.customerAddress<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Phone Number : "<<customerObject.customerPhoneNumber<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Voter Id     : "<< customerObject.customerVoterId<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Pan Card Id  : "<< customerObject.customerPanCardId<<END<<endl<<endl;

		flag=0;
	    }
	    else
	    {
		cout<<endl<<setw(34)<<FORMAT2<<"Customer Cannot Be Deactivated.Id Not Exist!"<<FORMAT1<<endl;
		continue;
	    }
	}
	conn->commit();
	conn->terminateStatement(stmt);
    }
}
/*This function is used to activate the deactivate customerby entering the id of the
 * customer*/
void Bankemployee::activateCustomer()
{
    header();
    Customer customerObject;
    int count,flag=1;
    string sqlstmt1,sqlstmt2;
    cout  <<FORMAT<<"\t\t\t******************** Activate Customer ********************"<<FORMAT1<<endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;
    //If the customer id does not exist then it will prompt to enter the id again
    while(flag)
    {
	cout<<endl<<setw(34)<<FORMAT3<<"Enter The Customer Id To Be Activated    :   "<<FORMAT;
	customerObject.customerId=checkInteger();
	stmt=conn->createStatement();
	sqlstmt2="select state from customer where cust_id=:1";
	stmt->setSQL(sqlstmt2);
	stmt->setInt(1,customerObject.customerId);
	rs=stmt->executeQuery();
	rs->next();
	if(rs->getInt(1)==1)
	{
	    cout<<endl<<"\033[3;31m\t\t\t\t\tCustomer Already Activated\033[0m"<<endl<<endl;
	    stmt->closeResultSet(rs);
	    flag=0;
	}
	else
	{

	    sqlstmt1="update customer set state=1 where cust_id=:1";
	    stmt->setSQL(sqlstmt1);
	    stmt->setInt(1,customerObject.customerId);
	    count=stmt->executeUpdate();
	    //Check whether the query is executed or not
	    if(count==1)
	    {
		cout<<endl<<"\033[3;32m\t\t\t\t\tCustomer Activated\033[0m"<<endl;
		sqlstmt1="select * from customer where cust_id=:1";
		stmt->setSQL(sqlstmt1);
		stmt->setInt(1,customerObject.customerId);
		rs = stmt->executeQuery();
		rs->next();
		customerObject.customerId  = rs->getInt(1);
		customerObject.customerAge = rs->getInt(2);
		customerObject.stateOfCustomer  = rs->getInt(3);
		customerObject.customerName = rs->getString(4);
		customerObject.customerAddress=rs->getString(5);
		customerObject.customerPhoneNumber=rs->getString(6);
		customerObject.customerPanCardId=rs->getString(7);
		customerObject.customerVoterId=rs->getString(8);
		cout<<endl<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Id           : "<<customerObject.customerId<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Name         : "<< customerObject.customerName <<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Age          : "<<customerObject.customerAge <<END<<endl;
		cout<<"\033[3;31m\t\t\t\tCustomer State        : "<<customerObject.stateOfCustomer<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Address      : "<<customerObject.customerAddress<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Phone NUmber : "<<customerObject.customerPhoneNumber<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Voter Id     : "<< customerObject.customerVoterId<<END<<endl;
		cout<<GREEN<<"\t\t\t\tCustomer Pan Card Id  : "<< customerObject.customerPanCardId<<END<<endl<<endl;

		flag=0;
	    }

	    else
	    {
		cout<<endl<<setw(34)<<FORMAT2<<"Customer Cannot Be Activated.Id Not Exist!"<<FORMAT<<endl;
		continue;
	    }
	}
	conn->commit();
	conn->terminateStatement(stmt);
    }
}
//Check whether the input value is integer or not
int Bankemployee::checkInteger()
{
    int l=1,a;
    int flag=0;
    string value;
    while(l)
    {
	flag=1;
	int len=0;
	cin>>value;
	for (int i=0; value[i]!='\0';i++)
	{
	    len++;
	    if(isdigit(value[i]))
	    {
		flag=1;
	    }
	    else
	    {
		flag=0;
		break;
	    }
	}
	a=atoi(value.c_str());

	if(flag==1) 
	{
	    l=0;
	}
	else
	{
	    cin.clear();
	    cout<<endl<<setw(34)<<FORMAT2<<"Enter Integer Value Only                 :   "<<FORMAT1;
	    cin.get();
	    flag=1;
	    len=0;
	}
    }
    return a;
}


void  Bankemployee::addCustomerAccount()
{
    string acc_type;
    header();
    cout<<"\033[3;30m                       ******************** Add Customer Account ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;
    CustomerAccount obj;
    while(1)
    {
	cout<<endl<<BLUE<<"Enter the Customer Id         : "<<END;
	obj.cust_id=val1.getIntegerValue();
	if(!activeCustId(obj.cust_id))
	{
	    return;
	}

	stmt=conn->createStatement();
	stmt->setSQL("select cust_id from customer where cust_id=:1");
	stmt->setInt(1,obj.cust_id);
	rs=stmt->executeQuery();
	if(rs->next())
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    break;
	}
	else
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    cout<<endl<<RED<<"Customer Id does not exist"<<END<<endl;
	    continue;
	}
    }

    cout<<endl<<BLUE<<"Bank Id                       : "<<END;
    obj.bank_id=workingBankId;
    cout<<obj.bank_id<<endl;
    do
    {
	acc_type="";
	cout<<endl<<BLUE<<"Type of Account(SS/SNS/CA/FD) : "<<END;
	getline(cin>>ws,obj.acc_mod);
	locale loc;
	for (string::size_type i=0; i<obj.acc_mod.length(); ++i)
	    acc_type=acc_type + toupper(obj.acc_mod[i],loc);
	obj.acc_mod=acc_type;
    }while(!(obj.acc_mod=="SS" || obj.acc_mod=="SNS" || obj.acc_mod=="CA" || obj.acc_mod=="FD") ); 

    stmt = conn->createStatement();
    stmt->setSQL("select age  from customer where cust_id=:1");
    stmt->setInt(1,obj.cust_id);
    rs= stmt->executeQuery();
    rs->next();
    obj.age=rs->getInt(1);
    cout<<endl<<BLUE<<"Age                           : "<<END<<obj.age<<endl;
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
    obj.service=0;


    if(obj.acc_mod.compare("SS")==0)
    {
	obj.mini_balance=0;
	obj.rate=0;
	obj.duration=0;
	cout<<endl<<BLUE<<"Balance                       : "<<END;
	obj.balance=val1.getDouble();
    }
    if(obj.acc_mod.compare("SNS")==0)
    {
	obj.mini_balance=0;
	cout<<endl<<BLUE<<"Minimum balance(5000/10000)   : "<<END;
	obj.mini_balance=val1.getIntegerValue();
	while(!((obj.mini_balance==5000) || (obj.mini_balance==10000)))
	{
	    cout<<endl<<RED<<"Minimum balance should be either 5000 or 10000"<<END<<endl;
	    cout<<endl<<BLUE<<"Minimum balance(5000/10000)   : "<<END;
	    obj.mini_balance=val1.getIntegerValue();

	}
	obj.rate=4.5;obj.duration=0;

	obj.balance=0;
	cout<<endl<<BLUE<<"Balance                       : "<<END;
	obj.balance=val1.getDouble();

	while(obj.balance<obj.mini_balance)
	{
	    cout<<endl<<RED<<"Balance should be more than minimum Balance"<<END<<endl;
	    cout<<endl<<BLUE<<"Balance                       : "<<END;

	    obj.balance=val1.getDouble();
	}


    }
    if(obj.acc_mod.compare("CA")==0)
    {
	obj.mini_balance=0;
	obj.rate=0;
	obj.duration=0;
	cout<<endl<<BLUE<<"Initial Deposit               : "<<END;
	obj.balance=val1.getDouble();
	string ch;
	do
	{
	    cout<<endl<<BLUE<<"Service(Y/N)                  : "<<END;
	    getline(cin>>ws,ch);
	    if(ch=="y" || ch=="Y")
		obj.service=1;
	    else if(ch=="n" || ch=="N")
		obj.service=0;
	}while(!(ch=="y" || ch=="Y" || ch=="n" ||  ch=="N"));	
    }
    else
	if(obj.acc_mod.compare("FD")==0)
	{
	    do
	    {
		cout<<endl<<BLUE<<"Duration(1/3/5)               : "<<END;
		obj.duration=val1.getIntegerValue();
	    }while(!(obj.duration==1 ||    obj.duration==3 || obj.duration==5));
	    if(obj.age<60)
	    {
		if(obj.duration==1)
		{
		    obj.rate=7;
		}
		if(obj.duration==3)
		{
		    obj.rate=7.25;
		}
		if(obj.duration==5)
		{
		    obj.rate=7;
		}
	    }
	    if(obj.age>=60)
	    {
		if(obj.duration==1)
		{
		    obj.rate=7.25;
		}
		if(obj.duration==3)
		{
		    obj.rate=7.5;
		}
		if(obj.duration==5)
		{
		    obj.rate=8;
		}
	    }

	    obj. mini_balance=10000;
	    obj.balance=0;
	    cout<<endl<<BLUE<<"Balance                       : "<<END;
	    obj.balance=val1.getDouble();
	    while(obj.balance<obj.mini_balance)
	    {
		cout<<endl<<RED<<"Minimum Balance should be 10000  for FD"<<END<<endl;
		cout<<endl<<BLUE<<"Enter the Balance again       : "<<END;
		obj.balance=val1.getDouble();
	    }
	}



    try
    {

	stmt = conn->createStatement();



	stmt->setSQL("insert into cust_account values(:1,:2,:3,:4,:5,:6,acc_no.nextVal,:7,:8)");

	stmt->setInt(1,obj.cust_id);
	stmt->setInt(2,obj.bank_id);
	stmt->setString(4,obj.acc_mod);
	stmt->setDouble(3,obj.balance);
	stmt->setDouble(5,obj.rate);
	stmt->setInt(6,obj.duration);
	stmt->setInt(7,obj.mini_balance);
	stmt->setInt(8,obj.service);
	int count=stmt->executeUpdate();

	conn->commit();
	stmt->setSQL("select balance from bank where bank_id=:1");
	stmt->setInt(1,obj.bank_id);
	rs=stmt->executeQuery();
	rs->next();
	double balance=rs->getDouble(1);
	balance=balance +obj.balance;
	stmt->closeResultSet(rs);
	stmt->setSQL("update bank set balance=:1 where bank_id=:2");
	stmt->setDouble(1,balance);
	stmt->setInt(2,obj.bank_id);
	stmt->executeUpdate();
	conn->terminateStatement(stmt);

    }catch(SQLException err)
    {
	cout<<err.what();
    }



    stmt=conn->createStatement();
    stmt->setSQL("select acc_no.currVal from dual");
    rs=stmt->executeQuery();
    rs->next();
    cout<<endl<<endl<<GREEN<<"\t\t\t\t\t\tCustomer Id    : "<<END<<obj.cust_id<<endl;
    cout<<GREEN<<"\t\t\t\t\t\tAccount Number : "<<END<<rs->getInt(1)<<endl;
    cout<<GREEN<<"\t\t\t\t\t\tBank Id        : "<<END<<obj.bank_id<<endl;
    cout<<GREEN<<"\t\t\t\t\t\tAccount Type   : "<<END<<obj.acc_mod<<endl;
    cout<<GREEN<<"\t\t\t\t\t\tMinimum balance: "<<END<<obj.mini_balance<<endl;
    cout<<GREEN<<"\t\t\t\t\t\tIntial Deposit : "<<END<<obj.balance<<endl;
    cout<<GREEN<<"\t\t\t\t\t\tRate           : "<<END<<obj.rate<<endl;
    cout<<GREEN<<"\t\t\t\t\t\tService        : "<<END<<obj.service<<endl<<endl;
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
}
void Bankemployee::viewCustomerAccount()
{
    header();
    cout<<"\033[3;30m                       ******************** View Customer Account ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    CustomerAccount obj;
    while(1)
    { 
	cout<<endl<<BLUE<<"Enter Account number  : "<<END;
	obj.acc_no=val1.getIntegerValue();

	stmt = conn->createStatement();
	string h="select * from cust_account where acc_no=:1";
	stmt->setSQL(h);
	stmt->setInt(1,obj.acc_no);
	rs=stmt->executeQuery();
	if(!(rs->next()))
	{

	    cout<<endl<<RED<<"Invalid Account number of customer"<<END<<endl;
	    continue; 
	}
	else
	{
	    obj.cust_id=rs->getInt(1);
	    obj.bank_id=rs->getInt(2);
	    obj.acc_mod=rs->getString(4);
	    obj.balance=rs->getDouble(3);
	    obj.rate=rs->getDouble(5);
	    obj.duration=rs->getInt(6);
	    obj.mini_balance=rs->getInt(8);
	    obj.service=rs->getInt(9);
	    break;
	}
    }
    cout<<endl<<GREEN<<"\t\t\t\t\tCustomer ID     : "<<END<<obj.cust_id;
    cout<<endl<<GREEN<<"\t\t\t\t\tBank ID         : "<<END<<obj.bank_id;
    cout<<endl<<GREEN<<"\t\t\t\t\tAccount Type    : "<<END<<obj.acc_mod;
    cout<<endl<<GREEN<<"\t\t\t\t\tAccount Balance : "<<END<<obj.balance;
    cout<<endl<<GREEN<<"\t\t\t\t\tRate            : "<<END<<obj.rate;
    cout<<endl<<GREEN<<"\t\t\t\t\tDuration        : "<<END<<obj.duration;
    cout<<endl<<GREEN<<"\t\t\t\t\tMinimum Balance : "<<END<<obj.mini_balance;
    cout<<endl<<GREEN<<"\t\t\t\t\tService         : "<<END<<obj.service;
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);


}
void Bankemployee::updateCustomerAccount()
{
    header();
    cout<<"\033[3;30m                       ******************** Update Customer Account ********************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    int count;
    CustomerAccount obj;
    while(1)
    {
	cout<<endl<<BLUE<<"Enter Account Number  :  "<<END;
	obj.acc_no=val1.getIntegerValue();
	if(!activeCheck(obj.acc_no))
	{
	    return;
	}

	stmt=conn->createStatement();
	stmt->setSQL("select acc_no from cust_account where acc_no=:1");
	stmt->setInt(1,obj.acc_no);
	rs= stmt->executeQuery();
	if(rs->next())
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);

	    break;
	}
	else
	{
	    cout<<endl<<RED<<"Enter valid Account Number"<<END<<endl;
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);

	    continue;
	}
    } 
    while(1)
    {
	int n;
	cout<<endl<<"\033[4;31m\t\t\t\t\tSelect to update"<<END<<endl;
	cout<<endl<<BLUE<<"1.Bank Id"<<END<<endl;
	cout<<endl<<BLUE<<"2.Services"<<END<<endl;
	cout<<endl<<"\033[3;30m\t\t\t\t\tEnter your choice"<<"\033[3;31m[1-2] : "<<END;
	n=val1.getIntegerValue();
	cout<<endl;
	if(n==1)
	{
	    while(1)
	    {
		cout<<endl<<BLUE<<"Enter new Bank Id  : "<<END;
		obj.bank_id=val1.getIntegerValue();
		stmt=conn->createStatement();
		stmt->setSQL("select bank_id from bank where bank_id=:1");
		stmt->setInt(1,obj.bank_id);
		rs=stmt->executeQuery();
		if(rs->next())
		{
		    stmt->closeResultSet(rs);
		    conn->terminateStatement(stmt);
		    break;
		}
		else 
		{
		    cout<<endl<<RED<<"Bank Id does not Exist"<<END<<endl;
		    stmt->closeResultSet(rs);
		    conn->terminateStatement(stmt);

		}


	    }
	    stmt=conn->createStatement();
	    string h="update cust_account set bank_id=:1 where acc_no=:2";
	    stmt->setSQL(h);
	    stmt->setInt(1,obj.bank_id);
	    stmt->setInt(2,obj.acc_no);
	    stmt->executeUpdate();
	    conn->commit();
	    conn->terminateStatement(stmt);
	    cout<<endl<<GREEN<<"\t\t\t\t\tBank Id Updated Successfully"<<END<<endl;
	    stmt= conn->createStatement();

	    stmt->setSQL("select * from  cust_account where acc_no=:1");
	    stmt->setInt(1,obj.acc_no);
	    rs=stmt->executeQuery();
	    rs->next();
	    obj.cust_id=rs->getInt(1);
	    obj.bank_id=rs->getInt(2);
	    obj.balance=rs->getDouble(3);
	    obj.acc_mod=rs->getString(4);
	    obj.rate=rs->getDouble(5);
	    obj.duration=rs->getInt(6);
	    obj.acc_no=rs->getInt(7);
	    obj.mini_balance=rs->getDouble(8);
	    obj.service=rs->getInt(9);

	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    cout<<endl<<GREEN<<"\t\t\t\t\tCustomer ID     : "<<END<<obj.cust_id;
	    cout<<endl<<GREEN<<"\t\t\t\t\tBank ID         : "<<END<<obj.bank_id;
	    cout<<endl<<GREEN<<"\t\t\t\t\tAccount Type    : "<<END<<obj.acc_mod;
	    cout<<endl<<GREEN<<"\t\t\t\t\tAccount Balance : "<<END<<obj.balance;
	    cout<<endl<<GREEN<<"\t\t\t\t\tRate            : "<<END<<obj.rate;
	    cout<<endl<<GREEN<<"\t\t\t\t\tDuration        : "<<END<<obj.duration;
	    cout<<endl<<GREEN<<"\t\t\t\t\tAccount Number  : "<<END<<obj.acc_no;
	    cout<<endl<<GREEN<<"\t\t\t\t\tMini Balance    : "<<END<<obj.mini_balance<<END;
	    cout<<endl<<GREEN<<"\t\t\t\t\tService         : "<<END<<obj.service<<END<<endl;

	    break;
	}
	else if(n==2)
	{
	    string ch;
	    do
	    {
		cout<<endl<<BLUE<<"Service(Y/N)             :"<<END;
		getline(cin>>ws,ch);
		if(ch=="y" || ch=="Y")
		    obj.service=1;
		else if(ch=="n" || ch=="N")
		    obj.service=0;
	    }while(!(ch=="y" || ch=="Y" || ch=="n" ||  ch=="N"));	
	    stmt=conn->createStatement();
	    stmt->setSQL("update cust_account set service=:1 where acc_no=:2 and acc_type='CA'");
	    stmt->setInt(1,obj.service);
	    stmt->setInt(2,obj.acc_no);
	    if(stmt->executeUpdate()>0)
	    {
		conn->commit();
		conn->terminateStatement(stmt);
		stmt= conn->createStatement();
		stmt->setSQL("select * from  cust_account where acc_no=:1");
		stmt->setInt(1,obj.acc_no);
		rs=stmt->executeQuery();
		rs->next();
		obj.cust_id=rs->getInt(1);
		obj.bank_id=rs->getInt(2);
		obj.balance=rs->getDouble(3);
		obj.acc_mod=rs->getString(4);
		obj.rate=rs->getDouble(5);
		obj.duration=rs->getInt(6);
		obj.acc_no=rs->getInt(7);
		obj.mini_balance=rs->getDouble(8);
		obj.service=rs->getInt(9);

		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);
		cout<<endl<<GREEN<<"\t\t\t\t\t\tServices Updated  Successfully"<<END<<endl;

		cout<<endl<<GREEN<<"\t\t\t\t\tCustomer ID     : "<<END<<obj.cust_id<<endl;
		cout<<endl<<GREEN<<"\t\t\t\t\tBank ID         : "<<END<<obj.bank_id;
		cout<<endl<<GREEN<<"\t\t\t\t\tAccount Type    : "<<END<<obj.acc_mod;
		cout<<endl<<GREEN<<"\t\t\t\t\tAccount Balance : "<<END<<obj.balance;
		cout<<endl<<GREEN<<"\t\t\t\t\tRate            : "<<END<<obj.rate;
		cout<<endl<<GREEN<<"\t\t\t\t\tDuration        : "<<END<<obj.duration;
		cout<<endl<<GREEN<<"\t\t\t\t\tAccount Number  : "<<END<<obj.acc_no;
		cout<<endl<<GREEN<<"\t\t\t\t\tMini Balance    : "<<END<<obj.mini_balance<<END;
		cout<<endl<<GREEN<<"\t\t\t\t\tService         : "<<END<<obj.service<<END<<endl;
	    }
	    else
	    {
		conn->terminateStatement(stmt);
		cout<<endl<<RED<<"You Cannot Modify SS/SNS/FD Account"<<END<<endl;
		cout<<endl<<RED<<"Services are only available for Customer Account(CA)"<<END<<endl;
	    }

	}
	else
	{
	    cout<<endl<<RED<<"Invalid selection"<<END<<endl;
	}
	break;
    }
}
void Bankemployee::closeCustomerAccount()
{
    header();
    cout<<"\033[3;30m                       ******************** Close Customer Account *******************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl;

    int count;
    CustomerAccount obj;
    cout<<endl<<BLUE<<"Enter Account Number  : "<<END;
    obj.acc_no=val1.getIntegerValue();
    stmt = conn->createStatement();
    string h="delete  from cust_account where acc_no=:1";
    stmt->setSQL(h);
    stmt->setInt(1,obj.acc_no);
    if(stmt->executeUpdate()==0)
    {
	cout<<endl<<RED<<"Invalid Account Number"<<END<<endl<<endl;
    }
    else
    {
	cout<<endl<<GREEN<<"\t\t\t\t\tAccount Closed Successfully"<<END<<endl<<endl;
    }
    conn->commit();
    conn->terminateStatement(stmt);
}
void Bankemployee::deleteCustomer()
{
    Customer customerObject;
    string sqlstmt1;
    int flag=1,count,count1;
    system("clear");
    header();
    cout <<FORMAT<<"\t\t\t******************** Delete Customer ********************"<<FORMAT<<endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;

    //if the id does not exist then it will prompt to enter the id again
    while(flag)
    {

	cout<<endl<<setw(39)<<FORMAT3<<"Enter The Customer Id    :   "<<FORMAT1;

	customerObject.customerId=val1.getIntegerValue();
	stmt = conn->createStatement();
	sqlstmt1 = "select cust_id  from customer where cust_id=:1";
	stmt->setSQL(sqlstmt1);
	stmt->setInt(1,customerObject.customerId);
	rs=stmt->executeQuery();      
	if(rs->next())
	{
	    stmt->closeResultSet(rs);
	    flag=0;
	    sqlstmt1 = "delete  from customer where cust_id=:1";
	    stmt->setSQL(sqlstmt1);
	    stmt->setInt(1,customerObject.customerId);
	    count= stmt->executeUpdate();
	    conn->commit();

	    sqlstmt1 = "delete from cust_account where cust_id=:1";
	    stmt->setSQL(sqlstmt1);
	    stmt->setInt(1,customerObject.customerId);
	    count1= stmt->executeUpdate();
	    conn->commit();
	    conn->terminateStatement(stmt);

	    cout<<endl<<GREEN<<"\t\t\t\t\tCustomer Deleted"<<END<<endl;
	}
	else
	{
	    stmt->closeResultSet(rs);
	    conn->terminateStatement(stmt);
	    cout<<endl<<RED<<"Invalid Customer Id"<<END<<endl;
	    continue;
	}

    }


}


void Bankemployee::respondAtmRequest()
{
    header();
    cout  <<FORMAT<<"                       ******************** ATM Request ********************"<<FORMAT<<endl;
    cout<<"\033[3;36m______________________________________________________________________________________________________\033[0m"<<endl;
    int count,accNumber;
    string sqlstmt1;
    cout<<endl<<FORMAT3<<"\t\t\tEnter the customer Account Number for ATM Request  : "<<END;
    accNumber=val1.getIntegerValue();
    if(!activeCheck(accNumber))
	return;
    else
	cout<<endl<<GREEN<<"\t\t\t\tAccount of customer exists.ATM Request accepted"<<END<<endl;
}
