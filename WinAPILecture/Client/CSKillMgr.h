#pragma once

class CEnergyBall;
class CTwisterSkill;
class CTTengBallSkill;

class CSKillMgr
{
private:
	CEnergyBall*		m_pEnergyBall;
	CTwisterSkill*		m_pTwisterSkill;
	CTTengBallSkill*	m_pTTengBallSkill;

public:
	void update();

public:
	void UpgradeSkill(SKILL_TYPE _eType);

public:
	CSKillMgr();
	~CSKillMgr();

};

