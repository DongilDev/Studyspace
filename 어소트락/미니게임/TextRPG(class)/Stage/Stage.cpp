#include "Stage.h"
#include "Player.h"
#include "Monster.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

void CStage::OutputStageName(char* pName)
{
	cout << "=============" << pName << "=============";
}

int CStage::OutputMenu()
{
	cout << "1. ����" << endl;
	cout << "2. �ڷΰ���" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iMenu = Input<int>();

	if (iMenu <= MENU_NONE || iMenu > MENU_BACK)
		return MENU_NONE;

	return iMenu;
}

// BATTLE_FLAG enum���� CStage Ŭ���� �ȿ� �ִ� enum���̴�.
// �׷��Ƿ� �տ� CStage:: �� �ٿ��־ Ÿ���� ����ؾ� �Ѵ�.
CStage::BATTLE_FLAG CStage::BattleAttack(CPlayer* pPlayer, CMonster* pMonster)
{
	// �÷��̾��� �������� ���ؿ´�.
	int iDamage = pPlayer->GetDamage() - pMonster->GetArmor();
	iDamage = iDamage < 1 ? 1 : iDamage;

	cout << pPlayer->GetName() << " �� " << pMonster->GetName() << " ���� " <<
		iDamage << " ���ظ� �־����ϴ�." << endl;

	// ��ȯ�� true��� ���Ͱ� �������̴�.
	if (pMonster->Damage(iDamage))
		return BF_MONSTER_DIE;
	
	// ���Ͱ� �÷��̾ �����Ѵ�.
	iDamage = pMonster->GetDamage() - pPlayer->GetArmor();
	iDamage = iDamage < 1 ? 1 : iDamage;

	cout << pMonster->GetName() << " �� " << pPlayer->GetName() << " ���� " <<
		iDamage << " ���ظ� �־����ϴ�." << endl;

	if (pPlayer->Damage(iDamage))
		return BF_PLAYER_DIE;

	return BF_NONE;
}
