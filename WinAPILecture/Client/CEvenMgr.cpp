#include "pch.h"
#include "CEvenMgr.h"

#include "CObject.h"
#include "CSceneMgr.h"
#include "CScene.h"

#include "CUIMgr.h"

CEvenMgr::CEvenMgr()
{

}
CEvenMgr::~CEvenMgr()
{

}

void CEvenMgr::update()
{
	// ===============================================
	// 이전 프레임에 등록해둔 Dead Object들을 삭제한다.
	// ===============================================
	for (size_t i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();


	// ==========
	// Event 처리
	// ==========
	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}

	m_vecEvent.clear(); // 다 처리했으면 비운다
}

void CEvenMgr::Excute(const tEvent& _eve)
{
	switch (_eve.eEven)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : Object Adress
		// wParam : Group Type
		CObject* pNewObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;

		CSceneMgr::GetInst()->GetCurScene()->AddObject(pNewObj, eType);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// IParam : Object Adress
		// Object를 Dead 상태로 변경
		// 삭제예정 오브젝트들을 모아둔다.
		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		// lParam : Next Scene type
		// Scene 변경
		CSceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_eve.lParam);
		
		// 포커스 UI 해제(이전 씬의 UI를 가리키고 있따)
		CUIMgr::GetInst()->SetFocusedUI(nullptr);
	}
		break;
	}
}
