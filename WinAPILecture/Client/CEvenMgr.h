#pragma once

// ������Ʈ ����, ���� �� �̺�Ʈ���� ���ð��뿡 ó���ž��Ѵ�!
// ���������������� �� ������ �������� �̺�Ʈ�� �ٷ� ó���ϸ�
// �� �������� ���ð��� ������ �ƴϴ� ������Ʈ�� �����ߴ��ϸ�
// �� ������ �ڵ� �������� �տ����� �����߰�, �ڴ� ������ �Ұ����� ������ �ȴ�!
// ���� ó���� ���ش�!! �̺�Ʈ ��Ƶΰ� �������� ������ �ѹ��� ó��!
struct tEvent
{
	EVENT_TYPE		eEven;	// �̺�Ʈ Ÿ��
	DWORD_PTR		lParam; // �̺�Ʈ ����
	DWORD_PTR		wParam; // �̺�Ʈ ����
};

class CEvenMgr
{
	SINGLE(CEvenMgr)
private:
	vector<tEvent> m_vecEvent;

	vector<CObject*> m_vecDead;	// �������� ������Ʈ


public:
	void update();

private:
	void Excute(const tEvent& _eve);

public:
	void AddEvent(const tEvent& _exe) { m_vecEvent.push_back(_exe); }
};

