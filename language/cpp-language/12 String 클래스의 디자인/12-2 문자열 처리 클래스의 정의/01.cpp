#include <iostream>
#include <cstring>

using namespace std;

class String {
	char* str;
	int len;
public:
	String() {
		len = 0;
		str = NULL;
	}
	String(const char* _str) {  // 생성자 
		len = strlen(_str)+1;
		str = new char[len];
		strcpy(str, _str);
	}
	String(const String& ref) { // 복사 생성자
		len = ref.len;
		str = new char[len];
		strcpy(str, ref.str);
	}
	String& operator=(const String& ref) { // 대입 연산자
		if (str != NULL)
			delete[]str;
		len = ref.len;
		str = new char[len];
		strcpy(str, ref.str);
		return *this;
	}
	String operator+(const String& ref) { // + 연산자
		char* tempstr = new char[len + ref.len - 1];
		strcpy(tempstr, str);
		strcat(tempstr, ref.str);
		
		String temp(tempstr);
		delete[]tempstr;
		return temp;
	}
	String& operator+=(const String& ref) { // += 연산자
		len += (ref.len-1);
		char* tempstr = new char[len];
		strcpy(tempstr, str);
		strcat(tempstr, ref.str);

		if (str != NULL)
			delete[]str;
		str = tempstr;
		return *this;
	}
	bool operator==(const String& ref) { // == 연산자
		return strcmp(str, ref.str) ? false : true;
	}
	friend ostream& operator<<(ostream& os, const String& ref); // << 연산자
	friend istream& operator>>(istream& is, String& ref); // >> 연산자

	~String() {
		if (str != NULL)
			delete[]str;
	}
};
ostream& operator<<(ostream& os, const String& ref) {
	os << ref.str;
	return os;
}
istream& operator>>(istream& is, String& ref) {
	char str[100];
	is >> str;
	ref = String(str);
	return is;
}

int main() {
	String str1 = "i like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;

	cout << str1 << endl;

	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	string str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;

	return 0;
}