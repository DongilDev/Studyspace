#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 10000

int main_file(void)
{
	// ���� ����� 
	// ���Ͽ� � �����͸� ����.
	// ���Ͽ� ����� �����͸� �ҷ����� 

	// fputs, fgets �� > ���ڿ� ���� 
	// char line[MAX]; // char line[10000]

	// ���Ͽ� ���� 
	/*FILE* file = fopen("c:\\test1.txt", "wb"); // r �б����� w �������� a �̾�� t �ؽ�Ʈ b ���̳� ������
	if (file == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}

	fputs("fputs �� �̿��ؼ� ���� ����Կ�\n", file);
	fputs("�� �������� Ȯ�����ּ��� \n", file);*/
	
	// ���� �б�
	/*FILE* file = fopen("c:\\test1.txt", "rb");
	if (file == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}

	while (fgets(line, MAX, file) != NULL)
	{
		printf("%s", line);
	}*/
	// ������ ���� ���� ���� ���� ���¿��� � ���α׷��� ������ �����? 
	// ������ �ս� �߻� ���� ! �׷��� �׻� ������ �ݾ��ִ� ������ �鿩�ּ���
	// fclose(file); 


	
	// fprintf, fscanf �� 
	// printf("%d %d %s ... ") 
	// scanf("%d %d", &num1, ...)
	int num[6] = { 0, 0, 0, 0, 0, 0, }; // �ζ� ��÷��ȣ
	int bonus = 0; // ���ʽ� ��ȣ
	char str1[MAX];
	char str2[MAX];

	//// ���Ͽ� ����
	//FILE* file = fopen("c:\\test2.txt", "wb");
	//if (file == NULL)
	//{
	//	printf("���� ���� ����\n");
	//	return 1;
	//}

	//// �ζ� ��÷ ��ȣ ����
	//fprintf(file, "%s %d %d %d %d %d %d\n", "��÷ ��ȣ", 1, 2, 3, 4, 5, 6);
	//fprintf(file, "%s %d\n", "���ʽ���ȣ", 7);

	// ���� �б�
	FILE* file = fopen("c:\\test2.txt", "rb");
	if (file == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}
	fscanf(file, "%s %d %d %d %d %d %d", str1,
		&num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1,
		num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);

	fclose(file);

	
	return 0;
}