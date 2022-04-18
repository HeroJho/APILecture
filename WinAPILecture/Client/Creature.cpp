#include "pch.h"
#include "Creature.h"

#include "CKeyMgr.h"

#include "CTimmer.h"

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


void Creature::update()
{
	// Timmer������Ʈ�� ������ �ְ�, �ð��� ����ٸ�
	if (GetTimmer())
	{
		if (KEY_HOLD(KEY::SPACE))
		{
			GetTimmer()->backTimeUpdate();
			return;
		}
		else
		{
			GetTimmer()->update();		// ���� ��ǥ ���
		}

		if (GetTimmer()->IsNowStop())
			return;
		else
			CreatureUpdate();
	}

	else
		CreatureUpdate();		// ���� ����
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
