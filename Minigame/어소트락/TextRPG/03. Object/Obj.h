#pragma once

#include "value.h"

class CObj
{
protected:
	CObj();
	CObj(const CObj& obj);

public:
	virtual ~CObj() = 0; // �Ϲ��Լ��� ���������Լ��� ����ٸ� �� �Լ��� �����κ��� ����� �ȵȴ�.
						 // �Ҹ��� ���� ���� ���������Լ��� �Ǵ��� �����κ��� ������ �Ѵ�.
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