#include <stdio.h>

int main() {
	char location[50];
	printf("경로를 입력하세요 : ");
	scanf("%s", location);
	printf("\n사용자가 입력한 경로 : %s", location);

	FILE* fp = fopen(location, "w");

	if (fp == NULL) {
		printf("File Error");
	}


	fputs("a", fp);

	fclose(fp);
	return 0;
}