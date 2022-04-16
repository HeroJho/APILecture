#include "pch.h"
#include "CSpawner.h"

#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CGameMgr.h"
#include "CScene.h"

#include "Creature.h"
#include "CMonster.h"
#include "CPlayer.h"

CSpawner::CSpawner()
	: m_eMonsterType(MONSTER_TYPE::BALLMAN)
	, m_fGenSpeed(1.f)
	, m_fCurTime(0.f)
	, m_test(0.f)
{

}

CSpawner::~CSpawner()
{

}



void CSpawner::update()
{
	m_fCurTime += fDT;
	if (m_fGenSpeed < m_fCurTime)
	{
		


		CreateMonster();



		m_fCurTime = 0.f;
	}

}

void CSpawner::Set_MonsterType(MONSTER_TYPE _eMonsterType)
{
	m_eMonsterType = _eMonsterType;
}

void CSpawner::CreateMonster()
{
	UINT iCount = 10;		// 몇 마리를


	switch (m_eMonsterType)
	{
	case MONSTER_TYPE::NONE:
		break;
	case MONSTER_TYPE::BALLMAN:
	{
		for (int i = 0; i < iCount; ++i)
		{
			CreateBallMan();
		}
	}		
		break;
	}
}

void CSpawner::CreateBallMan()
{
	CScene* cCurScene = CSceneMgr::GetInst()->GetCurScene();

	CreatureInfo* pInfo = new CreatureInfo(10, 1, 1);

	CMonster* pMonsterObj = new CMonster(pInfo);
	pMonsterObj->SetName(L"Monster");
	pMonsterObj->SetPos(GenerateRandomPos());
	pMonsterObj->SetScale(Vec2(50.f, 50.f));
	// cCurScene->AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	CreateObject(pMonsterObj, GROUP_TYPE::MONSTER);
}

Vec2 CSpawner::GenerateRandomPos()
{
	Vec2 vRandomPos{};

	Vec2 vPlayerPos = CGameMgr::GetInst()->GetPlayer()->GetPos();

	float fTheta = 0.f;
	m_test += 1.0f;

	if (DPI < m_test)
		m_test = 0;

	vRandomPos.x = vPlayerPos.x + 1000.f * cosf(m_test);
	vRandomPos.y = vPlayerPos.y + 1000.f * sinf(m_test);

	return vRandomPos;
}
