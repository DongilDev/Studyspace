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
		name = new char[strlen(person_Name)+1];
		strcpy(name, person_Name);

		company_name = new char[strlen(company_Name) + 1];
		strcpy(company_name, company_Name);

		number = new char[strlen(phone_Number) + 1];
		strcpy(number, phone_Number);
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
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::Assist);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	
	return 0;
}