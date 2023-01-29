#pragma once


typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;


// ����Ű Ctrl + '+' + '.'

// �迭 �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

// �迭 �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);

// ������ ���� �Լ�
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));