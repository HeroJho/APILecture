#include "pch.h"
#include "CSKillMgr.h"

#include "CEnergyBall.h"
#include "CTwisterSkill.h"


CSKillMgr::CSKillMgr()
	: m_pEnergyBall(nullptr)
	, m_pTwisterSkill(nullptr)
{
}

CSKillMgr::~CSKillMgr()
{
	if (nullptr != m_pEnergyBall)
		delete m_pEnergyBall;

	if (nullptr != m_pTwisterSkill)
		delete m_pTwisterSkill;
}

void CSKillMgr::update()
{
	if (nullptr != m_pEnergyBall)
		m_pEnergyBall->update();

	if (nullptr != m_pTwisterSkill)
		m_pTwisterSkill->update();
}

void CSKillMgr::UpgradeSkill(SKILL_TYPE _eType)
{

	switch (_eType)
	{
		case SKILL_TYPE::ENERGEBALL:
		{
			if (nullptr == m_pEnergyBall)
				m_pEnergyBall = new CEnergyBall();
			else
				m_pEnergyBall->Upgrade();
		}
			break;
		case SKILL_TYPE::TWISTER:
		{
			if (nullptr == m_pTwisterSkill)
				m_pTwisterSkill = new CTwisterSkill();
			else
				m_pTwisterSkill->Upgrade();
		}
			break;
	}

}
