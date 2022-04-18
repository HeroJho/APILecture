#pragma once

class CPlayer;

class CSKillMgr;
class CPoolingMgr;
class CPlayTimeMgr;

class CGameMgr
{
	SINGLE(CGameMgr)
private:


private:
	CPlayer*		m_pPlayer;

	CSKillMgr*		m_pSkillMgr;
	CPoolingMgr*	m_pPoolingMgr;
	CPlayTimeMgr*	m_pPlayTimeMgr;

private:
	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }


public:
	void update();


public:
	CPlayer* GetPlayer() { return m_pPlayer; }

	CSKillMgr* GetSkillMgr() { return m_pSkillMgr; }
	CPoolingMgr* GetPoolingMgr() { return m_pPoolingMgr; }
	CPlayTimeMgr* GetPlayTimeMgr() { return m_pPlayTimeMgr; }

	friend class Scene_Start;
};

