#pragma once

#include "value.h"

class CObjectManager
{
private:
	// map은 기본적으로 key, value로 구성되어 있다.
	// 첫번째 template 타입이 key, 두번째 template 타입이 value이다.
	// 그래서 타입을 2개를 지정해주고 key를 이용해서 탐색을 하게 된다.
	// 실제 값은 value에 지정된 타입의 값을 저장하는 것이다.
	unordered_map<string, class CObj*> m_mapObj;

public:
	bool Init();
	CObj* CreateObject(const string& strKey, OBJECT_TYPE eType);
	CObj* FindObject(const string& strKey);
	CObj* CloneObject(const string& strKey);
	CObj* CloneObject(STAGE_TYPE eType);

	DECLARE_SINGLE(CObjectManager)
};