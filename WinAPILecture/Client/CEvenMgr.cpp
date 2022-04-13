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
	// ���� �����ӿ� ����ص� Dead Object���� �����Ѵ�.
	// ===============================================
	for (size_t i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();


	// ==========
	// Event ó��
	// ==========
	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}

	m_vecEvent.clear(); // �� ó�������� ����
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
		// Object�� Dead ���·� ����
		// �������� ������Ʈ���� ��Ƶд�.
		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		// lParam : Next Scene type
		// Scene ����
		CSceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_eve.lParam);
		
		// ��Ŀ�� UI ����(���� ���� UI�� ����Ű�� �ֵ�)
		CUIMgr::GetInst()->SetFocusedUI(nullptr);
	}
		break;
	}
}
