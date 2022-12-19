#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "AccountException.h"

int main()
{
	AccountHandler manager;
	int choice;

	while (1) {
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			try {
				manager.DepositMoney();
			}
			catch (AccountException& expn) {
				expn.ShowExceptionReason();
			}
			break;
		case WITHDRAW:
			try {
				manager.WithdrawMoney();
			}
			catch (AccountException& expn) {
				expn.ShowExceptionReason();
			}
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "다시 입력해주세요." << endl;
		}
	}

	return 0;
}