#include <stdio.h>

int instr(char* pstr1, char* pstr2);

int main() {
	int pos = -1;
	char str1[100] = { 0, };
	char str2[100] = { 0, };

	printf("첫번째 문자열 : ");
	scanf("%[^\n]s", str1);
	getchar();
	printf("두번째 문자열 : ");
	scanf("%[^\n]s", str2);
	getchar();

	printf("%s\n", str1);
	printf("%s\n", str2);

	if ((pos = instr(str1, str2)) != -1) {
		printf("찾은 위치 : %d\n", pos);
	}
	else {
		printf("못찾았음!\n");
	}
}

int instr(char* pstr1, char* pstr2) {
	int i = 0, j = 0, k = 0, pos = -1;

	while (pstr1[i]) {
		if (pstr2[j] == '\0') break;
		if (pstr1[i] == pstr2[j]) {
			pos = k;
			j++;
		}
		else {
			pos = -1;
			k = (i + 1);
			j = 0;
		}
		i++;
	}

	return pos;
}