#pragma once

class CObject;

class CTimmer
{
private:
	CObject*			m_pOwner;
	list<Vec2>			m_listPrePos;		// ���� ��ǥ

	float				m_fPreTime;			// �� �� �ǵ��� ����
	float				m_fCurTime;

	bool				m_bIsStopObj;		// �ð� ���� ������Ʈ����


public:
	void SetNoneStopObj() { m_bIsStopObj = false; }
	bool IsStopObj() { return m_bIsStopObj; }
	bool IsNowStop();

public:
	void backTimeUpdate();

public:
	void update();
	void finalupdate();
	void render(HDC _dc);


public:
	CTimmer();
	~CTimmer();

	friend class CObject;
};

