#include "pch.h"
#include "Creature.h"


Creature::Creature()
	: m_sInfo(nullptr)
	, m_vDir{}
	, m_fTheta(0)
	, m_bIsDie(false)
{

}

Creature::~Creature()
{
	if (nullptr != m_sInfo)
		delete m_sInfo;
}


void Creature::Attacked(Creature* _pAttacker)
{
	m_sInfo->m_iHp -= _pAttacker->m_sInfo->m_iAt;
	
	if (IsHpZero() && !m_bIsDie)
	{
		m_bIsDie = true;
		Die();
	}
}