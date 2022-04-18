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


	// ���� ������ Update����
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


	// �÷��̾ ī�޶� Ÿ������ ����
	CCamera::GetInst()->SetTarget(pObj);
	// �÷��̾ �׸ſ� ���
	CGameMgr::GetInst()->SetPlayer(pObj);


	// �⺻ �������� ��ų �߰�
	CGameMgr::GetInst()->GetSkillMgr()->UpgradeSkill(SKILL_TYPE::ENERGEBALL);


	// Spawner ����
	m_pSpawner = new CSpawner();
	m_pSpawner->Init(MONSTER_TYPE::BALLMAN, 2.f, 1);


	// �浹 ���� >> ��� ������Ʈ���� �浹 üũ�ϸ� ����� ���� �ʹ� ��������
	// ������ �׷캰�� üũ�Ѵ�!
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::ITEM);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);


	// Camera Look �ʱ� ����
	// CCamera::GetInst()->SetLookAt(vResolution / 2.f);
}

void Scene_Start::Exit()
{	
	// ��� ��ü ����
	DeleteAll();

	// ���� �����ϸ� �׷캰 �浹 ������ �ʱ�ȭ!
	// ���������� �浹 ���谡 �ٲ� ���� ������
	CCollisionMgr::GetInst()->Reset();
}
