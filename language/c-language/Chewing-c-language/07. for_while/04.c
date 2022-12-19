#include <stdio.h>

int main(void)
{
	int f1 = 1, f2 = 1;
	int sum = 0;
	int total = 0;

	while(sum<=1000000)
	{
		if (sum % 2 == 0)
		{
			total += sum;
		}

		sum = f1 + f2;
		f1 = f2;
		f2 = sum;

	}
	printf("1000000 이하의 피보나치 수열중 짝수인 값의 합 : %d \n", total); 

	return 0;
}