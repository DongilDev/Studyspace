#include <stdio.h>

int add_book(char(*book_name)[30], char(*author_name)[30], char(*publisher_name)[30],
	int* borrowed_book, int* total_book);
int search_book(char(*book_name)[30], char(*author_name)[30], char(*publisher_name)[30], 
	int* borrowed_book, int total_book);

int compare(char* str1, char* str2);

int borrow_book(int* borrowed_book);
int return_book(int* borrowed_book);

int main(void) {

	int user_choice;
	int total_book = 0; 
	char book_name[100][30], author_name[100][30], publisher_name[100][30]; 
	int borrowed_book[100];

	while (1) {

		printf("도서 관리 프로그램 \n");
		printf("1. 책 추가하기 \n");
		printf("2. 책 검색하기 \n");
		printf("3. 책 빌리기 \n");
		printf("4. 책 반납하기 \n");
		printf("5. 종료하기 \n");
		printf("\n");

		printf("당신의 선택 : ");
		scanf("%d", &user_choice);
		printf("\n");

		switch (user_choice) {
		case 1:
			add_book(book_name, author_name, publisher_name, borrowed_book, &total_book);
			break;
		case 2:
			search_book(book_name, author_name, publisher_name, borrowed_book, total_book);
			break;
		case 3:
			borrow_book(borrowed_book);
			break;
		case 4:
			return_book(borrowed_book);
			break;
		case 5:
			return 0;
		}

	}
}

int add_book(char(*book_name)[30], char(*author_name)[30], char(*publisher_name)[30],
	int* borrowed_book, int* total_book) {

	printf("추가할 책의 제목 : ");
	scanf("%s", book_name[*total_book]);

	printf("추가할 책의 저자 : ");
	scanf("%s", author_name[*total_book]);

	printf("추가할 책의 출판사 : ");
	scanf("%s", publisher_name[*total_book]);

	borrowed_book[*total_book] = 0;
	(* total_book)++;

	printf("\n");

	return 0;
}

int search_book(char(*book_name)[30], char(*author_name)[30], char(*publisher_name)[30],
	int* borrowed_book, int total_book) {

	int user_input;
	int i;
	char search[30];

	printf("1. 책 이름 검색 \n");
	printf("2. 책 저자 검색 \n");
	printf("3. 책 풀판사 검색 \n");
	printf("\n");

	printf("당신의 선택 : ");
	scanf("%d", &user_input);

	printf("검색할 내용 입력 : ");
	scanf("%s", search);
	printf("\n");

	switch (user_input) {
	case 1:
		for (i = 0; i < total_book; i++) {
			if (compare(book_name[i], search)) {
				if (borrowed_book[i] == 0)
					printf("책 번호 : %d // 책 이름 : %s // 책 저자 : %s // 책 출판사 : %s \n", i, book_name[i], author_name[i], publisher_name[i]);
				else
					printf("대출됨");
			}
		}
		break;
	case 2:
		for (i = 0; i < total_book; i++) {
			if (compare(author_name[i], search)) {
				if (borrowed_book[i] == 0)
					printf("책 번호 : %d // 책 이름 : %s // 책 저자 : %s // 책 출판사 : %s \n", i, book_name[i], author_name[i], publisher_name[i]);
				else
					printf("대출됨");
			}
		}
		break;
	case 3:
		for (i = 0; i < total_book; i++) {
			if (compare(publisher_name[i], search)) {
				if (borrowed_book[i] == 0)
					printf("책 번호 : %d // 책 이름 : %s // 책 저자 : %s // 책 출판사 : %s \n", i, book_name[i], author_name[i], publisher_name[i]);
				else
					printf("대출됨");
			}
			break;
		}

		printf("\n");

		return 0;
	}
}

int compare(char* str1, char* str2) {
	int i=0, j=0, length = 0;

	while (str2[length])
		length++;

	while (str1[i]) {
		if (str1[i] != str2[j]) {
			i++;
		}
		else {
			i++;
			j++;
		}
	}

	if (j == length) {
		return 1;
	}

	return 0;
}

int borrow_book(int* borrowed_book) {

	int user_input;

	printf("빌릴 책 번호 입력 : ");
	scanf("%d", &user_input);

	if (borrowed_book[user_input] == 1)
		printf("이미 대여된 책 입니다 \n");
	else
	{
		printf("책을 정상적으로 대여 했습니다 \n");
		borrowed_book[user_input] = 1;
	}
	printf("\n");
	
	return 0;
}

int return_book(int* borrowed_book) {

	int user_input;

	printf("반납할 책 번호 입력 : ");
	scanf("%d", &user_input);

	if (borrowed_book[user_input] == 0)
		printf("이미 반납한 책 입니다 \n");
	else
	{
		printf("책을 정상적으로 반납 했습니다 \n");
		borrowed_book[user_input] = 0;
	}
	printf("\n");

	return 0;
}