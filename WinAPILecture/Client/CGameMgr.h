#pragma once

class CPlayer;
class CSKillMgr;

class CGameMgr
{
	SINGLE(CGameMgr)

private:
	CPlayer*		m_pPlayer;
	CSKillMgr*		m_pSkillMgr;


private:
	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }

public:
	CPlayer* GetPlayer() { return m_pPlayer; }
	CSKillMgr* GetSkillMgr() { return m_pSkillMgr; }


	friend class Scene_Start;
};

