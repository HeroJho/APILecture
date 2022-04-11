#pragma once

class CUI;

class CUIMgr
{
	SINGLE(CUIMgr);
private:
	CUI*	m_pFocusedUI;

public:
	void update();

	void SetFocusedUI(CUI* _pUI); // 키를 눌러 UI를 생성하면 그 UI가 포커스를 가져가야 하니 강제 포커스 전환 함수 필요

private:
	CUI* GetFocusedUI();

	// 부모 UI 내에서 실제로 타겟팅 된 UI를 찾아서 반환한다.
	CUI* GetTargetedUI(CUI* _pParentUI);

};

