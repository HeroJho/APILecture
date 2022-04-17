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
	, m_fSpawnTheta(0.f)
	, m_iCount(0)
{

}

CSpawner::~CSpawner()
{

}

void CSpawner::Init(MONSTER_TYPE _eMonsterType, float _fGenSpeed, UINT _iCount)
{
	m_eMonsterType = _eMonsterType;
	m_fGenSpeed = _fGenSpeed;
	m_iCount = _iCount;
}

void CSpawner::Set_MonsterType(MONSTER_TYPE _eMonsterType)
{
	m_eMonsterType = _eMonsterType;
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


void CSpawner::CreateMonster()
{

	switch (m_eMonsterType)
	{
	case MONSTER_TYPE::NONE:
		break;
	case MONSTER_TYPE::BALLMAN:
	{
		for (int i = 0; i < m_iCount; ++i)
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

	m_fSpawnTheta = GetRandomNum(0.f, DPI);

	//if (DPI < m_fSpawnTheta)
	//	m_fSpawnTheta = 0;

	vRandomPos.x = vPlayerPos.x + 800.f * cosf(m_fSpawnTheta);
	vRandomPos.y = vPlayerPos.y + 800.f * sinf(m_fSpawnTheta);

	return vRandomPos;
}
