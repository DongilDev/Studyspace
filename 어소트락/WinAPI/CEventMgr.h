#pragma once

struct tEvent
{
	EVENT_TYPE	eEven;
	DWORD_PTR	lParam;   // DWORD_PTR 쓰는 이유는 플랫폼에 따라서 바이트값을 변동시키기 위해
	DWORD_PTR	wParam;   // 예를 들어 플랫폼에 따라서 포인터는 4byte 나 8byte일 수 있기 때문
};

class CEventMgr
{
	SINGLE(CEventMgr)
private:
	vector<tEvent> m_vecEvent;

	vector<CObject*> m_vecDead;

public:
	void update();

private:
	void Excute(const tEvent& _eve);

public:
	void AddEvent(const tEvent& _eve) {	m_vecEvent.push_back(_eve);	}	
};

