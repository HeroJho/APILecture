#include "pch.h"
#include "CGameMgr.h"


#include "CSKillMgr.h"
#include "CPoolingMgr.h"


CGameMgr::CGameMgr()
	: m_pPlayer(nullptr)
	, m_pSkillMgr(nullptr)
	, m_pPoolingMgr(nullptr)
{
	// 매니저들 생성
	m_pSkillMgr = new CSKillMgr;
	m_pPoolingMgr = new CPoolingMgr;


}

CGameMgr::~CGameMgr()
{
	if (nullptr != m_pSkillMgr)
		delete m_pSkillMgr;
	if (nullptr != m_pPoolingMgr)
		delete m_pPoolingMgr;


}
