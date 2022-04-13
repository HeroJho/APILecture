#include "pch.h"
#include "CSKillMgr.h"
#include "CSkill.h"


CSKillMgr::CSKillMgr()
{
}

CSKillMgr::~CSKillMgr()
{
	for (int i = 0; i < m_vecSkill.size(); ++i)
	{
		if (nullptr != m_vecSkill[i])
			delete m_vecSkill[i];
	}

	m_vecSkill.clear();
}

void CSKillMgr::update()
{
	for (int i = 0; i < m_vecSkill.size(); ++i)
	{
		m_vecSkill[i]->update();
	}
}

void CSKillMgr::AddSkill(CSkill* _pSkill)
{
	m_vecSkill.push_back(_pSkill);
}
