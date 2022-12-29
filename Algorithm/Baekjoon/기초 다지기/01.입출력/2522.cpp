#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < 2 * n; i++) {
        for (int j = 1; j <= (i > n ? i - n : n - i); j++)
            cout << " ";
        for (int j = 1; j <= (i > n ? 2 * n - i : i); j++)
            cout << "*";
        cout << endl;
    }
}