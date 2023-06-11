#pragma once

struct Vec2
{
	float x;
	float y;

public:
	/*Vec2& operator = (POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}*/

	// CScene_Start::Enter() 함수에서 
	// Vec2 vResolution = CCore::GetInst()->GetResolution(); 이 코드를 적용시키기 위한 연산자 오버로딩이였지만
	// 초기화와 동시에 대입이 이루어 질 경우 복사생성자가 호출되므로 복사생성자를 만들어 주는 방법으로 바꿈 

public:
	Vec2()
		:x(0.f)
		,y(0.f)
	{}

	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}

	Vec2(int _x, int _y)
		:x ((float)_x)
		,y ((float)_y)
	{}

	Vec2(const POINT& _pt)
		:x((float)_pt.x)
		, y((float)_pt.y)
	{}
};