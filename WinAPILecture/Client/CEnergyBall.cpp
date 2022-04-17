#include "pch.h"
#include "CEnergyBall.h"

#include "CMissile.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CGameMgr.h"

#include "CPlayer.h"

CEnergyBall::CEnergyBall()
	: m_fCoolDown(0.f)
	, m_fSpeed(0.f)
	, m_fRange(0.f)
	, m_eLevel(SKILL_LEVEL::NONE)
	, m_fCurCool(0.f)
	, m_fCurSkillDir(0.f)
{
	Upgrade();
}

CEnergyBall::~CEnergyBall()
{

}

void CEnergyBall::update()
{
	m_fCurCool += fDT;

	if (m_fCurCool > m_fCoolDown)
	{
		m_fCurSkillDir += DPI / 20.f;
		if (DPI < m_fCurSkillDir)
			m_fCurSkillDir = 0;

		CreateMissile();
		m_fCurCool = 0.f;
	}

}

void CEnergyBall::CreateMissile()
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

	CMissile* pMissile = new CMissile(CGameMgr::GetInst()->GetPlayer(), m_fRange, m_fSpeed);
	pMissile->SetName(L"Missile_Player");
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(m_fCurSkillDir);

	CreateObject(pMissile, GROUP_TYPE::PROJ_PLAYER);
}



void CEnergyBall::Upgrade()
{
	UINT iLevel = (UINT)m_eLevel;

	if (iLevel >= (UINT)SKILL_LEVEL::END - 1)
		return;

	m_eLevel = (SKILL_LEVEL)(++iLevel);

	switch (m_eLevel)
	{
	case SKILL_LEVEL::ONE:
		SetSkill_One();
		break;
	case SKILL_LEVEL::TWO:
		SetSkill_Two();
		break;
	case SKILL_LEVEL::THREE:
		SetSkill_Three();
		break;
	case SKILL_LEVEL::FOUR:
		SetSkill_Four();
		break;
	case SKILL_LEVEL::FIVE:
		SetSkill_Five();
		break;
	}
}

void CEnergyBall::SetSkill_One()
{
	m_fCoolDown = 2.f;
	m_fSpeed = 200.f;
	m_fRange = 150.f;

}

void CEnergyBall::SetSkill_Two()
{
	m_fCoolDown = 1.5f;
	m_fSpeed = 250.f;
	m_fRange = 200.f;

}

void CEnergyBall::SetSkill_Three()
{
	m_fCoolDown = 1.f;
	m_fSpeed = 300.f;
	m_fRange = 250.f;

}

void CEnergyBall::SetSkill_Four()
{
	m_fCoolDown = 0.5f;
	m_fSpeed = 350.f;
	m_fRange = 300.f;

}

void CEnergyBall::SetSkill_Five()
{
	m_fCoolDown = 0.1f;
	m_fSpeed = 600.f;
	m_fRange = 400.f;

}
