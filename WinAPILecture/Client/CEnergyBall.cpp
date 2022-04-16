#include "pch.h"
#include "CEnergyBall.h"

#include "CMissile.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CGameMgr.h"

#include "CPlayer.h"

CEnergyBall::CEnergyBall(float _fCoolDown, float _fSpeed, float _fRange)
	: CSkill(_fCoolDown)
	, m_fCurSkillDir(0.f)
	, m_fSpeed(_fSpeed)
	, m_fRange(_fRange)
{

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
	//CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

	//CMissile* pMissile = new CMissile(CGameMgr::GetInst()->GetPlayer(), m_fRange, m_fSpeed);
	//pMissile->SetName(L"Missile_Player");
	//pMissile->SetScale(Vec2(25.f, 25.f));
	//pMissile->SetDir(m_fCurSkillDir);

	//CreateObject(pMissile, GROUP_TYPE::PROJ_PLAYER);

	CreateEnergeBall(m_fRange, m_fSpeed, m_fCurSkillDir);

}