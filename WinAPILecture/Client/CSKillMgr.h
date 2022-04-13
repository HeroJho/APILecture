#pragma once

class CSkill;

class CSKillMgr
{
private:
	vector<CSkill*> m_vecSkill;

public:
	void update();

public:
	void AddSkill(CSkill* _pSkill);

public:
	CSKillMgr();
	~CSKillMgr();

};

