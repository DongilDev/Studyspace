#include "StageNormal.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"

CStageNormal::CStageNormal()
{
}

CStageNormal::~CStageNormal()
{
}

bool CStageNormal::Init()
{
	return true;
}

void CStageNormal::Run()
{

	// 플레이어를 얻어온다.
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	// 몬스터를 복사한다.
	CMonster* pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(ST_NORMAL);

	while (true)
	{
		system("cls");
		OutputStageName("Normal");
		cout << endl;
		pPlayer->Render();
		cout << endl;
		pMonster->Render();
		cout << endl;

		switch (OutputMenu())
		{
		case MENU_ATTACK:
			switch (BattleAttack(pPlayer, pMonster))
			{
			case BF_PLAYER_DIE:
				pPlayer->DropExp();
				pPlayer->DropGold();
				pPlayer->FullHPMP();
				break;
			case BF_MONSTER_DIE:
				cout << pPlayer->GetName() << " 이 " << pMonster->GetCharacterInfo().iExp <<
					" 경험치를 획득하였습니다." << endl;

				int iDropGold;
				iDropGold = pMonster->GetDropGold();
				cout << pPlayer->GetName() << " 이 " << iDropGold << " Gold를 획득하였습니다." << endl;

				pPlayer->AddExp(pMonster->GetCharacterInfo().iExp);
				pPlayer->AddGold(iDropGold);

				// 레벨업 조건을 만족했다면 true를 반환한다.
				if (pPlayer->CheckLevelUp())
				{
					pPlayer->LevelUp();

					// 능력치 상승
					pPlayer->AddLevelUpStatus(GET_SINGLE(CCore)->GetLevelUpInfo(pPlayer->GetJob()));
					cout << "Level Up" << endl;
				}

				// 몬스터를 삭제하고 다시 복사해서 생성해준다.
				SAFE_DELETE(pMonster);
				pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(ST_NORMAL);
				break;
			}
			break;
		case MENU_BACK:
			// 뒤로가기를 하기전에 생성한 몬스터를 더 이상 사용하지 않으므로 지워준다.
			// 매번 맵에 들어올때마다 새로 생성을 해준다.
			SAFE_DELETE(pMonster);
			return;
		}

		system("pause");
	}
}
