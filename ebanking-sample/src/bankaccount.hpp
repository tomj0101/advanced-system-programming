#ifndef bankaccount_h
#define bankaccount_h
#include<iostream>
#include<string.h>

using namespace std;

class BankAccount
{
  public:
  string timestamp;
  int fromBankId, toBankId;
  double amount;

};
#endif
