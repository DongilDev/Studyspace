#include <iostream>

using namespace std;

class MyFriendInfo {
	char* name;
	int age;
public:
	MyFriendInfo(char* _name, int _age) : age(_age) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~MyFriendInfo() {
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(char* _name, int _age, char* _addr, char* _phone) : MyFriendInfo(_name, _age) {
		addr = new char[strlen(_addr) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(addr, _addr);
		strcpy(phone, _phone);
	}

	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}

	~MyFriendDetailInfo() {
		delete[]addr;
		delete[]phone;
	}
};

int main() {
	MyFriendDetailInfo fnd("동일", 24, "인천", "010-2222-6666");
	fnd.ShowMyFriendDetailInfo();

	return 0;
}