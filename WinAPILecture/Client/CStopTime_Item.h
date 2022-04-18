#pragma once
#include "CItem.h"


class CStopTime_Item :
    public CItem
{
private:


public:
	virtual void update();
	virtual void render(HDC _dc);


	CLONE(CStopTime_Item);
private:
	virtual void useItem(CObject* _pObj);

public:
	CStopTime_Item(Vec2 _vPos);
	~CStopTime_Item();
};

