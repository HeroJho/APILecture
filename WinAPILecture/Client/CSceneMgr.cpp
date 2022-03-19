#include "pch.h"
#include "CSceneMgr.h"

#include "Scene_Start.h"

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
	// ¾À »ý¼º
	m_arrScene[(UINT)SCENE_TYPE::START] = new Scene_Start();
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	
	// ÇöÀç ¾À ÁöÁ¤
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();

}

void CSceneMgr::update()
{
	m_pCurScene->update();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}

