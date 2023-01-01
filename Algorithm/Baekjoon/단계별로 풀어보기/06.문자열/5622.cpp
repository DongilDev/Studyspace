#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int time = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= 67 && s[i]>=65)
			time += 2;
		else if (s[i] <= 70 && s[i] >=68)
			time += 3;
		else if (s[i] <= 73 && s[i] >= 71)
			time += 4;
		else if (s[i] <= 76 && s[i] >= 74)
			time += 5;
		else if (s[i] <= 79 && s[i] >= 77)
			time += 6;
		else if (s[i] <= 83 && s[i] >= 80)
			time += 7;
		else if (s[i] <= 86 && s[i] >= 84)
			time += 8;
		else if (s[i] <= 90 && s[i] >= 87)
			time += 9;
	}

	cout << time + s.length();

	return 0;
}


// #include<stdio.h>

// int main() {
// 	int time = 0, cost[26]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
// 	char word[16];
// 	scanf("%s", word);
// 	for (int i = 0; word[i] != NULL; i++) {
// 		time += cost[word[i]-'A'];
// 	}
// 	printf("%d", time);
// }