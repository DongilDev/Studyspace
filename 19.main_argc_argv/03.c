#include <stdio.h>

int main(int argc, char** argv) {
	printf("argc : %d\n", argc);


	int i, j = 0;
	int num1 = 0, num2 = 0;
	int temp = -1;
	int flag = 0;


	if (argc == 1) {
		printf("인자가 없습니다\n");
		return 0;
	}

	for (i = 1; i < argc; i++) {

		temp = -1;
		j = 0;
		printf("\n\n인자 %d : %s\n", i, argv[i]);


		while (temp != 0) {
			temp = *(argv[i] + j);

			if (temp == 0) {
				break;
			}

			printf("*(argv[i] + %d) = %d\n", j ,temp );
			printf("ASCII = %c\n", temp);

			if (temp > 47 && temp < 58) {
				if (i == 1) {
					num1 = (10 * num1) + (temp - 48);
				}

				if (i == 3) {
					num2 = (10 * num2) + (temp - 48);
				}
			}
			else if (temp == 42 || temp == 43 || temp == 45 || temp == 47) {
				flag = temp;
			}

			  //42 43 45 47

			j++;


		}

	}

	printf("\nnum1 : %d, num2 : %d", num1, num2);
	if (flag == 42) {
		printf("\n\nANSWER : %d", num1 * num2);
	}
	else if (flag == 43) {
		printf("\n\nANSWER : %d", num1 + num2);
	}
	else if (flag == 45) {
		printf("\n\nANSWER : %d", num1 - num2);
	}
	else if (flag == 47) {
		printf("\n\nANSWER : %d", num1 / num2);
	}
	

}