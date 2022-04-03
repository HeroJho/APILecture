#include "pch.h"
#include "Scene_Start.h"

#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"
#include "CCollisionMgr.h"

void Scene_Start::Enter()
{
}

void Scene_Start::Exit()
{
}

Scene_Start::Scene_Start()
{
	// Player
	CObject* pObj = new CPlayer();
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	// Monster ��ġ
	int iMonCount = 10;
	float fMoveDist = 50.f;
	float fObjScale = 50.f;

	Vec2 vResolution = CCore::GetInst()->GetResolution();
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale / 2.f) * 2)) / (float)(iMonCount-1);

	CMonster* pMonsterObj = nullptr;

	for (int i = 0; i < iMonCount; ++i)
	{
		pMonsterObj = new CMonster();
		pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 50.f));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}

	// �浹 ���� >> ��� ������Ʈ���� �浹 üũ�ϸ� ����� ���� �ʹ� ��������
	// ������ �׷캰�� üũ�Ѵ�!
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
}

Scene_Start::~Scene_Start()
{
	// ���� �����ϸ� �׷캰 �浹 ������ �ʱ�ȭ!
	// ���������� �浹 ���谡 �ٲ� ���� ������
	CCollisionMgr::GetInst()->Reset();
}
