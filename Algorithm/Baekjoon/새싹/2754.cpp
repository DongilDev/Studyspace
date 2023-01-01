#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    switch (s[0]) {
    case 'A':
        if (s[1] == '+') cout << "4.3";
        else if (s[1] == '0') cout << "4.0";
        else cout << "3.7";
        break;
    case 'B':
        if (s[1] == '+') cout << "3.3";
        else if (s[1] == '0') cout << "3.0";
        else cout << "2.7";
        break;
    case 'C':
        if (s[1] == '+') cout << "2.3";
        else if (s[1] == '0') cout << "2.0";
        else cout << "1.7";
        break;
    case 'D':
        if (s[1] == '+') cout << "1.3";
        else if (s[1] == '0') cout << "1.0";
        else cout << "0.7";
        break;
    case 'F':
        cout << "0.0";
        break;
    }

    return 0;
}

// #include <stdio.h>
// int main()
// {
// 	char str[3];
// 	double score = 4.0;
// 	scanf("%s", str);
// 	if (str[0] == 'F')
// 	{
// 		printf("0.0\n");
// 		return 0;
// 	}
// 	score -= str[0] - 'A';
// 	if (str[1] == '+')
// 		score += 0.3;
// 	if (str[1] == '-')
// 		score -= 0.3;
// 	printf("%.1lf", score);
// }