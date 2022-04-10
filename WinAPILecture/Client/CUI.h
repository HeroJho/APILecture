#pragma once

#include "CObject.h"

class CUI: 
	public CObject
{
private:
	vector<CUI*>	m_vecChildUI;
	CUI*			m_pParentUI;

	Vec2			m_vFinalPos;

public:
	Vec2 GetFinalPos() { return m_vFinalPos; }


	CUI* GetParent() { return m_pParentUI; }
	void AddChild(CUI* _pUI) { m_vecChildUI.push_back(_pUI); _pUI->m_pParentUI = this; }

private:
	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);


private:
	void update_child();
	void finalupdate_child();
	void render_child(HDC _dc);

public:
	virtual void MouseOn();

	virtual void MouseLbtnDown();
	virtual void MouseLbtnUp();
	virtual void MouseLbtnClicked();



	CLONE(CUI);

public:
	CUI();
	virtual ~CUI();
};

