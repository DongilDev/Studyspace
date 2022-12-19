#include <stdio.h>

int add_book(char(*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],
    int* borrowed, int* num_total_book); // 책을 추가하는 함수
int search_book(char(*book_name)[30], char(*auth_name)[30],
    char(*publ_name)[30], int num_total_book); // 책을 검색하는 함수 호출 

int compare(char* str1, char* str2); // 문자열 비교 함수 
int borrow_book(int* borrowed); // 책을 빌리는 함수
int return_book(int* borrowed); // 책을 반납하는 함수

    int main() {

    int user_choice; /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */
    char book_name[100][30], auth_name[100][30], publ_name[100][30];  //책, 저자, 출판사를 저장할 배열. 책의 최대 개수는 100 권
    int borrowed[100]; // 빌렸는지 상태를 표시

    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");

        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);

        switch (user_choice) {
        case 1: // 책을 새로 추가하는 함수 호출
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
            break;
        case 2: // 책을 검색하는 함수 호출
            search_book(book_name, auth_name, publ_name, num_total_book);
            break;
        case 3: // 책을 빌리는 함수 호출
            borrow_book(borrowed);
            break;
        case 4: // 책을 반납하는 함수 호출
            return_book(borrowed);
            break;
        case 5: // 프로그램을 종료한다.
            break;
        }
    }

    return 0;
}

int add_book(char(*book_name)[30], char(*auth_name)[30],
    char(*publ_name)[30], int* borrowed, int* num_total_book) {
    printf("추가할 책의 제목 : ");
    scanf("%s", book_name[*num_total_book]);

    printf("추가할 책의 저자 : ");
    scanf("%s", auth_name[*num_total_book]);

    printf("추가할 책의 출판사 : ");
    scanf("%s", publ_name[*num_total_book]);

    borrowed[*num_total_book] = 0; /* 빌려지지 않음*/
    printf("추가 완료! \n");
    (*num_total_book)++;

    return 0;
}

int search_book(char(*book_name)[30], char(*auth_name)[30],
    char(*publ_name)[30], int num_total_book) {
    int user_input; /* 사용자의 입력을 받는다. */
    int i;
    char user_search[30];

    printf("어느 것으로 검색 할 것인가요? \n");
    printf("1. 책 제목 검색 \n");
    printf("2. 지은이 검색 \n");
    printf("3. 출판사 검색 \n");
    scanf("%d", &user_input);

    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);

    printf("검색 결과 \n");

    if (user_input == 1) {
        /*

        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을
        사용자가 입력한 검색어와 비교하고 있다.

        */
        for (i = 0; i < num_total_book; i++) {
            if (compare(book_name[i], user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_name[i], auth_name[i], publ_name[i]);
            }
        }

    }
    else if (user_input == 2) {
        /*

        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을
        사용자가 입력한 검색어와 비교하고 있다.

        */
        for (i = 0; i < num_total_book; i++) {
            if (compare(auth_name[i], user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_name[i], auth_name[i], publ_name[i]);
            }
        }

    }
    else if (user_input == 3) {
        /*

        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를
        사용자가 입력한 검색어와 비교하고 있다.

        */
        for (i = 0; i < num_total_book; i++) {
            if (compare(publ_name[i], user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_name[i], auth_name[i], publ_name[i]);
            }
        }
    }

    return 0;
}

int compare(char* str1, char* str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }

        str1++;
        str2++;
    }

    if (*str2 == '\0') return 1;

    return 0;
}

int borrow_book(int* borrowed) {
    int book_num; // 사용자로 부터 책번호를 받을 변수
     
    printf("빌릴 책의 번호를 말해주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &book_num);

    if (borrowed[book_num] == 1) {
        printf("이미 대출된 책입니다! \n");
    }
    else {
        printf("책이 성공적으로 대출되었습니다. \n");
        borrowed[book_num] = 1;
    }

    return 0;
}

int return_book(int* borrowed) {
    int num_book; // 반납할 책의 번호

    printf("반납할 책의 번호를 써주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &num_book);

    if (borrowed[num_book] == 0) {
        printf("이미 반납되어 있는 상태입니다\n");
    }
    else {
        borrowed[num_book] = 0;
        printf("성공적으로 반납되었습니다\n");
    }

    return 0;
}