#include <stdio.h>

int add_book(struct BOOK* book, int* total_book);
int search_book(struct BOOK* book, int total_book);
int borrow_book(struct BOOK* book);
int return_book(struct BOOK* book);

int compare(char* str1, char* str2);


struct BOOK {
	char book_name[30], auth_name[30], publ_name[30];
	int borrowed;
};

int main(void) {

	struct BOOK book[100];
	int total_book = 0;
	int user_input;

	while (1) {
		printf("도서 관리 프로그램 입니다 \n");
		printf("무엇을 하시겠습니까?  \n\n");
		printf("1. 책 추가하기 \n");
		printf("2. 책 검색하기 \n");
		printf("3. 책 대여하기 \n");
		printf("4. 책 반납하기 \n");
		printf("번호 입력 : ");
		scanf("%d", &user_input);
		printf("\n");

		switch (user_input) {
		case 1: // 책 추가하기
			add_book(book, &total_book);
			break;
		case 2: // 책 검색하기
			search_book(book, total_book);
			break;
		case 3: // 책 대여하기
			borrow_book(book);
			break;
		case 4: // 책 반납하기
			return_book(book);
			break;
		case 5: // 종료
			return 0;
		}
	}

	return 0;
}

int add_book(struct BOOK* book, int* total_book) {
	int user_input;

	if (total_book == 99) {
		printf("더 이상 추가할 공간이 없습니다. \n");
		return 0;
	}

	printf("1. 책 추가하기 \n");
	printf("2. 돌아가기 \n");
	printf("입력 : ");
	scanf("%d", &user_input);
	printf("\n");

	if (user_input == 1) {
		printf("책 이름 입력 : ");
		scanf("%s", book[*total_book].book_name);
		printf("책 저자 입력 : ");
		scanf("%s", book[*total_book].auth_name);
		printf("책 저자 입력 : ");
		scanf("%s", book[*total_book].publ_name);
	}

	if (user_input == 2) {
		return 0;
	}

	book[*total_book].borrowed = 0;
	(*total_book)++;

	return 0;
}

int search_book(struct BOOK* book, int total_book) {
	int user_input;
	char name[30];
	int i;

	printf("어느 것으로 검색 할 것인가요? \n");
	printf("1. 책 제목 검색 \n");
	printf("2. 책 저자 검색 \n");
	printf("3. 책 출판사 검색 \n");
	printf("입력 : ");
	scanf("%d", &user_input);
	printf("\n");

	printf("검색할 단어 입력 : ");
	scanf("%s", name);
	printf("검색 결과 \n\n");

	switch (user_input) {
	case 1:
		for (i = 0; i < total_book; i++) {
			if (compare(book[i].book_name, name)) {
				printf("책 번호 : %d  // 책 이름 : %s // 책 저자 : %s // 책 출판사 : %s \n",
					i, book[i].book_name, book[i].auth_name, book[i].publ_name);
			}
		}
		break;
	case 2:
		for (i = 0; i < total_book; i++) {
			if (compare(book[i].auth_name, name)) {
				printf("책 번호 : %d  // 책 이름 : %s // 책 저자 : %s // 책 출판사 : %s \n",
					i, book[i].book_name, book[i].auth_name, book[i].publ_name);
			}
		}
		break;
	case 3:
		for (i = 0; i < total_book; i++) {
			if (compare(book[i].publ_name, name)) {
				printf("책 번호 : %d  // 책 이름 : %s // 책 저자 : %s // 책 출판사 : %s \n",
					i, book[i].book_name, book[i].auth_name, book[i].publ_name);
			}
		}
		break;
	}

	printf("\n");

	return 0;
}

int compare(char* str1, char* str2) {
	int i = 0, j = 0, length = 0;

	while (str2[length])
		length++;

	while (str1[i]) {
		if (str1[i] != str2[i])
			i++;
		else {
			i++;
			j++;
		}
	}

	if (j == length)
		return 1;

	return 0;
}

int borrow_book(struct BOOK* book) {
	int user_input;

	printf("빌릴 책 번호 입력 : ");
	scanf("%d", &user_input);

	if (book[user_input].borrowed == 1)
		printf("이미 대여된 책 입니다 \n");
	else
	{
		printf("책을 정상적으로 대여 했습니다 \n");
		book[user_input].borrowed = 1;
	}
	printf("\n");

	return 0;
}
int return_book(struct BOOK* book) {
	int user_input;

	printf("반납할 책 번호 입력 : ");
	scanf("%d", &user_input);

	if (book[user_input].borrowed == 0)
		printf("이미 반납한 책 입니다 \n");
	else
	{
		printf("책을 정상적으로 반납 했습니다 \n");
		book[user_input].borrowed = 0;
	}
	printf("\n");

	return 0;
}