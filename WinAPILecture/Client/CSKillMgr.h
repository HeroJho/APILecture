#pragma once

class CEnergyBall;
class CTwisterSkill;

class CSKillMgr
{
private:
	CEnergyBall*	m_pEnergyBall;
	CTwisterSkill*	m_pTwisterSkill;

public:
	void update();

public:
	void UpgradeSkill(SKILL_TYPE _eType);

public:
	CSKillMgr();
	~CSKillMgr();

};

