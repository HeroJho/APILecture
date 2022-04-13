#include "pch.h"
#include "CSkill.h"


CSkill::CSkill(float _fCoolDown)
	: m_fCurCool(0.f)
	, m_fCoolDown(_fCoolDown)
{

}

CSkill::~CSkill()
{
}


void CSkill::SetStat(float _fCoolDown)
{
	m_fCoolDown = _fCoolDown;
}
