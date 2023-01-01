#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    string s;

    while (T--) {
        cin >> s;
        cout << s[0] << s[s.length()-1] << endl;
    }

    return 0;
}