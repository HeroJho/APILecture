#include "pch.h"
#include "CGameMgr.h"
#include "CSKillMgr.h"

CGameMgr::CGameMgr()
	: m_pPlayer(nullptr)
	, m_pSkillMgr(nullptr)
{
	m_pSkillMgr = new CSKillMgr;

}

CGameMgr::~CGameMgr()
{
	if (nullptr != m_pSkillMgr)
		delete m_pSkillMgr;
}
