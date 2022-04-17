#include "pch.h"
#include "CTwisterSkill.h"

#include "CTwister.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CGameMgr.h"

#include "CPlayer.h"

CTwisterSkill::CTwisterSkill()
	: m_fCoolDown(0.f)
	, m_eLevel(SKILL_LEVEL::NONE)
	, m_fCurCool(0.f)
	, m_fCurSkillDir(0.f)
	, m_fSpeed(0.f)
	, m_fRange(0.f)
	, m_iCount(0)
{
	Upgrade();
}

CTwisterSkill::~CTwisterSkill()
{

}

void CTwisterSkill::update()
{
	// 초당 몇 도 만큼 회전하냐
	m_fCurSkillDir += m_fSpeed * fDT;

	if (DPI < m_fCurSkillDir)
		m_fCurSkillDir = 0.f;

	float fThetaPer = DPI / m_vecTwister.size();
	float fTemp = 0.f;
	float fCurTheta = 0;

	for (int i = 0; i < m_vecTwister.size(); ++i)
	{
		fCurTheta = fTemp + m_fCurSkillDir;
		if (fCurTheta > DPI)
			fCurTheta -= DPI;

		m_vecTwister[i]->SetDir(fCurTheta);
		m_vecTwister[i]->update();
		fTemp += fThetaPer;
	}

}

void CTwisterSkill::CreateTwister()
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

	CTwister* pTwister = new CTwister(CGameMgr::GetInst()->GetPlayer(), 200);
	pTwister->SetName(L"Twister_Player");

	m_vecTwister.push_back(pTwister);

	CreateObject(pTwister, GROUP_TYPE::PROJ_PLAYER);
}

void CTwisterSkill::Upgrade()
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

void CTwisterSkill::SetSkill_One()
{ 
	m_fSpeed = 1.f;
	m_fRange = 200.f;
	m_iCount = 1;

	CreateTwister();
}

void CTwisterSkill::SetSkill_Two()
{
	m_fSpeed = 1.5f;
	m_fRange = 200.f;
	m_iCount = 2;

	CreateTwister();
}

void CTwisterSkill::SetSkill_Three()
{
	m_fSpeed = 2.f;
	m_fRange = 200.f;
	m_iCount = 3;

	CreateTwister();
}

void CTwisterSkill::SetSkill_Four()
{
	m_fSpeed = 2.5f;
	m_fRange = 200.f;
	m_iCount = 5;

	CreateTwister();
	CreateTwister();
}

void CTwisterSkill::SetSkill_Five()
{
	m_fSpeed = 3.f;
	m_fRange = 200.f;
	m_iCount = 8;

	CreateTwister();
	CreateTwister();
	CreateTwister();
}
