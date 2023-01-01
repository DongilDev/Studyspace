#include <iostream>
#include <ctime>
using namespace std;

int main(void) {
    struct tm* t;
    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);

    cout << t->tm_year + 1900 << "-"; // 기본으로 1900년 이후의 년 수 가 나온다.
    cout.width(2);  // 출력 자릿수 설정 
    cout.fill('0'); // 출력 자릿수 확인하고 빈 자리가 있다면 무엇으로 채워 넣을건지 설정
    cout << t->tm_mon + 1 << "-";  // 0 ~ 11 이 기본
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday;

    return 0;
}