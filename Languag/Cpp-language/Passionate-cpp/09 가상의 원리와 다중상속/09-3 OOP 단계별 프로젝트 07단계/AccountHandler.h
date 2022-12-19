#ifndef __ACCOUN_HANDLER_H__
#define __ACCOUN_HANDLER_H__

#include "Account.h"

class AccountHandler {
	Account* accArr[100];
	int accNum;

public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};
#endif