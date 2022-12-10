#include <iostream>
#include <cstring>

using namespace std;

class Book {
	char* title; // 책의 제목
	char* isbn; // 국제표준도서번호 
	int price; // 책의 정가
public:
	Book(char* _title, char* _isbn, int _price) : price(_price) {
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];
		strcpy(title, _title);
		strcpy(isbn, _isbn);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book {
	char* DRMKey; // 보안관련 키
public:
	EBook(char* _title, char* _isbn, int _price, char* _DRMKey) : Book(_title, _isbn, _price) {
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy(DRMKey, _DRMKey);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int main() {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}