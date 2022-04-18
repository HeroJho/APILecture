#include "pch.h"
#include "Scene_Start.h"

#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"
#include "CCollisionMgr.h"

#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CCamera.h"

#include "CGameMgr.h"
#include "CSKillMgr.h"

#include "CSpawner.h"

#include "CTTengBall.h"




Scene_Start::Scene_Start()
	: m_pSpawner(nullptr)
{
}

Scene_Start::~Scene_Start()
{
	if (nullptr != m_pSpawner)
		delete m_pSpawner;
}

void Scene_Start::update()
{
	CScene::update();


	// 몬스터 스포너 Update실행
	if(nullptr != m_pSpawner)
		m_pSpawner->update();
	

	//if (KEY_TAP(KEY::ENTER))
	//{
	//	ChangeScene(SCENE_TYPE::TOOL);
	//}

	//if (KEY_TAP(KEY::LBTN))
	//{
	//	Vec2 vLookAt = CCamera::GetInst()->GetRealPos(MOUSE_POS);
	//	CCamera::GetInst()->SetLookAt(vLookAt);
	//}
}

void Scene_Start::Enter()
{
	// Player
	CreatureInfo* pInfo = new CreatureInfo(100, 5, 1);
	CPlayer* pObj = new CPlayer(pInfo);
	pObj->SetName(L"Player");
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);


	// 플레이어를 카메라 타겟으로 설정
	CCamera::GetInst()->SetTarget(pObj);
	// 플레이어를 겜매에 등록
	CGameMgr::GetInst()->SetPlayer(pObj);


	// 기본 에너지볼 스킬 추가
	CGameMgr::GetInst()->GetSkillMgr()->UpgradeSkill(SKILL_TYPE::ENERGEBALL);


	// Spawner 생성
	m_pSpawner = new CSpawner();
	m_pSpawner->Init(MONSTER_TYPE::BALLMAN, 2.f, 1);


	// 충돌 지정 >> 모든 오브젝트마다 충돌 체크하면 경우의 수가 너무 많아진다
	// 설정한 그룹별로 체크한다!
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ITEM);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);


	// Camera Look 초기 지정
	// CCamera::GetInst()->SetLookAt(vResolution / 2.f);
}

void Scene_Start::Exit()
{	
	// 모든 객체 삭제
	DeleteAll();

	// 씬이 종료하면 그룹별 충돌 설정은 초기화!
	// 다음씬에서 충돌 관계가 바뀔 수도 있으니
	CCollisionMgr::GetInst()->Reset();
}
