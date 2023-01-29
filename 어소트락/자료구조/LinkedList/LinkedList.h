#pragma once

typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode;
}tNode;



typedef struct _tagList
{
	tNode* pHeadNode;
	int iCount;
}tLinkedList;


// 연결형 리스트 초기화
void InitList(tLinkedList* _pList);

// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);
void PushFront(tLinkedList* _pList, int _iData);

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _List);