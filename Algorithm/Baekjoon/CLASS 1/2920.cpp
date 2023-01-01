#include <iostream>

using namespace std;

int main() {
    int arr[8];

    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
 
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if ((arr[i] - arr[i + 1])==1 || (arr[i] - arr[i + 1]) == -1) {
            cnt++;
        }
    }

    if (cnt == 7) {
        if (arr[0] > arr[1])
            cout << "descending";
        else
            cout << "ascending";
    }
    else
        cout << "mixed";

    return 0;
}