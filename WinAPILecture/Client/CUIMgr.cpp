#include "pch.h"
#include "CUIMgr.h"

#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CScene.h"
#include "CUI.h"


CUIMgr::CUIMgr()
	: m_pFocusedUI(nullptr)
{

}

CUIMgr::~CUIMgr()
{

}

void CUIMgr::update()
{
	// 1. FocusedUI 확인
	m_pFocusedUI = GetFocusedUI();

	if (!m_pFocusedUI)
		return;


	// 2. FocusedUI 내에서 부모 UI 포함, 자식 UI들 중 실제 타켓팅 된 UI를 가져온다.
	CUI* pTargetUI = GetTargetedUI(m_pFocusedUI);

	bool bLbtnTap = KEY_TAP(KEY::LBTN);
	bool bLbtnAway = KEY_AWAY(KEY::LBTN);

	// 타겟이 있다면(마우스가 해당 자식에 올라가 있었다면)
	if (nullptr != pTargetUI)
	{
		pTargetUI->MouseOn();

		// 왼마우스 눌렀다
		if (bLbtnTap)
		{
			pTargetUI->MouseLbtnDown();
			pTargetUI->m_bLbtnDown = true;
		}
		else if (bLbtnAway)
		{
			pTargetUI->MouseLbtnUp();

			if (pTargetUI->m_bLbtnDown)
			{
				pTargetUI->MouseLbtnClicked();
			}

			// 왼쪽버튼 때면, 마우스가 위에 있다면 눌렸던 체크를 해제
			pTargetUI->m_bLbtnDown = false;
		}
	}
		
}

void CUIMgr::SetFocusedUI(CUI* _pUI)
{
	// 이미 포커싱인 경우 or 포커싱 해제요청인 경우
	if (m_pFocusedUI == _pUI || nullptr == _pUI)
	{
		m_pFocusedUI = _pUI;
		return;
	}

	m_pFocusedUI = _pUI;

	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	vector<CObject*>& vecUI = pCurScene->GetUIGroup();

	vector<CObject*>::iterator iter = vecUI.begin();

	for (; iter != vecUI.end(); ++iter)
	{
		if (m_pFocusedUI == *iter)
		{
			break;
		}
	}

	// 순번 교체
	vecUI.erase(iter);
	vecUI.push_back(m_pFocusedUI);

}

CUI* CUIMgr::GetFocusedUI()
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	vector<CObject*>& vecUI = pCurScene->GetUIGroup();

	bool bLbtnTap = KEY_TAP(KEY::LBTN);

	CUI* pFocusedUI = m_pFocusedUI;

	// 애초에 클릭이 안 됐으면 포커스가 바뀔 일이 없다
	if (!bLbtnTap)
	{
		return pFocusedUI;
	}

	vector<CObject*>::iterator targetiter = vecUI.end();
	vector<CObject*>::iterator iter = vecUI.begin();

	for (; iter != vecUI.end(); ++iter)
	{
		// 마우스가 위에 있는 UI
		if (((CUI*)*iter)->IsMouseOn())
		{
			// 계속 갱신. 겹쳐도 결국은 맨 뒤(맨 앞에 랜더링한)UI가 포커스로 됨!
			targetiter = iter;
		}
	}

	// 이번에 Focus된 UI가 없다
	if (vecUI.end() == targetiter)
	{
		return nullptr;
	}

	pFocusedUI = (CUI*)*targetiter;

	// 벡터 내에서 맨 뒤로 순번 교체
	vecUI.erase(targetiter);
	vecUI.push_back(pFocusedUI);

	return pFocusedUI;
} 

CUI* CUIMgr::GetTargetedUI(CUI* _pParentUI)
{
	bool bLbtnAway = KEY_AWAY(KEY::LBTN);

	// 1.부모 UI 포함, 모든 자식들을 검사한다.
	CUI* pTargetUI = nullptr;

	static list<CUI*> queue;
	static vector<CUI*> vecNoneTarget;

	queue.clear();
	vecNoneTarget.clear();

	queue.push_back(_pParentUI);

	while (!queue.empty())
	{
		// 큐에서 데이터 꺼내기
		CUI* pUI = queue.front();
		queue.pop_front();

		// =============================================

		// 큐에서 꺼내온 UI가 TargetUI인지 확인
		// 타켓 UI들 중, 더 우선순위가 높은 기준은 더 낮은 계층의 자식 UI
		if (pUI->IsMouseOn())
		{
			if (nullptr != pTargetUI)
			{
				vecNoneTarget.push_back(pTargetUI);
			}

			pTargetUI = pUI;
		}
		else
		{
			vecNoneTarget.push_back(pUI);
		}

		// =============================================

		// 자식 UI를 큐에 넣는다.
		const vector<CUI*>& vecChild = pUI->GetChildUI();
		for (size_t i = 0; i < vecChild.size(); ++i)
		{
			queue.push_back(vecChild[i]);
		}

	}

	
	// 왼쪽버튼 떼면, 눌렸던 체크를 다시 해제한다.
	if (bLbtnAway)
	{
		for (size_t i = 0; i < vecNoneTarget.size(); ++i)
		{
			vecNoneTarget[i]->m_bLbtnDown = false;
		}
	}

	return pTargetUI;
}
