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
	Book(Book& ref) : price(ref.price) {
		cout << "Book 복사 생성자 호출" << endl;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}
	Book& operator=(Book& ref) {
		cout << "Book 대입 연산자 호출" << endl;
		delete[]title;
		delete[]isbn;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		cout << "Book 소멸자 호출" << endl;
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book {
	char* DRMKey; // 보안관련 키
public:
	EBook(char* _title, char* _isbn, int _price, char* _DRMKey) : Book(_title, _isbn, _price) {
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy(DRMKey, _DRMKey);
	}
	EBook(EBook& ref) : Book(ref) {
		cout << "EBook 복사 생성자 호출" << endl;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator=(EBook& ref) {
		cout << "EBook 대입 연산자 호출" << endl;
		delete[]DRMKey;
		Book::operator=(ref);
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		cout << "EBook 소멸자 호출" << endl;
		delete[]DRMKey;
	}
};

int main() {
	Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2("1", "1", 1); 
	Book book3 = book1; // Book 복사 생성자 호출
	book2 = book1; // Book 대입 연산자 호출
	
	book1.ShowBookInfo();
	book2.ShowBookInfo();
	book3.ShowBookInfo();

	cout << endl << endl;

	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2("1", "1", 1, "1");
	EBook ebook3 = ebook1; // EBook 복사 생성자 호출
	ebook2 = ebook1; // EBook 대입 연산자 호출

	ebook1.ShowEBookInfo();
	ebook2.ShowEBookInfo();
	ebook3.ShowEBookInfo();

	return 0;
}