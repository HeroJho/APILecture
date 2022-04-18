#pragma once

class CObject;

class CTimmer
{
private:
	CObject*			m_pOwner;
	list<Vec2>			m_listPrePos;		// 이전 좌표

	float				m_fPreTime;			// 몇 초 되돌릴 건지
	float				m_fCurTime;

	bool				m_bIsStopObj;		// 시간 멈춤 오브젝트인지


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

