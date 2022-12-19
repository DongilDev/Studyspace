// 직접 만든 코드

#include <iostream>

using namespace std;

typedef struct {
	int account_number;
	char name[20];
	int balance;
}Account;

Account arr[100];
int total_num = 0;

void Showmenu();
void Accout_Opening();
void Deposit();
void Withdraw();
void All_account_information();

int main() {
	int input;

	while (1) {
		Showmenu();
		cin >> input;

		switch (input) {
		case 1:
			Accout_Opening();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			All_account_information();
			break;
		case 5:
			cout << "-------프로그램을 종료합니다.-------" << endl;
			return 0;
		}
	}
	return 0;
}

void Showmenu() {
	cout << "-----MENU-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void Accout_Opening() {
	int account_number;
	char name[20];
	int balance;

	cout << "계좌번호 입력: ";
	cin >> account_number;
	cout << "이름: ";
	cin >> name;
	cout << endl;
	
	arr[total_num].account_number = account_number;
	strcpy(arr[total_num].name, name);
	arr[total_num].balance = 0;

	cout << "계좌번호: " << arr[total_num].account_number << endl;
	cout << "이름: " << arr[total_num].name << endl;
	cout << "잔액: " << arr[total_num].balance << endl;

	total_num++;
}

void Deposit() {
	char name[20];
	int money;
	int i;

	cout << "입금하실 계좌의 이름 입력: ";
	cin >> name;

	for (i = 0; i <= total_num; i++) {
		if (strcmp(arr[i].name, name) == -1) {
			cout << "해당하는 계좌가 없습니다 다시 입력하십시오" << endl;
			return Deposit();
		}
		else if (strcmp(arr[i].name, name) == 0)
			break;
	}

	cout << "입금 금액 입력: ";
	cin >> money;
	arr[i].balance += money;

	cout << "계좌에 있는 총 금액: " << arr[i].balance << endl;
}

void Withdraw() {
	char name[20];
	int money;
	int i;

	cout << "출금하실 계좌의 이름 입력: ";
	cin >> name;

	for (i = 0; i <= total_num; i++) {
		if (strcmp(arr[i].name, name) == -1) {
			cout << "해당하는 계좌가 없습니다 다시 입력하십시오" << endl;
			return Withdraw();
		}
		else if (strcmp(arr[i].name, name) == 0)
			break;
	}

	cout << "출금 금액 입력 : ";
	cin >> money;
	arr[i].balance -= money;

	cout << "계좌에 있는 총 금액: " << arr[i].balance << endl;
}

void All_account_information() {
	for (int i = 0; i < total_num; i++) {
		cout << "계좌번호: " << arr[i].account_number << endl;
		cout << "이름: " << arr[i].name << endl;
		cout << "잔액: " << arr[i].balance << endl << endl;
	}
}

// 답안 코드

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);       // 메뉴출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);       // 입    금
void WithdrawMoney(void);      // 출    금
void ShowAllAccInfo(void);     // 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct 
{
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char cusName[NAME_LEN];   // 고객이름
} Account;

Account accArr[100];   // Account 저장을 위한 배열
int accNum=0;        // 저장된 Account 수

int main(void)
{
	int choice;
	
	while(1)
	{
		ShowMenu();
		cout<<"선택: "; 
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
		case MAKE:
			MakeAccount(); 
			break;
		case DEPOSIT:
			DepositMoney(); 
			break;
		case WITHDRAW: 
			WithdrawMoney(); 
			break;
		case INQUIRE:
			ShowAllAccInfo(); 
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입    금"<<endl;
	cout<<"3. 출    금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void MakeAccount(void) 
{
	int id;
	char name[NAME_LEN];
	int balance;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"이  름: ";	cin>>name;
	cout<<"입금액: ";	cin>>balance;
	cout<<endl;
	
	accArr[accNum].accID=id;
	accArr[accNum].balance=balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout<<"[입    금]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"입금액: ";	cin>>money;
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID==id)
		{
			accArr[i].balance+=money;
			cout<<"입금완료"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout<<"[출    금]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"출금액: ";	cin>>money;
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID==id)
		{
			if(accArr[i].balance<money)
			{
				cout<<"잔액부족"<<endl<<endl;
				return;
			}

			accArr[i].balance-=money;
			cout<<"출금완료"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void ShowAllAccInfo(void)	
{
	for(int i=0; i<accNum; i++)
	{
		cout<<"계좌ID: "<<accArr[i].accID<<endl;
		cout<<"이  름: "<<accArr[i].cusName<<endl;
		cout<<"잔  액: "<<accArr[i].balance<<endl<<endl;
	}
}