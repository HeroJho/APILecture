#include "pch.h"
#include "func.h"

#include "CEvenMgr.h"
#include "CGameMgr.h"
#include "CPoolingMgr.h"
#include "CPooling.h"
#include "CObject.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"
#include "CMissile.h"

void CreateEnergeBall(float _fRange, float _fSpeed, float _vDir)
{
	CObject* _pObj = CGameMgr::GetInst()->GetPoolingMgr()->Get_PoolingObj(POOLING_TYPE::ENERGEBALL);

	if (nullptr != _pObj)
	{
		CMissile* pMissile = (CMissile*)_pObj;
		pMissile->Init(CGameMgr::GetInst()->GetPlayer(), _fRange, _fSpeed);
		pMissile->SetName(L"Missile_Player");
		pMissile->SetScale(Vec2(25.f, 25.f));
		pMissile->SetDir(_vDir);
	}
	else
	{
		CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

		CMissile* pMissile = new CMissile(CGameMgr::GetInst()->GetPlayer(), _fRange, _fSpeed);
		pMissile->SetName(L"Missile_Player");
		pMissile->SetScale(Vec2(25.f, 25.f));
		pMissile->SetDir(_vDir);

		CreateObject(pMissile, GROUP_TYPE::PROJ_PLAYER);
	}


}

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	// Ǯ�� Ȯ��
	//if (_pObj->GetPooling())
	//{
	//	POOLING_TYPE eType = _pObj->GetPooling()->Get_PoolingType();
	//	CGameMgr::GetInst()->GetPoolingMgr()->Get_PoolingObj(eType);

	//	return;
	//}


	// DWORD_PTR : ������ ȯ��(32, 64��Ʈ)�� ���� �ڷ���(��Ʈ)�� �ٲ��
	// �������� ��� 4, 8����Ʈ ������ ������ ����Ѵ�
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

	CEvenMgr::GetInst()->AddEvent(evn);
}

void DeleteObject(CObject* _pObj)
{
	// Ǯ�� Ȯ��
	if (_pObj->GetPooling())
	{
		CGameMgr::GetInst()->GetPoolingMgr()->Set_PoolingObj(_pObj);

		return;
	}

	tEvent evn = {};
	evn.eEven = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;

	CEvenMgr::GetInst()->AddEvent(evn); 

}

void ChangeScene(SCENE_TYPE _eNext)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::SCENE_CHANGE;
	evn.lParam = (DWORD_PTR)_eNext;

	CEvenMgr::GetInst()->AddEvent(evn);
}
