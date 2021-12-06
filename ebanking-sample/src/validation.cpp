#include<iomanip>
#include<stdlib.h>
#include"validation.hpp"
#define BLUE "\x1b[34;3m"
#define RESET "\x1b[0m"
#define RED "\x1b[31;3m"
#define GREEN "\x1b[32;3m"
Validations::Validations()
{
    flag=0;
    value=" ";
    name=" ";
    emailAddress=" ";
    email=" ";
    mobileNumber=" ";
    mobile=" ";
    date1=" ";
}



string Validations::isValidMobileNumber()// This function is used for validating the mobile number entered. Example:9876543211 is valid.Digits less than 10 and negative digits are invalid.
{
    int l=1;
    flag=1;int Len,Len1;
    while(l)
    {
	Len=0;
	cin>>mobileNumber;
	Len = mobileNumber.length();
	if(Len!=10)
	    flag=0;
	for(unsigned int i = 0; i < Len; i++)
	{
	    if(!isdigit(mobileNumber[i]))
		flag=0;
	    if(isspace(mobileNumber[i]))
		flag=0;
	}
	if(flag==1)
	{
	    l=0;
	}
	else
	{
	    cin.clear();
	    cout<<endl<<setw(27)<<"\033\t\t\t[3;31mPlease enter a valid mobile number(10 digits)   :        \033[0m";	
	    cin.get();
	    l=1;
	    flag=1;
	}
    }
    return mobileNumber;
}
int Validations::stringtoint(string s)
{
    int temp;
    istringstream buff(s);
    buff >> temp;
    return temp;
}

int Validations::ageValidation()
{
    int l=1,a;
    int flag=0;
    string value;
    while(l)
    {
	flag=1;
	int len=0;
	cin>>value;
	for (int i=1; value[i]!='\0';i++)
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

	if((flag==1) &&(a >10 && a<100 ))
	{
	    l=0;
	}
	else
	{
	    cin.clear();
	    cout<<endl<<"\033[3;31m\t\t\tEnter integer value only between 10 and 100    :        \033[0m";
	    cin.get();
	    flag=1;
	    len=0;
	}
    }
    return a;
}

string Validations::isValidDate() //This function checks for the valid date,month and year.It also checks for leap year and non-leap year.
{
    int i,len,k,day,yy,leap,leap1,l=1,flag=1;
    string d,m,y;
    while(l)
    {
	flag=1;
	cin>>date1;
	for(int i=0;date1[i]!='\0';i++)
	    date1[i]=tolower(date1[i]);
	len=date1.size();
	if(len<12)
	{
	    if(date1[2]=='-'&&date1[6]=='-')
	    {
		d=date1.substr(0,2);
		m=date1.substr(3,3);
		y=date1.substr(7,4);							
		day=stringtoint(d);
		yy=stringtoint(y);
		leap=yy%4;
		leap1=yy%400;
	    }
	    else
	    {
		flag=0;
	    }
	}
	else
	{
	    flag=0;
	}
	if((m=="jan"||m=="mar"||m=="may"||m=="jul"||m=="aug"||m=="oct"||m=="dec")&&day<32)
	{
	}
	else if((m=="apr"||m=="jun"||m=="sep"||m=="nov") && day<31)
	{
	}

	else if((m=="feb" && day<29 &&  leap!=0) || (m=="feb" && day<30 && leap==0 && leap1!=0 ))
	{
	}
	else
	{
	    flag=0;
	}
	if(flag==1)
	{
	    l=0;
	}
	else
	{
	    cin.clear();

	    cout<<"\n"<<RED<<"\t\t\tPlease enter date in DD-MMM-YYYY format : "<<RESET;
	    cin.get();
	    l=1;
	    flag=1;
	}
    }
    return date1;
}


int Validations::integerValidation()
{
    int l=1;
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
	if(flag==1)
	{
	    l=0;
	}
	else
	{
	    cin.clear();
	    cout<<endl<<RED<<"\t\t\tEnter integer value only                          : "<<RESET;
	    cin.get();
	    flag=1;
	    len=0;
	}
    }
    return atoi(value.c_str());
}

char Validations::getCharacter()
{
    string val;
    getline(cin>>ws,value);
    result=isValidchar();
    while(result==1 || result==2 || result==3)
    {
	cout<<endl<<"\033[3;31m\t\t\t\t\tPlease enter (y/n) only  : \033[0m";
	//cout<<setw(i)<<att_name;
	getline(cin>>ws,value);
	result=isValidchar();
    }
    char ch[1];
    value.copy(ch,1);
    return ch[0];
}

int Validations::isValidchar()
{
    if(value.empty())
    {
	return 1;
    }
    if(value.length()>1)
    {
	return 2;
    }
    else if(value.length()==1 && (value=="y" || value=="Y" || value=="N" || value=="n") )
    {
	return 0;
    }
    else
    {
	return 3;
    }
}

string Validations::stringValidation()
    //string Validations::stringValidation(string s)

{
    string s;
    cout<<s;
    int l=1;
    while(l)
    {
	flag=1;
	int len=0;
	getline(cin>>ws,name);
	for (int i=0; name[i]!='\0';i++)
	{
	    //name[i]=tolower(name[i]);
	    len++;
	    if(isalpha(name[i]))
	    {
		flag=1;
	    }
	    else
	    {
		flag=0;
		break;
	    }
	}
	if(flag==1)
	{
	    l=0;
	}
	else
	{
	    cin.clear();
	    cout<<"\n"<<RED<<"\t\t\tEnter alphabetic characters only : "<<RESET;
	    cin.get();
	    flag=1;
	    len=0;
	}
    }
    return name;
}

double Validations::getDouble()
{
    double num;
    getline(cin>>ws,value);
    result=isValidDouble();
    do
    {
	while(result==0 || result==2 || result==3)
	{
	    cout<<endl<<RED<<"\t\t\tEnter valid value                           :     "<<RESET;
	    //<<setw(i)<<att_name;
	    getline(cin,value);
	    result=isValidDouble();
	}
	result=0;
	num=toDouble();
    }while(num==0);
    return(toDouble());
}

int Validations::isValidDouble()
{
    int e=0;
    if(value.empty())
    {
	return 3;
    }
    char a[value.length()];
    value.copy(a,value.length());
    for(int i=0;i<value.length();i++)
    {
	if(a[i]=='.' &&  e==0)
	{
	    e++;
	    continue;
	}
	else if(isdigit(a[i]))
	{
	    continue;
	}
	else if(isalpha(a[i]))
	{
	    return 2;
	}
	else
	{
	    return 0;
	}
    }
    return 1;
}

double Validations::toDouble()
{
    char temp[value.length()];
    value.copy(temp,value.length());
    char *end;
    return(strtod (temp,&end));
}


int Validations::getIntegerValue()
{
    int value=integerValidation();
    return value;
}

string Validations::getStringValue()
{
    string name=stringValidation();
    return name;
}

string Validations::getMobile()
{
    string mobileNumber=isValidMobileNumber();
    return mobileNumber;
}
string Validations::getDate()
{
    cout<<"\n"<<RED<<"\t\t\t\t\t[DD-MON-YYYY] format : "<<RESET;
    string date1=isValidDate();
    return date1;
}
/*char Validations::getCharValue()
  {
  char ch=charValidation();
  return ch;
  } */		
