#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount {
	int specialRate;

public:
	HighCreditAccount(int id, int money, String name, int rate, int special)
		:NormalAccount(id, money, name, rate), specialRate(special)
	{}

	virtual void Deposit(int money) {
		if (money < 0)
			throw DepositException(money);
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}
};
#endif