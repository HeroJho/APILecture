#pragma once
#include "CObject.h"

class CTexture;

class CTile
	: public CObject
{
private:
	CTexture*	m_pTileTex;
	int			m_iIdx;			// 어느 타일을 선택 중인지. 음수면 아무것도 x

public:
	void SetTexture(CTexture* _pTex) { m_pTileTex = _pTex; }


private:
	virtual void update();
	virtual void render(HDC _dc);

	CLONE(CTile);
public:
	CTile();
	~CTile();

};

