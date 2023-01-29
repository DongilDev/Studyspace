#pragma once

#include "value.h"

class CObj
{
protected:
	CObj();
	CObj(const CObj& obj);

public:
	virtual ~CObj() = 0; // 일반함수를 순수가상함수로 만든다면 그 함수는 구현부분을 만들면 안된다.
						 // 소멸자 같은 경우는 순수가상함수로 되더라도 구현부분을 만들어야 한다.
private:
	friend class CObjectManager;

protected:
	string m_strName;
	OBJECT_TYPE m_eType;

public:
	OBJECT_TYPE GetObjectType() const;

public:
	void SetName(char* pName);
	string GetName() const;

public:
	virtual bool Init();
	virtual void Render();
	virtual CObj* Clone() = 0;
	virtual void Save(class CFileStream* pFile);
	virtual void Load(class CFileStream* pFile);
};