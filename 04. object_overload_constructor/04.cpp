#include <iostream>

class string {
	char* str;
	int len;

public:
	string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
	string(const char* s);
	string(const string& s);
	~string();

	void add_string(const string& s);   // str 뒤에 s 를 붙인다.
	void copy_string(const string& s);  // str 에 s 를 복사한다.
	int strlen();                       // 문자열 길이 리턴	
	void print();
};

string::string(char c, int n) {
	len = n;
	str = new char[len];
	for (int i = 0; i < len; i++) {
		str[i] = c;
	}
	str[len] = NULL;
}
string::string(const char* s) {
	len = 0;
	while (s[len]) {
		len++;
	}
	str = new char[len];
	for (int i = 0; i < len; i++) {
		str[i] = s[i];
	}
}
string::string(const string& s) {
	len = s.len;
	str = new char[len];
	for (int i = 0; i < len; i++) {
		str[i] = s.str[i];
	}
}
string::~string() {
	if (str) {
		delete[] str;
	}
}

void string::add_string(const string& s) {
	char* tmp = new char[len + s.len];
	int i;
	for (i = 0; i < len; i++) tmp[i] = str[i];
	for (int j = 0; i < len + s.len; i++, j++) tmp[i] = s.str[j];
	len += s.len, delete[] str, str = tmp;
}

void string::copy_string(const string& s) {
	len = s.len;
	delete[] str;
	str = new char[len];
	for (int i = 0; i < len; i++) {
		str[i] = s.str[i];
	}
}

int string::strlen() {
	return len;
}
void string::print()
{
	for (int i = 0; i < len; i++) std::cout << str[i];
}


int main() {
	string str1("ABCEDFGHIJKL");
	string str2(str1);
	string add("mnopqrstuvwxyz");
	str1.print(), std::cout << std::endl, str2.print(), std::cout << std::endl;
	add.print(), std::cout << std::endl;
	std::cout << str1.strlen() << ", " << add.strlen() << std::endl;
	str1.add_string(add);
	str2.copy_string(str1);
	str1.print(), std::cout << std::endl, str2.print(), std::cout << std::endl;
	std::cout << str1.strlen() << ", " << str2.strlen() << std::endl;

	return 0;
}