#pragma once
#include "CItem.h"


class CEnergeBall_Item :
    public CItem
{
private:


public:
	virtual void update();
	virtual void render(HDC _dc);


	CLONE(CEnergeBall_Item);
private:
	virtual void useItem(CObject* _pObj);

public:
	CEnergeBall_Item(Vec2 _vPos);
	~CEnergeBall_Item();
};

