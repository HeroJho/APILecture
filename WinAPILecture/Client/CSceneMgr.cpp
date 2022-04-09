#include "pch.h"
#include "CSceneMgr.h"

#include "Scene_Start.h"
#include "CScene_Tool.h"
#include "CEvenMgr.h"

CSceneMgr::CSceneMgr()
	:m_arrScene{},
	m_pCurScene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{
	for (int i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if(nullptr != m_arrScene[i])
			delete m_arrScene[i];
	}
}

void CSceneMgr::init()
{
	// �� ����
	m_arrScene[(UINT)SCENE_TYPE::START] = new Scene_Start();
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");

	m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CScene_Tool();
	m_arrScene[(UINT)SCENE_TYPE::TOOL]->SetName(L"Tool Scene");
	
	// ���� �� ����
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TOOL];
	m_pCurScene->Enter();

}

void CSceneMgr::update()
{
	m_pCurScene->update();

	// ���� �Ű� �� �ᵵ ���ư��� ���� ���� (Collider����)
	// render���� ó���Ǳ� ������ update���� finalupdate�� ó���� ���¸� �׻� ���Եȴ�!
	m_pCurScene->finalupdate();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}

void CSceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();

	m_pCurScene = m_arrScene[(UINT)_eNext];

	m_pCurScene->Enter();
}

