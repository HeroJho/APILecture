#include "pch.h"
#include "CSKillMgr.h"

#include "CEnergyBall.h"
#include "CTwisterSkill.h"
#include "CTTengBallSkill.h"


CSKillMgr::CSKillMgr()
	: m_pEnergyBall(nullptr)
	, m_pTwisterSkill(nullptr)
	, m_pTTengBallSkill(nullptr)
{
}

CSKillMgr::~CSKillMgr()
{
	if (nullptr != m_pEnergyBall)
		delete m_pEnergyBall;
	if (nullptr != m_pTwisterSkill)
		delete m_pTwisterSkill;
	if (nullptr != m_pTTengBallSkill)
		delete m_pTTengBallSkill;
}

void CSKillMgr::update()
{
	if (nullptr != m_pEnergyBall)
		m_pEnergyBall->update();

	if (nullptr != m_pTwisterSkill)
		m_pTwisterSkill->update();

	if (nullptr != m_pTTengBallSkill)
		m_pTTengBallSkill->update();
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
		case SKILL_TYPE::TTENGBALL:
		{
			if (nullptr == m_pTTengBallSkill)
				m_pTTengBallSkill = new CTTengBallSkill();
			else
				m_pTTengBallSkill->Upgrade();
		}
		break;
	}

}
