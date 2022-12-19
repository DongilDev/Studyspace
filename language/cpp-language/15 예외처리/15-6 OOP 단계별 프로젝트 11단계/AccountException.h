#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class AccountException {
public:
	virtual void ShowExceptionReason() const = 0;
};

class DepositException : public AccountException {
	int reqDep; // 요청 입금액 
public:
	DepositException(int money) : reqDep(money) {}
	void ShowExceptionReason()const {
		cout << "[예외 메시지: " << reqDep << "는 입금 불가]" << endl;
	}
};

class WithdrawException : public AccountException {
	int balance;
public:
	WithdrawException(int money) : balance(money) {}
	void ShowExceptionReason() const {
		cout << "[예외 메시지: 잔액" << balance << ", 잔액부족]" << endl;
	}
};

#endif