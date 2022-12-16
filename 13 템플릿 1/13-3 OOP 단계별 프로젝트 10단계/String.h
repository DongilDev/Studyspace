#ifndef __STRING_H__  // ------------- 헤더파일 추가 
#define __STRING_H__

#include "BankingCommonDecl.h"

using namespace std;

class String {
	char* str;
	int len;
public:
	String(); // 생성자
	String(const char* _str); // 생성자
	String(const String& ref); // 복사 생성자
	~String(); // 소멸자

	String& operator=(const String& ref); // 대입 연산자
	String operator+(const String& ref); // + 연산자
	String& operator+=(const String& ref); // += 연산자
	bool operator==(const String& ref); // == 연산자

	friend ostream& operator<<(ostream& os, const String& ref); // << 연산자
	friend istream& operator>>(istream& is, String& ref); // >> 연산자
};
#endif;