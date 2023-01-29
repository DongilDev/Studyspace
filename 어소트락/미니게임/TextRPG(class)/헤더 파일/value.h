#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <time.h>

using namespace std;

// 사용자정의 헤더
#include "defines.h"
#include "Flags.h"

template <typename T>
T Input()
{
	T data;
	cin >> data;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return 0;
	}

	return data;
}

template <typename T>
void Safe_Delete_VecList(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(*iter);
	}

	p.clear();
}

template <typename T>
void Safe_Delete_Map(T& p)
{
	T::iterator iter;
	T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		// first : key , second : value
		// 즉 모든 노드를 다 지워주는 것
		SAFE_DELETE(iter->second);		                          
	}

	p.clear();
}

typedef struct _tagCharacterInfo
{
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
}CHARACTERINFO, * PCHARACTERINFO;

typedef struct _tagLevelUpInfo
{
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iMP;
}LEVELUPINFO, PLEVELUPINFO;

#define MAX_LEVEL 10
static int g_iLvUpTable[MAX_LEVEL] = { 4000, 7000, 10000, 15000, 20000, 30000, 40000, 50000, 80000, 130000};

// Item Info
typedef struct _tagItemInfo
{
	ITEM_TYPE eType;
	string strTypeName;
	int iPrice;
	int iSell;
	string strDesc;
}ITEMINFO, *PITEMINFO;