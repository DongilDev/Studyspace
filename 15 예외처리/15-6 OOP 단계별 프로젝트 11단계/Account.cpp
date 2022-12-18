#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int id, int money, String name) // -------- 변경
	:accID(id), balance(money), cusName(name) {}

//------ 복사, 대입, 소멸자 삭제

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
	if (money < 0)
		throw DepositException(money);
	balance += money;
}
int Account::Withdraw(int money) {
	if (balance < money)
		throw WithdrawException(money);

	balance -= money;
	return money;
}
void Account::ShowAccInfo() const {
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
}