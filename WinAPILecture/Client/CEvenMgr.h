#pragma once

// 오브젝트 생성, 삭제 등 이벤트들은 동시간대에 처리돼야한다!
// ㅁㅁㅁㅁㅇㅁㅁㅁ 한 프레임 기준으로 이벤트를 바로 처리하면
// 한 프레임이 동시간의 개념이 아니니 오브젝트를 삭제했다하면
// 한 프레임 코드 기준으로 앞에서는 존재했고, 뒤는 참조가 불가능한 삭제가 된다!
// 지연 처리를 해준다!! 이벤트 모아두고 프레임이 끝나면 한번에 처리!
struct tEvent
{
	EVENT_TYPE		eEven;	// 이벤트 타입
	DWORD_PTR		lParam; // 이벤트 정보
	DWORD_PTR		wParam; // 이벤트 정보
};

class CEvenMgr
{
	SINGLE(CEvenMgr)
private:
	vector<tEvent> m_vecEvent;

	vector<CObject*> m_vecDead;	// 삭제예정 오브젝트


public:
	void update();

private:
	void Excute(const tEvent& _eve);

public:
	void AddEvent(const tEvent& _exe) { m_vecEvent.push_back(_exe); }
};

