#include <stdio.h>

int getnum(char* ptr);

int main(int argc, char **argv) {
	int i;
	int num1;
	int num2;
	num1=getnum(argv[1]);
	num2=getnum(argv[3]);
	switch (*argv[2]) {
	case '+':
		printf("%d", num1 + num2);
		break;
	case '-':
		printf("%d", num1 - num2);
		break;
	case '*':
		printf("%d", num1 * num2);
		break;
	case '/':
		printf("%f", (float)num1 / num2);
		break;
	default:
		printf("기대한 입력이 아닙니다. 다시 시도해주세요. \n");
	}
	return 0;
}
int getnum(char* ptr) {
	int num[10] = { 0 };
	int val;
	int i = 0;
	int j;
	int k;
	
	if (48 <= *ptr && *ptr <= 57) {
		while (*ptr) {
			num[i] = (int)*ptr - 48;
			i++;
			ptr++;
		}
		val = num[i-1];
		for (j = i - 2; j>=0 ; j--) {
			for(k=i-1;k>j;k--)
				num[j] *= 10;
			val += num[j];
		}
		
		return val;
	}
	else {
		printf("숫자를 입력하세요. \n");
		return 0;
	}

}