#include "pch.h"
#include "CTwisterSkill.h"

#include "CTwister.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CGameMgr.h"

#include "CPlayer.h"

CTwisterSkill::CTwisterSkill(float _fCoolDown, float _fSpeed, float _fRange, UINT _iCount)
	: CSkill(_fCoolDown)
	, m_fCurSkillDir(0.f)
	, m_fSpeed(_fSpeed)
	, m_fRange(_fRange)
	, m_iCount(_iCount)
{
	for (int i = 0; i < m_iCount; ++i)
	{
		CreateTwister();
	}
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