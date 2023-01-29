#include "Core.h"
#include "EditorCore.h"


enum GAME_MODE
{
	GM_NONE,
	GM_INGAME,
	GM_EDIT,
	GM_EXIT
};

int main()
{	
	srand((unsigned int)time(0));

	int iGameMode = 0;

	while (true)
	{
		system("cls");
		cout << "1. 게임모드" << endl;
		cout << "2. 게임툴" << endl;
		cout << "3. 종료" << endl;
		cout << " 메뉴를 선택하세요 : ";
		iGameMode = Input<int>();

		if (iGameMode <= GM_NONE || iGameMode > GM_EXIT)
			continue;

		else if (iGameMode == GM_EXIT)
			return 0;

		break;
	}

	switch (iGameMode)
	{
	case GM_INGAME:
		if (!GET_SINGLE(CCore)->Init())
		{
			DESTROY_SINGLE(CCore);
			return 0;
		}

		GET_SINGLE(CCore)->Run();

		DESTROY_SINGLE(CCore);
		break;
	case GM_EDIT:
		if (!GET_SINGLE(CEditorCore)->Init())
		{
			DESTROY_SINGLE(CEditorCore);
			return 0;
		}

		GET_SINGLE(CEditorCore)->Run();

		DESTROY_SINGLE(CEditorCore);
		break;
	}

	return 0;
}