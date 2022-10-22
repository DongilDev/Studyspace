#include <stdio.h>

int MagicBox(int x)
{
	x += 4;
	return x;
}

int main()
{
	int x;

	printf("마술 상자에 넣을 수를 입력 : ");
	scanf_s("%d", &x);

	printf("마술 상자에서 나온 값 : %d \n", MagicBox(x));

	return 0;
}
