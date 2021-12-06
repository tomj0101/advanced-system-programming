#ifndef validation_p
#define validation_p
#include<iostream>
#include<string.h>
#include<climits>
#include<stdlib.h>
#include<sstream>
#include<ctype.h>
using namespace std;

class Validations
{
    string emailAddress,mobileNumber,date1,email,mobile,value,name;
    int flag,result;

    public:
    Validations();
    int getIntegerValue();
    string getStringValue();
    string getDate();
    string getMobile();
    int stringtoint(string);
    int ageValidation();
    string isValidMobileNumber();
    string isValidDate(); 
    int integerValidation();
    string stringValidation();
    char getCharacter();
    int isValidchar();
    double getDouble();
    double toDouble();
    int isValidDouble(); 
};
#endif
