#include "pch.h"
#include "Creature.h"


Creature::Creature()
	: m_sInfo(nullptr)
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
	
	if (IsDead())
	{
		DeleteObject(this);
	}
}