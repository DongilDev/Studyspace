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
	// 플레이어를 생성한다.		
	CObj* pPlayer = CreateObject("Player", OT_PLAYER);

	// 몬스터 목록 파일을 읽어온다.
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
		// CreateObject 함수는 몬스터를 생성하고 CObj* 타입을 리턴한다.
		// 그런데 몬스터의 기반 변수들은 몬스터 클래스나 character 클래스가 가지고 있으므로
		// 몬스터 클래스로 형변환하여 저장해두고 기능을 사용하도록 한다.
		CMonster* pMonster = (CMonster*)CreateObject("Goblin", OT_MONSTER);

		pMonster->SetName("고블린");
		pMonster->SetCharacterInfo(10, 20, 3, 5, 100, 10, 1, 1000);
		pMonster->SetGold(1000, 2000);

		pMonster = (CMonster*)CreateObject("Troll", OT_MONSTER);

		pMonster->SetName("트롤");
		pMonster->SetCharacterInfo(50, 80, 40, 60, 2000, 300, 5, 7000);
		pMonster->SetGold(5000, 10000);

		pMonster = (CMonster*)CreateObject("Dragon", OT_MONSTER);

		pMonster->SetName("드래곤");
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

	// 맵은 key와 value 를 이용해서 데이터를 관리하기 때문에 
	// make_pair를 이용해서 key와 value를 묶어서 맵에 insert 한다.
	m_mapObj.insert(make_pair(strKey, pObj));

	return pObj;
}

CObj* CObjectManager::FindObject(const string& strKey)
{
	// 맵은 find 함수를 제공해준다.
	// find 함수에 key를 넣어주면 해당 키를 탐색하여 있을 경우
	// 해당 키의 iterator 를 반환하고 없을 경우 end() 를 반환한다.
	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strKey);

	// end() 일 경우는 찾지 못했다는 것이다.
	if (iter == m_mapObj.end())
		return NULL;

	return iter->second;
}

// 인자로 들어오는 키를 이용해서 객체를 찾은 후에 해당 객체를 복사해서 생성한 후 반환해준다.
CObj* CObjectManager::CloneObject(const string& strKey)
{
	// 복사할 원본객체를 찾는다.
	CObj* pOrigin = FindObject(strKey);

	if (!pOrigin)
		return NULL;

	// 만약 찾았다면 원본 객체를 복사한 새로운 객체를 만들어서 반환한다.
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
