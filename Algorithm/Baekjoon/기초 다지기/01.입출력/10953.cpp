#include<iostream>

using namespace std;

int main()
{
    int T, A, B;
    cin >> T;
    char c;
    
    for (int i = 0; i < T; i++)
    {
        cin >> A >> c >> B;
        cout << A + B << endl;
    }
}