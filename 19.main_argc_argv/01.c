#include <stdio.h>

int charToInt(char* number);
int main(int argc, char** argv) {
	int num1, num2;

	if (argc != 4) {
		printf("받은 인자의 갯수 : %d \n", argc);
		return 0;
	}

	num1 = charToInt(argv[1]);
	num2 = charToInt(argv[3]);

	if (*argv[2] == '+') {
		printf("%d + %d = %d \n", num1, num2, num1 + num2);
	}

	return 0;
}

int charToInt(char* number) {
	int decimation = 1;
	int i = 0;
	int result = 0;

	while (number[i]) i++;

	while (i) {
		i--; /* 현재 number[i]가 NULL을 가리키므로 먼저 한 번 빼준다.*/

		result += (number[i] - 48) * decimation;

		decimation *= 10;
	}

	return result;
}