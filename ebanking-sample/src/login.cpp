#include"login.hpp"
#include<cstdlib>
#define BLUE1 "\x1b[34;3m"
#define RESET "\x1b[0m"
#define RED1 "\x1b[36;3m"
#define GREEN1 "\x1b[30;3m"
#define MAG "\x1b[22;35m"
#define WHITE "\x1b[32;3m"
#define CYAN "\x1b[36;3m"
#define LRED "\033[01;31m"
#define DARKGREY "\033[03;35m"
#define LBLUE "\033[01;40m"
Login::Login()
{

}

void Login:: show(string st,int space)
{
    system("clear");
    cout<<endl<<endl;
    head();
}

void Login:: head()
{

    cout<<setw(25)<<RED1<<"   ########        ##### ###    ###        ##### #########         #####"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(25)<<WHITE<<"  ####  ####      ###### ###    ###       ###### ###   ####       ######"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(25)<<GREEN1<<"  #####          ####### ###    ###      ####### ###    ###      #######"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(25)<<RED1<<"   #######      #### ### ##########     #### ### ###   ####     #### ###"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(25)<<WHITE<<"      ######   ####  ### ###    ###    ####  ### #########     ####  ###"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(25)<<GREEN1<<"        ####  ####   ### ###    ###   ####   ### ### ####     ####   ###"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(25)<<RED1<<"  ####  #### ########### ###    ###  ########### ###  ####   ###########"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(25)<<WHITE<<"   ######## ####     ### ###    ### ####     ### ###   #### ####     ###"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<endl<<endl<<endl;
    cout<<setw(35)<<GREEN1<<"  ########         ##### ####    ### ###    ###"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(35)<<RED1<<"  ###  ####       ###### #####   ### ###   ###"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(35)<<WHITE<<"  ###  ####      ####### ######  ### ###  ###"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(35)<<GREEN1<<"  #########     #### ### ####### ### #######"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(35)<<RED1<<"  ###  #####   ####  ### ### ####### ########"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(35)<<WHITE<<"  ###    ###  ####   ### ###  ###### ###  ####"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(35)<<GREEN1<<"  ###   #### ########### ###   ##### ###   ####"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<setw(35)<<RED1<<"  ######### ####     ### ###    #### ###    ####"<<RESET<<endl;
    system("sleep 0.1s");

    cout<<endl<<endl<<setw(50)<<"\033[3;31m\t\t\t\t                           --Smart Bank for smart people"<<RESET<<endl;
    system("sleep 0.1s");
    cout<<endl;

    system("read -n1 -r -p \"\033[3;31m\n\n                                            Press any key to continue...\033[0m\"  key");
    /*
       cout<<endl<<"\033[1;47m                                                                                                        Copyright(c)All Rights Reserved by saharabank.com                                                                                                                                                            "<<RESET<<endl;
       */
    system("sleep 0.1s");
    system("sleep 0.1");
    cout<<" .";
    system("sleep 0.1s");
    cout<<" .";
    system("sleep 0.1s");
    cout<<" .";
    system("sleep 0.1s");
    cout<<endl<<RESET;
}

void Login::chooseDesignation()
{
    char ch;
    int choice;
    Validations val;
    show("Welcome",1);
    do
    {
	system("clear");
	cout<<"\x1b[41m                                                                                                       \x1b[0m"<<endl;
	cout<<"\033[3;30m                         *************Welcome to SAHARA BANKING**************\033[0m"<<endl;
	cout<<endl<<"\033[3;30m                           ********CORE BANKING MANAGEMENT SYSTEM*********\033[0m"<<endl;
	cout<<endl<<"\033[3;30m                               *****************************************\033[0m"<<endl;
	cout<<"\x1b[42m                                                                                                       \x1b[0m"<<endl;

	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;


	cout<<"\t\t\t"<<"\033[3;30m  *************** Choose Your Designation ***************\033[0m"<<endl;
	cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"\033[3;34m1.  General  Manager\033[0m"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"\033[3;34m2.  Regional Manager\033[0m"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"\033[3;34m3.  Branch   Manager\033[0m"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"\033[3;34m4.  Employee\033[0m"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"\033[3;34m5.  Exit\033[0m"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"\033[3;30mEnter Your Choice\033[0m"<<"\033[3;31m[1-5] : "<<"\033[0m";

	choice=val.getIntegerValue();


	switch(choice)

	{

	    case 1:

		validateCredentials(1);

		break;

	    case 2: validateCredentials(2);

		    break;

	    case 3: validateCredentials(3);

		    break;

	    case 4: validateCredentials(4);


		    break;

	    case 5:
		    exit(1);
	    default:
		    system("read -n1 -r -p \"\033[3;31m\n\n                                            Invalid Input\n\n\n                                      Press any key to try login again.\033[0m\"  key");  
	}
    }while(1);
}
void Login::validateCredentials(int rank)
{
    Validations val;
    char ch;
    int username;
    string password;
    system("clear");
    cout<<"\x1b[41m                                                                                                       \x1b[0m"<<endl;
    cout<<"\033[3;30m                         *************Welcome to SAHARA BANKING**************\033[0m"<<endl;
    cout<<endl<<"\033[3;30m                           ********CORE BANKING MANAGEMENT SYSTEM*********\033[0m"<<endl;
    cout<<endl<<"\033[3;30m                               *****************************************\033[0m"<<endl;
    cout<<"\x1b[42m                                                                                                       \x1b[0m"<<endl;

    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;

    cout<<"\t\t\t"<<"\033[3;30m************************* Login ***************************\033[0m"<<endl;
    cout<<"\033[3;36m_______________________________________________________________________________________________________\033[0m"<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"\033[3;34m Enter Username : \033[0m";
    username=val.getIntegerValue();
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"\033[3;34m Enter Password : \033[0m";
    cin.ignore();
    password=getPass("Enter Password");
    string sQlstmt;
    int empId;
    Environment *env1;
    Connection *conn1;
    Statement *stt;
    ResultSet *rset;

    env1 = Environment::createEnvironment();
    conn1 = env1->createConnection("e838243","Er.anshu04","ILPChnUnix");

    stt = conn1->createStatement();
    sQlstmt = "select emp_id,password,rank from employeedetails where emp_id = :1";
    stt->setSQL(sQlstmt);
    stt->setInt(1,username);
    rset = stt->executeQuery();
    rset->next();
    empId  = rset->getInt(1);
    empPassword = rset->getString(2);
    empRank=rset->getInt(3);
    stt->closeResultSet(rset);
    conn1->terminateStatement(stt);
    env1->terminateConnection(conn1);
    Environment::terminateEnvironment(env1);

    if(empPassword==password && empRank==rank)
    {   
	if(rank==1)
	{
	    GeneralManager gm(username);
	    gm.startupGeneralManager(1,username);
	}
	if(rank==2)
	{
	    RegionalManager rm(username);
	    rm.startupRegionalManager(2,username);

	} 
	if(rank==3)
	{
	    BranchManager bm(username);
	    bm.startupBranchManager(3,username);
	}
	if(rank==4)
	{
	    Bankemployee be(username);
	    be.startBankEmployee();
	}

    }
    else
    {
	cout<<endl<<"\t\t\t\t\t"<<"\033[3;31mInvalid Login Credentials\033[0m"<<endl;
	cout<<endl<<"\t\t\t\t\t"<<"\033[3;31mDo you want to try again?(y/n)\033[0m";
	ch=val.getCharacter();
	if(ch=='y'||ch=='Y')
	    chooseDesignation();
	else
	    exit(1);
    }	
}

int Login::getch()
{
    int ch;
    struct termios t_old, t_new;
    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;	
}

string Login::getPass(const char *prompt)
{
    const char BACKSPACE=127;
    const char RETURN=10;
    string password;
    unsigned char ch=0;
    bool show_asterisk=true;
    while((ch=getch())!=RETURN)
    {
	if(ch==BACKSPACE)
	{
	    if(password.length()!=0)
	    {
		if(show_asterisk)
		    cout <<"\b \b";
		password.resize(password.length()-1);
	    }
	}
	else
	{
	    password+=ch;
	    if(show_asterisk)
		cout <<'*';
	}
    }
    cout <<endl;
    return password;
}



Login::~Login()
{

}
