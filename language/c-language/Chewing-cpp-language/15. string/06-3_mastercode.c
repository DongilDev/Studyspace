#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
#define STRLEN 40
#define FINDBOOKNAME	1
#define FINDAUTHOR		2 
#define FINDPUBLISHER	3
#define TRUE	1
#define FALSE	0

void showTitle();
void showMenu();
void showList(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int cnt);
void addBook(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int *cnt);
void delBook(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int *cnt);
void searchBook(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int s_type, int cnt);
void borrow(char *state, int cnt, int is_rent);

int confirm();
void copyArray(char *arr1, char* arr2);
int equalString(char *str1, char *str2);
void lowerCase(char *arr);
int instr(char *pstr1, char *pstr2);

int main(){

int cmd = TRUE;
int cnt = 2;	//총 도서수
int active = 1;
char error[100] = {0,};

char bookname[MAXLEN][STRLEN] = {"씹어먹는 C 언어", "최신낚시입문",};
char author[MAXLEN][STRLEN] = {"Psi", "편집부",};
char publisher[MAXLEN][STRLEN] = {"Psi출판사", "하남출판사",};
char state[MAXLEN] = {0,};

while(active){

system("cls");
showTitle();
showMenu();
scanf("%d", &cmd);
getchar();
system("cls");

switch(cmd){
case 1:
showList(bookname, author, publisher, state, cnt);
printf("\n\n마치시려면 엔터를 눌러주세요\n");
getchar();
break;
case 2:
system("cls");
addBook(bookname, author, publisher, state, &cnt);
break;
case 3:
showList(bookname, author, publisher, state, cnt);
delBook(bookname, author, publisher, state, &cnt);
break;
case 4:
searchBook(bookname, author, publisher, state, FINDBOOKNAME, cnt);
break;
case 5:
searchBook(author, author, publisher, state, FINDAUTHOR, cnt);
break;
case 6:
searchBook(publisher, author, publisher, state, FINDPUBLISHER, cnt);
break;
case 7:
showList(bookname, author, publisher, state, cnt);
borrow(state, cnt, 1);
break;
case 8:
showList(bookname, author, publisher, state, cnt);
borrow(state, cnt, 0);
break;
case 9:
active = FALSE;
break;
}
}
}

//프로그램 제목 출력
void showTitle(){
printf("######################################################################\n");
printf("  도서관리프로그램     \n");
printf("######################################################################\n\n");
}

//메뉴출력
void showMenu(){
printf("----------------------------------------------------------------------\n");
printf("메뉴를 선택하세요 : \n");
printf("----------------------------------------------------------------------\n");
printf("1. 전체목록보기 \n");
printf("2. 도서 추가\n");
printf("3. 도서 삭제\n");
printf("4. 도서명으로 검색\n");
printf("5. 작가명으로 검색\n");
printf("6. 출판사명으로 검색\n");
printf("7. 대출하기\n");
printf("8. 반납하기\n");
printf("9. 종료\n");
printf("----------------------------------------------------------------------\n");
printf(" > ");
}

//전체목록보기
void showList(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int cnt){
int i=0, j=0;

printf("======================================================================\n");
printf(" 전체목록\n");
printf("======================================================================\n");
for(i=0;i<cnt;i++){
printf("[%d] %s (%s, %s)", (i+1), bookname[i], author[i], publisher[i]);
if(state[i] == 1){
printf(" - %s\n", "대출됨");
}else{
printf(" - %s\n", "미대출");
}
}
if(i==0){
printf("입고된 도서가 존재하지 않습니다\n");
}
}

//도서추가
void addBook(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int *cnt){

char _bookname[STRLEN] = {0,};
char _author[STRLEN] = {0,};
char _publisher[STRLEN] = {0,};

printf("======================================================================\n");
printf(" 도서추가\n");
printf("======================================================================\n");
printf("※한글 및 공백문자도 입력이 가능합니다\n");
while(1){
printf("도서명 : ");
scanf("%[^\n]s", _bookname);
getchar();
if(_bookname[0] != '\0') break;
}

while(1){
printf("작가명 : ");
scanf("%[^\n]s", _author);
getchar();
if(_author[0] != '\0') break;
}

while(1){
printf("출판사 : ");
scanf("%[^\n]s", _publisher);
getchar();
if(_publisher[0] != '\0') break;
}

if(confirm()){
copyArray(bookname[*cnt], _bookname);
copyArray(author[*cnt], _author);
copyArray(publisher[*cnt], _publisher);
state[*cnt] = FALSE;
(*cnt)++;
}else{
printf("취소되었습니다\n");
}
}

//도서삭제
void delBook(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int *cnt){
int num = -1;
int i = 0;

while(1){
printf("삭제할 도서의 번호를 입력해 주세요");
printf("번호 : ");
scanf("%d", &num);
getchar();
if(num < 0 || num > *cnt){
printf("범위를 벗어난 입력입니다\n");
continue;
}
break;
}

if(confirm()){
i = num-1;
while(i < *cnt){
copyArray(bookname[i], bookname[i+1]);
copyArray(author[i], author[i+1]);
copyArray(publisher[i], publisher[i+1]);
*(state+i) = *(state+i+1);
i++;
}
(*cnt)--;
}else{
printf("취소되었습니다");
}
}

//검색
void searchBook(char (*bookname)[STRLEN], char (*author)[STRLEN], char (*publisher)[STRLEN], char *state, int s_type, int cnt){

int i=0, j=0;
char words[40] = {0,};
char (*arr)[STRLEN] = {0,};
char *title;

switch(s_type){
case FINDBOOKNAME:
arr = bookname;
title = "도서검색 - 도서명으로 검색";
break;
case FINDAUTHOR:
arr = author;
title = "도서검색 - 작가명으로 검색";
break;
case FINDPUBLISHER:
arr = publisher;
title = "도서검색 - 출판사명으로 검색";
break;
}

printf("======================================================================\n");
printf("  %s\n", title);
printf("======================================================================\n\n");

printf("검색어를 입력해 주세요(대소문자 구분없이 검색 가능)\n");
printf("검색어 : ");
scanf("%39s", words);
printf("\n\n");
getchar();


if(words[0] == '\0') return;

for(i=0;i<cnt;i++){
if(instr(arr[i], words) != -1){
printf("[%d] %s (%s, %s)", (i+1), bookname[i], author[i], publisher[i]);
if(state[i] == 1){
printf(" - %s\n", "대출됨");
}else{
printf(" - %s\n", "미대출");
}
j++;
}
}

printf("\n\n총 검색 결과 : %d건\n", j);
printf("엔터를 누르시면 복귀합니다\n");
getchar();
}

//대출 or 반납
void borrow(char *state, int cnt, int is_rent){
char *title;
int num = -1;

printf("\n\n");

while(1){
if(is_rent==TRUE){
title = "대출할 도서의 번호를 입력해 주세요";
}else{
title = "반납할 도서의 번호를 입력해 주세요";
}

while(1){
printf("%s\n", title);
printf("번호[취소:'0'] : ");
scanf("%d", &num);
getchar();
if(num < 0 || num > cnt){
printf("범위를 벗어난 입력입니다\n");
continue;
}
break;
}

//취소
if(num==0) break;

if(is_rent){
if(state[num-1] == TRUE){
printf("이미 대출중인 도서입니다\n");
continue;
}
state[num-1] = TRUE;
printf("대출이 완료되었습니다");
}else{
if(state[num-1] == FALSE){
printf("대출한적이 없는 도서입니다\n");
continue;
}
state[num-1] = FALSE;
printf("반납이 완료되었습니다");
}
break;
}
}


/*****************************
유틸리티
*****************************/
//확인 취소, 확인은 1 취소는 0 리턴
int confirm(){
char cmd[2] = {0,};
while(1){
printf("확인(s), 취소(c) : ");
scanf("%1s", cmd);
getchar();
lowerCase(cmd);
if(cmd[0] == 's' || cmd[0] == 'c') break;
printf("잘못입력하셨습니다. 다시입력해 주세요\n");
}
if(cmd[0] == 's') return 1;
else return 0;
}

//배열복사
void copyArray(char *arr1, char* arr2){
int i=0;
while((*(arr1+i) = *(arr2+i)) != '\0') i++;
}

//배열같은지 비교, 다르면 0반환 같으면 1반환
int equalString(char *str1, char *str2){
int i=0;
while(*(str1+i) != '\0' || *(str2+i) != '\0'){
if(*(str1+i) != *(str2+i)) return 0;
i++;
}
return 1;
}

//배열내의 문자열 모두 소문자로
void lowerCase(char *arr){
int i=0;
while(*(arr+i) != '\0'){
if(*(arr+i) >= 65 && *(arr+i) <= 90)
*(arr+i) += 32;
i++;
}
}

//문자열 검색, pstr1에서 pstr2를 찾는다, 찾으면 위치 리턴, 못찾으면 -1 리턴
int instr(char *pstr1, char *pstr2){
int i=0,j=0,k=0,pos = -1;
char str1[STRLEN] = {0,};
char str2[STRLEN] = {0,};

copyArray(str1, pstr1);
copyArray(str2, pstr2);
lowerCase(str1);
lowerCase(str2);

while(str1[i]){
if(str2[j]=='\0') break;
if(str1[i] == str2[j]){
pos = k;
j++;
}else{
pos = -1;
k = (i+1);
j=0;
}
i++;
}

return pos;
}