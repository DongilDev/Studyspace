#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, Assist, Manager };

	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case Assist:
			cout << "대리" << endl;
			break;
		case Manager:
			cout << "과장" << endl;
			break;
		}
	}
};

class NameCard {
	char* name;
	char* company_name;
	char* number;
	int position;

public:

	NameCard(const char* person_Name, const char* company_Name, const char* phone_Number, const int pos) : position(pos) {
		name = new char[strlen(person_Name) + 1];  // 생성자 
		strcpy(name, person_Name);

		company_name = new char[strlen(company_Name) + 1];
		strcpy(company_name, company_Name);

		number = new char[strlen(phone_Number) + 1];
		strcpy(number, phone_Number);
	}

	NameCard(const NameCard& copy) : position(copy.position) { // 복사 생성자 
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);

		company_name = new char[strlen(copy.company_name) + 1];
		strcpy(company_name, copy.company_name);

		number = new char[strlen(copy.number) + 1];
		strcpy(number, copy.number);
	}

	void ShowNameCardInfo() const {
		cout << "이름: " << name << endl;
		cout << "회사: " << company_name << endl;
		cout << "전화번호: " << number << endl;
		cout << "직급: ";
		COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}

	~NameCard() {
		delete[]name;
		delete[]company_name;
		delete[]number;
	}
};


int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}