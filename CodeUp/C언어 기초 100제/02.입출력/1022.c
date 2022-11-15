#include <stdio.h>

int main() {
	char data[2000];
	fgets(data, sizeof(data), stdin);
	printf("%s", data);

	return 0;
}