#include <stdio.h>
#include <time.h>

// 10������ ���� �ٸ� ���� (2�� ��)
// ����ڷκ��� 2���� �Է°��� �޾Ƽ� -> ���� ���� ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ� 

int arrayAnimal[4][5]; // ī�� ���� (20���� ī��)
int checkAnimal[4][5]; // ���������� ���� Ȯ�� 

char* strAnimal[10]; // ������ �̸� ĳ���� ��������

//char* cPtr = "�׽�Ʈ"; // �׽�Ʈ��� ������ �ּҸ� ������. ���� ���ٰ���

void initAnimalArray(); // ���� �迭
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition(); // ��ǥ���� �� ���� ã��
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals(); // ���� ��ġ ���
void printQuestion(); // ���� ��� (ī�� ����)

int foundAnimals();

int main(void)
{
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0; //���� Ƚ��

	while (1) // ���� ����
	{
		int select1 = 0; // ����ڰ� ������ ó�� �� 
		int select2 = 0; // ����ڰ� ������ �ι� ° �� 

		printAnimals(); // ���� ��ġ ���
		printQuestion(); // ���� ��� (ī�� ����)
		printf("\n");
		printf("������ ī�� 2���� ���ÿ� : ");
		scanf_s("%d %d", &select1, &select2);
		if (select1 == select2)
		{
			printf("�� �� ���� ����\n");
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ �ƴ��� Ȯ��

		// select �Է��� seq�� ���ϱ� ������ǥ(x,y)�� ��ȯ�ؾ� �Ѵ�. 
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// ������ ī�尡 ������ ī������ && �� ī�尡 ���� �������� Ȯ��
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&& arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])
		{
			printf("\n\n ����! : %s�߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		// �������µ� �ٸ� ������ ���
		else
		{
			printf("\n\n ��! (���� ������ �ƴϰų� �̹� ������ ī���Դϴ�) \n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		// ��� ������ ã�Ҵ��� 1 : ��, 0 : ����
		if (foundAnimals() == 1) // foundAnimals()�� foundAnimals �Լ��� ��ȯ���� �ǹ� 
		{
			printf("\n\n�����մϴ�! ��� ������ �� ã�ҳ׿�\n");
			printf("���ݱ��� �� %d �� �Ǽ��Ͽ����ϴ�.\n", failCount);
			break;
		}

	}

	return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "�䳢";
	strAnimal[1] = "����";
	strAnimal[2] = "�ܽ���";
	strAnimal[3] = "�ٶ���";
	strAnimal[4] = "����";

	strAnimal[5] = "������";
	strAnimal[6] = "�����";
	strAnimal[7] = "�޹���";
	strAnimal[8] = "�з�";
	strAnimal[9] = "������";
}

void shuffleAnimal()
{
	// ������          ������   �������� 2���� �̰�, �ű⿡�ٰ� ������ �̸��� ���� �ִ´�. 
	// ������     ->   ������   �׷��� for�� 2���� ���� 10(��������) , 2(����)�� ���� ���� �Ŵ�.
	// ������          ������
	// ������          ������

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// ��ǥ���� ������� ã�� ���� ��ȯ�ϴ� �Լ� 
int getEmptyPosition()
{
	//                    0 1 2 3 4
	// �� �� �� �� ��         0 �� �� �� �� ��    
	// �� �� �� �� ��     ->  1 �� �� �� �� ��   19�� ° ���ڴ� (3,4)�� �ǹ��Ѵ�. 
	// �� �� �� �� ��         2 �� �� �� �� ��   19 / 5 = 3 �̰� 19 % 5 = 4�� ������ ������ x���� /�� y���� %�� ǥ���ϸ� �ȴ�.
	// �� �� �� �� ��         3 �� �� �� �� ��  

	while (1)
	{
		int randPos = rand() % 20; // 0 ~ 19 ������ ���� ��ȯ -> �迭ĭ�� �� 20����

		// 19 -> (3,4) �� ǥ�� �ؾ��Ѵ�. 
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) // -1�̸� ����ִٴ� ���̴�. 
		{
			return randPos;
			// randPro�� ��ȯ�ϸ� �� ������ x,y ���� ���ϴ� �ڵ尡 �ݺ��Ǵµ� x,y���� ��ȯ�ϸ� ���� �ʴ���?
			// ������, ����ü ���� ����ϸ� �׷��� �ڵ带 ������ �� �ִµ� ���� ����� �ʾƼ� �̷��� ��
		}
	}

	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5;
}

void printAnimals() // ���� ��ġ ���
{
	printf("\n============= ��� ===============\n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n==================================\n\n");
}

void printQuestion() // ���� ��� (ī�� ����)
{
	printf("\n\n ���� \n\n");
	int seq = 0;
	//                   seq ǥ��                                      seq ǥ��         
	// ������          0  1  2  3  4                                  0  1  2  3  4
	// ������     ->   5  6  7  8  9    ���. ��� ����! ����!  ->    �ϸ�  6  7  8  9 
	// ������         10 11 12 13 14                                 10 11 12 �ϸ� 14
	// ������         15 16 17 18 19                                 15 16 17 18 19
	//                                       checkAnimal�� Ȯ�� ( != 0 )
	//                                           0 0 0 0 0
	//                                           1 0 0 0 0
	//                                           0 0 0 1 0
	//                                           0 0 0 0 0

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// ī�带 ����� ������ ���߸� '���� �̸�'�� �������� 
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// ������ ���������� �޸� -> ��ġ�� ��Ÿ���� ���� -> seq 
			else
			{
				printf("%8d", seq);
			}
			seq++;
			// seq�� 0���� ���������� ���� ����� 0���θ� �ȴ�. �׷��� for���� ���������� seq++�� �ؼ� 0 1 2�� ǥ��
			// �Ѵ�. if, else�� �ۿ��� �� ������ �ش� ������ ���� �ɶ��� seq�� ++�ϸ� ������ �߻��ϱ� �����̴�. 

		}
		printf("\n");
	}
}

int foundAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0) // ���� ��ã���� �ϳ��� �ִٸ� 0�� ��ȯ
				return 0;
		}
	}

	return 1; // ��� �� ã��
}