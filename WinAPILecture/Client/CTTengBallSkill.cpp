#include "pch.h"
#include "CTTengBallSkill.h"

#include "CTTengBall.h"
#include "CSceneMgr.h"
#include "CGameMgr.h"

#include "CPlayer.h"

CTTengBallSkill::CTTengBallSkill()
	: m_eLevel(SKILL_LEVEL::NONE)
	, m_fSpeed(300.f)
	, m_iCount(0)
{
	Upgrade();
}

CTTengBallSkill::~CTTengBallSkill()
{

}

void CTTengBallSkill::update()
{
	//for (int i = 0; i < m_vecTTengBall.size(); ++i)
	//{
	//	// m_vecTTengBall[i]->update();
	//}
}

void CTTengBallSkill::Upgrade()
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

void CTTengBallSkill::SetSkill_One()
{
	m_iCount = 1;
	m_fSpeed = 300.f;

	CreateTTengBall();
}

void CTTengBallSkill::SetSkill_Two()
{
	m_iCount = 2;
	m_fSpeed = 400.f;

	CreateTTengBall();
}

void CTTengBallSkill::SetSkill_Three()
{
	m_iCount = 3;
	m_fSpeed = 500.f;

	CreateTTengBall();
}

void CTTengBallSkill::SetSkill_Four()
{
	m_iCount = 5;
	m_fSpeed = 700.f;

	CreateTTengBall();
	CreateTTengBall();
}

void CTTengBallSkill::SetSkill_Five()
{
	m_iCount = 8;
	m_fSpeed = 1000.f;

	CreateTTengBall();
	CreateTTengBall();
	CreateTTengBall();
}

void CTTengBallSkill::CreateTTengBall()
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

	CTTengBall* pTTengBall = new CTTengBall(CGameMgr::GetInst()->GetPlayer(), m_fSpeed);
	pTTengBall->SetName(L"TTengBall_Player");

	m_vecTTengBall.push_back(pTTengBall);

	CreateObject(pTTengBall, GROUP_TYPE::PROJ_PLAYER);
}