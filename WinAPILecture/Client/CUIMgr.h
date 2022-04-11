#pragma once

class CUI;

class CUIMgr
{
	SINGLE(CUIMgr);
private:
	CUI*	m_pFocusedUI;

public:
	void update();

	void SetFocusedUI(CUI* _pUI); // Ű�� ���� UI�� �����ϸ� �� UI�� ��Ŀ���� �������� �ϴ� ���� ��Ŀ�� ��ȯ �Լ� �ʿ�

private:
	CUI* GetFocusedUI();

	// �θ� UI ������ ������ Ÿ���� �� UI�� ã�Ƽ� ��ȯ�Ѵ�.
	CUI* GetTargetedUI(CUI* _pParentUI);

};

