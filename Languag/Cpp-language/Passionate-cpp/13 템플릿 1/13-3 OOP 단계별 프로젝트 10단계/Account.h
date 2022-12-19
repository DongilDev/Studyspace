#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
	int accID;
	int balance;
	String cusName; // ------- 변경

public:
	Account(int id, int money, String name);
	// ------ 복사, 대입, 소멸자 삭제

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
};
#endif