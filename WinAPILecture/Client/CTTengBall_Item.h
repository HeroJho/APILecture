#pragma once
#include "CItem.h"

class CTTengBall_Item :
	public CItem
{
private:


public:
	virtual void update();
	virtual void render(HDC _dc);


	CLONE(CTTengBall_Item);
private:
	virtual void useItem(CObject* _pObj);

public:
	CTTengBall_Item(Vec2 _vPos);
	~CTTengBall_Item();
};

