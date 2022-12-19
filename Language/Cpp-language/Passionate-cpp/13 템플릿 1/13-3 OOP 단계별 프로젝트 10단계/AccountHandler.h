#ifndef __ACCOUN_HANDLER_H__
#define __ACCOUN_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

typedef Account* Account_Ptr;
class AccountHandler {
	BoundCheckArray<Account_Ptr> accArr;
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