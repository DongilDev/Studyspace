#include "String.h"  // ------------- 소스파일 추가

String::String() { // 생성자
	len = 0;
	str = NULL;
}
String::String(const char* _str) {  // 생성자 
	len = strlen(_str) + 1;
	str = new char[len];
	strcpy(str, _str);
}
String::String(const String& ref) { // 복사 생성자
	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);
}
String& String::operator=(const String& ref) { // 대입 연산자
	if (str != NULL)
		delete[]str;
	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);
	return *this;
}
String String::operator+(const String& ref) { // + 연산자
	char* tempstr = new char[len + ref.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, ref.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}
String& String::operator+=(const String& ref) { // += 연산자
	len += (ref.len - 1);
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, ref.str);

	if (str != NULL)
		delete[]str;
	str = tempstr;
	return *this;
}
bool String::operator==(const String& ref) { // == 연산자
	return strcmp(str, ref.str) ? false : true;
}
String::~String() {
	if (str != NULL)
		delete[]str;
}
ostream& operator<<(ostream& os, const String& ref) { // << 연산자
	os << ref.str;
	return os;
}
istream& operator>>(istream& is, String& ref) { // >> 연산자
	char str[100];
	is >> str;
	ref = String(str);
	return is;
}