#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"
#include "FileStream.h"

DEFINITION_SINGLE(CObjectManager)

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
	Safe_Delete_Map(m_mapObj);
}

bool CObjectManager::Init()
{
	// �÷��̾ �����Ѵ�.		
	CObj* pPlayer = CreateObject("Player", OT_PLAYER);

	// ���� ��� ������ �о�´�.
	CFileStream file("MonsterList.mtl", "rb");

	if (file.GetOpen())
	{
		int iMonsterCount = 0;

		file.Read(&iMonsterCount, 4);

		for (int i = 0; i < iMonsterCount; ++i)
		{
			CMonster* pMonster = new CMonster;

			pMonster->Load(&file);

			m_mapObj.insert(make_pair(pMonster->GetName(), pMonster));
		}
	}

	else
	{
		// CreateObject �Լ��� ���͸� �����ϰ� CObj* Ÿ���� �����Ѵ�.
		// �׷��� ������ ��� �������� ���� Ŭ������ character Ŭ������ ������ �����Ƿ�
		// ���� Ŭ������ ����ȯ�Ͽ� �����صΰ� ����� ����ϵ��� �Ѵ�.
		CMonster* pMonster = (CMonster*)CreateObject("Goblin", OT_MONSTER);

		pMonster->SetName("���");
		pMonster->SetCharacterInfo(10, 20, 3, 5, 100, 10, 1, 1000);
		pMonster->SetGold(1000, 2000);

		pMonster = (CMonster*)CreateObject("Troll", OT_MONSTER);

		pMonster->SetName("Ʈ��");
		pMonster->SetCharacterInfo(50, 80, 40, 60, 2000, 300, 5, 7000);
		pMonster->SetGold(5000, 10000);

		pMonster = (CMonster*)CreateObject("Dragon", OT_MONSTER);

		pMonster->SetName("�巡��");
		pMonster->SetCharacterInfo(150, 250, 150, 250, 10000, 100000, 10, 25000);
		pMonster->SetGold(30000, 50000);
	}

	return true;
}

CObj* CObjectManager::CreateObject(const string& strKey, OBJECT_TYPE eType)
{
	CObj* pObj = NULL;

	switch (eType)
	{
	case OT_PLAYER:
		pObj = new CPlayer;
		break;
	case OT_MONSTER:
		pObj = new CMonster;
		break;
	}

	if (!pObj->Init())
	{
		SAFE_DELETE(pObj);
		return NULL;
	}

	// ���� key�� value �� �̿��ؼ� �����͸� �����ϱ� ������ 
	// make_pair�� �̿��ؼ� key�� value�� ��� �ʿ� insert �Ѵ�.
	m_mapObj.insert(make_pair(strKey, pObj));

	return pObj;
}

CObj* CObjectManager::FindObject(const string& strKey)
{
	// ���� find �Լ��� �������ش�.
	// find �Լ��� key�� �־��ָ� �ش� Ű�� Ž���Ͽ� ���� ���
	// �ش� Ű�� iterator �� ��ȯ�ϰ� ���� ��� end() �� ��ȯ�Ѵ�.
	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strKey);

	// end() �� ���� ã�� ���ߴٴ� ���̴�.
	if (iter == m_mapObj.end())
		return NULL;

	return iter->second;
}

// ���ڷ� ������ Ű�� �̿��ؼ� ��ü�� ã�� �Ŀ� �ش� ��ü�� �����ؼ� ������ �� ��ȯ���ش�.
CObj* CObjectManager::CloneObject(const string& strKey)
{
	// ������ ������ü�� ã�´�.
	CObj* pOrigin = FindObject(strKey);

	if (!pOrigin)
		return NULL;

	// ���� ã�Ҵٸ� ���� ��ü�� ������ ���ο� ��ü�� ���� ��ȯ�Ѵ�.
	return pOrigin->Clone();
}

CObj* CObjectManager::CloneObject(STAGE_TYPE eType)
{
	vector<CMonster*> vecMonster;

	unordered_map<string, CObj*>::iterator iter;
	
	for (iter = m_mapObj.begin(); iter != m_mapObj.end(); ++iter)
	{
		if (iter->second->GetObjectType() == OT_MONSTER)
		{
			CMonster* pMonster = (CMonster*)iter->second;

			if (pMonster->GetStageType() == eType)
				vecMonster.push_back(pMonster);
		}
	}

	if (vecMonster.empty())
		return NULL;

	int idx = rand() % vecMonster.size();
	return vecMonster[idx]->Clone();
}
