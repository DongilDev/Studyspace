#include <stdio.h>

int slave(int master_money, int today_incom)
{
	master_money += today_incom;
	return master_money;
}

int main(void)
{
	int master_money = 100000;
	int today_incom = 0;

	printf("귀족이 오늘 벌어들인 돈 : ");
	scanf_s("%d", &today_incom);

	printf("귀족의 재산과 당일 수입을 합친 값 : %d", slave(master_money, today_incom));

	return 0;
}