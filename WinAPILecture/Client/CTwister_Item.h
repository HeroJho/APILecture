#pragma once
#include "CItem.h"


class CTwister_Item :
	public CItem
{
private:


public:
	virtual void update();
	virtual void render(HDC _dc);


	CLONE(CTwister_Item);
private:
	virtual void useItem(CObject* _pObj);

public:
	CTwister_Item(Vec2 _vPos);
	~CTwister_Item();
};

