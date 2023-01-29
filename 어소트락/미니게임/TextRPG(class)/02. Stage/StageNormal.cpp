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

	// �÷��̾ ���´�.
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	// ���͸� �����Ѵ�.
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
				cout << pPlayer->GetName() << " �� " << pMonster->GetCharacterInfo().iExp <<
					" ����ġ�� ȹ���Ͽ����ϴ�." << endl;

				int iDropGold;
				iDropGold = pMonster->GetDropGold();
				cout << pPlayer->GetName() << " �� " << iDropGold << " Gold�� ȹ���Ͽ����ϴ�." << endl;

				pPlayer->AddExp(pMonster->GetCharacterInfo().iExp);
				pPlayer->AddGold(iDropGold);

				// ������ ������ �����ߴٸ� true�� ��ȯ�Ѵ�.
				if (pPlayer->CheckLevelUp())
				{
					pPlayer->LevelUp();

					// �ɷ�ġ ���
					pPlayer->AddLevelUpStatus(GET_SINGLE(CCore)->GetLevelUpInfo(pPlayer->GetJob()));
					cout << "Level Up" << endl;
				}

				// ���͸� �����ϰ� �ٽ� �����ؼ� �������ش�.
				SAFE_DELETE(pMonster);
				pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(ST_NORMAL);
				break;
			}
			break;
		case MENU_BACK:
			// �ڷΰ��⸦ �ϱ����� ������ ���͸� �� �̻� ������� �����Ƿ� �����ش�.
			// �Ź� �ʿ� ���ö����� ���� ������ ���ش�.
			SAFE_DELETE(pMonster);
			return;
		}

		system("pause");
	}
}
