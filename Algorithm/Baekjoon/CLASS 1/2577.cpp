#include <iostream>
#include <string>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int arr[10] = {};
    string str;

    str = to_string(A * B * C); // int형을 string 으로 형 변환 시켜줌 
    
    for (int i = 0; i < str.length(); i++) {
        arr[str[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;

    return 0;
}