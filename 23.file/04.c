#include <stdio.h>

int main(void) {
	char word[100];
	char buffer[100];
	int count = 0;

	printf("탐색할 단어: ");
	scanf("%s", word);

	FILE* fp = fopen("a.txt", "r");

	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return 0;
	}

	/*fgets 는 읽어올 파일을 한줄씩 읽어오기 때문에 while 문을 사용해줍니다
	while 문에서 조건을 탐색할 때 line 변수에 한줄의 값이 들어가게 되고 바로 while문 안의 내용이 출력되게 됩니다.*/
	while (fgets(buffer, 100, fp) != NULL) {
		count++;
		if (strstr(buffer, word) != NULL) {
			printf("%d %s\n", count, buffer);
		}
	}

	fclose(fp);
	return 0;
}