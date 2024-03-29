#include <iostream>
#include <string.h>

// 문자열 클래스 만들기 

// 문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성
// 문자열 길이를 구하는 함수
// 문자열 뒤에 다른 문자열 붙이기
// 문자열 내에 포함되어 있는 문자열 구하기
// 문자열이 같은지 비교
// 문자열 크기 비교 (사전 순)

class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length;    // 문자열 길이
	int memory_capacity;  // 현재 할당된 용량
	
public:
	MyString(char c);              // 문자 하나로 생성
	MyString(const char* str);     // 문자열로 부터 생성
	MyString(const MyString& str); // 복사 생성자
	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print() const;
	void println() const;

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	char at(int i) const;

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	
	MyString& erase(int loc, int num);

	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;
}; 

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}

	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}

	// str.string_length + 1 ~ string_length 부분은초기화 시킬 필요 x 
	// 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

	string_length = str.string_length;

	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}

	string_length = str_length;

	return *this;
}

int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		delete[] prev_string_content;
	}
}

char MyString::at(int i) const {
	if (i >= string_length || i < 0) {
		return 0;
	}
	else {
		return string_content[i];
	}
}

MyString& MyString::insert(int loc, const MyString& str) {
	// i 의 위치 바로 앞에 문자를 삽입하게 된다. 
	// ex : abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.
	
	// 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) {
		
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}

		// 그리고 새롭게 insert 되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}

		// 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

	// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
	for (int i = string_length - 1; i >= loc; i--) {
		string_content[i + str.string_length] = string_content[i];
	}

	// 그리고 insert 되는 문자 다시 집어넣기
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];

	string_length = string_length + str.string_length;
	return *this;
}
MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
	// loc 의 앞 부터 시작해서 num 문자를 지운다.
	// ex : abcd 라는 문자열에서 erase(1,2); 를 하게 된다면, bc 가 지워져서 ad 가 리턴 됩니다.
	if (num < 0 || loc<0 || loc>string_length) return *this;

	//지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고 생각하면 됩니다.

	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}

	string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const {
	int i, j;
	if (str.string_length == 0) return - 1;
	for (i = find_from; i <= string_length - str.string_length; i++) { // abcdefg 7 cd 2
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}

		if (j == str.string_length) return i;
	}

	return -1; // 찾지 못했음
}
int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
	// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
	// 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
	// 이 같다는 의미, -1 은 (*this) 가 사전식으로 더 앞에 온다는 의미이다.

	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i])
			return 1;

		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	// 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
	// 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

	if (string_length == str.string_length) return 0;

	// 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
	else if (string_length > str.string_length)
		return 1;

	return -1;
}

int main() {
	MyString str1("abcdef");
	MyString str2("abcde");

	std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}

// 실제로 만든 기능 

// 문자 c 혹은 C 형식 문자열 str 에서 생성할 수 있는 생성자와 복사 생성자
// 문자열의 길이를 리턴하는 함수(length)
// 문자열 대입 함수(assign)
// 문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
// 특정 위치의 문자를 리턴하는 함수(at)
// 특정 위치에 특정 문자열을 삽입하는 함수(insert)
// 특정 위치의 특정 개수의 문자를 지우는 함수(erase)
// 특정 위치를 시작으로 특정 문자열을 검색하는 함수(find)
// 두 문자열을 사전식 비교하는 함수(compare)