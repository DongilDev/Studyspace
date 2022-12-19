#ifndef __ACCOUN_HANDLER_H__
#define __ACCOUN_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler {
	BoundCheckAccountPtrArray accArr;
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