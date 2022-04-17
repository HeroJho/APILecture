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

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	// DWORD_PTR : 컴파일 환경(32, 64비트)에 따라 자료형(비트)이 바뀐다
	// 포인터의 경우 4, 8바이트 변경이 있으니 사용한다
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

	CEvenMgr::GetInst()->AddEvent(evn);
}

void DeleteObject(CObject* _pObj)
{
	// 풀링 확인
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

float GetRandomNum(float _tLeft, float _tRight)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(_tLeft, _tRight);

	return dis(gen);
}
int GetRandomNum(int _tLeft, int _tRight)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(_tLeft, _tRight);

	return dis(gen);
}

