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
	int i = 0;
	int result = 0;
	int number_place = 1;

	while (number[i]) i++;

	while (i) {
		i--; 
		result += (number[i] - 48) * number_place;
		number_place *= 10;
	}

	return result;
}