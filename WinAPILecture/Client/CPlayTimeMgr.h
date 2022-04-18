#pragma once


class CPlayTimeMgr
{
private:
	bool		m_bIsStop;
	float		m_fStopTime;
	float		m_fCurTime;

public:
	void SetIsStop(bool _bIsStop) { m_bIsStop = _bIsStop; }
	bool GetIsStop() { return m_bIsStop; }

public:
	void update();

public:
	CPlayTimeMgr();
	~CPlayTimeMgr();
};

