#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;

    while (true)
    {
        getline(cin, str); // 앤터가 나오기 전 까지 한 줄 입력 
        if (str == "") // 공백이 입력되면 종료 
            break;
        cout << str << endl; // 입력된 한 줄 출력 
    }

    return 0;
}