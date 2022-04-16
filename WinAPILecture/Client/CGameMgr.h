#pragma once

class CPlayer;

class CSKillMgr;
class CPoolingMgr;

class CGameMgr
{
	SINGLE(CGameMgr)


private:


private:
	CPlayer*		m_pPlayer;

	CSKillMgr*		m_pSkillMgr;
	CPoolingMgr*	m_pPoolingMgr;

private:
	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }

public:
	CPlayer* GetPlayer() { return m_pPlayer; }

	CSKillMgr* GetSkillMgr() { return m_pSkillMgr; }
	CPoolingMgr* GetPoolingMgr() { return m_pPoolingMgr; }

	friend class Scene_Start;
};

