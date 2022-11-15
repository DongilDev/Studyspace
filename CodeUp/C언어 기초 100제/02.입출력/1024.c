#include <stdio.h>

int main() {
	int i = 0;
	char c[20];
	scanf("%s", c);
	while (c[i]) {
		printf("\'%c\' \n", c[i]);
		i++;
	}

	return 0;
}
