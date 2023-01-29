#include <iostream>

using namespace std;

#define	NAME_SIZE	32
#define	ITEM_DESC_LENGTH	512
#define	STORE_WEAPON_MAX	3
#define	STORE_ARMOR_MAX		3

enum MAIN_MENU
{
	MM_NONE,
	MM_ADD,
	MM_LOAD,
	MM_SAVE,
	MM_OUTPUT,
	MM_EXIT
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};
enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE	eType;
	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];
};

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

void AddItem(_tagItem* pWeaponStore, _tagItem* pArmorStore)
{
	system("cls");
	int iStore = 0;

	while (true)
	{
		cout << "1. 무기상점 " << endl;
		cout << "2. 방어구상점" << endl;
		cout << "3. 취소 " << endl;		
		cout << "추가할 상점을 선택하세요 : ";
		iStore = InputInt();

		if (iStore == 3)
			return;

		else if (iStore < 1 || iStore > 3)
			continue;
		break;
	}

	int iItemLevel = 0;
	while (true)
	{
		system("cls");
		cout << "1. 초급" << endl;
		cout << "2. 중급" << endl;
		cout << "3. 고급" << endl;
		cout << "4. 취소" << endl;
		cout << "추가할 아이템 난이도를 선택하세요 : ";
		iItemLevel = InputInt();

		if (iItemLevel == 4)
			return;

		else if (iItemLevel < 1 || iItemLevel > 4)
			continue;

		--iItemLevel;
		break;
	}

	cin.clear();
	cin.ignore(1024, '\n');

	_tagItem* pItem = NULL;

	// 인자로 무기상점에서 사용할 아이템 배열과 방어구상점에서 사용할 아이템 배열을 따로 넣어주었다.
	// 아이템을 추가할때에도 추가할 상점을 선택하고 아이템의 난이도를 선택했다.
	// 그러므로 복잡하기 때문에 여기에서 추가할 아이템의 메모리 주소를 얻어와서 추가해주면 쉽게 처리가 가능하다.
	if (iStore == SM_WEAPON)
	{
		pItem = &pWeaponStore[iItemLevel];
		pItem->eType = IT_WEAPON;
		strcpy_s(pItem->strTypeName, "무기");
	}		

	else
	{
		pItem = &pArmorStore[iItemLevel];
		pItem->eType = IT_ARMOR;
		strcpy_s(pItem->strTypeName, "방어구");
	}		

	// 아이템 이름을 입력받는다.
	cout << "이름 : ";
	cin.getline(pItem->strName, NAME_SIZE - 1);

	cout << "아이템 설명 : ";
	cin.getline(pItem->strDesc, ITEM_DESC_LENGTH - 1);

	cout << "최소능력치 : ";
	pItem->iMin = InputInt();

	cout << "최대능력치 : ";
	pItem->iMax = InputInt();

	cout << "Price : ";
	pItem->iPrice = InputInt();

	cout << "Sell : ";
	pItem->iSell = InputInt();

	cout << "아이템 추가 완료" << endl;

	system("pause");
}

bool SaveStore(_tagItem* pWeapon, _tagItem* pArmor)
{
	FILE* pFile = NULL;

	fopen_s(&pFile, "Store.str", "wb");

	if (pFile)
	{
		fwrite(pWeapon, sizeof(_tagItem), STORE_WEAPON_MAX, pFile);
		fwrite(pArmor, sizeof(_tagItem), STORE_ARMOR_MAX, pFile);

		fclose(pFile);
	}

	return false;
}

bool LoadStore(_tagItem* pWeapon, _tagItem* pArmor)
{
	FILE* pFile = NULL;

	fopen_s(&pFile, "Store.str", "rb");

	if (pFile)
	{
		fread(pWeapon, sizeof(_tagItem), STORE_WEAPON_MAX, pFile);
		fread(pArmor, sizeof(_tagItem), STORE_ARMOR_MAX, pFile);
	}

	return false;
}

void Output(_tagItem* pWeapon, _tagItem* pArmor)
{
	system("cls");

	// 판매 목록을 보여준다.
	for (int i = 0; i < STORE_WEAPON_MAX; ++i)
	{
		cout << i + 1 << ". 이름 : " << pWeapon[i].strName <<
			"\t종류 : " << pWeapon[i].strTypeName << endl;
		cout << "공격력 : " << pWeapon[i].iMin << " - " <<
			pWeapon[i].iMax << endl;
		cout << "판매가격 : " << pWeapon[i].iPrice <<
			"\t구매가격 : " << pWeapon[i].iSell << endl;
		cout << "설명 : " << pWeapon[i].strDesc << endl << endl;
	}

	for (int i = 0; i < STORE_ARMOR_MAX; ++i)
	{
		cout << i + 1 << ". 이름 : " << pArmor[i].strName <<
			"\t종류 : " << pArmor[i].strTypeName << endl;
		cout << "공격력 : " << pArmor[i].iMin << " - " <<
			pArmor[i].iMax << endl;
		cout << "판매가격 : " << pArmor[i].iPrice <<
			"\t구매가격 : " << pArmor[i].iSell << endl;
		cout << "설명 : " << pArmor[i].strDesc << endl << endl;
	}

	system("pause");
}

int main()
{
	_tagItem tWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tArmor[STORE_ARMOR_MAX] = {};

	while (true)
	{
		system("cls");
		cout << "1. 아이템 추가" << endl;
		cout << "2. 읽어오기" << endl;
		cout << "3. 저장" << endl;
		cout << "4. 아이템 출력" << endl;
		cout << "5. 게임 종료" << endl;
		cout << "메뉴를 선택하세요 : ";

		int iMenu = InputInt();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_ADD:
			AddItem(tWeapon, tArmor);
			break;
		case MM_LOAD:
			LoadStore(tWeapon, tArmor);
			break;
		case MM_SAVE:
			SaveStore(tWeapon, tArmor);
			break;
		case MM_OUTPUT:
			Output(tWeapon, tArmor);
			break;
		}
	}

	// 자동 저장기능. 저장을 하지 않더라도 프로그램이 종료될때 자동으로 저장
	SaveStore(tWeapon, tArmor);

	return 0;
}