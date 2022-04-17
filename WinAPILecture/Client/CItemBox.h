#pragma once
#include "CItem.h"


class CItemBox :
    public CItem
{
private:


public:
	virtual void update();
	virtual void render(HDC _dc);


	CLONE(CItemBox);
private:
	virtual void useItem(CObject* _pObj);
	void GenerateRandomItem();

public:
	CItemBox(Vec2 _vPos);
	~CItemBox();
};

